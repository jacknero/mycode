/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  CURSOR>patimon
 *
 *        Version:  1.0
 *        Created:  2010年01月23日 23時20分41秒
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  jacknero (), jack_nero2000@yahoo.co.jp
 *        Company:  
 *
 * =====================================================================================
 */


#include<cstdio>
#include<iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++ )
#define MAX 1000
#define INFTY (1<<21)
struct Point{ int x, y; };
int H, W, sy, sx, gy, gx, cnt[5];
Point P[5][MAX];
int D[5][MAX];

inline int mdist(int x1, int y1, int x2, int y2){
  return max(x1, x2) - min(x1, x2) + max(y1, y2) - min(y1, y2);
}

void compute(){
  int opts, optc = INFTY;
  int t;
  rep(s, 5){
    rep(i, 5) rep(j, cnt[i]) D[i][j] = INFTY;
    t = (s+1)%5;
    rep(j, cnt[t]) D[t][j] = mdist(sx, sy, P[t][j].x, P[t][j].y );
    for ( int i = s+1; i < s + 5; i++ ){
      int b = (i)%5;
      int e = (i+1)%5;
      rep(k, cnt[b]) rep(l, cnt[e]) {
        D[e][l] = min(D[e][l], D[b][k] + mdist(P[b][k].x, P[b][k].y, P[e][l].x, P[e][l].y));
      }
    }
    t = (s+4)%5;
    rep(j, cnt[t] ){
      if ( D[t][j] + mdist(gx, gy, P[t][j].x, P[t][j].y ) < optc ){
        optc = D[t][j] + mdist(gx, gy, P[t][j].x, P[t][j].y);
        opts = s;
      }
    }
  }
  if ( optc == INFTY ) cout << "NA" << endl;
  else cout << opts+1 << " " << optc << endl;
}

main(){
  char ch;
  while(cin >> W >> H && W){
    rep(i, 5) cnt[i] = 0;
    rep(y, H) rep(x, W) {
      cin >> ch;
      if ( ch == '.' ) continue;
      if ( ch == 'S' ){
        sy = y; sx = x;
      } else if ( ch == 'G' ){
        gy = y; gx = x;
      } else {
        int p = ch -'0' - 1;
        P[p][cnt[p]].x = x;
        P[p][cnt[p]++].y = y;
      }
    }
    compute();
  }
}
