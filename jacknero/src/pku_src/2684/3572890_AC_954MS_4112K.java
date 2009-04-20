import java.util.*;

public class Main {
    private static Scanner sc;
    public static void main(String[] args) {
        sc = new Scanner(System.in);
        int n;
        while((n=sc.nextInt())>0){
            int m0 = sc.nextInt();
            PolyLine tmp = new PolyLine(m0, readPoints(m0));
            PolyLine rtmp = tmp.reverse();
            int[] tmpcode = tmp.code();
            int[] rtmpcode = rtmp.code();
            for(int i=1;i<=n;i++){
                int m = sc.nextInt();
                PolyLine pl = new PolyLine(m, readPoints(m));
                if(m!=m0) continue;
                int[] plcode = pl.code();
                if(PolyLine.codeEquals(tmpcode, plcode) ||
                        PolyLine.codeEquals(rtmpcode, plcode)){
                    System.out.println(i);
                }
            }
            System.out.println("+++++");
        }
    }
    private static Point[] readPoints(int m){
        Point[] ps = new Point[m];
        for(int i=0;i<m;i++) ps[i] = new Point(sc.nextInt(), sc.nextInt());
        return ps;
    }
}

class PolyLine{
    int m;
    Point[] ps;
    public PolyLine(int m, Point[] ps) {
        this.m = m;
        this.ps = ps;
    }
    public PolyLine reverse(){
        Point[] rps = new Point[m];
        for(int i=0;i<m;i++) rps[i] = ps[m-1-i];
        return new PolyLine(m, rps);
    }
    public int[] code(){
        int[] ret = new int[2*m-3];
        for(int i=0;i<m-1;i++) ret[2*i] = Point.dist(ps[i], ps[i+1]);
        for(int i=0;i<m-2;i++) ret[2*i+1] = Point.angleSign(ps[i], ps[i+1], ps[i+2]);
        return ret;
    }
    public static boolean codeEquals(int[] c1, int[] c2){
        if(c1.length!=c2.length) return false;
        boolean flag = true;
        for(int i=0;i<c1.length;i++) if(c1[i]!=c2[i]) flag = false;
        return flag;
    }
}

class Point{
    int x;
    int y;
    public Point(int x, int y) {
        // TODO Auto-generated constructor stub
        this.x = x;
        this.y = y;
    }
    public static int dist(Point p1, Point p2){
        return Math.abs(p1.x - p2.x) + Math.abs(p1.y - p2.y);
    }
    public static int angleSign(Point p1, Point p2, Point p3){
        if((p2.x - p1.x)*(p3.y - p2.y) - (p2.y - p1.y)*(p3.x - p2.x) > 0) return 1;
        else return -1;
    }
}