import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            int a[] = new int[n];
            for(int i=0;i<n;i++){
                a[i] = sc.nextInt() - 1;
            }
            Solver sol = new Solver(n, a);
            while(true){
                int k = sc.nextInt();
                if(k==0) break;
                String s = sc.nextLine().substring(1);
                char[] cs = new char[n];
                for(int i=0;i<s.length();i++){
                    cs[i] = s.charAt(i);
                }
                for(int i=s.length();i<n;i++){
                    cs[i] = ' ';
                }
                System.out.println(sol.encode(cs, k));
            }
            System.out.println();
        }
    }
}
class Solver {
    int n;
    int as[];
    int os[];
    public Solver(int n, int[] as) {
        this.n = n;
        this.as = as;
        this.os = new int[n];
        for(int i=0;i<n;i++) os[i] = i;
    }
    public String encode(char[] cs, int k){
        char[] rs = new char[n];
        int[] bs = exp(as, k);
        for(int i=0;i<n;i++){
            rs[bs[i]] = cs[i];
        }
        return new String(rs);
    }
    public int[] exp(int[] as, int k){
        //System.out.println("k:"+k);
        if(k==0) return os;
        else if(k==1) return as;
        else{
            if(k%2==0){
                int[] bs = exp(as, k/2);
                return mul(bs, bs);
            }
            else{
                return mul(exp(as, k-1), as);
            }
        }
    }
    public int[] mul(int[] as, int[] bs){
        int[] cs = new int[n];
        for(int i=0;i<n;i++) cs[i] = bs[as[i]];
        return cs;
    }
}