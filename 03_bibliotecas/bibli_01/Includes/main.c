#include <stdio.h>
#include <esfera_utils.h>
int main()
{
    float raio, area, volume;
    scanf("%d", &raio);
    area = calcula_area(raio);
    volume = calcula_volume(raio);
    printf("Area:%f\nVolume:%f", area, volume);
    return 0;
}