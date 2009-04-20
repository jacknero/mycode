public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        long n = sc.nextInt();
        long k = sc.nextInt();
        long r = 0;
        /*
        for(int i=1;i<=n;i++) r += k%i;
        System.out.println(r);
        */
        long n0 = (long)Math.sqrt(n);
        for(int i=1;i<=n0;i++) r += k%i;
        
        // n0 == n
        if(n0==n){
            System.out.println(r);
            return;
        }
        
        // n0 != n
        long c1, c2, r1, r2, q;
        // k = c1 * q + r1
        // k = c2 * q + r2
        c1 = n0 + 1;
        q = k / c1;
        while(true){
            if(q==0) c2 = n;
            else c2 = Math.min(k/q, n);
            
            r1 = k - c1 * q;
            r2 = k - c2 * q;
            r += (r1 + r2) * (c2 - c1 + 1) / 2;
            if(c2==n) break;
            
            c1 = c2 + 1;
            q = k / c1;
        }
        System.out.println(r);
    }
}