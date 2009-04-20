import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            LineSegment[] ls = new LineSegment[n];
            for(int i=0;i<n;i++){
                Point p1 = new Point(sc.nextDouble(),sc.nextDouble());
                Point p2 = new Point(sc.nextDouble(),sc.nextDouble());
                ls[i] = new LineSegment(p1,p2,i);
            }
            Solver sol = new Solver(n,ls);
            if(sol.solve()) System.out.println("yes");
            else System.out.println("no");
        }
    }
}

class Solver{
    int n;
    LineSegment[] line;
    Point[][] crosspoint;
    
    Solver(int n,LineSegment[] line) {
        this.n = n;
        this.line = line;
        this.crosspoint = new Point[n][n];
        for(int i=0;i<n;i++) for(int j=0;j<n;j++) crosspoint[i][j] = null;
    }
    public boolean solve(){
        for(int i=0;i<n;i++){
            // add ls[i]
            
            // calc cross point with ls[0]..ls[i-1]
            TreeMap<Point,Integer> loccrosspoint = new TreeMap<Point,Integer>();
            for(int j=0;j<i;j++){
                Point p = line[i].crossPoint(line[j]);
                if(p!=null){
                    crosspoint[i][j] = p;
                    crosspoint[j][i] = p;
                    loccrosspoint.put(p,j);
                }
            }
            
            // find loop and check
            Integer[] cline = new Integer[loccrosspoint.size()];
            cline = loccrosspoint.values().toArray(cline);
            int m = cline.length;
            for(int j=0;j<m;j++){
                for(int k=j+1;k<m;k++){
                    if(line[cline[j]].group==line[cline[k]].group){
                        if(solve_sub(cline[j],cline[k],i)) return true;
                        continue;
                    }
                }
            }
            
            // merge group
            TreeSet<Integer> merged = new TreeSet<Integer>();
            for(int j=0;j<m;j++){
                merged.add(line[cline[j]].group);
            }
            for(int g:merged){
                for(int j=0;j<i;j++){
                    if(line[j].group==g){
                        line[j].group = i;
                    }
                }
            }
        }
        return false;
    }
    
    // find loop subroutin
    public boolean solve_sub(int j,int k,int m){
        // BFS
        int[] prev = new int[m];
        boolean[] searched = new boolean[m];
        for(int u=0;u<m;u++) prev[u] = -1;
        for(int u=0;u<m;u++) searched[u] = false;
        
        Queue<Integer> q = new LinkedList<Integer>();
        prev[j] = m;
        searched[j] = true;
        q.offer(j);
        boolean searchend = false;
        while(!searchend){
            int u = q.poll();
            for(int v=0;v<m;v++){
                if(crosspoint[u][v]!=null&&!searched[v]){
                    searched[v] = true;
                    prev[v] = u;
                    if(v==k){
                        searchend = true;
                        break;
                    }
                    else{
                        q.offer(v);
                    }
                }
            }
        }
        
        // calc path
        ArrayList<Point> path = new ArrayList<Point>();
        path.add(crosspoint[m][k]);
        int v = k;
        while(v!=m){
            path.add(crosspoint[v][prev[v]]);
            v = prev[v];
        }
        
        // return
        return Point.inPolygon(path);
    }
}

class Point implements Comparable<Point>{
    double x;
    double y;
    static final double EPSILON = 1E-8;
    Point(double x,double y){
        this.x = x;
        this.y = y;
    }
    public int compareTo(Point p){
        if(this.x>p.x) return 1;
        else if(this.x<p.x) return -1;
        else{
            if(this.y>p.y) return 1;
            else if(this.y<p.y) return -1;
            else return 0;
        }
    }
    public boolean equals(Object o){
        Point p = (Point)o;
        return this.x==p.x&&this.y==p.y;
    }
    /*
    public static boolean isCrossed(Point p1,Point p2,Point q1,Point q2){
        return 
            ((p1.x - p2.x) * (q1.y - p1.y) + (p1.y - p2.y) * (p1.x - q1.x)) * 
            ((p1.x - p2.x) * (q2.y - p1.y) + (p1.y - p2.y) * (p1.x - q2.x)) < 0 &&
            ((q1.x - q2.x) * (p1.y - q1.y) + (q1.y - q2.y) * (q1.x - p1.x)) *
            ((q1.x - q2.x) * (p2.y - q1.y) + (q1.y - q2.y) * (q1.x - p2.x)) < 0;
    }
    */
    public static boolean isCrossed(Point p1,Point p2,Point q1,Point q2){
        double c1 = 
            ((p1.x - p2.x) * (q1.y - p1.y) + (p1.y - p2.y) * (p1.x - q1.x)) * 
            ((p1.x - p2.x) * (q2.y - p1.y) + (p1.y - p2.y) * (p1.x - q2.x));
        double c2 =
            ((q1.x - q2.x) * (p1.y - q1.y) + (q1.y - q2.y) * (q1.x - p1.x)) *
            ((q1.x - q2.x) * (p2.y - q1.y) + (q1.y - q2.y) * (q1.x - p2.x));
        
        // c1>0 or c2>0
        if(c1>EPSILON||c2>EPSILON) return false;
        // c1<0 and c2<0
        else if(c1<-EPSILON||c2<-EPSILON) return true;
        // c1=0 and c2=0
        else if(Math.abs(c1)<EPSILON&&Math.abs(c2)<EPSILON){
            if(p1.equals(q1)||p1.equals(q2)||p2.equals(q1)||p2.equals(q2))
                return true;
            return false;
        }
        // "c1=0 and c2<0" or "c1<0 and c2=0"
        else return true;
    }
    public static boolean inPolygon(ArrayList<Point> poly){
        double acc = 0.0;
        int n = poly.size();
        for(int i=0;i<n-1;i++){
            acc += arg(poly.get(i),poly.get(i+1));
        }
        acc += arg(poly.get(n-1),poly.get(0));
        
        if(Math.abs(acc)<EPSILON) return false;
        else return true;
    }
    /*
     * 0<= theta < Pi
    private static double arg(Point p1,Point p2,Point p3){
        double ax = p1.x - p2.x;
        double ay = p1.y - p2.y;
        double bx = p3.x - p2.x;
        double by = p3.y - p2.y;
        double theta = 
            Math.atan2((ax*by-ay*bx)/(ax*ax+ay*ay),(ax*bx+ay*by)/(ax*ax+ay*ay));
        return Math.abs(theta);
    }
    */
    // -Pi < theta < Pi
    private static double arg(Point p1,Point p2){
        double ax = p1.x;
        double ay = p1.y;
        double bx = p2.x;
        double by = p2.y;
        double theta = 
            Math.atan2((ax*by-ay*bx)/(ax*ax+ay*ay),(ax*bx+ay*by)/(ax*ax+ay*ay));
        return theta;
    }
}

class LineSegment{
    Point p1;
    Point p2;
    double a;
    double b;
    double c;
    int group;
    static final double EPSILON = 1E-8;
    LineSegment(Point p1,Point p2,int group){
        this.p1 = p1;
        this.p2 = p2;
        this.a = p1.y-p2.y;
        this.b = -p1.x+p2.x;
        this.c = -p1.x*(p1.y-p2.y)+p1.y*(p1.x-p2.x);
        this.group = group;
    }
    public boolean hasCrossPoint(LineSegment l){
        return Point.isCrossed(this.p1,this.p2,l.p1,l.p2);
    }
    public Point crossPoint(LineSegment l){
        if(!hasCrossPoint(l)) return null;
        
        double det = this.a*l.b-this.b*l.a;
        if(Math.abs(det)<EPSILON){
            if     (this.p1.equals(l.p1)||this.p1.equals(l.p2)) return this.p1;
            else if(this.p2.equals(l.p1)||this.p2.equals(l.p2)) return this.p2;
        }
        
        double x = (-l.b*this.c+this.b*l.c)/det;
        double y = (l.a*this.c-this.a*l.c)/det;
        return new Point(x,y);
    }
}