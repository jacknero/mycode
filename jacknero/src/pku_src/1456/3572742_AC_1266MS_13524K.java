import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int n = sc.nextInt();
            if(n==0) System.out.println("0");
            else{
                Vector<Integer>[]prodset = (Vector<Integer>[])(new Vector<?>[10000]);
                for(int i=0;i<10000;i++) prodset[i] = new Vector<Integer>();
                
                for(int i=0;i<n;i++){
                    int profit = sc.nextInt();
                    int dead = sc.nextInt()-1;
                    prodset[dead].add(profit);
                }
                Solver sol = new Solver(prodset);
                System.out.println(sol.solve());
            }
        }
    }
}

class Solver{
    Vector<Integer>[] prodset;
    
    Solver(Vector<Integer>[] prodset){
        this.prodset = prodset;
    }
    
    public int solve(){
        int sum = 0;
        PriorityQueue<RevInteger> q = new PriorityQueue<RevInteger>();
        for(int i=9999;i>=0;i--){
            if(prodset[i].size()!=0){
                for(int j=0;j<prodset[i].size();j++){
                    q.offer(new RevInteger(prodset[i].get(j)));
                }
            }
            if(!q.isEmpty()){
                sum += q.poll().i;
            }
        }
        return sum;
    }
}

class RevInteger implements Comparable<RevInteger>{
    int i;
    RevInteger(int x){
        i = x;
    }
    public int compareTo(RevInteger r){
        return -(i-r.i);
    }
}