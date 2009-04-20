import java.util.Scanner;
   
   public class Main {
     static Scanner sc;
     static final int[] dx = {1, -1, 0, 0};
     static final int[] dy = {0, 0, 1, -1};
     
     int cnt;
     int w, h;
     char[][] field = new char[21][21];
     
     void find(int x, int y) {
       cnt++;
       field[y][x] = '#';
       for(int i=0; i<4; i++){
         int nx = x + dx[i];
         int ny = y + dy[i];
         if(nx < 0 || w <= nx) continue;
         if(ny < 0 || h <= ny) continue;      
         if(field[ny][nx] == '#') continue;
         find(nx, ny);
       }
     }
     
     Main(){
       while(true){
         cnt = 0;
         w = sc.nextInt();
         h = sc.nextInt();
         if(w == 0) break;
         
         int sy=0, sx=0;
         for(int y=0; y<h; y++){
           field[y] = sc.next().toCharArray();
           for(int x=0; x<field[y].length; x++){
             if (field[y][x] == '@'){
               sx = x;
               sy = y;
             } 
           }
         }
         find(sx, sy);
         System.out.println(cnt);
       }
     }
     
     public static void main(String[] args) {
       sc = new Scanner(System.in);
       new Main();
     }
   }