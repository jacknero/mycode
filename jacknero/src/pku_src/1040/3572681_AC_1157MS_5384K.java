import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            int m = sc.nextInt();
            int onum = sc.nextInt();
            if(n==0 && m==0 && onum==0) break;
            Order[] os = new Order[onum];
            for(int i=0;i<onum;i++){
                os[i] = new Order(sc.nextInt(), sc.nextInt(), sc.nextInt());
            }
            Solver sol = new Solver(n, m, onum, os);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int n;
    int m;
    int onum;
    Order[] os;
    
    int maxprofit; // 発見した最大利益
    
    public Solver(int n, int m, int onum, Order[] os) {
        // TODO Auto-generated constructor stub
        this.n = n;
        this.m = m;
        this.onum = onum;
        this.os = os;
        Arrays.sort(this.os, new OrderComparator());
        this.maxprofit = Integer.MIN_VALUE;
    }
    public int solve(){
        search();
        return maxprofit;
    }
    private void search(){
        int[] getoff = new int[m+1];
        Arrays.fill(getoff, 0);
        search(0, 0, 0, 0, getoff);
    }
    private void search(int depth, int sta, int profit, int pasnum, int[] getoff){
        if(depth==onum){
            if(profit > maxprofit) maxprofit = profit;
        }
        else{
            Order o = os[depth];
            int nsta = o.start;
            if(sta<nsta){
                for(int i=sta+1;i<=nsta;i++) pasnum -= getoff[i];
            }
            
            int p = (o.dest-o.start)*o.p;
            if(pasnum + o.p<=n){
                getoff[o.dest] += o.p;
                search(depth+1, nsta, profit + p, pasnum+o.p, getoff);
                getoff[o.dest] -= o.p;
                
                search(depth+1, nsta, profit, pasnum, getoff);
            }
            else{
                search(depth+1, nsta, profit, pasnum, getoff);
            }
        }
    }
}

class Order{
    int start;
    int dest;
    int p;
    public Order(int start, int dest, int p) {
        super();
        // TODO Auto-generated constructor stub
        this.start = start;
        this.dest = dest;
        this.p = p;
    }
}

class OrderComparator implements Comparator<Order>{
    OrderComparator(){
        super();
    }
    public int compare(Order o1, Order o2){
        return o1.start - o2.start;
    }
}