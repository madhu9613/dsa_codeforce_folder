
// write a c++ programe and store some data. and using pointer modify some of the data and accessn it through it::

// for example is 5  is even digit number then the modify will be 10 in odd place it will be 15

// for example array is 1,2 ,3 ,4 ,5 ,6
//  output will be 3,4,9,8,15,12
// now modifing even digit number to 2

#include <stdio.h>

int main()
{
    int num[20];
    int n;
    int a;
    int *p = num;
    // p is pointer to the first element of the num arrey;

    // storing data in arrey
    printf("how many data ou want to store :\n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("eneter data %d :", i + 1);
        scanf("%d", &*(p + i));
    }

    printf("original data is :\n ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }
    // want to modify the data
    for (int i = 1; i < n; i += 2)  // Iterate over even place starting from 2th place;
    {
        *(p + i) *= 2;  //  doubling the value
    }

for(int i=0;i<n;i+=2)
{
    *(p+i) *=3;
}
     printf("\n");
     
    printf("Modified data are :\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", *(p + i));
    }
    
    return 0;
    }