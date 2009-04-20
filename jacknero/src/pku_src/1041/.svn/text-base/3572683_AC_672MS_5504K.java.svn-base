import java.util.*;
public class Main {
    static final int NMAX = 1995; // 辺数の最大値
    static final int MMAX = 45; //　頂点数の最大値
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int ix, iy, iz;
        while(true){
            ix = sc.nextInt();
            iy = sc.nextInt();
            if(ix==0&&iy==0) break;
            int x[] = new int[NMAX];
            int y[] = new int[NMAX];
            int z[] = new int[NMAX];
            int n = 0;
            while(true){
                if(ix==0&&iy==0) break;
                iz = sc.nextInt();
                x[n] = ix;
                y[n] = iy;
                z[n] = iz;
                n++;
                ix = sc.nextInt();
                iy = sc.nextInt();
            }
            int start = Math.min(x[0], y[0]);
            for(int i=n-1;i>=0;i--){
                for(int j=1;j<=i;j++){
                    if(z[j-1]>z[j]){
                        int tx = x[j];
                        int ty = y[j];
                        int tz = z[j];
                        x[j] = x[j-1];
                        y[j] = y[j-1];
                        z[j] = z[j-1];
                        x[j-1] = tx;
                        y[j-1] = ty;
                        z[j-1] = tz;
                    }
                }
            }
            
            //for(int i=0;i<n;i++) System.out.println("z:"+z[i]);
            
            int d[] = new int[MMAX];
            for(int i=0;i<MMAX;i++) d[i] = 0;
            
            for(int i=0;i<n;i++){
                d[x[i]] ++;
                d[y[i]] ++;
            }
            
            boolean impossible = false;
            for(int i=0;i<MMAX;i++){
                if(d[i]%2!=0) impossible = true;
            }
            if(impossible){
                System.out.println("Round trip does not exist.");
            }
            else{
                LinkedList<Integer> ret = new LinkedList<Integer>();
                boolean used[] = new boolean[n];
                for(int i=0;i<n;i++) used[i] = false;
                ret = euler(x, y, n, used, start);

                for(int i:ret) System.out.print(z[i]+" ");
                System.out.println();
            }
            
        }
    }
    static LinkedList<Integer> euler(int x[], int y[], int n, boolean used[], int s){
        LinkedList<Integer> path_edge = new LinkedList<Integer>();
        LinkedList<Integer> path_node = new LinkedList<Integer>();
        path_node.add(s);
        int now = s;
        while(true){
            int next = -1;
            int next_edge = -1;
            for(int i=0;i<n;i++){
                if(used[i]) continue;
                if(x[i]==now){
                    next_edge = i;
                    next = y[i];
                    used[i] = true;
                    break;
                }
                else if(y[i]==now){
                    next_edge = i;
                    next = x[i];
                    used[i] = true;
                    break;
                }
            }
            if(next==-1) break;
            else{
                path_edge.add(next_edge);
                path_node.add(next);
                now = next;
            }
        }
        
        ListIterator<Integer> iter_edge = path_edge.listIterator(path_edge.size());
        ListIterator<Integer> iter_node = path_node.listIterator(path_node.size());
        while(iter_edge.hasPrevious()){
            int v = iter_node.previous();
            LinkedList<Integer> subpath = euler(x, y, n, used, v);
            for(int i:subpath){ iter_edge.add(i); }
            int sublen = subpath.size();
            for(int i=0;i<sublen;i++) iter_edge.previous();
            iter_edge.previous();
        }
        
        return path_edge;
    }
}