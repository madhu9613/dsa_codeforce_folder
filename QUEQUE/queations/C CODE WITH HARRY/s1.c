//structure help us to store dissimilar data;;

#include <stdio.h>
#include<string.h>


struct employee
{
    int code;
    char name[20];
    float sallary;
};

int main(){
    struct employee e1, e2,e3,e4,e5,e6;

    e1.code=8012;
    strcpy(e1.name ,"madhujya\n");
    e1.sallary=20000;
    // printf("%d %s %.2lf \n",e1.code , e1.name , e1.sallary);
    

    e2.code=8013; 
    strcpy(e2.name ,"bhumi\n");
    e2.sallary=20000;

   
    

    e3.code=8014; 
    strcpy(e3.name ,"jintu\n");
    e3.sallary=20000;
    

    e4.code=8015; 
    strcpy(e4.name ,"rahim\n");
    e4.sallary=20000;
    

    e5.code=8016; 
    strcpy(e5.name ,"jibon\n");
    e5.sallary=20000;
    

    e6.code=8013; 
    strcpy(e6.name ,"lakhi\n");
    e6.sallary=20000;

    struct employee e[]={e1,e2,e3,e4,e5,e6};
    for(int i=0; i<6 ;i++)
    {
        printf("EMPLOYEE NO : %d\n",i+1);
         printf("%d %s %.2lf \n",e[i].code , e[i].name , e[i].sallary);

    }

    return 0;
}