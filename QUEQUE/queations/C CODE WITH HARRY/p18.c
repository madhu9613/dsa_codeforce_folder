#include <stdio.h>

int main(){
    float per;
    printf("enter student percentage :");
    scanf("%f",&per);
    printf("STUDENT GRADE IS :\n");
    if(per>=90)
    {
        printf("A+");
    }
    else if(per>=80 && per<90)
    {
        printf("A");
    }
     if(per>=60 && per<80)
    {
        printf("B");
    } 
     if(per>=30 && per<60)
    {
        printf("C");
    }
    else if(per<30)
    {
        printf("D");
    }

    return 0;
}