import java.util.*;

public class Main {
          public static void main(String args[]){
              Scanner sc = new Scanner(System.in);
                  int n = sc.nextInt();
                  int[][] a = new int[n+1][n+1];
                  a[0][0] = 0;
                  for(int j=1;j<=n;j++) a[0][j] = 0;
                  for(int i=1;i<=n;i++) a[i][0] = 0;
                  for(int i=1;i<=n;i++){
                      for(int j=1;j<=n;j++){
                          a[i][j] = sc.nextInt();
                      }
                  }
                  
                  int[][] b = new int[n+1][n+1];
                  b[0][0] = 0;
                  for(int j=1;j<=n;j++) b[0][j] = 0;
                  for(int i=1;i<=n;i++) b[i][0] = 0;
                  for(int i=1;i<=n;i++){
                      for(int j=1;j<=n;j++){
                          b[i][j] = b[i-1][j] + b[i][j-1] - b[i-1][j-1] + a[i][j];
                          //System.out.print(b[i][j]+" ");
                      }
                      //System.out.println();
                  }
                  
                  int max = Integer.MIN_VALUE;
                  for(int i=1;i<=n;i++){
                      for(int j=1;j<=n;j++){
                          for(int k=i;k<=n;k++){
                              for(int l=j;l<=n;l++){
                                  max = Math.max(max, b[i-1][j-1]+b[k][l]-b[i-1][l]-b[k][j-1]);
                              }
                          }
                      }
                  }
                  System.out.println(max);
          }
}