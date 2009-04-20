import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int c=0;c<n;c++){
            double x = sc.nextDouble();
            int k = sc.nextInt();
            double f[] = new double[k];
            for(int i=0;i<k;i++){
                f[i] = sc.nextDouble();
            }
            
            Solver sol = new Solver(x, k, f);
            if(sol.solve()){
                System.out.println("Nils");
            }
            else{
                System.out.println("Mikael");
            }
        }
    }
}

class Solver{
    double x;
    int k;
    double[] f;
    static final double EPSILON = 1.0E-9;
    public Solver(double x, int k, double[] f) {
        // TODO Auto-generated constructor stub
        this.x = x;
        this.k = k;
        this.f = f;
        Arrays.sort(this.f);
    }
    public boolean solve(){
        TreeSet<Double> ts = new TreeSet<Double>();
        HashMap<Double, Boolean> hm = new HashMap<Double, Boolean>();
        PriorityQueue<Double> q = new PriorityQueue<Double>();
        
        // zero check
        for(int i=0;i<k;i++){
            if(f[i]==0.0) return true;
        }
        
        // Initialize
        // 1st step
        ts.add(1.0);
        hm.put(1.0, true);
        
        // 2nd step
        ts.add(1.0/f[0]);
        hm.put(1.0/f[0], false);
        if(x<1.0/f[0]) return true;
        
        for(int i=0;i<k;i++){
            q.offer(1.0/(f[0]*f[i]));
        }
        if(k==1) q.offer(1.0/(f[0]*f[0]*f[0]));
            
        boolean lastflag = false;
        while(true){
            double now = q.poll();
            //System.out.println("now:"+now);
            if(now>x) break;
            
            double next;
            if(q.size()>=1) next = q.peek();
            else next = now / f[k-1];
            
            if(next-now < EPSILON) continue;
            
            double test = (now + next) * 0.5;
            if(lastflag){
                boolean flag = true;
                for(int i=0;i<k;i++){
                    SortedSet<Double> ss = ts.headSet(test*f[i]);
                    if(!hm.get(ss.last())){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    ts.add(now);
                    hm.put(now, false);
                    for(int i=0;i<k;i++){
                        double y = now/f[i];
                        q.offer(y);
                    }
                    lastflag = false;
                }
            }
            else{
                boolean flag = false;
                for(int i=0;i<k;i++){
                    SortedSet<Double> ss = ts.headSet(test*f[i]);
                    if(!hm.get(ss.last())){
                        flag = true;
                        break;
                    }
                }
                
                if(flag){
                    ts.add(now);
                    hm.put(now, true);
                    for(int i=0;i<k;i++){
                        double y = now/f[i];
                        q.offer(y);
                    }
                    lastflag = true;
                }
            }
        }
        //System.out.println("tmsize:"+tm.size());
        return lastflag;
    }
}