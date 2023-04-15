#include <stdio.h>

float powerr(float x, float y){
    if (y == 0)
        return 1;
    if (y == 1)
        return x;
    else
        return x * powerr(x, y - 1);
}

int main(){

    float x, y;
    scanf("%f", &x);
    scanf(" %f", &y);

    printf("powerr(%.2f, %.2f): %.2f", x, y, powerr(x, y));
    printf("\n");
    return 0;
}