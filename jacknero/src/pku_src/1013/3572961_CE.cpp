#include "stdio.h"
#include "string.h"
char left[3][7],right[3][7],result[3][5];


bool isHeavy(char x )
{
    int i;
    for(i=0;i<3;i++)
    {
        switch(result[i][0])
        {
        case 'u':if(strchr(left[i],x)==NULL)return false;break;
        case 'e':if(strchr(left[i],x)!=NULL||strchr(right[i],x)!=NULL)return false;break;
        case 'd':if(strchr(right[i],x)==NULL)return false;break;
        }
    }
    return true;
}

bool isLight(char x )
{
    int i;
    for(i=0;i<3;i++)
    {
        switch(result[i][0])
        {
        case 'u':if(strchr(right[i],x)==NULL)return false;break;
        case 'e':if(strchr(left[i],x)!=NULL||strchr(right[i],x)!=NULL)return false;break;
        case 'd':if(strchr(left[i],x)==NULL)return false;break;
        }
    }
    return true;
}

void main()
{
    int n;
    char c;
    int i;
    scanf("%d",&n);
    while(n>0)
    {
        for( i=0;i<3;i++)
            scanf("%s%s%s",left[i],right[i],result[i]);
        for(c='A';c<='L';c++)
        {
            if(isLight(c))
            {
                printf("%c is the counterfeit coin and it is light.\n",c);
                break;
            }
            if(isHeavy(c))
            {
                printf("%c is the counterfeit coin and it is heavy.\n",c);
                break;
            }

        }
        n--;

    }
}