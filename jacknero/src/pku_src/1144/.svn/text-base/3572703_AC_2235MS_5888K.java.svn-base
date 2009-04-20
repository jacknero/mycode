import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = (new Scanner(sc.nextLine())).nextInt();
            if(n==0) break;
            boolean a[][] = new boolean[n][n];
            for(int i=0;i<n;i++) Arrays.fill(a[i], false);
            while(true){
                Scanner scline = new Scanner(sc.nextLine());
                int u = scline.nextInt()-1;
                if(u==-1) break;
                while(scline.hasNext()){
                    int v = scline.nextInt()-1;
                    a[u][v] = true;
                    a[v][u] = true;
                }
            }
            Solver sol = new Solver(n, a);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int n;
    boolean a[][];

    int dfcnt;
    boolean[] searched;
    int[] dfnumber;
    int[] low;
    int[] prev;
    public Solver(int n, boolean[][] a) {
        this.n = n;
        this.a = a;
        dfcnt = 0;
        searched = new boolean[n];
        Arrays.fill(searched, false);
        dfnumber = new int[n];
        low = new int[n];
        prev = new int[n];
    }
    private void dfs(){
        prev[0] = -1;
        dfs(0);
    }
    private void dfs(int u){
        searched[u] = true;
        dfnumber[u] = dfcnt;
        dfcnt++;
        low[u] = dfnumber[u];
        for(int i=0;i<n;i++){
            if(u==i) continue;
            if(a[u][i]&&searched[i]){
                low[u] = Math.min(dfnumber[i], low[u]);
            }
        }
        for(int i=0;i<n;i++){
            if(u==i) continue;
            if(a[u][i]&&!searched[i]){
                prev[i] = u;
                dfs(i);
                low[u] = Math.min(low[i], low[u]);
            }
        }
    }
    public int solve(){
        dfs();
        
        int cnt = 0;
        // root
        int rootdeg = 0;
        for(int i=0;i<n;i++){
            if(prev[i]==0){
                rootdeg++;
            }
        }
        if(rootdeg>=2) cnt++;
        
        // except root
        for(int i=1;i<n;i++){
            boolean flag = false;
            for(int j=0;j<n;j++){
                if(prev[j]==i){
                    if(low[j]>=dfnumber[i]){
                        flag = true;
                        break;
                    }
                }
            }
            if(flag) cnt++;
        }
        return cnt;
    }
}