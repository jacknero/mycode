import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            int[][] dist = new int[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j) dist[i][j] = 0;
                    else dist[i][j] = 65536;
                }
            }
            
            for(int i=0;i<n;i++){
                int m=sc.nextInt();
                for(int j=0;j<m;j++){
                    int p = sc.nextInt()-1;
                    int t = sc.nextInt();
                    dist[i][p] = t;
                }
            }
            
            int[][] a = new int[n][n];
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    a[i][j] = dist[i][j];
                }
            }
                                                                                                                                                               
            for(int k=0;k<n;k++){
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        if(a[i][j]>a[i][k]+a[k][j]){
                            a[i][j] = a[i][k] + a[k][j];
                        }
                    }
                }
            }
            
            int retp = -1;
            int rett = 65536;
            for(int i=0;i<n;i++){
                int max = 0;
                for(int j=0;j<n;j++){
                    if(max<a[i][j]) max = a[i][j];
                }
                
                if(max<rett){
                    retp = i;
                    rett = max;
                }
            }
            
            if(retp==-1){
                System.out.println("disjoint");
            }
            else{
                System.out.println((retp+1)+" "+rett);
            }
        }
    }
}