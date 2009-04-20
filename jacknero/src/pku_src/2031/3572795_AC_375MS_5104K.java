import java.io.*;
import java.util.*;
import java.text.*;

public class Main{
    public static void main(String[] args)throws IOException{
        Scanner sc = new Scanner(System.in);
        DecimalFormat formatter = new DecimalFormat("#0.000");
        int n = sc.nextInt();
        while(n!=0){
            double data[][] = new double[n][4];
            for(int i=0;i<n;i++){
                data[i][0] = sc.nextDouble();
                data[i][1] = sc.nextDouble();
                data[i][2] = sc.nextDouble();
                data[i][3] = sc.nextDouble();
            }
            
            Solver s = new Solver(n,data);
            double ans = s.solve();
            
            System.out.println(formatter.format(ans));
            
            n = sc.nextInt();
        }
    }
}

class Solver{
    int size;
    int connected[];//expression of MF-SET
    PriorityQueue<Edge> q;
    Solver(int n,double data[][]){
        size = n;
        connected = new int[size];
        q = new PriorityQueue<Edge>();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double elen = edgeLength(data[i],data[j]);
                Edge e = new Edge(i,j,elen);
                q.offer(e);
            }
        }
        for(int i=0;i<n;i++) connected[i] = i;
    }
    
    public double solve(){
        double corlen;
        corlen = 0;
        //Kruskal's algorithm
        while(!q.isEmpty()){
            Edge e = q.poll();
            int i = e.p1;
            int j = e.p2;
            if(connected[i]!=connected[j]){
                merge(i,j);
                corlen += e.length;
            }
        }
        return corlen;
    }
    
    //MERGE OF MF-SET
    private void merge(int i,int j){
        int m1 = connected[i];
        int m2 = connected[j];
        for(int k=0;k<size;k++){
            if(connected[k]==m2) connected[k] = m1;
        }
    }
    
    private double edgeLength(double d1[],double d2[]){
        double dx = d1[0]-d2[0];
        double dy = d1[1]-d2[1];
        double dz = d1[2]-d2[2];
        double dist = Math.sqrt(dx*dx+dy*dy+dz*dz);
        double prelen = dist - (d1[3]+d2[3]);
        if(prelen>=0.0) return prelen;
        else return 0.0;
    }
}

class Edge implements Comparable<Edge>{
    int p1;
    int p2;
    double length;
    Edge(int i,int j,double l){
        p1 = i;
        p2 = j;
        length = l;
    }
    public int compareTo(Edge e){
        if(length>e.length) return 1;
        else if(length==e.length) return 0;
        else return -1;
    }
}