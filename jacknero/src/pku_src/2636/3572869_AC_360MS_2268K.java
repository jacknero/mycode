import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int k = sc.nextInt();
            int sum = 0;
            for(int j=0;j<k;j++) sum += sc.nextInt();
            sum -= k-1;
            System.out.println(sum);
        }
    }
}