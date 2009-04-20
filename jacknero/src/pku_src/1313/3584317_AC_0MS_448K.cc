#include <iostream>
using namespace std;
struct page
{
 int pageNum[4];
};
int main()
{
 int totalPages,sheets;
 page pages[26];
 int i,p,ps,temp=0,back=0;
 while(1)
 {
  cin>>totalPages;
  if( totalPages==0 ) break;
  memset(pages,0,sizeof(pages));
  sheets=totalPages/4;
  if(totalPages%4!=0) sheets++;
  back=temp=ps=0;p=-1;
  for(i=1; i<=totalPages; i++)
  {
   if( i<=sheets*2 )
   {
    if(i%2==1) p++;  
    if(temp==0)
     pages[p].pageNum[1]=i;
    else
     pages[p].pageNum[2]=i;
    temp = (temp+1)%2;
    back=0;
   }
   else
   {
    if(back==0) { p++; back=1; }
    if( i%2==1 ) p--;
    if(temp==0)
     pages[p].pageNum[3]=i;
    else
     pages[p].pageNum[0]=i;
    temp = (temp+1)%2;
   }
  } 
  cout<<"Printing order for "<<totalPages<<" pages:"<<endl;
  for(i=0;i<sheets;i++)
  {
   if( (pages[i].pageNum[0]==0 && pages[i].pageNum[1]==0) )
    continue;
   cout<<"Sheet "<<i+1<<", front: ";
   if(pages[i].pageNum[0]!=0) cout<<pages[i].pageNum[0]<<", ";
   else cout<<"Blank, ";
   if(pages[i].pageNum[1]!=0) cout<<pages[i].pageNum[1]<<endl;
   else cout<<"Blank"<<endl;

   if( pages[i].pageNum[2]==0 && pages[i].pageNum[3]==0 )
    continue;
   cout<<"Sheet "<<i+1<<", back : ";
   if(pages[i].pageNum[2]!=0) cout<<pages[i].pageNum[2]<<", ";
   else cout<<"Blank, ";
   if(pages[i].pageNum[3]!=0) cout<<pages[i].pageNum[3]<<endl;
   else cout<<"Blank"<<endl;
  }
 }
 return 0;
}

