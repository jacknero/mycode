import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            Point p[] = new Point[n];
            for(int i=0;i<n;i++)
                p[i] = new Point(sc.nextDouble(),sc.nextDouble(),sc.nextDouble());
            
            double minrad = Double.MAX_VALUE;
            
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    Point o = Point.midpoint(p[i],p[j]);
                    double r = o.dist(p[i]);
                    boolean valid = true;
                    for(int k=0;k<n;k++){
                        if(k==i||k==j) continue;
                        if(o.dist(p[k])>r){
                            valid = false;
                            break;
                        }
                    }
                    if(valid&&minrad>r) minrad = r;
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        Point o =
                            Point.centerOfCircumCircle(p[i],p[j],p[k]);
                        if(o==null) continue;
                        double r = o.dist(p[i]);
                        boolean valid = true;
                        for(int l=0;l<n;l++){
                            if(l==i||l==j||l==k) continue;
                            if(o.dist(p[l])>r){
                                valid = false;
                                break;
                            }
                        }
                        if(valid&&minrad>r) minrad = r;
                    }
                }
            }
            
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++){
                        for(int l=k+1;l<n;l++){
                            Point o = 
                                Point.centerOfCircumSphere(p[i],p[j],p[k],p[l]);
                            if(o==null) continue;
                            double r = o.dist(p[i]);
                            boolean valid = true;
                            for(int m=0;m<n;m++){
                                if(m==i||m==j||m==k||m==l) continue;
                                if(o.dist(p[m])>r){
                                    valid = false;
                                    break;
                                }
                            }
                            if(valid&&minrad>r) minrad = r;
                        }
                    }
                }
            }
            
            System.out.printf("%.5f\r\n",minrad);
        }
    }
}

class Point{
    double x;
    double y;
    double z;
    Point(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }
    public double dist(Point p){
        double dx = p.x-this.x;
        double dy = p.y-this.y;
        double dz = p.z-this.z;
        return Math.sqrt(dx*dx+dy*dy+dz*dz);
    }
    //determinant of matrix |a1 a2 a3| where a1,a2,a3 are column vectors
    public static double det(Point a1,Point a2,Point a3){
        double d1 = a1.x*(a2.y*a3.z-a2.z*a3.y);
        double d2 = a1.y*(a2.x*a3.z-a2.z*a3.x);
        double d3 = a1.z*(a2.x*a3.y-a2.y*a3.x);
        return d1-d2+d3;
    }
    /* solution of linear equation
     * where coefficient matrix is (a1 a2 a3) and c is constant vector
     * when the solution is not unique, return null
     */
    public static Point solveLinearEquation(Point a1,Point a2,Point a3,Point c){
        double d = det(a1,a2,a3);
        if(Math.abs(d)<1E-10) return null;
        double o1 = det(c,a2,a3);
        double o2 = det(a1,c,a3);
        double o3 = det(a1,a2,c);
        return new Point(o1/d,o2/d,o3/d);
    }
    /* center of circumcircle of Triangle pqr
     * when p,q,r are on a line, return null
     */
    public static Point centerOfCircumCircle(Point p,Point q,Point r){
        double a11 = 2*(p.x-q.x);
        double a12 = 2*(p.y-q.y);
        double a13 = 2*(p.z-q.z);
        double c1 = p.x*p.x+p.y*p.y+p.z*p.z-q.x*q.x-q.y*q.y-q.z*q.z;
        double a21 = 2*(p.x-r.x);
        double a22 = 2*(p.y-r.y);
        double a23 = 2*(p.z-r.z);
        double c2 = p.x*p.x+p.y*p.y+p.z*p.z-r.x*r.x-r.y*r.y-r.z*r.z;
        double a31 = p.y*q.z+q.y*r.z+r.y*p.z-p.z*q.y-q.z*r.y-r.z*p.y;
        double a32 = p.z*q.x+q.z*r.x+r.z*p.x-p.x*q.z-q.x*r.z-r.x*p.z;
        double a33 = p.x*q.y+q.x*r.y+r.x*p.y-p.y*q.x-q.y*r.x-r.y*p.x;
        double c3 = det(p,q,r);
        Point a1 = new Point(a11,a21,a31);
        Point a2 = new Point(a12,a22,a32);
        Point a3 = new Point(a13,a23,a33);
        Point c = new Point(c1,c2,c3);
        return solveLinearEquation(a1,a2,a3,c);
    }
    /* center of circumsphere of tetrahedron pqrs
     * when p,q,r,s are on a plane, return null
     */
    public static Point centerOfCircumSphere(Point p,Point q,Point r,Point s){
        double a11 = 2*(p.x-q.x);
        double a12 = 2*(p.y-q.y);
        double a13 = 2*(p.z-q.z);
        double c1 = p.x*p.x+p.y*p.y+p.z*p.z-q.x*q.x-q.y*q.y-q.z*q.z;
        double a21 = 2*(p.x-r.x);
        double a22 = 2*(p.y-r.y);
        double a23 = 2*(p.z-r.z);
        double c2 = p.x*p.x+p.y*p.y+p.z*p.z-r.x*r.x-r.y*r.y-r.z*r.z;
        double a31 = 2*(p.x-s.x);
        double a32 = 2*(p.y-s.y);
        double a33 = 2*(p.z-s.z);
        double c3 = p.x*p.x+p.y*p.y+p.z*p.z-s.x*s.x-s.y*s.y-s.z*s.z;
        Point a1 = new Point(a11,a21,a31);
        Point a2 = new Point(a12,a22,a32);
        Point a3 = new Point(a13,a23,a33);
        Point c = new Point(c1,c2,c3);
        return solveLinearEquation(a1,a2,a3,c);
    }
    public static Point midpoint(Point p,Point q){
        return new Point((p.x+q.x)/2,(p.y+q.y)/2,(p.z+q.z)/2);
    }
}