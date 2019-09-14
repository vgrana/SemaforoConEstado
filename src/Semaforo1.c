/*
 * Semaforo.c
 *
 *  Created on: 2 sep. 2019
 *      Author: valeria
 */
#include "Semaforo1.h"
#include "sapi.h"

void EstadoInicial1(Semaforo * sema) {
	sema->LuzRoja = 0;
	sema->LuzAmarilla = 0;
	sema->LuzVerde = 0;
}

void SemaforoInicializar1(Semaforo * sema, int colorLuz) {
	EstadoInicial1(sema);
	if (Roja == colorLuz) {
		sema->LuzRoja = 1;
	}
	if (Amarilla == colorLuz) {
		sema->LuzAmarilla = 1;
	}
	if (Verde == colorLuz) {
		sema->LuzVerde = 1;
	}

}
void SemaforoPrenderLuz1(Semaforo * sema, int colorLuz) {

EstadoInicial1(sema);
	if (Roja == colorLuz) {
		sema->LuzRoja = 1;
	}
	if (Amarilla == colorLuz) {
		sema->LuzAmarilla = 1;
	}
	if (Verde == colorLuz) {
		sema->LuzVerde = 1;
	}
}

void ApagarUnaLuz1(Semaforo * sema, int colorLuz) {
		if (Roja == colorLuz) {
			sema->LuzRoja = 0;
		}
		if (Amarilla == colorLuz) {
			sema->LuzAmarilla = 0;
		}
		if (Verde == colorLuz) {
			sema->LuzVerde =0;
		}
	}



void SemaforoImprimir1(Semaforo * sema) {
	if ((sema->LuzRoja) == 1) {
		gpioWrite(LED2, ON);
	} else {
		gpioWrite(LED2, OFF);
	}
	if ((sema->LuzAmarilla) == 1) {
		gpioWrite(LED1, ON);
	} else {
		gpioWrite(LED1, OFF);
	}
	if ((sema->LuzVerde) == 1) {
		gpioWrite(LED3, ON);
	} else {
		gpioWrite(LED3, OFF);
	}

}

void CambiarLuz1(Semaforo * sema, int colorLuz) {
	EstadoInicial1(sema);
	SemaforoPrenderLuz1(sema, colorLuz);
}

