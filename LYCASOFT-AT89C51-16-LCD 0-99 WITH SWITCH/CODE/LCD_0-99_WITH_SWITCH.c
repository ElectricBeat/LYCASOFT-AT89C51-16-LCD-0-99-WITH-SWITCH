#include<reg51.h>
#include "8051_delay.h"
#include "LCD_4_BIT_HEADER_FILE.h"

sbit SW = P1^0;
int Count;

void divider(int x)
{
	int Temp,Dig1,Dig2;
	
	Temp = x;

	Dig1 = Temp/10;
	Lcd_Data(Dig1+48);

	Dig2 = Temp%10;
	Lcd_Data(Dig2+48);
}

void main()
{
	SW = 1;

	Lcd_Intialization();

	Lcd_Command(0x80);
	Lcd_String("LYCO SOFT");
	
	while(1)
	{
		Lcd_Command(0xc0);
		divider(Count);
		
		if(SW == 1)
		{
			Count++;
		}
		
		if(Count > 99)
			Count = 0;
	}
}