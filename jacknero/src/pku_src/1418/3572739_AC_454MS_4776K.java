import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while((n = sc.nextInt())!=0){
            Circle[] cir = new Circle[n];
            for(int i=0;i<n;i++){
                cir[i] = new Circle(sc.nextDouble(),sc.nextDouble(),sc.nextDouble());
            }
            Solver sol = new Solver(n,cir);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int size;
    Circle[] cir;
    Solver(int n,Circle[] c){
        size = n;
        cir = new Circle[size];
        for(int i=0;i<size;i++) cir[i] = c[i];
    }
    public int solve(){
        int cnt = 0; //counter
        for(int i=0;i<size;i++){ //if Circle i is visible counter increments
            /*if Circle i has no intersection wih Circle j or covers Circle j forall j>i, 
              then Circle i is visible*/
            boolean haveNoIntersection = true;
            for(int j=i+1;j<size;j++){
                if(!cir[i].distant(cir[j])&&!cir[i].covers(cir[j])){
                    haveNoIntersection = false;
                    break;
                }
            }
            if(haveNoIntersection){
                cnt++;
                continue;
            }
            
            /* if there exists Circle j s.t. contains Circle i, then Circle i is visible*/
            boolean contained = false;
            for(int j=i+1;j<size;j++){
                if(cir[j].covers(cir[i])){
                    contained = true;
                    break;
                }
            }
            if(contained) continue;
            
            //def testpoints := cross point of Circle j and Circle k (i<=j<k)
            //if there exists a testpoint s.t. forall l>i Circle l doesn't cover the point,
            //Circle i is visible
            boolean visible = false;
            for(int j=i;j<size;j++){
                for(int k=j+1;k<size;k++){
                    if(!cir[j].haveCrossPoint(cir[k])) continue;
                        
                    Point p1 = cir[j].crossPoint1(cir[k]);
                    if(j==i||cir[i].contains(p1)){
                        boolean pvisible = true;
                        for(int l=i+1;l<size;l++){
                            if(l==j||l==k) continue;
                            if(cir[l].contains(p1)){
                                pvisible = false;
                                break;
                            }
                        }
                        if(pvisible){
                            visible = true;
                            break;
                        }
                    }
                    Point p2 = cir[j].crossPoint2(cir[k]);
                    if(j==i||cir[i].contains(p2)){
                        boolean pvisible = true;
                        for(int l=i+1;l<size;l++){
                            if(l==j||l==k) continue;
                            if(cir[l].contains(p2)){
                                pvisible = false;
                                break;
                            }
                        }
                        if(pvisible){
                            visible = true;
                            break;
                        }
                    }
                }
                if(visible){
                    break;
                }
            }
            if(visible) cnt++;
        }
        return cnt;
    }
}

class Point{
    double x;
    double y;
    Point(double px,double py){
        x = px;
        y = py;
    }
}

class Circle{
    double x;
    double y;
    double r;
    Circle(double cx,double cy,double cr){
        x = cx;
        y = cy;
        r = cr;
    }
    public double centerDist(Circle c){
        return Math.sqrt((x-c.x)*(x-c.x)+(y-c.y)*(y-c.y));
    }
    public boolean contains(Point p){
        return Math.sqrt((x-p.x)*(x-p.x)+(y-p.y)*(y-p.y))<r;
    }
    public boolean covers(Circle c){
        return centerDist(c)<r-c.r; //d<r1-r2
    }
    public boolean haveCrossPoint(Circle c){
        double d = centerDist(c);
        return Math.abs(r-c.r)<d && d<(r+c.r); //|r1-r2|<d<r1+r2
    }
    public boolean distant(Circle c){
        double d = centerDist(c);
        return r+c.r<d; //r1+f2<d
    }
    public Point crossPoint1(Circle c){
        double d = centerDist(c);
        double d1 = (d*d + r*r - c.r*c.r)/(2*d);
        double ex = x + (c.x-x)*d1/d;
        double ey = y + (c.y-y)*d1/d;
        double l = Math.sqrt(r*r-d1*d1);
        double lx = -(c.y-y)*l/d;
        double ly = (c.x-x)*l/d;
        return new Point(ex+lx,ey+ly);
    }
    public Point crossPoint2(Circle c){
        double d = centerDist(c);
        double d1 = (d*d + r*r - c.r*c.r)/(2*d);
        double ex = x + (c.x-x)*d1/d;
        double ey = y + (c.y-y)*d1/d;
        double l = Math.sqrt(r*r-d1*d1);
        double lx = -(c.y-y)*l/d;
        double ly = (c.x-x)*l/d;
        return new Point(ex-lx,ey-ly);
    }
}