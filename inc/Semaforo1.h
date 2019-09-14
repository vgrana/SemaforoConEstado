/*
 * Semaforo.h
 *
 *  Created on: 2 sep. 2019
 *      Author: valeria
 */

#ifndef SEMAFORO_H_
#define SEMAFORO_H_

enum Color1 {
	Roja, Amarilla, Verde
};
enum Estado {
	Apagar, Prender
};
typedef struct Semaforo {
	int LuzRoja;
	int LuzAmarilla;
	int LuzVerde;

} Semaforo;

//////////////////////////////////////////////////////////////////////////////////////////
//                                 P   A   R  T  E    1                                //
////////////////////////////////////////////////////////////////////////////////////////

void EstadoInicial1(Semaforo * sema);
void SemaforoInicializar1(Semaforo * sema, int color);
void SemaforoPrenderLuz1(Semaforo * sema, int color);
void ApagarUnaLuz1(Semaforo * sema, int color);
void CambiarLuz1(Semaforo * sema, int color);
void SemaforoImprimir1(Semaforo * sema);

#endif /* SEMAFORO_H_ */
