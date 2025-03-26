#include <stdio.h>

int main(){
    int a,b;
    printf("enter the value of a and b : \n");
    scanf("%d %d", &a,&b);

    // condition ? expression-if-true : expression-if-false
    a>b? printf("a is greater") :printf(" b is greater ");
    return 0;
}