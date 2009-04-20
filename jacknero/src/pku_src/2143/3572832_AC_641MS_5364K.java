import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int p = sc.nextInt();
            if(n==0&&m==0&&p==0) break;
            Point[] input = new Point[p];
            for(int i=0;i<p;i++){
                input[i] = new Point(sc.nextInt()-1,sc.nextInt()-1);
            }
            Solver sol = new Solver(n,m,input);
            sol.printSolution();
        }
    }
} 
class Solver{
    int n;
    int m;
    Point[] input;
    int[][][] table;
    int turn;
    
    Solver(int n,int m,Point[] input){
        this.n = n;
        this.m = m;
        this.input = input;
        this.table = new int[n][n][n];
        for(int x=0;x<n;x++){
            for(int y=0;y<n;y++){
                for(int z=0;z<n;z++){
                    this.table[x][y][z] = -1;
                }
            }
        }
        this.turn = 0;
    }
    public void printSolution(){
        while(turn<input.length){
            boolean end = executeTurn();
            if(end){
                if(turn%2==0){
                    System.out.println("Black "+(turn+1));
                    return;
                }
                else{
                    System.out.println("White "+(turn+1));
                    return;
                }
            }
            turn++;
        }
        System.out.println("Draw");
    }
    private boolean executeTurn(){
        Point p = input[turn];
        int z = 0;
        while(table[p.x][p.y][z]!=-1) z++;
        table[p.x][p.y][z] = turn%2;
        return isEnd(p.x,p.y,z);
    }
    private boolean isEnd(int x,int y,int z){
        for(int i=0;i<13;i++){
            if(directionalTest(x,y,z,i)) return true;
        }
        return false;
    }
    private boolean directionalTest(int x,int y,int z,int dir){
        int dx,dy,dz;
        switch(dir){
        case 0:
            dx = 1; dy = 0; dz = 0; break;
        case 1:
            dx = 0; dy = 1; dz = 0; break;
        case 2:
            dx = 0; dy = 0; dz = 1; break;
        case 3:
            dx = 1; dy = 1; dz = 0; break;
        case 4:
            dx = 1; dy = -1; dz = 0; break;
        case 5:
            dx = 0; dy = 1; dz = 1; break;
        case 6:
            dx = 0; dy = 1; dz = -1; break;
        case 7:
            dx = 1; dy = 0; dz = 1; break;
        case 8:
            dx = -1; dy = 0; dz = 1; break;
        case 9:
            dx = 1; dy = 1; dz = 1; break;
        case 10:
            dx = 1; dy = -1; dz = 1; break;
        case 11:
            dx = 1; dy = 1; dz = -1; break;
        default:
            dx = 1; dy = -1; dz = -1; break;
        }
        int cnt = 1;
        int col = turn%2;
        int px,py,pz;
        px = x+dx; py = y+dy; pz = z+dz;
        while(0<=px&&px<n&&0<=py&&py<n&&0<=pz&&pz<n){
            if(table[px][py][pz]==col){
                cnt++;
                px += dx;
                py += dy;
                pz += dz;
            }
            else break;
        }
        px = x-dx; py = y-dy; pz = z-dz;
        while(0<=px&&px<n&&0<=py&&py<n&&0<=pz&&pz<n){
            if(table[px][py][pz]==col){
                cnt++;
                px -= dx;
                py -= dy;
                pz -= dz;
            }
            else break;
        }
        if(cnt>=m) return true;
        else return false;
    }
} 
class Point{
    int x;
    int y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}