import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        sc.useDelimiter("\\D+");
        while(sc.hasNext()){
            int num_nodes = sc.nextInt();
            int num_powers = sc.nextInt();
            int num_consumers = sc.nextInt();
            int num_edges = sc.nextInt();
            int[][] network = new int[num_nodes+2][num_nodes+2];
            int source = num_nodes;
            int sink = num_nodes+1;
            for(int i=0;i<num_nodes+2;i++) Arrays.fill(network[i],0);
            for(int i=0;i<num_edges;i++){
                int u = sc.nextInt();
                int v = sc.nextInt();
                network[u][v] = sc.nextInt();
            }
            for(int i=0;i<num_powers;i++){
                int u = sc.nextInt();
                network[source][u] = sc.nextInt();
            }
            for(int i=0;i<num_consumers;i++){
                int u = sc.nextInt();
                network[u][sink] = sc.nextInt();
            }
            Solver sol = new Solver(num_nodes+2,source,sink,network);
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
        int[] path;
        int flow = 0;
        while(true){
            path = searchPath();
            if(path==null) break;
            
            int pathlen = path.length-1;
            
            //calculate how much flow increases
            int flowinc = Integer.MAX_VALUE;
            for(int i=0;i<pathlen;i++){
                flowinc = Math.min(flowinc,network[path[i]][path[i+1]]);
            }
            
            //flow increases
            flow += flowinc;
            
            //update network array
            for(int i=0;i<pathlen;i++){
                network[path[i]][path[i+1]] -= flowinc;
                network[path[i+1]][path[i]] += flowinc;
            }
        }
        
        return flow;
    }
    
    //search shortest path from source to sink by BFS
    private int[] searchPath(){
        boolean[] discovered = new boolean[size];
        int[] pred = new int[size];
        Arrays.fill(discovered,false);
        
        LinkedList<Integer> l = new LinkedList<Integer>();
        l.addLast(source);
        pred[source] = -1;
        discovered[source] = true;
        
        while(!l.isEmpty()){
            int u = l.getFirst();
            for(int i=0;i<size;i++){
                if(!discovered[i]&&network[u][i]>0){
                    pred[i] = u;
                    discovered[i] = true;
                    l.addLast(i);
                    
                    //discoverd path to sink
                    if(i==sink){
                        return getPath(pred);
                    }               
                }
            }
            l.removeFirst();
        }
        
        //cannot find path
        return null;
    }
    
    //get path to sink from pred node array
    private int[] getPath(int[] pred){
        LinkedList<Integer> path = new LinkedList<Integer>();
        int u = sink;
        while(u!=-1){
            path.addFirst(u);
            u = pred[u];
        }
        int pathsize = path.size();
        Integer[] __ret = new Integer[pathsize];
        __ret = path.toArray(__ret);
        int[] ret = new int[pathsize];
        for(int i=0;i<ret.length;i++) ret[i] = __ret[i];
        return ret;
    }
}