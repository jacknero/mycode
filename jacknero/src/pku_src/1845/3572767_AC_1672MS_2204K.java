import java.util.*;

public class Main {
    final static int M = 9901;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        
        int[] prime = new int[3000];
        makePrimeTable(prime);
        // prime[2999] = 27449
        
        int a = sc.nextInt();
        int b = sc.nextInt();
        int ans;
        if(a!=0){
            Vector<IntPair> v = new Vector<IntPair>();
            factorization(a,v,prime);
            for(IntPair p:v){
                p.fst %= M;
                p.snd *= b;
            }
            
            ans = 1;
            for(IntPair p:v){
                int pa = p.fst;
                int pb = p.snd;
                // pb = k*(M-1) + r;
                int k = pb/(M-1);
                k %= M;
                int r = pb%(M-1);
                int product;
                if(pa==0) product = 1;
                else if(pa==1) product = (M-1)*k + expsum(pa,r);
                else product = expsum(pa,r);
                product %= M;
                ans *= product;
                ans %= M;
            }
        }
        else ans = 0;
        
        System.out.println(ans);
    }
    
    private static int expsum(int x,int n){
        int ret = 1;
        int add = 1;
        for(int i=1;i<=n;i++){
            add *= x;
            add %= M;
            ret += add;
            ret %= M;
        }
        return ret;
    }

    private static void factorization(int x,Vector<IntPair> v,int[] prime){
        for(int i=0;/*i<prime.length&&*/prime[i]*prime[i]<=x;i++){
            int cnt = 0;
            while(x%prime[i]==0){
                x /= prime[i];
                cnt++;
            }
            v.add(new IntPair(prime[i],cnt));
            if(x==1) break;
        }
        if(x!=1) v.add(new IntPair(x,1));
    }
    private static void makePrimeTable(int[] prime){
        int x = 2;
        int cnt = 0;
        while(cnt<prime.length){
            boolean divided = false;
            for(int i=0;i<cnt&&prime[i]*prime[i]<=x;i++){
                if(x%prime[i]==0){
                    divided = true;
                    break;
                }
            }
            if(!divided){
                prime[cnt] = x;
                cnt++;
            }
            x++;
        }
    }
}

class IntPair{
    int fst;
    int snd;
    public IntPair(int fst, int snd) {
        this.fst = fst;
        this.snd = snd;
    }
}