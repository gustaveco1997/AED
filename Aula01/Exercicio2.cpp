#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

float calcula (float x, float y, float z){
    return (sqrtl(x+y+z));
}

main(){
    printf("Resultado: %3.2f\n",calcula(2,3,4));
}
   