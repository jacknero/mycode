#include <iostream>
#include <stdlib.h>

//#define DEBUG
#define MAXR 10 
#define MAXC 15
using namespace std;

const int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};

int floodfill(int x,int y , char map[][18], char ch) {
 int _x,_y;
 int tatol=0;
 for(int i=0; i<4; i++) {
   _x=x+dir[i][0];
   _y=y+dir[i][1];
   if(map[_x][_y]==ch) {
    map[_x][_y]='\0';
    tatol+=1+floodfill(_x,_y,map,ch);
   }
 }
 return tatol;
}

void shiftMap(char map[][18]) {
 int left=0,down=0;
 for(int col=1; col<=15; col++){
   for(int row=10; row>=1; row--) {
    if(map[row][col]=='\0'){
     down++;
    } else {
     map[row+down][col-left]=map[row][col];
     if(down!=0||left!=0) map[row][col]='\0';
    }
   }
   if(down==10) left++;
   down=0;
 }
}

void printMap(char map[][18]) {

 for(int i=1; i<=MAXR; i++){
   for(int j=1; j<=MAXC; j++){
    if(map[i][j]=='\0') cout<<"O";
    else cout<<map[i][j];
   }
   cout<<endl;
 }
 return ;
}

void copyMap(char a[][18] , char b[][18]) { //a   to b
 for(int i=1; i<=MAXR+2; i++){
   for(int j=1; j<=MAXC+3; j++){
    b[i][j]=a[i][j];
   }
 }
}

int main(int argc, char *argv[])
{
     char map[13][18];
 char vis[13][18];
     int cas,num,tatol,remain;
 int max,temp,tempR,tempC;
     char tempCh;
     cin>>cas;
     for(int i=1; i<=cas; i++) {
     
         memset(map,'\0', sizeof(map));
  
         for(int j=1; j<=10; j++){
             cin>>&map[j][1];
         }
  
         #ifdef DEBUG
    cout<<" "<<endl;
          printMap(map);
          cout<<endl;
          cout<<map[1][1];
    cout<<":"<<floodfill(1,1,map,map[1][1]);
    cout<<endl;
    printMap(map);
    cout<<"-------------";
    cout<<endl;
    shiftMap(map);
    printMap(map);
         #endif
        
         cout<<"Game "<<i<<":"<<endl; 
   cout<<endl;

   num=0;
   tatol=0;
   while(1){
    max=0;
    num++;
    copyMap(map,vis);
    for(int col=1; col<=15; col++){
     for(int row=10; row>=1; row--){
      if(vis[row][col]=='\0') continue;
      temp=floodfill(row,col,vis,map[row][col]);
      if(temp>max) {
       max=temp;
       tempR=row;
       tempC=col;
       tempCh=map[row][col];
      }
     }
    }
   
    if(max==0){
     remain=0;
     for(int col=1; col<=15; col++){
      for(int row=10; row>=1; row--){
       if(map[row][col]!='\0') {
        remain++;
       } else {
        break;
       }
      }
     }
    
     if(remain==0) tatol+=1000;
    
     cout<<"Final score: "<<tatol<<", with "<<remain<<" balls remaining."<<endl; 

     //Final score: 3661, with 1 balls remaining. 
     cout<<endl;
     break;
    } else {
     floodfill(tempR,tempC,map,map[tempR][tempC]);
     shiftMap(map);
     tatol+=(max-2)*(max-2);
     cout<<"Move "<<num<<" at ("<<11-tempR<<","<<tempC<<"): removed "<<max<<" balls of color "<<tempCh<<", got "<<(max-2)*(max-2)<<" points."<<endl; 
     //Move 1 at (4,1): removed 32 balls of color B, got 900 points. 

    }
   
   } 
 
 }    
  
   system("PAUSE"); 
   return 0;
}

/*
10
RGGBBGGRBRRGGBG 
RBGRBGRBGRBGRBG
RRRRGBBBRGGRBBB
GGRGBGGBRRGGGBG
GBGGRRRRRBGGRRR
BBBBBBBBBBBBBBB
BBBBBBBBBBBBBBB
RRRRRRRRRRRRRRR
RRRRRRGGGGRRRRR
GGGGGGGGGGGGGGG

RRRRRRRRRRRRRRR
RRRRRRRRRRRRRRR
GGGGGGGGGGGGGGG
GGGGGGGGGGGGGGG
BBBBBBBBBBBBBBB
BBBBBBBBBBBBBBB
RRRRRRRRRRRRRRR
RRRRRRRRRRRRRRR 
GGGGGGGGGGGGGGG
GGGGGGGGGGGGGGG

RBGRBGRBGRBGRBG
BGRBGRBGRBGRBGR
GRBGRBGRBGRBGRB
RBGRBGRBGRBGRBG
BGRBGRBGRBGRBGR
GRBGRBGRBGRBGRB
RBGRBGRBGRBGRBG
BGRBGRBGRBGRBGR
GRBGRBGRBGRBGRB
RBGRBGRBGRBGRBG


RGRGGGGBBRRRRRR
RBBRRRRRRRRRRBR
RBBRBBBRBRRBRBR
RBBRBBBRBRBBRRR
RBRRBRRRBRBBRRR
RBRRRRBBBRBBRRR
RBRRRRBBBTRBRRR
RBRRRBBBBGBRBRR
RBRBRRRBBBBBRRR
RRRBBRBBBBBBBRR

 

*/

/*

RGRGGGGBBRRRRRR
RBBRRRRRRRRRRBR
RBBRBBBRBRRBRBR
RBBRBBBRBRBBRRR
RBRRBRRRBRBBRRR
RBRRRRBBBRBBRRR
RBRRRRBBBTRBRRR
RBRRRBBBBGBRBRR
RBRBRRRBBBBBRRR
RRRBBRBBBBBBBRR

 

*/