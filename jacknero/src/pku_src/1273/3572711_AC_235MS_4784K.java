import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int[][] network = new int[m][m];
            for(int i=0;i<m;i++) Arrays.fill(network[i], 0);
            
            for(int i=0;i<n;i++){
                int s = sc.nextInt() - 1;
                int e = sc.nextInt() - 1;
                int c = sc.nextInt();
                network[s][e] += c;
            }
            
            Solver sol = new Solver(m, 0, m-1, network);
            System.out.println(sol.solve());    
        }
    }
}

class Solver{
    int size;//number of nodes
    int source;//nodeID of source
    int sink;//nodeID of sink
    int[][] network;
    Solver(int n,int s,int t,int[][] net){
        size = n;
        source = s;
        sink = t;
        network = net;
    }
    public int solve(){
        List<Integer> path;
        int flow = 0;
        while(true){
            path = searchPath();
            if(path==null) break;
            
            //calculate how much flow increases
            int flowinc = Integer.MAX_VALUE;
            
            int prev = source;
            for(int v:path){
                flowinc = Math.min(flowinc,network[prev][v]);
                prev = v;
            }
            
            //flow increases
            flow += flowinc;
            
            //update network array
            prev = source;
            for(int v:path){
                network[prev][v] -= flowinc;
                network[v][prev] += flowinc;
                prev = v;
            }
        }
        
        return flow;
    }
    
    //search shortest path from source to sink by BFS
    private List<Integer> searchPath(){
        int[] prev = new int[size];
        Arrays.fill(prev, -1);
        
        Queue<Integer> q = new LinkedList<Integer>();
        q.offer(source);
        
        L : while(!q.isEmpty()){
            int u = q.poll();
            for(int i=0;i<size;i++){
                if(prev[i]==-1&&network[u][i]>0){
                    prev[i] = u;
                    
                    //discoverd path to sink
                    if(i==sink) break L;
                    
                    q.offer(i);
                }
            }
        }
        
        if(prev[sink]==-1) return null;
        else return getPath(prev);
    }
    
    //get path to sink from pred node array
    private List<Integer> getPath(int[] prev){
        LinkedList<Integer> path = new LinkedList<Integer>();
        int u = sink;
        while(u!=source){
            path.addFirst(u);
            u = prev[u];
        }
        return path;
    }
}