import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            long n = sc.nextLong();
            int ans = solve(n);
            if(ans==1){
                System.out.println("Stan wins.");
            }
            else{
                System.out.println("Ollie wins.");
            }
        }
    }
    private static int solve(long n){
        if(n==1) return 0;
        
        long m = (long)Math.ceil(n/9.0);
        
        if(m==1) return 1;
        
        long l = (long)Math.ceil(m/2.0);
        
        return solve(l);
    }
}