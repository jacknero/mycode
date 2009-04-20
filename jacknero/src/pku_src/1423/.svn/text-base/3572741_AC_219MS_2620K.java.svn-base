import java.util.*;

public class Main {
    public static void main(String[] args) {
        final int ASIZE = 100000; 
        Scanner sc = new Scanner(System.in);
        int a[] = new int[ASIZE];
        
        double x = 0.0;
        a[0] = 1;
        
        for(int i=1;i<ASIZE;i++){
            x += Math.log10(i);
            a[i] = (int)x + 1;
        }
        // xl = log((ASIZE-1)!)
        double xl = x;
        
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int m = sc.nextInt();
            if(m<ASIZE){
                System.out.println(a[m]);                
            }
            else{
                double y = 
                    xl
                    + (((m+0.5) * Math.log(m+0.5) - (m+0.5))
                            - (((ASIZE-1)+0.5) * Math.log((ASIZE-1)+0.5) - ((ASIZE-1)+0.5)))
                      * Math.log10(Math.E);
                System.out.println((int)y + 1);
            }
        }
    }
}