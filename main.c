#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TONES 12
#define C 0
#define D 2
#define E 4
#define F 5
#define G 7
#define A 9
#define B 11

void convertNumToLetter(int num);

int main(void)
{
    srand(time(NULL));
    int arrayTones[TONES];

    for (int i = 0; i < TONES; i++)
    {
        arrayTones[i] = i;
    }

    for (int i = 0; i < TONES-2; i++)
    {
        int j, temp;
        do
        {
            j = rand()%TONES;
        } 
        while (j < i && j >= TONES);
        
        temp = arrayTones[i];
        arrayTones[i]=arrayTones[j];
        arrayTones[j]=temp;
    }

        for (int i = 0; i < TONES; i++)
    {
        //printf("%d: %d\n", i, arrayTones[i]);
        //printf("%d: %d\n", i, convertNumToLetter(arrayTones[i]));
        convertNumToLetter(arrayTones[i]);
    }
    printf("\n");
    return 0;
}

void convertNumToLetter(int num)
{
    //printf("num: %d\n", num);
    switch(num)
    {
        case 0 ... 1:
            printf("C");
            break;
        case 2 ... 3:
            printf("D");
            break;
        case 4:
            printf("E");
            break;
        case 5 ... 6:
            printf("F");
            break;
        case 7 ... 8:
            printf("G");
            break;
        case 9 ... 10:
            printf("A");
            break;
        case 11:
            printf("B");
            break;
        default:
            printf("Error!");
            break;
    }
    if (num <= 4)
    {
        if (num % 2 != 0)
        {
            printf("#");
        }
    }
    else
    {
        if (num % 2 == 0)
        {
            printf("#");
        }
    }
    printf(" ");

    return;
}