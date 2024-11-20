#include <stdio.h>

int main(void)
{
    unsigned int startValue = 0;
    while(1)
    {
        printf("ENTER THE START VALUE (VALUE MUST BE >=2): ");
        scanf("%u", &startValue);
        if(startValue >= 2)
            break;
        else
            printf("VALUE MUST BE (VALUE >= 2)");
    }
    printf("\nCollatz conjecture : %u ", startValue);
    while(startValue != 1)
    {
        if(startValue % 2 == 0)
            startValue /= 2;
        else
        {
            startValue *= 3;
            startValue += 1;
        }
        printf("%u ", startValue);
    }
    printf("\n");
    return 0;
}