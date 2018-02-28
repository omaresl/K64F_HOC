/*
 * app_Time.c
 *
 *  Created on: 26/02/2018
 *      Author: uidj2522
 */


void app_Time_Delay(void)
{
	unsigned int lul_Time;

	lul_Time = 10000000u;

	do
	{
		lul_Time--;
	}while(lul_Time > 0u);
}
