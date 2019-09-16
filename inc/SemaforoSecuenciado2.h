/*
 * SemaforoSecuenciado.h
 *
 *  Created on: 6 sep. 2019
 *      Author: valeria
 */

#ifndef SEMAFOROSECUENCIADO_H_
#define SEMAFOROSECUENCIADO_H_
#define tiempoLuzRoja 4000
#define tiempoLuzAmarilla 3000
#define tiempoLuzVerde 2000

enum EstadoSemaforo {
	Ro, AR, V, AV
};
typedef struct SemaforoSecuenciado {
	Semaforo sema;
	int TiempoRoja;
	int TiempoAmarilla;
	int TiempoVerde;
	int ultimoCambio;
	int EstadoSemaforo;
} SemaforoSecuenciado;


void EstadoInicial(SemaforoSecuenciado * semSec);
void SemaforoInicializar(SemaforoSecuenciado * semSec, int Roja,
		int AsignarTiempoLuzRoja);
void SemaforoImprimir(SemaforoSecuenciado * semSec);
void SemaforoPrenderLuz(SemaforoSecuenciado * semSec, int colorLuz,
		int tiempoEncendido);
void CambiarLuz(SemaforoSecuenciado * semSec, int colorLuz,
		int tiempoEncendido);
void cicloSemaforo(SemaforoSecuenciado * semSec);
void cicloSemaforo_Update(SemaforoSecuenciado * semSec);
void cicloSemaforo_Render(SemaforoSecuenciado * semSec);
#endif /* SEMAFOROSECUENCIADO_H_ */
