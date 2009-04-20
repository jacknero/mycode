import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int h, w;
        while(true){
            h = sc.nextInt();
            w = sc.nextInt();
            if(h==0&&w==0) break;
            
            char[][] floor = new char[h][w];
            for(int i=0;i<h;i++){
                String s = sc.next();
                for(int j=0;j<w;j++) floor[i][j] = s.charAt(j);
            }
            
            int m = 0;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(floor[i][j]=='H') m++;
                }
            }
            
            int hx[] = new int[m];
            int hy[] = new int[m];
            int hc = 0;
            int mx[] = new int[m];
            int my[] = new int[m];
            int mc = 0;
            
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(floor[i][j]=='H'){
                        hy[hc] = i;
                        hx[hc] = j;
                        hc++;
                    }
                    if(floor[i][j]=='m'){
                        my[mc] = i;
                        mx[mc] = j;
                        mc++;
                    }
                }
            }
            
            int[][] dist = new int[m][m];
            for(int i=0;i<m;i++){
                for(int j=0;j<m;j++){
                    dist[i][j] = Math.abs(hx[i]-mx[j]) + Math.abs(hy[i]-my[j]);
                }
            }
            
            Solver sol = new Solver(m, dist);
            System.out.println(sol.solve());
        }
    }
}

class Solver {
    int n; //ノードの数
    int source; //ソース
    int sink; //シンク
    int[][] d; //距離行列
    int[][] c; //コスト行列
    int[][] a; //フローの上限
    int[][] f; //フロー
    int[] v; //始点からの距離
    int[] prev;
    int totalf; //トータルフロー
    int totalc; //トータルコスト
    public Solver(int m, int[][] dist) {
        n = 2*m+2;
        source = 2*m;
        sink = 2*m+1;
        d = new int[n][n];
        // init of d
        for(int i=0;i<n;i++) Arrays.fill(d[i], Integer.MAX_VALUE);
        for(int i=0;i<m;i++) d[source][i] = 0;
        for(int i=0;i<m;i++) d[m+i][sink] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                d[i][m+j] = dist[i][j];
            }
        }
        
        c = new int[n][n];
        // init of c
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) c[i][j] = d[i][j];
        }
        
        a = new int[n][n];
        // init of a
        for(int i=0;i<n;i++) Arrays.fill(a[i], 0);
        for(int i=0;i<m;i++) a[source][i] = 1;
        for(int i=0;i<m;i++) a[m+i][sink] = 1;
        for(int i=0;i<m;i++){
            for(int j=0;j<m;j++){
                a[i][m+j] = 1;
            }
        }
        
        f = new int[n][n];
        for(int i=0;i<n;i++) Arrays.fill(f[i],0);
        v = new int[n];
        Arrays.fill(v, Integer.MAX_VALUE);
        prev = new int[n];
        Arrays.fill(prev, -1);
        totalf = 0;
        totalc = 0;
    }
    public int solve(){
        while(true){
            boolean flag;
            flag = dijekstra();
            if(!flag) break;
            tracePath();
            calcCost();
        }
        return totalc;
    }
    public void tracePath(){
        int u = sink;
        int v = prev[u];
        while(v!=-1){
            if(a[v][u]==1&&f[v][u]==0){
                f[v][u] = 1;
                totalc += d[v][u];
            }
            else if(a[u][v]==1&&f[u][v]==1){
                f[u][v] = 0;
                totalc -= d[u][v];
            }
            else throw new RuntimeException();
            
            u = v;
            v = prev[u];
        }
        totalf += 1;
    }
    public void calcCost(){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]==1 && f[i][j]==0) c[i][j] = d[i][j] + v[i] - v[j];
                else if(a[j][i]==1 && f[j][i]==1) c[i][j] = - d[j][i] + v[i] - v[j];
                else c[i][j] = Integer.MAX_VALUE;
            }
        }
    }
    public boolean dijekstra(){
        boolean[] searched = new boolean[n];
        Arrays.fill(searched, false);
        Arrays.fill(v, Integer.MAX_VALUE);
        v[source] = 0;
        prev[source] = -1;
        
        int u = -1;
        int min = Integer.MAX_VALUE;
        while(true){
            min = Integer.MAX_VALUE;
            for(int i=0;i<n;i++){
                if(!searched[i]&&v[i]<min){
                    u = i;
                    min = v[i];
                }
            }
            
            if(min==Integer.MAX_VALUE) break;
            
            searched[u] = true;
            for(int i=0;i<n;i++){
                if(searched[i]==false && c[u][i] < Integer.MAX_VALUE && v[i]>v[u]+c[u][i]){
                    v[i] = v[u]+c[u][i];
                    prev[i] = u;
                }
            }
        }
        
        return searched[sink];
    }
}