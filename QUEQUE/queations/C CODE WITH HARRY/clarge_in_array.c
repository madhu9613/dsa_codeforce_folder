#include <stdio.h>

int main()
{

    double arr[100];
    int n;
    double largest;
    printf("enter number of element you want to enter (max 100 numbers ):  \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("now enter %d number \n", i + 1);
        scanf("%lf", &arr[i]);
    }

    largest=arr[0];
    s
    for (int i = 1; i< n; i++)
    {
        if(arr[0]<arr[i]){
            arr[0]=arr[i];
        }

    }

    printf("the largest number in the array is : %.2lf", largest);
    return 0;
}