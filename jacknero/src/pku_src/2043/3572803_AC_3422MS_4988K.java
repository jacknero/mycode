import java.util.*;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            //read input
            int n = sc.nextInt();
            if(n==0) break;
            int xmin = Integer.MAX_VALUE;
            int ymin = Integer.MAX_VALUE;
            int xmax = Integer.MIN_VALUE;
            int ymax = Integer.MIN_VALUE;
            Point[] p = new Point[n+1];
            for(int i=0;i<n;i++){
                int x = sc.nextInt();
                int y = sc.nextInt();
                if(x<xmin) xmin = x;
                if(x>xmax) xmax = x;
                if(y<ymin) ymin = y;
                if(y>ymax) ymax = y;
                p[i] = new Point(x,y);
            }
            p[n] = p[0];
            
            // standardize
            for(int i=0;i<n;i++){
                p[i].x -= xmin;
                p[i].y -= ymin;
            }
            xmax = xmax - xmin;
            ymax = ymax - ymin;
            
            //solve
            Solver sol = new Solver(n,p,xmax,ymax);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int n;
    Point[] p;
    int xmax;
    int ymax;
    final static double EPSILON = 1E-5;
    
    Solver(int n, Point[] p, int xmax, int ymax) {
        this.n = n;
        this.p = p;
        this.xmax = xmax;
        this.ymax = ymax;
    }
    public int solve(){
        int ret = 0;

        for(int y=0;y<ymax;y++){
            ArrayList<Double> intersect0 = new ArrayList<Double>();
            ArrayList<Double> intersect1 = new ArrayList<Double>();
            
            for(int i=0;i<n;i++){
                int y0 = p[i].y;
                int y1 = p[i+1].y;
                int x0 = p[i].x;
                int x1 = p[i+1].x;
                if(Math.min(y0,y1)<=y&&y+1<=Math.max(y0,y1)){
                    if(x0!=x1){
                        double lx0 = (x0*(y1-(y+EPSILON))+x1*((y+EPSILON)-y0))/(double)(y1-y0);
                        double lx1 = (x0*(y1-(y+1-EPSILON))+x1*((y+1-EPSILON)-y0))/(double)(y1-y0);
                        intersect0.add(lx0);
                        intersect1.add(lx1);
                    }
                    else/* x0==x1 */{
                        intersect0.add((double)x0);
                        intersect1.add((double)x0);
                    }
                }
            }
            
            double[] array0 = new double[intersect0.size()];
            double[] array1 = new double[intersect1.size()];
            for(int i=0;i<array0.length;i++) array0[i] = intersect0.get(i);
            for(int i=0;i<array0.length;i++) array1[i] = intersect1.get(i);
            Arrays.sort(array0);
            Arrays.sort(array1);
            
            boolean count[] = new boolean[xmax];
            for(int i=0;i<xmax;i++) count[i] = false;
            
            for(int i=0;i<array0.length;i+=2){
                int x0 = (int)Math.floor(Math.min(array0[i],array1[i]));
                int x1 = (int)Math.ceil(Math.max(array0[i+1],array1[i+1])) - 1;
                for(int x=x0;x<=x1;x++){
                    count[x] = true;
                }
            }
            
            for(int i=0;i<xmax;i++) if(count[i]) ret++;
        }
        return ret;
    }
}

class Point{
    int x;
    int y;
    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}