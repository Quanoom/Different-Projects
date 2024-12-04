#include <p18f452.h>
#pragma config WDT = OFF

#define		rs		PORTCbits.RC0
#define 	rw 		PORTCbits.RC1
#define 	en		PORTCbits.RC2
#define 	max		5

unsigned char state = 0, decision = 0, j = 0;
unsigned char array[max];

void initiaLcd(void);			
void delay250ms(void);		
void delay3us(void);			
void commandInst(void);
void busyFlag(void);				
void dataInst(void);				
void timer0Generation(void);
void firstLine(void);
void secondLine(void);
void thirdLine(void);
void forthLine(void);
void displayChoice(unsigned char* str);
void validatChoice(void);
void newPass(void);
void entPass(void);
void seePass(void);
void clearForthLine(void);
void storePass(void);

#pragma interrupt myFunction
void myFunction(void)
{
	if(PIR1bits.TMR1IF == 1)		
	{
		PIR1bits.TMR1IF = 0;
		TMR1H = 0x3C;
		TMR1L = 0xB0;
		switch(state)
		{
			case 0 :
				state = 1;
				LATA = 0x7E;
				break;
			case 1:
				state = 2;
				LATA = 0x7D;
				break;
			case 2:
				state = 0;
				LATA = 0x7B;
				break;
		}
	}
	else if(INTCONbits.RBIF == 1)
	{
		PORTB = PORTB;
		if( j <= 4)
		{
			if(PORTAbits.RA0 == 0)
			{
				if(PORTBbits.RB4 == 0)
				{
					LATD = '3';
					if(decision == 0)
						decision = '3';
					else
					{
						array[j++] = '3';
						PORTEbits.RE0 = ~PORTEbits.RE0;
						delay250ms();
						PORTEbits.RE0 = ~PORTEbits.RE0;
					}
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB5 == 0)	
				{
					LATD = '6';
					array[j++] = '6';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB6 == 0)
				{
					LATD = '9';
					array[j++] = '9';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB7 == 0)
					storePass();
			}
			else if(PORTAbits.RA1 == 0)
			{
				if(PORTBbits.RB4 == 0)
				{
					LATD = '2';
					if(decision == 0)
						decision = '2';
					else
					{
						array[j++] = '2';
						PORTEbits.RE0 = ~PORTEbits.RE0;
						delay250ms();
						PORTEbits.RE0 = ~PORTEbits.RE0;
					}
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB5 == 0)	
				{
					LATD = '5';
					array[j++] = '5';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB6 == 0)
				{
					LATD = '8';
					array[j++] = '8';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB7 == 0)
				{
					LATD = '0';
					array[j++] = '0';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
			}
			else if(PORTAbits.RA2 == 0)
			{
				if(PORTBbits.RB4 == 0)
				{
					LATD = '1';
					if(decision == 0)
						decision = '1';
					else
					{
						array[j++] = '1';
						PORTEbits.RE0 = ~PORTEbits.RE0;
						delay250ms();
						PORTEbits.RE0 = ~PORTEbits.RE0;
					}
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB5 == 0)	
				{
					LATD = '4';
					array[j++] = '4';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB6 == 0)
				{
					LATD = '7';
					array[j++] = '7';
					PORTEbits.RE0 = ~PORTEbits.RE0;
					delay250ms();
					PORTEbits.RE0 = ~PORTEbits.RE0;
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB7 == 0)
					validatChoice();
			}
		}
		else
		{
			if(PORTAbits.RA2 == 0)
			{
				if(PORTBbits.RB4 == 0)
				{
					LATD = '1';
					if(decision == 0)
						decision = '1';
					else
					{
						array[j++] = '1';
						PORTEbits.RE0 = ~PORTEbits.RE0;
						delay250ms();
						PORTEbits.RE0 = ~PORTEbits.RE0;
					}
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB7 == 0)
					validatChoice();
			}
			else if(PORTAbits.RA1 == 0)
			{
				if(PORTBbits.RB4 == 0)
				{
					LATD = '2';
					if(decision == 0)
						decision = '2';
					else
					{
						array[j++] = '2';
						PORTEbits.RE0 = ~PORTEbits.RE0;
						delay250ms();
						PORTEbits.RE0 = ~PORTEbits.RE0;
					}
					dataInst();
					busyFlag();
				}	
			}
			if(PORTAbits.RA0 == 0)
			{
				if(PORTBbits.RB4 == 0)
				{
					LATD = '3';
					if(decision == 0)
						decision = '3';
					else
					{
						array[j++] = '3';
						PORTEbits.RE0 = ~PORTEbits.RE0;
						delay250ms();
						PORTEbits.RE0 = ~PORTEbits.RE0;
					}
					dataInst();
					busyFlag();
				}
				else if(PORTBbits.RB7 == 0)
					storePass();
			}
		}
		INTCONbits.RBIF = 0;	
	}	
}

#pragma code myInterruptVector = 0x00008
void myInterruptVector(void)
{
	_asm
		GOTO myFunction
	_endasm
}
#pragma code


/* MAIN FUNCTION */
void main(void)
{
		unsigned char string_1[] = "1.NEW PASSWORD", string_2[] = "2.ENTER PASSWORD", string_3[] = "3.SEE PASSWORD", string_4[] = "ENTER : ";
		TRISB = 0xF1;			
		TRISD = 0x00;	
		TRISC = 0xF8;
		TRISA = 0x78;
		TRISEbits.TRISE0 = 0;
		PORTEbits.RE0 = 0;
		ADCON1 = 0x07;	
		initiaLcd();
		firstLine();
		displayChoice(string_1);
		secondLine();
		displayChoice(string_2);
		thirdLine();
		displayChoice(string_3);
		forthLine();
		displayChoice(string_4);
		INTCONbits.GIE = 1;				
		INTCONbits.PEIE = 1;		
		INTCONbits.RBIE = 1;			
		PIE1bits.TMR1IE = 1;		
		PIR1bits.TMR1IF = 0;	
		INTCONbits.RBIF = 0;
		T1CON = 0x14;
		TMR1H = 0x3C;
		TMR1L = 0xB0;
		T1CONbits.TMR1ON = 1;			
		while(1);				
}
void initiaLcd(void)
{
		LATD = 0x38;
		commandInst();
		delay250ms();
		LATD = 0x01;
		commandInst();
		delay250ms();
		LATD = 0x0F;
		commandInst();
		delay250ms();
}
void delay250ms(void)
{
		T0CON = 0x01;
		TMR0H = 0x0B;
		TMR0L = 0xBC;
		timer0Generation();		
}
void delay3us(void)
{
		T0CON = 0x48;
		TMR0L = 253;
		timer0Generation();
}
void commandInst(void)
{
		rs = 0;
		rw = 0;
		en = 1;
		delay3us();
		en = 0;
}
void dataInst(void)
{
		rs = 1;
		rw = 0;
		en = 1;
		delay3us();
		en = 0;
}
void busyFlag(void)
{
		rs = 0;
		rw = 1;	
		TRISDbits.TRISD7 = 1;
		do
		{
			en = 0;
			delay3us();
			en = 1;
		}while(PORTDbits.RD7 == 1);
		en = 0;
		TRISDbits.TRISD7 = 0;
}
void timer0Generation(void)
{
	INTCONbits.TMR0IF = 0;
	T0CONbits.TMR0ON = 1;
	while(INTCONbits.TMR0IF == 0);
	INTCONbits.TMR0IF = 0;
	T0CONbits.TMR0ON = 0;	
}
void firstLine(void)				// JUMP TO FIRST LINE
{
	LATD = 0x80;
	commandInst();
	busyFlag();
}
void secondLine(void)				// JUMP TO SECOND LINE
{		
	LATD = 0xC0;
	commandInst();
	busyFlag();
}
void thirdLine(void)				// JUMP TO THIRD LINE
{
	LATD = 0x90;
	commandInst();
	busyFlag();
}
void forthLine(void)				// JUMP TO FORTH LINE
{
	LATD = 0xD0;
	commandInst();
	busyFlag();
}
void displayChoice(unsigned char* str)
{
	unsigned char i = 0;
	while(str[i] != '\0')
	{
		LATD = str[i];
		dataInst();
		busyFlag();
		++i;
	}	
}
void validatChoice(void)
{
	switch(decision)
	{
		case '1' :
			newPass();
			break;
		case '3' :
			seePass();
			break;
	}
}
void seePass(void)
{
	unsigned char i = 0, str[] = "PASS : ";
	clearForthLine();
	while(str[i] != '\0')
	{
		LATD = str[i];
		dataInst();
		busyFlag();
		++i;	
	}
 	i = 0;
	while(array[i] != '\0')
	{
		LATD = array[i];
		dataInst();
		busyFlag();
		++i;	
	}	
}
void clearForthLine(void)
{
	unsigned char i = 0;
	forthLine();
	while(i<16)
	{
		LATD = 0x20;		
		dataInst();
		busyFlag();
		++i;
	}
	forthLine();	
}
void newPass(void)
{
	unsigned char str[] = "ENT PASS:", i = 0;
	clearForthLine();
	while(str[i] != '\0')
	{
		LATD = str[i];		
		dataInst();
		busyFlag();
		++i;
	}
}
void storePass(void)
{
	unsigned char string_4[] = "ENTER : ", i = 0;
	clearForthLine();
	displayChoice(string_4);
	decision = 0;
}