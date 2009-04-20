import java.util.*;
public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        while(true){
            int w = sc.nextInt();
            int h = sc.nextInt();
            if(w==0&&h==0) break;
            
            char[][] floor = new char[h][w];
            for(int i=0;i<h;i++){
                String s = sc.next();
                for(int j=0;j<w;j++){
                    floor[i][j] = s.charAt(j);
                }
            }
            
            Solver sol = new Solver(w, h, floor);
            System.out.println(sol.solve());
        }
    }

}

class Solver{
    int w;
    int h;
    char[][] floor;
    int size; // 1 + num of dirty tile
    Point loc[];
    int[][] dist;
    int max;
    public Solver(int w, int h, char[][] floor) {
        this.w = w;
        this.h = h;
        this.floor = floor;
        
        // initialize information of robot and dirty tiles
        size = 1;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(floor[i][j]=='*'){
                    size++;
                }
            }
        }
        
        int cnt = 1;
        loc = new Point[size];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(floor[i][j]=='o') loc[0] = new Point(i,j);
                if(floor[i][j]=='*'){
                    loc[cnt] = new Point(i,j);
                    cnt++;
                }
            }
        }
        
        // initialize distance table
        initDist();
        
        max = Integer.MAX_VALUE;
    }
    private void initDist() {
        dist = new int[size][size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                char[][] f = new char[h][w];
                for(int y=0;y<h;y++){
                    for(int x=0;x<w;x++){
                        f[y][x] = floor[y][x];
                    }
                }
                int sx = loc[i].x;
                int sy = loc[i].y;
                int ex = loc[j].x;
                int ey = loc[j].y;
                
                f[sx][sy] = '!';
                int d = 0;
                while(true){
                    if(f[ex][ey]=='!') break;
                    
                    boolean end = true;
                    for(int y=0;y<h;y++){
                        for(int x=0;x<w;x++){
                            if(f[y][x]!='x'&&f[y][x]!='!'){
                                if(y>0  &&f[y-1][x]=='!'){ f[y][x] = '?'; end = false;}
                                if(y<h-1&&f[y+1][x]=='!'){ f[y][x] = '?'; end = false;}
                                if(x>0  &&f[y][x-1]=='!'){ f[y][x] = '?'; end = false;}
                                if(x<w-1&&f[y][x+1]=='!'){ f[y][x] = '?'; end = false;}
                            }
                        }
                    }
                    if(end){
                        d = -1;
                        break;
                    }
                    else{
                        for(int y=0;y<h;y++){
                            for(int x=0;x<w;x++){
                                if(f[y][x]=='?') f[y][x] = '!';
                            }
                        }
                        d++;
                    }
                }
                
                dist[i][j] = d;
                // System.out.print(dist[i][j]+" ");
            }
            // System.out.println();
        }
    }
    public int solve(){
        boolean[] searched = new boolean[size];
        Arrays.fill(searched, false);
        searched[0] = true;
        int ret = search(0, 0, 1, searched);
        if(ret==Integer.MAX_VALUE) ret = -1;
        return ret;
    }
    private int search(int loc, int len, int snum, boolean[] searched){
        if(snum==size){
            max = Math.min(max, len);
            return len;
        }
        else{
            if(len>=max) return max;
            
            int ret = Integer.MAX_VALUE;
            for(int i=0;i<size;i++){
                if(!searched[i]&&dist[loc][i]>=0){
                    searched[i] = true;
                    ret = Math.min(ret, search(i, len + dist[loc][i], snum + 1, searched));
                    searched[i] = false;
                }
            }
            return ret;
        }
    }
}

class Point{
    int x;
    int y;
    public Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}