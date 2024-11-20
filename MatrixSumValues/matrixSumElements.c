#include <stdio.h>
#define R 3
#define C 5

int main(void)
{
    unsigned int sum = 0, matrix[R][C] = {{1, 2, 3, 5, 6}, {4, 5, 6, 9, 0}, {1, 5, 7, 1, 2}};
    printf("\nMATRIX VALUES : \n\n");
    for(unsigned int i = 0; i < R; ++i)
    {
        printf("\t\t");
        for(unsigned int j = 0; j < C; ++j)
            printf("%u ", matrix[i][j]);
        printf("\n");
    }
    for(unsigned int i = 0; i < R; ++i)
    {
        for(unsigned int j = 0; j < C; ++j)
            sum += matrix[i][j];
    }
    printf("\nSUM OF MATRIX VALUES = %u\n", sum);
    return 0;
}