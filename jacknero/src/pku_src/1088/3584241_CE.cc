#include<iostream>

using namespace std;

int main(void)
{
	int r,c,j,i;
	cin>>r>>c;
	int **save=new int *[r*c];
	for(int i=0;i<r*c;i++)
	{
		save[i]=new int[2];
		save[i][0]=0;
		save[i][1]=0;
	}

	int **a=new int *[r];
	int **b=new int *[r];
	for(i=0;i<r;i++)
	{
		a[i]=new int[c];
		b[i]=new int[c];
		for(j=0;j<c;j++)
		{
			b[i][j]=0;
			cin>>a[i][j];
			for(int k=0;k<i*c+j;k++)
			{
				if(save[k][1]>=a[i][j])
					break;
			}
			int count;
			count=i*c+j;
			for(;k<count;count--)
			{
				save[count][0]=save[count-1][0];
				save[count][1]=save[count-1][1];
			}
			save[k][0]=i*c+j;
			save[k][1]=a[i][j];
		}
	}

	int all=0;
	int temp;
	for(int m=0;m<r*c;m++)
	{
		    temp=0;
			i=save[m][0]/c;
			j=save[m][0]%c;
			if(i-1>=0) 
			{
				if(a[i][j]>a[i-1][j]&&temp<=b[i-1][j]) temp=b[i-1][j]+1;
			}	
	        if(i+1<r)  
			{
				if(a[i][j]>a[i+1][j]&&temp<=b[i+1][j]) temp=b[i+1][j]+1;
			}
	        if(j-1>=0) 
			{
				if(a[i][j]>a[i][j-1]&&temp<=b[i][j-1]) temp=b[i][j-1]+1;
			}
	        if(j+1<c)  
			{
				if(a[i][j]>a[i][j+1]&&temp<=b[i][j+1]) temp=b[i][j+1]+1; 
			}

			b[i][j]=temp;
			if(all<temp) all=temp;
	}
     cout<<all+1<<endl;
	return 0;
}
