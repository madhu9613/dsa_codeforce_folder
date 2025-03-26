#include <stdio.h>
int main()
{

  int t;
  scanf("%d", &t);

  while (t--)
  {

     int room[100] = {0};
    int l, r, L, R;

    scanf("%d%d", &l, &r);
    scanf("%d%d", &L, &R);

    for (int i = l; i <= r; i++)
    {
      room[i]++;
    }
    for (int i = L; i <= R; i++)

    {
      room[i]++;
    }
    int count = 0;
    for (int i = 0; i <100; i++)
    {
      if (room[i] == 2 && room[i-1]==1)
      {
                  count++;
      }
      if(room[i]==2 && room[i+1]==1 && i<100)
      {
        count++;
      }
      if(room[i]==2)
      {
        count++;
      }
    }
int ans=count-1;
if(ans<0)
{
  ans=-1*ans;
}
    printf("%d\n",ans);
  }

  return 0;
}