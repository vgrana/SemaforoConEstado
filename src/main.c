/*
 * Main.c
 *
 *  Created on: 2 sep. 2019
 *      Author: valeria
 */

#include "Semaforo2.h"
#include "SemaforoSecuenciado2.h"
#include "sapi.h"
//
int main(void) {
	boardConfig();
	SemaforoSecuenciado semaforo;

	EstadoInicial(&semaforo);
	while (1) {
		estadoBlinky();
		//cicloSemaforo(&semaforo);
		cicloSemaforo_Update(&semaforo);
		cicloSemaforo_Render(&semaforo);
		delay(1);
	}
	return 0;

}
