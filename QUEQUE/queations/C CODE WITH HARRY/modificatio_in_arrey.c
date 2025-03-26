#include <stdio.h>

void store(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {   printf("enter element no : %d ",i+1);
        scanf("%d",arr+i);
    }
    printf("\n");
}
void display(int *arr,int n)
{
    for(int i=0;i<n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}
void op(int *arr, int n,int k)
{
    for(int i=0;i<k;i++) //expression will be perform k times ::
    {
         for(int i=0;i<n;i++)
         {
            if(i%2==0)
            {
                *(arr+i)=*(arr+i)*2+1;
            }
            else
            {
                *(arr+i)=*(arr+i)*2;
            }
            
         }
    }
}
void even_odd(int *arr,int n)
{
   for(int i=0;i<n;i++){
    if(*(arr+i)%2==0)
    {
        *(arr+i)=*(arr+i)*2+1;
    }
    else
    {
        *(arr+i)=*(arr+i)*2;
    }
    
   }
}

void sum(int *arr,int n)
{
    for(int i=0;i<n;i++)
    {
        if(i!=(n-1+i))
        {

            *(arr+i)=*(arr+i)+*(arr+n-1+i);
        }
        else
        {
            *(arr+i)=*(arr+i);
        }
        
        
    }
}
int main(){
    int num[100];
    store(num,7) ;
    printf("original arrey is :\n");
    display(num,7);
    op(num,7,3);
    printf("after modification 1  :\n");
    display(num,7);
    for(int i=0;i<3;i++)
    {
        even_odd(num,7);
    }
    printf("after modification 2:\n");
    display(num,7);
    printf("summe:\n");
    sum(num,7);
    display(num,4);

    return 0;
}