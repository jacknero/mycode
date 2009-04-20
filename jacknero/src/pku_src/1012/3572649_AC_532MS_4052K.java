import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int ans[] = new int[14];
        ans[0] = -1;
        for(int i=1;i<14;i++){
            int c = 1;
            while(true){
                if(proper(i, c)){
                    ans[i] = c;
                    break;
                }
                else{
                    c++;
                }
            }
        }
        
        while(true){
            int x = sc.nextInt();
            if(x==0) break;
            System.out.println(ans[x]);
        }
    }
    private static boolean proper (int k, int m){
        int x = 0;
        for(int i=0;i<k;i++){
            x = (x + m - 1) % (2*k-i);
            if(x<k) return false;
        }
        return true;
    }
}