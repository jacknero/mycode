import java.util.*;
public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        while(true){
            int n = sc.nextInt();
            int m = sc.nextInt();
            if(n==0 && m==0) break;
            cnt++;
            
            Patch ps[] = new Patch[m];
            for(int k=0;k<m;k++){
                int time = sc.nextInt();
                String sconds = sc.next();
                String seffects = sc.next();
                int[] conds = new int[n];
                int[] effects = new int[n];
                for(int i=0;i<n;i++){
                    if(sconds.charAt(i)=='+') conds[i] = 1;
                    else if(sconds.charAt(i)=='-') conds[i] = -1;
                    else if(sconds.charAt(i)=='0') conds[i] = 0;
                    else throw new RuntimeException();
                }
                for(int i=0;i<n;i++){
                    if(seffects.charAt(i)=='+') effects[i] = 1;
                    else if(seffects.charAt(i)=='-') effects[i] = -1;
                    else if(seffects.charAt(i)=='0') effects[i] = 0;
                    else throw new RuntimeException();
                }
                ps[k] = new Patch(time, conds, effects);
            }
            
            Solver sol = new Solver(n, m, ps, cnt);
            sol.printSolution();
            //System.out.println("FreeMemory:"+Runtime.getRuntime().freeMemory());
            //System.out.println("TotalMemory"+Runtime.getRuntime().totalMemory());
        }
    }
}

class Solver{
    int n;
    int m;
    Patch[] ps;
    int cnt;
    public Solver(int n, int m, Patch[] ps, int cnt) {
        super();
        // TODO Auto-generated constructor stub
        this.n = n;
        this.m = m;
        this.ps = ps;
        this.cnt = cnt;
    }
    public void printSolution(){
        int ans = -1;
        PriorityQueue<State> q = new PriorityQueue<State>();
        int[] h = new int[(2<<n)-1];
        for(int i=0;i<h.length;i++) h[i] = -1;
        
        State s0 = new State(n);
        q.offer(s0);
        h[s0.bugcode()] = s0.time;
        
        int debugcnt = 0;
        int maxq = 1;
        while(!q.isEmpty()){
            maxq = Math.max(maxq, q.size());
            State s = q.poll();
            debugcnt++;
            //for(int i=0;i<s.bugnum;i++) System.out.print(s.bugs[i]);
            //System.out.println();
            if(s.isEnd()){
                ans = s.time;
                break;
            }
            
            for(Patch p:ps){
                State t = s.apply(p);
                if(t==null) continue;
                else{
                    if(h[t.bugcode()]!=-1){
                        int otime = h[t.bugcode()];
                        if(t.time<otime){
                            h[t.bugcode()] = t.time;
                            State ot = new State(otime, t.bugcode(), m);                
                            q.remove(ot);
                            
                            q.offer(t);
                        }
                    }
                    else{
                        h[t.bugcode()] = t.time;
                        q.offer(t);
                    }
                }
            }
        }
        System.out.printf("Product %d\r\n", cnt);
        //System.out.printf("debugcnt:%d\r\n", debugcnt);
        //System.out.printf("maxq:%d\r\n", maxq);
        if(ans==-1){
            System.out.println("Bugs cannot be fixed.");
        }
        else{
            System.out.printf("Fastest sequence takes %d seconds.\r\n", ans);
        }
        System.out.println();
    }
}

class State implements Comparable<State>{
    int time;
    int bugcode;
    int bugnum;
    public State(int bugnum){
        this.time = 0;
        bugcode = 0;
        for(int i=0;i<bugnum;i++) setBug(i);
        this.bugnum = bugnum;
    }
    public State(int time, int bugcode, int bugnum) {
        // TODO Auto-generated constructor stub
        this.time = time;
        this.bugcode = bugcode;
        this.bugnum = bugnum;
    }
    public boolean hasBug(int i){
        if(((bugcode>>i)&1) == 1) return true;
        else return false;
    }
    public void setBug(int i){
        bugcode |= (1<<i);
    }
    public void unsetBug(int i){
        bugcode &= (Integer.MAX_VALUE - (1<<i));
    }
    public boolean isEnd(){
        for(int i=0;i<bugnum;i++) if(hasBug(i)) return false;
        return true;
    }
    public State apply(Patch p){
        for(int i=0;i<bugnum;i++){
            if(hasBug(i) && p.conds[i]==-1) return null;
            else if(!hasBug(i) && p.conds[i]==1) return null;
        }
        State ret = new State(p.time+time, bugcode, bugnum);
        for(int i=0;i<bugnum;i++){
            if(p.effects[i]==1) ret.setBug(i);
            else if(p.effects[i]==-1) ret.unsetBug(i);
        }
        return ret;
    }
    public int compareTo(State s){
        return this.time - s.time;
    }
    public boolean equals(Object o){
        State s = (State)o;
        return (this.bugcode==s.bugcode)&&(this.time==s.time);
    }
    public int bugcode(){
        return bugcode;
    }
}

class Patch{
    int time;
    int[] conds;
    int[] effects;
    public Patch(int time, int[] conds, int[] effects) {
        // TODO Auto-generated constructor stub
        this.time = time;
        this.conds = conds;
        this.effects = effects;
    }
}