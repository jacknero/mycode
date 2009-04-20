import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int p = sc.nextInt();
            int a = sc.nextInt()-1;
            int b = sc.nextInt()-1;
            if(n==0 && m==0 && p==0) break;
            int[] t = new int[n];
            for(int i=0;i<n;i++) t[i] = sc.nextInt();
            double[][] path = new double[m][m];
            for(int i=0;i<m;i++) Arrays.fill(path[i], Double.MAX_VALUE);
            for(int i=0;i<p;i++){
                int x = sc.nextInt()-1;
                int y = sc.nextInt()-1;
                double z = sc.nextDouble();
                path[x][y] = z;
                path[y][x] = z;
            }
            
            Solver sol = new Solver(n, m, a, b, t, path);
            double ans = sol.solve();
            if(ans==Double.MAX_VALUE) System.out.println("Impossible");
            else System.out.printf("%.3f\r\n", sol.solve());
        }
    }
}

class Solver{
    int n;
    int m;
    int a;
    int b;
    int[] t;
    double[][] path;
    public Solver(int n, int m, int a, int b, int[] t, double[][] path) {
        this.n = n;
        this.m = m;
        this.a = a;
        this.b = b;
        this.t = t;
        this.path = path;
    }
    public double solve(){        
        boolean searched[][] = new boolean[m][1<<n];
        double x[][] = new double[m][1<<n];
        
        for(int i=0;i<m;i++) Arrays.fill(searched[i], false);
        for(int i=0;i<m;i++) Arrays.fill(x[i], Double.MAX_VALUE);
        x[a][(1<<n)-1] = 0;
        
        PriorityQueue<State> q = new PriorityQueue<State>();
        q.add(new State(a, (1<<n)-1, 0.0));
        while(!q.isEmpty()){
            State s = q.poll();
            if(searched[s.city][s.ticketcode]) continue;
            searched[s.city][s.ticketcode] = true;
            
            // end
            if(s.city==b){
                return s.x;
            }
            
            // next
            TICKET: for(int i=0;i<n;i++){
                if(!hasTicket(s.ticketcode, i)) continue TICKET;
                int newcode = useTicket(s.ticketcode, i);
                CITY: for(int j=0;j<m;j++){
                    if(path[s.city][j]==Double.MAX_VALUE) continue CITY;
                    if(searched[j][newcode]) continue CITY;

                    if(s.x + path[s.city][j]/t[i] < x[j][newcode]){
                        x[j][newcode] = s.x + path[s.city][j]/t[i];
                        q.add(new State(j, newcode, x[j][newcode]));                        
                    }
                }
            }
        }
        return Double.MAX_VALUE;
    }
    private static boolean hasTicket(int ticketcode, int i){
        return (ticketcode>>i)%2==1;
    }
    private int useTicket(int ticketcode, int i){
        return ticketcode - (1<<i);
    }
}

class State implements Comparable<State>{
    int city;
    int ticketcode;
    double x;
    public State(int city, int ticketcode, double x) {
        this.city = city;
        this.ticketcode = ticketcode;
        this.x = x;
    }
    public int compareTo(State s){
        if(x>s.x) return 1;
        else if(x<s.x) return -1;
        else return 0;
    }
}