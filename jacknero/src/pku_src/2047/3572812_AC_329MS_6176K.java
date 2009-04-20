import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            ArrayList<Request> input = new ArrayList<Request>();
            int daymax = 0;
            for(int i=0;i<n;i++){
                Request r = new Request(sc.nextInt(),sc.nextInt(),sc.nextInt());
                input.add(r);
                if(daymax<r.end) daymax = r.end;
            }
            
            ArrayList<ArrayList<Request>> reqs =
                new ArrayList<ArrayList<Request>>();
            for(int i=0;i<=daymax;i++) reqs.add(new ArrayList<Request>());
            for(int i=0;i<n;i++){
                Request r = input.get(i);
                reqs.get(r.end).add(r);
            }
            
            Solver sol = new Solver(reqs,daymax);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    ArrayList<ArrayList<Request>> reqs;
    int daymax;
    Solver(ArrayList<ArrayList<Request>> reqs, int daymax){
        this.reqs = reqs;
        this.daymax = daymax;
    }
    public int solve(){
        int max[][] = new int[daymax+1][daymax+1];
        max[0][0] = 0;
        for(int k=1;k<=daymax;k++){
            ArrayList<Request> lreqs = reqs.get(k);
            
            // max[k][0]..max[k][k-1]
            for(int i=0;i<k;i++) max[k][i] = max[k-1][i];
            for(int i=0;i<k;i++){
                for(Request r:lreqs){
                    if(max[r.start-1][i]+r.pay>max[k][i])
                        max[k][i] = max[r.start-1][i] + r.pay;
                }
            }
            
            // max[0][k]..max[k-1][k]
            for(int i=0;i<k;i++) max[i][k] = max[k][i];
            
            // max[k][k]
            max[k][k] = max[k-1][k];
            int n = lreqs.size();
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    Request r1 = lreqs.get(i);
                    Request r2 = lreqs.get(j);
                    if(max[r1.start-1][r2.start-1]+r1.pay+r2.pay>max[k][k]){
                        max[k][k] = max[r1.start-1][r2.start-1]+r1.pay+r2.pay;
                    }
                }
            }
        }
        
        return max[daymax][daymax];
    }
}

class Request{
    int start;
    int end;
    int pay;
    Request(int start, int end, int pay) {
        this.start = start;
        this.end = end;
        this.pay = pay;
    }
}