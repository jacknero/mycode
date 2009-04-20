import java.util.*;
import java.math.*;
public class Main {
    public static void main(String[] args) {
        int prime[] = new int[80000];
        prime[0] = 2;
        int cnt = 3;
        int index = 1;
        while(index<80000){
            boolean flag = true;
            for(int i=0;i<index;i++){
                if(cnt%prime[i]==0){
                    flag = false;
                    break;
                }
                if(prime[i]*prime[i]>=cnt) break;
            }
            if(flag){
                prime[index] = cnt;
                index++;
            }
            cnt+=2;
        }
        
        //for(int i=0;i<10;i++) System.out.println(prime[i]);
        //System.out.println(prime[79999]);
        
        Scanner sc = new Scanner(System.in);
        while(true){
            BigInteger k = sc.nextBigInteger();
            int l = sc.nextInt();
            if(l==0) break;
            boolean ans = true;
            int ans_p = -1;
                
            for(int i=0;i<80000;i++){
                if(prime[i]>=l) break;
                if(k.remainder(BigInteger.valueOf(prime[i])).signum()==0){
                    ans = false;
                    ans_p = prime[i];
                    break;
                }
            }
            
            if(ans){
                System.out.println("GOOD");
            }
            else{
                System.out.printf("BAD %d\r\n", ans_p);
            }
        }
    }
}