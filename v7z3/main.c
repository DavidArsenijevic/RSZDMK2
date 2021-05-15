/**
 * @file main.c
 * @version 1.0
 * @brief zad3
 * @author D.A.
 * @date 15.5.2021.
 */

#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>
#include "../usart/usart.h"

int main()
{
	int8_t str[64];
	uint16_t broj;
	uint8_t moduo;         // moduo
	int8_t i;
	int8_t tmp[64];
	int8_t indikator = 1;
	usartInit(9600);

	while (1)
	{

		indikator = 1;
		usartPutString("Unesite ceo broj: \r\n");

		while(!usartAvailable())
		;
		_delay_ms(100);

		broj = usartParseInt();

		usartPutString("Uneli ste broj : \r\n");
		sprintf(str,"%d \0",broj);
		usartPutString(str);
		usartPutString("\r\n");
		//str[duzinastr] = '\0';

		while (broj != 0)
		{

			moduo += (broj % 10);
			broj = broj / 10;

		}
		usartPutString("Vas zbir je : ");
		sprintf(str,"%d \0",moduo);
		usartPutString(str);

	}


}
