import java.util.*;

public class Main{
    static int[][][] mem;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            LineSegment ls[] = new LineSegment[n+1];
            ls[0] = new LineSegment(-30000,-20000);
            for(int i=1;i<=n;i++){
                ls[i] = new LineSegment(sc.nextInt(),sc.nextInt());
            }
            Arrays.sort(ls);
            
            int m = sizeOfMaxStableSet(ls);
            int e = n+1 - m;
            mem = new int[m][n+1][n+1];
            for(int i=0;i<m;i++){
                for(int j=0;j<=n;j++){
                    Arrays.fill(mem[i][j],-1);
                }
            }
            int c = numOfMaxStableSet(ls,m-1,1,0);
            System.out.println(e+" "+c);
        }
    }
    private static int numOfMaxStableSet(LineSegment[] ls,int size,int k,int l){
        if(k>=ls.length) return 0;
        if(mem[size-1][k][l]==-1){
            int ret;
            
            if(ls.length-k<size){
                ret = 0;
            }
            else if(ls[k].x0<ls[l].x1){
                ret = numOfMaxStableSet(ls,size,k+1,l);
            }
            else if(size==1){
                ret = 1 + numOfMaxStableSet(ls,size,k+1,l);
            }
            else{
                ret = numOfMaxStableSet(ls,size-1,k+1,k) + numOfMaxStableSet(ls,size,k+1,l);
            }
            
            mem[size-1][k][l] = ret;
            return ret;
        }
        else{
            return mem[size-1][k][l];
        }
    }
    private static int sizeOfMaxStableSet(LineSegment[] ls){
        int ret = 0;
        int x = Integer.MIN_VALUE;
        for(int i=0;i<ls.length;i++){
            if(x<=ls[i].x0){
                x = ls[i].x1;
                ret++;
            }
        }
        return ret;
    }
}

class LineSegment implements Comparable<LineSegment>{
    int x0;
    int x1;
    LineSegment(int x0, int x1) {
        this.x0 = Math.min(x0,x1);
        this.x1 = Math.max(x0,x1);
        if(this.x0==this.x1){
            throw new RuntimeException();
        }
    }
    public boolean equals(Object o){
        LineSegment ls = (LineSegment)o;
        return this.x0==ls.x0&&this.x1==ls.x1;
    }
    public int compareTo(LineSegment ls){
        if(this.x1!=ls.x1) return this.x1 - ls.x1;
        else return this.x0 - ls.x0;
    }
}