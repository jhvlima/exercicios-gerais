#include <stdio.h> 
#include "esfera_utils.h" 
 
int main () 
{ 
    float R, volume, area; 
    float *pArea = &area, *pVolume = &volume;
    scanf("%f", &R); 
 
    CalculaVolume(R, pVolume); 
    CalculaArea(R, pArea); 
 
    printf("Area: %.2f\n", area); 
    printf("Volume: %.2f\n", volume); 
 
    return 0; 
}