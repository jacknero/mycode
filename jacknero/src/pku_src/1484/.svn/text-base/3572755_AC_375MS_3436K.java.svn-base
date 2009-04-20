import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        while(true){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int c = sc.nextInt();
            
            if(n==0 && m==0 && c==0) break;
            
            cnt++;
            int dev_consume[] = new int[n];
            boolean dev_on[] = new boolean[n];
            int toggle[] = new int[m];
            
            for(int i=0;i<n;i++){
                dev_consume[i] = sc.nextInt();
            }
            Arrays.fill(dev_on, false);
            for(int i=0;i<m;i++){
                toggle[i] = sc.nextInt() - 1;
            }
            
            int total = 0;
            int max = 0;
            boolean blowup = false;
            for(int i=0;i<m;i++){
                int k = toggle[i];
                if(dev_on[k]){
                    dev_on[k] = false;
                    total -= dev_consume[k];
                }
                else{
                    dev_on[k] = true;
                    total += dev_consume[k];
                }
                
                if(total>c){
                    blowup = true;
                    break;
                }
                else max = Math.max(max, total);
            }
            
            System.out.printf("Sequence %d\r\n", cnt);
            if(blowup){
                System.out.println("Fuse was blown.");
            }
            else{
                System.out.println("Fuse was not blown.");
                if(max<=1) System.out.printf("Maximal power consumption was %d amperes.\r\n", max);
                else System.out.printf("Maximal power consumption was %d amperes.\r\n", max);
            }
            System.out.println();
        }
    }
}