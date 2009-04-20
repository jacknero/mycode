import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int e = sc.nextInt();
        boolean[][] adj = new boolean[n][n];
        for(int i=0;i<n;i++) Arrays.fill(adj[i],false);
        while(sc.hasNext()){
            int p = sc.nextInt();
            int q = sc.nextInt();
            adj[p][q] = true;
        }
        Solver sol = new Solver(n,e,adj);
        System.out.printf("Put guards in room %d.\r\n",sol.solve());
    }
}

class Solver{
    int n;
    int e;
    boolean[][] adj;
    boolean[][] avail;
    Solver(int n, int e, boolean[][] adj) {
        this.n = n;
        this.e = e;
        this.adj = adj;
        this.avail = new boolean[n][n];
    }
    public int solve(){
        analyzeAvailable();
        return nearestPoint();
    }
    private int nearestPoint(){
        Queue<Integer> q = new LinkedList<Integer>();
        boolean[] searched = new boolean[n];
        q.offer(e);
        Arrays.fill(searched,false);
        searched[e] = true;
        while(!q.isEmpty()){
            int v = q.poll();
            if(avail[e][v]) return v;
            for(int i=0;i<n;i++){
                if(adj[i][v]&&!searched[i]){
                    q.offer(i);
                    searched[i] = true;
                }
            }
        }
        return -1;
    }
    private void analyzeAvailable(){
        for(int i=0;i<n;i++) Arrays.fill(avail[i],true);
        for(int k=1;k<n;k++) avail[0][k] = false;
        while(!analyzeAvailableSub());
        for(int i=0;i<n;i++) avail[i][i] = false;
    }
    private boolean analyzeAvailableSub(){
        boolean end = true;
        for(int i=1;i<n;i++){
            boolean[] availnext = new boolean[n];
            Arrays.fill(availnext,false);
            
            boolean first = true;
            for(int p=0;p<n;p++){
                if(adj[p][i]){
                    if(first){
                        for(int k=0;k<n;k++){
                            availnext[k] = avail[p][k];
                        }
                        first = false;
                    }
                    else{
                        for(int k=0;k<n;k++){
                            availnext[k] &= avail[p][k];
                        }
                    }
                }
            }
            availnext[i] = true;
            
            for(int k=0;k<n;k++){
                if(avail[i][k]!=availnext[k]) end = false;
                avail[i][k] = availnext[k];
            }
        }
        return end;
    }
}