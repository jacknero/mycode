import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Solver sol = new Solver();
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            System.out.println(sol.solve(n,4,1));
        }
    }
}

class Solver{
    HashSet<Integer> square;
    HashSet<Integer> square2;
    Solver(){
        square = new HashSet<Integer>();
        square2 = new HashSet<Integer>();
        for(int i=1;i<=32768;i++){
            if(presolve(i,1,1)>0) square.add(i);
        }
        for(int i=1;i<=32768;i++){
            if(presolve(i,2,1)>0) square2.add(i);
        }
    }
    
    public int presolve(int n,int m,int a){
        // n==0 m>=0
        if(n==0) return 1;
        // n>0 m==0
        else if(m==0) return 0;
        // n>0 m>0
        else{
            int cnt = 0;
            for(int i=a;i*i<=n;i++){
                cnt += solve(n-i*i,m-1,i);
            }
            return cnt;
        }
    }
    
    public int solve(int n,int m,int a){
        // n==0 m>=0
        if(n==0) return 1;
        // n>0 m==0
        else if(m==0) return 0;
        // n>0 m>0
        else if(m==1){
            if(!square.contains(n)) return 0;
            else if(n>=a*a) return 1;
            else return 0;
        }
        else if(m==2){
            if(!square2.contains(n)) return 0;
            
            int cnt = 0;
            for(int i=a;i*i<=n;i++){
                cnt += solve(n-i*i,m-1,i);
            }
            return cnt;
        }
        else{
            int cnt = 0;
            for(int i=a;i*i<=n;i++){
                cnt += solve(n-i*i,m-1,i);
            }
            return cnt;
        }
    }
}