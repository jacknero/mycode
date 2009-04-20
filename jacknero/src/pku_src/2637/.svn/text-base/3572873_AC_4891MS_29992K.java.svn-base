import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            TreeSet<Integer> yset = new TreeSet<Integer>();
            HashMap<Integer, Integer> y_to_i = new HashMap<Integer, Integer>();
            int r[] = new int[n];
            for(int i=0;i<n;i++){
                int yi = sc.nextInt();
                int ri = sc.nextInt();
                yset.add(yi);
                y_to_i.put(yi, i);
                r[i] = ri;
            }
            Solver sol = new Solver(n, yset, y_to_i, r);
            int m = sc.nextInt();
            if(n==0 && m==0) break;
            for(int i=0;i<m;i++){
                int y = sc.nextInt();
                int x = sc.nextInt();
                int ans = sol.solve(x, y);
                if(ans==1){
                    System.out.println("true");
                }
                else if(ans==0){
                    System.out.println("maybe");
                }
                else{
                    System.out.println("false");
                }
            }
            System.out.println();
        }
    }
}

class Solver{
    int n;
    TreeSet<Integer> yset;
    HashMap<Integer, Integer> y_to_i;
    int r[];;
    int rm[];
    static final int BSIZE = 1000;
    public Solver(int n, TreeSet<Integer> yset, HashMap<Integer, Integer> y_to_i, int[] r) {
        super();
        // TODO Auto-generated constructor stub
        this.n = n;
        this.yset = yset;
        this.y_to_i = y_to_i;
        this.r = r;
        this.rm = new int[n/BSIZE];
        for(int i=0;i<n/BSIZE;i++){
            rm[i] = Integer.MIN_VALUE;
            for(int j=i*BSIZE;j<n&&j<(i+1)*BSIZE;j++){
                rm[i] = Math.max(rm[i], r[j]);
            }
        }
    }
    public int index(int x){
        return y_to_i.get(x);
    }
    public int solve(int x, int y){
        if(yset.contains(x)&&yset.contains(y)){
            int ix = index(x);
            int iy = index(y);
            
            if(r[ix]>r[iy]) return -1;
            
            if(index(x)-index(y)==x-y){
                boolean flag = true;
                for(int z=iy+1;z<ix;z++){
                    if(r[z]>=r[ix]){
                        flag = false;
                        break;
                    }
                }
                if(flag) return 1;
            }
        }
        
        if(yset.contains(x)){
            int ix = index(x);
            if(y+1>x-1) return 0;
            SortedSet<Integer> ysub = yset.subSet(y+1, x);
            if(ysub.isEmpty()) return 0;
            
            int z1 = index(ysub.first());
            int z2 = index(ysub.last());
            int m1 = z1/BSIZE;
            int m2 = z2/BSIZE;
            if(m1==m2){
                for(int z=z1;z<=z2;z++){
                    if(r[z]>=r[ix]) return -1;
                }
            }
            else{
                for(int z=z1;z<(z1/BSIZE + 1)*BSIZE;z++){
                    if(r[z]>=r[ix]) return -1;
                }
                for(int z=(z2/BSIZE)*BSIZE;z<=z2;z++){
                    if(r[z]>=r[ix]) return -1;
                }
                for(int m=m1+1;m<m2;m++){
                    if(rm[m]>=r[ix]) return -1;
                }
            }
        }
        
        if(yset.contains(y)){
            int iy = index(y);
            if(y+1>x-1) return 0;
            SortedSet<Integer> ysub = yset.subSet(y+1, x);
            if(ysub.isEmpty()) return 0;
            
            int z1 = index(ysub.first());
            int z2 = index(ysub.last());
            int m1 = z1/BSIZE;
            int m2 = z2/BSIZE;
            if(m1==m2){
                for(int z=z1;z<=z2;z++){
                    if(r[z]>=r[iy]) return -1;
                }
            }
            else{
                for(int z=z1;z<(z1/BSIZE + 1)*BSIZE;z++){
                    if(r[z]>=r[iy]) return -1;
                }
                for(int z=(z2/BSIZE)*BSIZE;z<=z2;z++){
                    if(r[z]>=r[iy]) return -1;
                }
                for(int m=m1+1;m<m2;m++){
                    if(rm[m]>=r[iy]) return -1;
                }
            }
        }
        
        return 0;
    }
}