import java.util.*;

public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int g = sc.nextInt();
            int a[] = new int[g];
            for(int j=0;j<g;j++){
                a[j] = sc.nextInt();
            }
            Arrays.sort(a);

            boolean[] ans = new boolean[1000000];
            Arrays.fill(ans, true);
            ans[0] = false;
            
            if(g==1) System.out.println(1);
            else{
                for(int k=0;k<g;k++){
                    for(int l = k+1;l<g;l++){
                        int x = a[l] - a[k];
                        if(ans[x]==false) continue;
                        for(int m=1;m*m<=x;m++){
                            if(x%m==0){
                                ans[m] = false;
                                ans[x/m] = false;
                            }
                        }
                    }
                }
                
                for(int m=1;m<=1000000;m++){
                    if(ans[m]){
                        System.out.println(m);
                        break;
                    }
                }
            }
        }
    }
}