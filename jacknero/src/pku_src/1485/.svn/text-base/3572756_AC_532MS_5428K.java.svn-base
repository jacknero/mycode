import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        while(true){
            int n = sc.nextInt();
            int k = sc.nextInt();
            if(n==0&&k==0) break;
            
            int[] x = new int[n];
            for(int i=0;i<n;i++){
                x[i] = sc.nextInt();
            }
            Solver sol = new Solver(n, k, x);
            int[] ans = sol.solve();
            
            System.out.printf("Chain %d\r\n",cnt+1);
            for(int i=0;i<k;i++){
                int start = ans[i]+1;
                int end = ans[i+1];
                int center = (start+end)/2;
                if(start!=end){
                    System.out.printf("Depot %d at restaurant %d serves restaurants %d to %d\r\n", i+1, center, start, end);
                }
                else{
                    System.out.printf("Depot %d at restaurant %d serves restaurant %d\r\n", i+1, center, start);
                }
            }
            System.out.printf("Total distance sum = %d\r\n", ans[k+1]);
            System.out.println();
        }
    }
}

class Solver{
    int n;
    int k;
    int x[];
    public Solver(int n, int k, int[] x) {
        this.n = n;
        this.k = k;
        this.x = x;
    }
    public int[] solve(){
        int[] ret = new int[k+2];
        
        int[][] w = new int[n][n];
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int c = (i+j)/2;
                int sum = 0;
                for(int m=i;m<=j;m++) sum += Math.abs(x[m]-x[c]);
                w[i][j] = sum;
            }
        }
        
        int[][] t = new int[n][k];
        int[][] s = new int[n][k];
        for(int i=0;i<n;i++){
            t[i][0] = w[0][i];
            s[i][0] = 0;
        }
        for(int j=1;j<k;j++){
            t[j][j] = 0;
            s[j][j] = j;
            for(int i=j+1;i<n;i++){
                int min = Integer.MAX_VALUE;
                for(int m=j;m<=i;m++){
                    int sum = t[m-1][j-1] + w[m][i];
                    if(sum<min){
                        min = sum;
                        t[i][j] = min;
                        s[i][j] = m;
                    }
                }
            }
        }
        ret[k+1] = t[n-1][k-1];
        ret[k] = n;
        for(int i=k-1;i>=0;i--){
            ret[i] = s[ret[i+1]-1][i];
        }
        return ret;
    }
}