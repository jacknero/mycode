import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        while(n!=0){
            Point p[] = new Point[n];
            for(int i=0;i<n;i++){
                double x = sc.nextDouble();
                double y = sc.nextDouble();
                p[i] = new Point(x,y);
            }
            
            Solver s = new Solver(n,p);
            s.solve();
            
            n = sc.nextInt();
        }
    }
}

class Solver{
    int size;
    Point point[];
    
    Solver(int n,Point p[]){
        size = n;
        point = p;
    }
    
    public void solve(){
        int c;
        c = 1;
        
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                if(i==j) continue;
                if(point[i].dist2(point[j]) <4){
                    Point test1 = point[i].centerOfPassingCircle1(point[j],1);
                    int tmp = count(test1,i,j);
                    if(tmp>c) c = tmp;
                    Point test2 = point[i].centerOfPassingCircle2(point[j],1);
                    tmp = count(test2,i,j);
                    if(tmp>c) c = tmp;
                }
            }
        }
        System.out.println(c);
    }
    
    private int count(Point p,int i,int j){
        int c;
        c = 2;
        for(int k=0;k<size;k++){
            if(k==i || k==j) continue;
            if(p.dist2(point[k])<1) c++;
        }
        return c;
    }
}

class Point{
    double x;
    double y;
    Point(double px,double py){
        x = px;
        y = py;
    }
    public double dist2(Point p){
        return (x-p.x)*(x-p.x) + (y-p.y)*(y-p.y);
    }
    public double dist(Point p){
        return Math.sqrt(this.dist2(p));
    }
    public Point centerOfPassingCircle1(Point p,double r){
        double a = p.x - x;
        double b = p.y - y;
        double d = this.dist(p);
        double qx = x / 2 + p.x / 2 + Math.sqrt(r - d*d/4)*(-b)/d;
        double qy = y / 2 + p.y / 2 + Math.sqrt(r - d*d/4)*a/d;
        return new Point(qx,qy);
    }
    public Point centerOfPassingCircle2(Point p,double r){
        double a = p.x - x;
        double b = p.y - y;
        double d = this.dist(p);
        double qx = x / 2 + p.x / 2 - Math.sqrt(r - d*d/4)*(-b)/d;
        double qy = y / 2 + p.y / 2 - Math.sqrt(r - d*d/4)*a/d;
        return new Point(qx,qy);
    }
}