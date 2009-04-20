import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            int[] a = new int[9];
            for(int j=0;j<9;j++){
                long tmp = sc.nextLong(16);
                if(tmp>Integer.MAX_VALUE) tmp -= (long)1<<32;
                a[j] = (int)tmp;
            }
            
            int key = 0;
            for(int j=0;j<32;j++){
                int[] b = new int[9];
                for(int k=0;k<9;k++){
                    b[k] = a[k] ^ key;
                }
                int b07sum = 0;
                for(int k=0;k<8;k++) b07sum += b[k];
                
                int mask = (1<<j);
                if((b07sum&mask)!=(b[8]&mask)) key += (1<<j);
            }
            
            System.out.println(Integer.toHexString(key));
        }
    }
}