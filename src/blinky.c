#include "blinky.h"
#include "sapi.h"
void estadoBlinky() {

	gpioWrite(LEDR, ON);
	delay(500);

	/* Apago el led rojo */
	gpioWrite(LEDR, OFF);
	delay(500);

	gpioWrite(LEDG, ON);
	delay(500);

	/* Apago el led amarillo */
	gpioWrite(LEDG, OFF);
	delay(500);

	/* Prendo el led verde */
	gpioWrite(LEDB, ON);
	delay(500);

	/* Apago el led verde */
	gpioWrite(LEDB, OFF);
	delay(500);

}
