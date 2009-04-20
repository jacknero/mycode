#include <iostream>
using namespace std;

struct Rectangle
{
int minx;
int maxx;
int miny;
int maxy;
};

int main()
{
int Area[5000],Area1[5000],a[5000];
Rectangle Rec[5000];
int i ,j ,temp ;
int num, Index ,sum;
while(scanf("%d",&num )!=EOF )
{
   for(i=0; i<num; i++)
   {
    scanf("%d %d %d %d", &Rec[i].minx, &Rec[i].maxx, &Rec[i].miny, &Rec[i].maxy );
    Area[i] = ( Rec[i].maxx - Rec[i].minx ) *( Rec[i].maxy-Rec[i].miny);
    Area1[i] =Area[i];
   }

        for(i=0;i<num-1;i++)
     {
           int   min=i;
           for(j = i+1; j < num; j ++)
             if( Area1[j] < Area1[min])
                min = j;
           temp = Area1[min];
           Area1[min] = Area1[i];
           Area1[i] = temp;
     }
     for(i = 0; i < num; i ++)
           for(j=0 ; j < num; j ++)
             if(Area1[i] == Area[j])
             {
                Area[j]=0;
                a[i]=j;
                break;
    }
        for(sum=0,j=0;j<num-1;j++)
          for(i=j+1;i<num;i++)
            if(Rec[a[j]].maxx<=Rec[a[i]].maxx&&Rec[a[j]].minx>=Rec[a[i]].minx
      &&Rec[a[j]].maxy<=Rec[a[i]].maxy&&Rec[a[j]].miny>=Rec[a[i]].miny )
            {     
               sum++;
               break;
     }     
        for(i=0;i<num-1;i++)
           if(Rec[i].maxx==Rec[num-1].maxx && Rec[i].minx==Rec[num-1].minx
     &&Rec[i].maxy==Rec[num-1].maxy&&Rec[i].miny==Rec[num-1].miny)
           {
              sum+=1;
              break;
           }

   printf("%d\n",sum);
}
return 0;
}
