#include <stdio.h>
#include "temperature_conversor.h"

int main()
{
    float temperatura, convertido;
    char from, to;
    scanf("%f %c %c", &temperatura, &from, &to);


    if (from == 'k')
    {
        if (to == 'c')
        {

        }
        else
        {
            /* code */
        } 
    }
    else if (from == 'c')
    {
        if (to == 'k')
        {
            /* code */
        }
        else
        {
            /* code */
        }
    }
    else
    {
        if (to == 'k')
        {
            /* code */
        }
        else
        {
            /* code */
        }    
    }
    
    printf("Temperature: %f%c", convertido, to);
    return 0;
}