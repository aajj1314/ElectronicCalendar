#include <REGX52.H>
#include <INTRINS.H>
#include "delay.h"

void Delay(unsigned int xms)	//@24.000MHz
{
	unsigned char data i, j;
	while(xms--)
	{
	i = 4;
	j = 225;
	do
	{
		while (--j);
	} while (--i);
	}
}


