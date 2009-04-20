import java.util.*;
public class Main {
    static final double EPSILON = 1.0E-6;
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        while(true){
            int k = sc.nextInt();
            if(k==0) break;
            
            double a[] = new double[k];
            for(int i=0;i<k;i++) a[i] = sc.nextDouble();
            Arrays.sort(a);
            
            if(k==1){
                System.out.println("NO");
                continue;
            }
            
            boolean end = false;
            for(int i=1;i<k;i++){
                double sum = 0;
                for(int j=0;j<i;j++) sum += a[j];
                if(sum - a[i] > -EPSILON){
                    System.out.println("YES");
                    end = true;
                    break;
                }
                if(end) break;
            }
            if(end) continue;
            else System.out.println("NO");
        }
    }
}