/*
 * SemaforoSecuenciado.c
 *
 *  Created on: 6 sep. 2019
 *      Author: valeria
 */
#include "Semaforo1.h"
#include "SemaforoSecuenciado.h"
#include "sapi.h"

void EstadoInicial(SemaforoSecuenciado * semSec) {

	semSec->sema.LuzRoja = 1;
	(semSec->TiempoRoja) = tiempoLuzRoja;
	semSec->sema.LuzAmarilla = 0;
	(semSec->TiempoAmarilla) = tiempoLuzAmarilla;
	semSec->sema.LuzVerde = 0;
	(semSec->TiempoVerde) = tiempoLuzVerde;
	(semSec->ultimoCambio) = tickRead();
	(semSec->EstadoSemaforo) = Ro;

}
void SemaforoInicializar(SemaforoSecuenciado * semSec, int LuzAPrender,
		int AsignarTiempoALuz) {
	EstadoInicial(semSec);
	if (Roja == LuzAPrender) {
		(semSec->sema.LuzRoja) = 1;
		semSec->TiempoRoja = AsignarTiempoALuz;
		delay(semSec->TiempoRoja);
	}
	if (Amarilla == LuzAPrender) {
		(semSec->sema.LuzAmarilla) = 1;
		semSec->TiempoAmarilla = AsignarTiempoALuz;
		delay(semSec->TiempoAmarilla);
	}
	if (Verde == LuzAPrender) {
		(semSec->sema.LuzVerde) = 1;
		semSec->TiempoVerde = AsignarTiempoALuz;
		delay(semSec->TiempoVerde);
	}

}
void SemaforoImprimir(SemaforoSecuenciado * semSec) {

	if ((semSec->sema.LuzRoja) == 1) {

		gpioWrite(LED2, ON);
	} else {
		gpioWrite(LED2, OFF);

	}
	if ((semSec->sema.LuzAmarilla) == 1) {
		gpioWrite(LED1, ON);
	} else {
		gpioWrite(LED1, OFF);
	}
	if ((semSec->sema.LuzVerde) == 1) {
		gpioWrite(LED3, ON);
	} else {
		gpioWrite(LED3, OFF);
	}
}
void SemaforoPrenderLuz(SemaforoSecuenciado * semSec, int colorLuz,
		int tiempoEncendido) {

	EstadoInicial(semSec);
	if (Roja == colorLuz) {
		semSec->sema.LuzRoja = 1;
		semSec->TiempoRoja = tiempoEncendido;
		delay(semSec->TiempoRoja);
	}
	if (Amarilla == colorLuz) {
		semSec->sema.LuzAmarilla = 1;
		semSec->TiempoAmarilla = tiempoEncendido;
		delay(semSec->TiempoAmarilla);
	}
	if (Verde == colorLuz) {
		semSec->sema.LuzVerde = 1;
		semSec->TiempoVerde = tiempoEncendido;
		delay(semSec->TiempoVerde);
	}
}

void CambiarLuz(SemaforoSecuenciado * semSec, int colorLuz, int tiempoEncendido) {
//	EstadoInicial(semSec);
	SemaforoPrenderLuz(semSec, colorLuz, tiempoEncendido);
}

void cicloSemaforo_Update(SemaforoSecuenciado * semSec) {
	int TickActual = tickRead();
	int TiempoPasado = TickActual - semSec->ultimoCambio;

	switch (semSec->EstadoSemaforo) {
	case Ro: {
		if (TiempoPasado >= semSec->TiempoRoja) {
			semSec->EstadoSemaforo = AR;
			semSec->ultimoCambio = TickActual;
		}
		break;
	}
	case AR: {
		if (TiempoPasado >= semSec->TiempoAmarilla) {
			semSec->EstadoSemaforo = V;
			semSec->ultimoCambio = TickActual;

		}
		break;
	}
	case V: {
		if (TiempoPasado >= semSec->TiempoVerde) {
			semSec->EstadoSemaforo = AV;
			semSec->ultimoCambio = TickActual;

		}
		break;
	}
	case AV: {
		if (TiempoPasado >= semSec->TiempoAmarilla) {
			semSec->EstadoSemaforo = Ro;
			semSec->ultimoCambio = TickActual;
		}
		break;
	}

	}
}

void cicloSemaforo_Render(SemaforoSecuenciado * semSec) {
	switch (semSec->EstadoSemaforo) {

	case Ro: {
		gpioWrite(LED1, 0);
		gpioWrite(LED2, 1);
		gpioWrite(LED3, 0);
		break;
	}
	case AR: {
		gpioWrite(LED1, 1);
		gpioWrite(LED2, 1);
		gpioWrite(LED3, 0);
		break;
	}
	case V: {
		gpioWrite(LED1, 0);
		gpioWrite(LED2, 0);
		gpioWrite(LED3, 1);
		break;
	}
	case AV: {
		gpioWrite(LED1, 1);
		gpioWrite(LED2, 0);
		gpioWrite(LED3, 1);
		break;
	}

	}
}

