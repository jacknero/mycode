import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            double a[] = new double[n+2];
            double b[] = new double[n+2];
            double c[] = new double[n+2];
            double d[] = new double[n+2];
            a[0] = 0.0;
            a[n+1] = 1.0;
            b[0] = 0.0;
            b[n+1] = 1.0;
            c[0] = 0.0;
            c[n+1] = 1.0;
            d[0] = 0.0;
            d[n+1] = 1.0;
            for(int i=1;i<n+1;i++) a[i] = sc.nextDouble();
            for(int i=1;i<n+1;i++) b[i] = sc.nextDouble();
            for(int i=1;i<n+1;i++) c[i] = sc.nextDouble();
            for(int i=1;i<n+1;i++) d[i] = sc.nextDouble();
            Solver sol = new Solver(n,a,b,c,d);
            System.out.printf("%.6f\r\n",sol.solve());
        }
    }
}

class Solver{
    int n;
    double[] a;
    double[] b;
    double[] c;
    double[] d;
    Solver(int n, double[] a, double[] b, double[] c, double[] d) {
        this.n = n;
        this.a = a;
        this.b = b;
        this.c = c;
        this.d = d;
    }
    public double solve(){
        Line[] ablines = new Line[n+2];
        Line[] cdlines = new Line[n+2];
        for(int i=0;i<n+2;i++){
            ablines[i] = new Line(new Point(a[i],0.0),new Point(b[i],1.0));
            cdlines[i] = new Line(new Point(0.0,c[i]),new Point(1.0,d[i]));
        }
        Point[][] crosspoints = new Point[n+2][n+2];
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                crosspoints[i][j] = ablines[i].crossPoint(cdlines[j]);
            }
        }
        
        double max = Double.MIN_VALUE;
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n+1;j++){
                Point p1 = crosspoints[i][j];
                Point p2 = crosspoints[i+1][j];
                Point p3 = crosspoints[i+1][j+1];
                Point p4 = crosspoints[i][j+1];
                double s1 = Point.squareOfTriangle(p1,p2,p3);
                double s2 = Point.squareOfTriangle(p3,p4,p1);
                double s = s1+s2;
                if(s>max) max = s;
            }
        }
        return max;
    }
}

class Point{
    double x;
    double y;
    Point(double x,double y){
        this.x = x;
        this.y = y;
    }
    public static double squareOfTriangle(Point p1,Point p2,Point p3){
        double x1 = p1.x-p2.x;
        double x2 = p3.x-p2.x;
        double y1 = p1.y-p2.y;
        double y2 = p3.y-p2.y;
        double s = (x1*y2-x2*y1)/2;
        return Math.abs(s);
    }
}

class Line{
    double a;
    double b;
    double c;
    Line(Point p1,Point p2){
        this.a = p1.y-p2.y;
        this.b = -p1.x+p2.x;
        this.c = p1.x*p2.y-p2.x*p1.y;
    }
    public Point crossPoint(Line l){
        double x = (-l.b*this.c+this.b*l.c)/(this.a*l.b-this.b*l.a);
        double y = (l.a*this.c-this.a*l.c)/(this.a*l.b-this.b*l.a);
        return new Point(x,y);
    }
}