import java.util.*;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int cnt = 0;
        for(int m=1;m<=n;m++){
            if(n<(m*(m+1))/2) break;
            if(m%2==1){
                if(n%m==0) cnt++;
            }
            else{
                if((2*n)%m==0&&((2*n)/m)%2==1) cnt++;
            }
        }
        System.out.println(cnt);
    }
}