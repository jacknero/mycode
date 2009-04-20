import java.util.*;

public class Main {
    static final double EPS = 1.0E-6;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            Point[] ps = new Point[2*n];
            for(int i=0;i<n;i++){
                double x = sc.nextDouble();
                double y = sc.nextDouble();
                ps[2*i] = new Point(x, y);
                ps[2*i+1] = new Point(x, y-1.0);
            }
            
            double ans = - Double.MAX_VALUE;
            for(int i=0;i<2*n;i++){
                for(int j=i+1;j<2*n;j++){
                    Point p1 = ps[i];
                    Point p2 = ps[j];
                    if(p1.x==p2.x) continue;
                    
                    double a = (p2.y-p1.y) / (p2.x-p1.x);
                    double b = - a * p1.x + p1.y;
                    
                    double y0 = a * ps[0].x + b;

                    // initial point check
                    if(y0>ps[0].y + EPS || ps[1].y-EPS>y0) continue;
                    
                    double impactx = Double.MAX_VALUE;
                    
                    for(int k=1;k<n;k++){
                        double xnow = ps[2*k].x;
                        double ynow = a * xnow + b;
                        double xprev = ps[2*k-2].x;
                        double yprev = a * xprev + b;
                        double ynowsup = ps[2*k].y;
                        double ynowinf = ps[2*k+1].y;
                        double yprevsup = ps[2*k-2].y;
                        double yprevinf = ps[2*k-1].y;
                        if(ynow <= ynowsup + EPS && ynow >= ynowinf - EPS) continue;
                        else if(ynow > ynowsup + EPS){
                            impactx = xprev + (xnow-xprev)*(yprevsup - yprev)/((yprevsup - yprev)+(ynow - ynowsup));
                            break;
                        }
                        else{
                            impactx = xprev + (xnow-xprev)*(yprev - yprevinf)/((yprev - yprevinf)+(ynowinf - ynow));
                            break;
                        }
                    }
                    ans = Math.max(impactx, ans);
                    
                    //System.out.printf("i:%d j:%d min:%f\r\n", i, j, ans);
                }
            }
            
            if(ans==Double.MAX_VALUE){
                System.out.println("Through all the pipe.");
            }
            else{
                System.out.printf("%.2f\r\n", ans);
            }
        }
    }
}

class Point{
    double x;
    double y;
    public Point(double x, double y) {
        // TODO Auto-generated constructor stub
        this.x = x;
        this.y = y;
    }
}