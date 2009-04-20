import java.util.*;

public class Main{
    public static void main(String args[]){
        int m,n,c;
        boolean ans;
        Scanner sc = new Scanner(System.in);
        c=0;
        while(true){
            n = sc.nextInt();
            m = sc.nextInt();
            if(n==0) break;
            c++;
            Solver sol = new Solver(n,m);
            ans = sol.solve();
            if(ans){
                System.out.println("Case "+c+": "+n+" lines with exactly "+m+" crossings can cut the plane into "+(n+m+1)+" pieces at most.");
            }
            else{
                System.out.println("Case "+c+": "+n+" lines cannot make exactly "+m+" crossings.");
            }
        } 
    }
}

class Solver{
    int n,m;
    Solver(int n0,int m0){
        n = n0;
        m = m0;
    }
    public boolean solve(){
        return solveMain(n,m,0,n);
    }
    private boolean solveMain(int n,int m,int l,int a){
        if(n==0){
            if(m==0){
                return true;
            }
            else{
                return false;
            }
        }
    
        if(a==1){
            if(m==n*(2*l+n-1)/2){
                return true;
            }
            else{
                return false;
            }
        }
    
        //cut
        int q = n/a;
        if(l*n>m){
            return false;
        }
        if(n*(2*l+n-1)/2<m){
            return false;
        }
    
        //next
        boolean ans = false;
        for(int i=1;i<=a;i++){
            boolean tmp = solveMain(n-i,m-l*i,l+i,i);
            if(tmp){
                ans = true;
                break;
            }
        }
        return ans;
    }
}