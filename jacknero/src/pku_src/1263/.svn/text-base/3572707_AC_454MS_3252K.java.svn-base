import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            cnt++;
            Circle[] cs = new Circle[n];
            for(int i=0;i<n;i++) cs[i] = new Circle(sc.nextDouble(), sc.nextDouble(), sc.nextDouble());
            double x = sc.nextDouble();
            double y = sc.nextDouble();
            double dx = sc.nextDouble();
            double dy = sc.nextDouble();
            
            Solver sol = new Solver(n, cs, x, y, dx, dy);
            
            System.out.println("Scene "+cnt);
            for(int i=0;i<11;i++){
                int k = sol.step();
                if(i==10){
                    if(k!=-1) System.out.println("...");
                    else System.out.println("inf");
                }
                else{
                    if(k!=-1) System.out.print((k+1) + " ");
                    else{
                        System.out.println("inf");
                        break;
                    }                
                }
            }
            System.out.println();
        }
    }
}

class Solver{
    int n;
    Circle[] cs;
    double x;
    double y;
    double dx;
    double dy;
    static final double EPSILON = 1.0e-8;
    public Solver(int n, Circle[] cs, double x, double y, double dx, double dy) {
        // TODO Auto-generated constructor stub
        this.n = n;
        this.cs = cs;
        this.x = x;
        this.y = y;
        this.dx = dx;
        this.dy = dy;
        normalizeDirvec();
    }
    private void normalizeDirvec(){
        double a = Math.sqrt(dx*dx + dy*dy);
        dx = dx/a;
        dy = dy/a;
    }
    public int step(){
        int k = -1;
        double t = Double.MAX_VALUE;
        for(int i=0;i<n;i++){
            double cx = cs[i].x;
            double cy = cs[i].y;
            double r = cs[i].r;
            double d2 = // d2 = D/4 D:判別式
                ((x-cx)*dx+(y-cy)*dy)*((x-cx)*dx+(y-cy)*dy) -
                    ((x-cx)*(x-cx)+(y-cy)*(y-cy)-r*r);
            if(d2>0){
                double s = -((x-cx)*dx+(y-cy)*dy) - Math.sqrt(d2);
                if(s>-EPSILON&&s<t){
                    if(s<0) s = 0;
                    t = s;
                    k = i;
                }
            }
        }
        
        if(k==-1) return -1;
        
        // x, y, dx, dy の更新
        x += t * dx;
        y += t * dy;
        
        double ux = (cs[k].x-x)/cs[k].r;
        double uy = (cs[k].y-y)/cs[k].r;
        double dx2 = dx + -2*(dx*ux+dy*uy)*ux;
        double dy2 = dy + -2*(dx*ux+dy*uy)*uy;
        dx = dx2;
        dy = dy2;
        normalizeDirvec();
        return k;
    }
}

class Circle{
    double x;
    double y;
    double r;
    public Circle(double x, double y, double r) {
        // TODO Auto-generated constructor stub
        this.x = x;
        this.y = y;
        this.r = r;
    }
}