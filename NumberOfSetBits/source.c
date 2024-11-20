/*C CODE FOR COUTING THE NUMBER OF SET BITS IN 32 BIT INTEGER*/
#include<stdio.h>

int main(void)
{
    unsigned int number = 0, position = 1, setBits = 0;
    printf("ENTER YOUR NUMBER : ");
    scanf("%u", &number);
    while(position != 0x00) 
    {
        if(number & position)
            ++setBits;
        position<<= 1;
    }
    printf("NUMBER OF SET BITS ARE %d BITS\n", setBits);
    return 0;
}