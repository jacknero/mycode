import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            Sphere[] sph = new Sphere[n];
            for(int i=0;i<n;i++){
                sph[i] = new Sphere
                (sc.nextDouble(),sc.nextDouble(),sc.nextDouble(),sc.nextDouble());
            }
            
            TreeSet<ActionPoint> act = new TreeSet<ActionPoint>();
            findActionPoint1(n, sph, act);
            findActionPoint2(n, sph, act);
            Vector<Integer> output = new Vector<Integer>();
            boolean[] exist = new boolean[n];
            boolean[][] connect = new boolean[n][n];
            for(int i=0;i<n;i++) exist[i] = false;
            for(int i=0;i<n;i++) for(int j=0;j<n;j++) connect[i][j] = false;
            int prev = 0;
            for(ActionPoint a:act){
                int s = a.s;
                if(a.type == ActionPoint.GENERATE){
                    exist[s] = true;
                    for(int t:a.connectv){
                        connect[s][t] = true;
                        connect[t][s] = true;
                    }
                }
                else if(a.type == ActionPoint.UNGENERATE){
                    exist[s] = false;
                    for(int i=0;i<n;i++){
                        connect[i][s] = false;
                        connect[s][i] = false;
                    }
                }
                else if(a.type == ActionPoint.CONNECT){
                    int t = a.connect;
                    connect[s][t] = true;
                    connect[t][s] = true;
                }
                else if(a.type == ActionPoint.UNCONNECT){
                    int t = a.connect;
                    connect[s][t] = false;
                    connect[t][s] = false;
                }
                
                int cnt = count(n,exist,connect);
                
                //System.out.println("cnt:"+cnt);
                
                if(prev>cnt) output.add(0);
                else if(prev<cnt) output.add(1);
                
                prev = cnt;
            }
            System.out.println(output.size());
            for(int b:output){
                System.out.print(b);
            }
            System.out.println();
        }
    }

    private static int count(int n, boolean[] exist, boolean[][] connect){
        int cnt = 0;
        boolean[] searched = new boolean[n];
        for(int i=0;i<n;i++) searched[i] = false;
        for(int i=0;i<n;i++){
            if(exist[i]&&!searched[i]){
                search(n,connect,searched,i);
                cnt++;
            }
        }
        return cnt;
    }
    private static void search(int n,boolean[][] connect,boolean[] searched,int k){
        searched[k] = true;
        for(int i=0;i<n;i++){
            if(connect[k][i]&&!searched[i]) search(n,connect,searched,i);
        }
    }
    private static void findActionPoint1(int n, Sphere[] sph,  TreeSet<ActionPoint> act) {
        for(int i=0;i<n;i++){
            Sphere s = sph[i];
            ActionPoint gen = new ActionPoint(ActionPoint.GENERATE,i,s.z-s.r);
            ActionPoint ungen = new ActionPoint(ActionPoint.UNGENERATE,i,s.z+s.r);
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(s.bottomContained(sph[j])){
                    gen.connectv.add(j);
                }
            }
            act.add(gen);
            act.add(ungen);
        }
    }

    private static void findActionPoint2(int n, Sphere[] sph, TreeSet<ActionPoint> act) {
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double d = sph[i].dist(sph[j]);
                if(d==0) continue;
                if(d>=sph[i].r+sph[j].r) continue;
                
                double z0,z1,r0,r1;
                if(sph[i].z<=sph[j].z){
                    z0 = sph[i].z;
                    z1 = sph[j].z;
                    r0 = sph[i].r;
                    r1 = sph[j].r;
                }
                else{
                    z0 = sph[j].z;
                    z1 = sph[i].z;
                    r0 = sph[j].r;
                    r1 = sph[i].r;
                }
                
                double t = z1-z0;
                
                double dx = sph[i].x-sph[j].x;
                double dy = sph[i].y-sph[j].y;
                double s = Math.sqrt(dx*dx+dy*dy);
                
                double d0 = (d+(r0*r0-r1*r1)/d)*0.5;
                double x = Math.sqrt(r0*r0-d0*d0);
                
                double zplus = d0*t/d + x*s/d + z0;
                double zminus = d0*t/d - x*s/d + z0;
                
                if(!sph[i].topContained(sph[j]) && !sph[j].topContained(sph[i])){
                    ActionPoint a = new ActionPoint(ActionPoint.UNCONNECT,i,zplus,j);
                    act.add(a);
                }
                if(!sph[i].bottomContained(sph[j]) && !sph[j].bottomContained(sph[i])){
                    ActionPoint a = new ActionPoint(ActionPoint.CONNECT,i,zminus,j);
                    act.add(a);
                }
            }
        }
    }
}

class ActionPoint implements Comparable<ActionPoint>{
    static final int GENERATE = 0;
    static final int UNGENERATE = 1;
    static final int CONNECT = 2;
    static final int UNCONNECT = 3;
    int type;
    int s;
    double z;
    int connect;
    Vector<Integer> connectv;
    public boolean equals(Object o){
        ActionPoint a = (ActionPoint)o;
        return this.z==a.z;
    }
    public int compareTo(ActionPoint a){
        if(this.z-a.z>0) return 1;
        else if(this.z-a.z<0) return -1;
        else return 0;
    }
    ActionPoint(int type, int s, double z) {
        this.type = type;
        this.s = s;
        this.z = z;
        this.connect = -1;
        this.connectv = new Vector<Integer>();
    }
    ActionPoint(int type, int s, double z,int connect) {
        this.type = type;
        this.s = s;
        this.z = z;
        this.connect = connect;
        this.connectv = null;
    }
}

class Sphere{
    double x;
    double y;
    double z;
    double r;
    Sphere(double x, double y, double z, double r) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.r = r;
    }
    public boolean bottomContained(Sphere s){
        double dx = this.x-s.x;
        double dy = this.y-s.y;
        double dz = (this.z-this.r)-s.z;
        double d = Math.sqrt(dx*dx+dy*dy+dz*dz);
        return d<=s.r;
    }
    public boolean topContained(Sphere s){
        double dx = this.x-s.x;
        double dy = this.y-s.y;
        double dz = (this.z+this.r)-s.z;
        double d = Math.sqrt(dx*dx+dy*dy+dz*dz);
        return d<=s.r;
    }
    public double dist(Sphere s){
        double dx = this.x-s.x;
        double dy = this.y-s.y;
        double dz = this.z-s.z;
        double d = Math.sqrt(dx*dx+dy*dy+dz*dz);
        return d;
    }
}