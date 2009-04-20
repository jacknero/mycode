import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        int p = sc.nextInt();
        int q = sc.nextInt();
        int a = sc.nextInt();
        int n = sc.nextInt();
        
        while(n!=0){
            System.out.println(count(p,q,a,n,1));
            
            p = sc.nextInt();
            q = sc.nextInt();
            a = sc.nextInt();
            n = sc.nextInt();
        }
    }
    
    //mは使用できる単位分数の分母の最小値
    private static int count(int p,int q,int a,int n,int m){
        int d = gcd(p,q);
        p = p/d;
        q = q/d;
        
        if(q>a) return 0;
        
        //q<=a
        
        if(n==1){
            if(p==1 && q>=m) return 1;
            else return 0;
        }
        
        int c = 0;
        
        //if p/q is unit fraction, count itself
        if(p==1 && q>=m) c++;
        //count for p/q - 1/r
        for(int r=m;(r*r)<=a;r++){
            if(p*r-q>0) c += count(p*r-q,q*r,a/r,n-1,r);
        }
        return c;
    }
    
    private static int gcd(int x, int y){
        if(x<y) return gcd(y,x);
        else/* x>=y */{
            int r = x % y;
            if(r==0) return y;
            else{
                return gcd(y,r);
            }
        }
    }
}