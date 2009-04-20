import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            boolean[][] schedule = new boolean[n][16];
            for(int i=0;i<n;i++){
                for(int j=0;j<16;j++){
                    int s = sc.nextInt();
                    if(s==1) schedule[i][j] = true;
                    else schedule[i][j] = false;
                }
            }
            Solver sol = new Solver(n,schedule);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int n;
    boolean[][] schedule;
    Solver(int n, boolean[][] schedule) {
        this.n = n;
        this.schedule = schedule;
    }
    public int solve(){
        
        Stack<State> st = new Stack<State>();
        HashSet<State> h = new HashSet<State>();
        
        // initial state
        State init = new State();
        if(valid(init)){
            if(end(init)){
                return 1;
            }
            else{
                st.push(init);
                h.add(init);
            }
        }
        
        // DFS
        while(!st.empty()){
            State s = st.pop();
            
            for(int i=0;i<5;i++){
                State next = s.move(i);
                if(valid(next)&&!h.contains(next)){
                    if(end(next)){
                        return 1;
                    }
                    else{
                        st.push(next);
                        h.add(next);
                    }
                }
            }
        }
        
        return 0;
    }
    private boolean valid(State s){    
        int d = s.day;
        boolean[] sch = schedule[d];
        int x = s.cloud%3;
        int y = s.cloud/3;
        if(sch[4*y+x]||sch[4*y+x+1]||sch[4*y+x+4]||sch[4*y+x+5]) return false;
        
        for(int i=0;i<4;i++) if(s.dry[i]>=7) return false;
        
        return true;
    }
    private boolean end(State s){
        if(n-1==s.day) return true;
        else return false;
    }
}

class State{
    int day;
    int cloud;
    int dry[];
    State(){
        day = 0;
        cloud = 4;
        dry = new int[4];
        for(int i=0;i<4;i++) dry[i] = 1;
    }
    State(State s){
        this.day = s.day;
        this.cloud = s.cloud;
        this.dry = new int[4];
        for(int i=0;i<4;i++) this.dry[i] = s.dry[i];
    }
    public State move(int dir){
        State ret = new State(this);
        ret.day++;
        
        int x = ret.cloud%3;
        int y = ret.cloud/3;
        // dir=0,1 N-S direction
        if(dir==0) y = (y+1)%3;
        else if(dir==1) y = (y+2)%3;
        // dir=2,3 E-W direction
        else if(dir==2) x = (x+1)%3;
        else if(dir==3) x = (x+2)%3;
        // dir=4 no move
        
        ret.cloud = y*3+x;
        
        for(int i=0;i<4;i++) ret.dry[i]++;
        ret.rain();
        return ret;
    }
    private void rain(){
        if(cloud==0) dry[0] = 0;
        else if(cloud==2) dry[1] = 0;
        else if(cloud==6) dry[2] = 0;
        else if(cloud==8) dry[3] = 0;
    }
    public boolean equals(Object o){
        State s = (State)o;
        if(this.day!=s.day||this.cloud!=s.cloud) return false;
        for(int i=0;i<4;i++) if(this.dry[i]!=s.dry[i]) return false;
        return true;
    }
    public int hashCode(){
        int ret = day<<20+cloud<<16;
        for(int i=0;i<4;i++) ret += dry[i]<<(4*i);
        return ret;
    }
}