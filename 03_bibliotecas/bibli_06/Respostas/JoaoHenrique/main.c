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
            convertido = convert_temperature(temperatura, convert_kelvin_to_celsius);
        }
        else
        {
            convertido = convert_temperature(temperatura, convert_kelvin_to_fahrenheit);
        } 
    }
    else if (from == 'c')
    {
        if (to == 'k')
        {
            convertido = convert_temperature(temperatura, convert_celsius_to_kelvin);
        }
        else
        {
            convertido = convert_temperature(temperatura, convert_celsius_to_fahrenheit);
        }
    }
    else
    {
        if (to == 'k')
        {
            convertido = convert_temperature(temperatura, convert_fahrenheit_to_kelvin);
        }
        else
        {
            convertido = convert_temperature(temperatura, convert_fahrenheit_to_celsius);
        }    
    }
    
    printf("Temperature: %.2f", convertido);
    
    if (to == 'k' || to == 'K')
    {
        printf("K");
    }
    else if (to == 'c' || to == 'C')
    {
        printf("Cº");
    }
    else
    {
        printf("Fº");
    }
    
    return 0;
}