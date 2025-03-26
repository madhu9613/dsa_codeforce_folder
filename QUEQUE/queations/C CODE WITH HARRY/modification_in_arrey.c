#include <stdio.h>

int main()
{
    int num[50];
    int mod[50];
    int n;
    int *p = num; // p is a pointer who store address of the first element of num arrey
    int *q = mod; // same is p but it will store in mod arrey

    printf("enter the number of data you want to store :\n");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        // printf("enter data no %d :" ,i+1);
        scanf("%d", p + i);
    }
    for (int i = 0; i < n; i += 2)
    {
        *(q + i) = *(p + i) * 3;
    }
    for (int i = 1; i < n; i += 2)
    {
        *(q + i) = *(p + i) * 2;
    }

    //printing original arrey:
    printf("original data are : \n");
    for(int i=0; i<n; i++)
    {
        printf("%d ", *(p+i));
    }
    printf("\n");
    printf("modified data are : \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",*(q+i));
    }
        return 0;
}