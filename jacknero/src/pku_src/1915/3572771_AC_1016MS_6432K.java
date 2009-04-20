import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int size = sc.nextInt();
            int sx = sc.nextInt();
            int sy = sc.nextInt();
            int ex = sc.nextInt();
            int ey = sc.nextInt();
            Solver sol = new Solver(size,sx,sy,ex,ey);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int size;
    int startx;
    int starty;
    int endx;
    int endy;
    Solver(int s,int x1,int y1,int x2,int y2){
        size = s;
        startx = x1;
        starty = y1;
        endx = x2;
        endy = y2;
    }
    public int solve(){
        Queue<Point> q = new LinkedList<Point>();
        boolean table[][] = new boolean[size][size];
        for(int i=0;i<size;i++)
            for(int j=0;j<size;j++) table[i][j] = true;
        q.offer(new Point(startx,starty,(int)0));
        table[startx][starty] = false;
        while(true){
            Point p = q.poll();
            if(p.x==endx&&p.y==endy){
                return p.turn;
            }
            Point newpoints[] = new Point[8];
            newpoints[0] = new Point(p.x+1,p.y+2,p.turn+1);
            newpoints[1] = new Point(p.x+2,p.y+1,p.turn+1);
            newpoints[2] = new Point(p.x-1,p.y+2,p.turn+1);
            newpoints[3] = new Point(p.x-2,p.y+1,p.turn+1);
            newpoints[4] = new Point(p.x-1,p.y-2,p.turn+1);
            newpoints[5] = new Point(p.x-2,p.y-1,p.turn+1);
            newpoints[6] = new Point(p.x+1,p.y-2,p.turn+1);
            newpoints[7] = new Point(p.x+2,p.y-1,p.turn+1);
            for(int i=0;i<8;i++){
                if(newpoints[i].check(size)&&table[newpoints[i].x][newpoints[i].y]){
                    q.offer(newpoints[i]);
                    table[newpoints[i].x][newpoints[i].y]=false;
                }
            }
        }
    }
}

class Point{
    int x;
    int y;
    int turn;
    Point(int ix,int iy,int t){
        x = ix;
        y = iy;
        turn = t;
    }
    public boolean check(int size){
        if(0<=x&&x<size&&0<=y&&y<size) return true;
        else return false;
    }
}