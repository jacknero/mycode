import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int amax = sc.nextInt();
            int bmax = sc.nextInt();
            int n = sc.nextInt();
            Solver sol = new Solver(amax,bmax,n);
            sol.printSolution();
        }
    }
}

class Solver{

    int amax;
    int bmax;
    int n;
    Queue<State> q;
    HashSet<State> h;
    State suc;
    Solver(int amax, int bmax, int n) {
        this.amax = amax;
        this.bmax = bmax;
        this.n = n;
        this.q = null;
        this.h = null;
        this.suc = null;
    }
    public void printSolution(){
        solve();
        suc.printProcedureLog();
        System.out.println("success");
    }
    private void solve(){
        State.amax = amax;
        State.bmax = bmax;
        q = new LinkedList<State>();
        h = new HashSet<State>();
        State init = new State(0,0);
        q.offer(init);
        h.add(init);
        while(!q.isEmpty()){
            State s = q.poll();
            if(isEnd(s)){
                suc = s;
                break;
            }
            for(int i=0;i<6;i++){
                State next = new State(s,i);
                if(!h.contains(next)){
                    q.offer(next);
                    h.add(next);
                }
            }
        }
        assert suc!=null;
    }
    private boolean isEnd(State s){
        return s.a==n||s.b==n;
    }
}

class State{
    static final int FILL_A = 0;
    static final int FILL_B = 1;
    static final int EMPTY_A = 2;
    static final int EMPTY_B = 3;
    static final int POUR_A_B = 4;
    static final int POUR_B_A = 5;
    static int amax;
    static int bmax;
    int a;
    int b;
    int proc;
    State prev;
    State(int a, int b) {
        // TODO Auto-generated constructor stub
        this.a = a;
        this.b = b;
        this.proc = -1;
        this.prev = null;
    }
    State(State s,int p) {
        // TODO Auto-generated constructor stub
        this.a = s.a;
        this.b = s.b;
        this.proc = p;
        this.prev = s;
        int m;
        switch(p){
        case FILL_A:
            this.a = amax;
            break;
        case FILL_B:
            this.b = bmax;
            break;
        case EMPTY_A:
            this.a = 0;
            break;
        case EMPTY_B:
            this.b = 0;
            break;
        case POUR_A_B:
            m = Math.min(this.a,bmax-this.b);
            this.a -= m;
            this.b += m;
            break;
        case POUR_B_A:
            m = Math.min(amax-this.a,this.b);
            this.a += m;
            this.b -= m;
            break;
        }
    }
    public void printProcedureLog(){
        int m;
        if(proc!=-1) prev.printProcedureLog();
        switch(proc){
        case FILL_A:
            System.out.println("fill A");
            break;
        case FILL_B:
            System.out.println("fill B");
            break;
        case EMPTY_A:
            System.out.println("empty A");
            break;
        case EMPTY_B:
            System.out.println("empty B");
            break;
        case POUR_A_B:
            System.out.println("pour A B");
            break;
        case POUR_B_A:
            System.out.println("pour B A");
            break;
        default:
            // do nothing
        }
    }
    public boolean equals(Object o){
        State s = (State)o;
        return this.a==s.a&&this.b==s.b;
    }
    public int hashCode(){
        return a*1024+b;
    }
}