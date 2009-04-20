import java.util.*;

public class Main {
    final static int I[][] = {{1,0,0,0},{0,1,0,0},{0,0,1,0},{0,0,0,1}};
    final static int A[][] = {{1,1,0,0},{0,0,1,1},{1,0,0,0},{0,0,1,0}};
    final static int F[] = {2,2,1,1};
    final static int mod = 2005;

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            int ans = answer(n);
            System.out.println(ans);
        }
    }
    
    public static int answer(int n){
        if(n==1) return 2;
        else if(n==2) return 4;
        else{
            int m[][] = exp(n-3);
            int x[] = new int[4];
            for(int i=0;i<4;i++){
                x[i] = 0;
                for(int j=0;j<4;j++){
                    x[i] += m[i][j]*F[j];
                }
                x[i] %= mod;
            }
            return (x[0]+x[1]+x[2]+x[3]) % mod;
        }
    }

    public static int[][] exp(int n){
        if(n==0) return I;
        else if(n==1) return A;
        else if(n%2==0){
            int m[][] = exp(n/2);
            return mul(m,m);
        }
        else{
            return mul(exp(n-1),A);
        }
        
    }
    public static int[][] mul(int a[][],int b[][]){
        int m[][] = new int[4][4];
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                m[i][j] = 0;
                for(int k=0;k<4;k++){
                    m[i][j] += a[i][k]*b[k][j];
                }
                m[i][j] %= mod;
            }
        }
        return m;
    }
}