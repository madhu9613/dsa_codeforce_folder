#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, d, D;
    printf("Enter coefficient of x^2: \n");
    scanf("%lf", &a);
    printf("Enter coefficient of x: \n");
    scanf("%lf", &b);
    printf("Enter constant term: \n");
    scanf("%lf", &c);

    d = b * b - 4 * a * c;

    if (d == 0) {
        double r1 = -b / (2 * a);
        printf("All roots are real and equal:\n");
        printf("Root is: %lf\n", r1);
    } 
    else if (d > 0) {
        D = sqrt(d); 
        double r1 = (-b + D) / (2 * a);
        double r2 = (-b - D) / (2 * a);
        printf("All roots are real:\n");
        printf("Roots are: %lf and %lf\n", r1, r2);
    } 
    else {
        double rp = -b / (2 * a);
        double ip = sqrt(-d) / (2 * a);
        printf("All roots are complex:\n");
        printf("Roots are: %lf + %lfi and %lf - %lfi\n", rp,ip, rp, ip);
    }

    return 0;
}
