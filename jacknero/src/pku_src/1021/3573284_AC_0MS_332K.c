#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int domark(char x, char y,char** board){
  if(x<0 || y<0) return 0;
  if(board[x][y]==0) return 0;
  board[x][y]=0;
  return 1 +
  domark(x-1,y,board)+
  domark(x+1,y,board)+
  domark(x,y-1,board)+
  domark(x,y+1,board);
}

int main(){
  int i,n,w,h,m,sx,sy;
  char *tx,*ty, **board;
  char **mk;

  mk=(char**)malloc(sizeof(char*)*2);
  scanf("%d", &n);
  while(n-->0){
    scanf("%d%d%d",&w,&h,&m);
    tx=(char*)malloc(sizeof(char)*m);
    ty=(char*)malloc(sizeof(char)*m);
    board=(char**)malloc(sizeof(char*)*(w+1));
    mk[0]=(char*)malloc(sizeof(char)*m);memset(mk[0],0,m);
    mk[1]=(char*)malloc(sizeof(char)*m);memset(mk[1],0,m);
    for(i=0;i<w+1;i++){
      board[i]=(char*)malloc(sizeof(char)*(h+1));
      memset(board[i],0,h+1);
    }
    for(i=0;i<m;i++){
      scanf("%d%d",&sx,&sy);
      tx[i]=sx;ty[i]=sy;
      board[sx][sy] = i+1;
    }   
    for(i=0;i<m;i++){
      sx = domark(tx[i],ty[i],board);
      if(sx!=0) mk[0][sx]++;
    }

    for(i=0;i<w+1;i++){
      memset(board[i],0,h+1);
    }

    for(i=0;i<m;i++){
      scanf("%d%d",&sx,&sy);
      tx[i]=sx;ty[i]=sy;
      board[sx][sy] = i+1;
    }   
    for(i=0;i<m;i++){
      sx = domark(tx[i],ty[i],board);
      if(sx!=0) mk[1][sx]++;
    }
    
    for(i=1;i<m;i++){
      if(mk[0][i]!=mk[1][i]){
	printf("NO\n");
	break;
      }
    }
    if(i==m)printf("YES\n");
    for(i=0;i<w+1;i++){
      free(board[i]);
    }

    free(board);

    free(tx);free(ty);

    free(mk[0]);free(mk[1]);
  }
  free(mk);
  return 0;  
}
