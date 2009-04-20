import java.util.*;

public class Main {
    public static final int BEGIN = 8*60;
    public static final int END = 18*60;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            LinkedHashSet<String> locateset = new LinkedHashSet<String>();
            HashMap<String,ArrayList<Edge>> gpre =
                new HashMap<String,ArrayList<Edge>>();
            HashMap<String,ArrayList<Edge>> revgpre =
                new HashMap<String,ArrayList<Edge>>();
            HashMap<String,Edge[]> g = new HashMap<String,Edge[]>();
            HashMap<String,Edge[]> revg = new HashMap<String,Edge[]>();
            for(int i=0;i<n;i++){
                String start = sc.next();
                int starttime = timeToInt(sc.next());
                String arrival = sc.next();
                int arrivaltime = timeToInt(sc.next());
                int cost = sc.nextInt();
                if(!locateset.contains(start)){
                    locateset.add(start);
                    gpre.put(start,new ArrayList<Edge>());
                    revgpre.put(start,new ArrayList<Edge>());
                }
                if(!locateset.contains(arrival)){
                    locateset.add(arrival);
                    gpre.put(arrival,new ArrayList<Edge>());
                    revgpre.put(arrival,new ArrayList<Edge>());
                }
                if(BEGIN<=starttime&&arrivaltime<=END){
                    gpre.get(start)
                        .add(new Edge(arrival,starttime,arrivaltime,cost));
                    revgpre.get(arrival)
                        .add(new Edge(start,-arrivaltime,-starttime,cost));
                }
            }
            
            for(String loc:locateset){
                Edge[] es,reves;
                ArrayList<Edge> ge = gpre.get(loc);
                ArrayList<Edge> revge = revge = revgpre.get(loc);
                es = new Edge[ge.size()];
                reves = new Edge[revge.size()];
                es = ge.toArray(es);
                reves = revge.toArray(reves);
                Arrays.sort(es);
                Arrays.sort(reves);
                g.put(loc,es);
                revg.put(loc,reves);
            }
            
            Solver sol = new Solver(locateset,g,revg);
            if(!locateset.contains("Hakodate")&&!locateset.contains("Tokyo"))
                System.out.println(0);
            System.out.println(sol.solve());
        }
    }
    
    private static int timeToInt(String s){
        int h = Integer.parseInt(s.substring(0,2));
        int m = Integer.parseInt(s.substring(3));
        return 60*h+m;
    }
}

class Solver{
    LinkedHashSet<String> locateset;
    HashMap<String,Edge[]> g;
    HashMap<String,Edge[]> revg;
    HashMap<String,LinkedList<State>> fromTokyo;
    HashMap<String,LinkedList<State>> fromHakodate;
    HashMap<String,LinkedList<State>> revFromTokyo;
    HashMap<String,LinkedList<State>> revFromHakodate;

    Solver(LinkedHashSet<String> locateset,
            HashMap<String, Edge[]> g, HashMap<String, Edge[]> revg) {
        this.locateset = locateset;
        this.g = g;
        this.revg = revg;
        fromTokyo = new HashMap<String,LinkedList<State>>();
        fromHakodate = new HashMap<String,LinkedList<State>>();
        revFromTokyo = new HashMap<String,LinkedList<State>>();
        revFromHakodate = new HashMap<String,LinkedList<State>>();
        for(String loc:locateset){
            fromTokyo.put(loc,new LinkedList<State>());
            fromHakodate.put(loc,new LinkedList<State>());
            revFromTokyo.put(loc,new LinkedList<State>());
            revFromHakodate.put(loc,new LinkedList<State>());
        }
    }
    
    public int solve(){
        makeStateMap(g,"Tokyo",fromTokyo,false);
        makeStateMap(g,"Hakodate",fromHakodate,false);
        makeStateMap(revg,"Tokyo",revFromTokyo,true);
        makeStateMap(revg,"Hakodate",revFromHakodate,true);
        int min = Integer.MAX_VALUE;
        for(String loc:locateset){
            int tmp = localSolve(loc);
            if(min>tmp) min = tmp;
        }
        if(min==Integer.MAX_VALUE) return 0;
        else return min;
    }
    private int localSolve(String locate){
        int min = Integer.MAX_VALUE;
        for(State fromTok:fromTokyo.get(locate)){
            for(State revFromTok:revFromTokyo.get(locate)){
                if((-revFromTok.time)-fromTok.time<30) continue;
                for(State fromHak:fromHakodate.get(locate)){
                    if((-revFromTok.time)-fromHak.time<30) continue;
                    for(State revFromHak:revFromHakodate.get(locate)){
                        if((-revFromHak.time)-fromTok.time<30||
                           (-revFromHak.time)-fromHak.time<30)
                            continue;
                        int cost = fromHak.cost + fromTok.cost +
                                   revFromHak.cost + revFromTok.cost;
                        if(min>cost) min = cost;
                    }
                }
            }
        }
        return min;
    }
    private void makeStateMap(HashMap<String,Edge[]> graph,String startloc,
                              HashMap<String,LinkedList<State>> statemap,
                              boolean reverse){
        Stack<State> st = new Stack<State>();
        State beginstate;
        if(!reverse) beginstate = new State(startloc,Main.BEGIN,0);
        else beginstate = new State(startloc,-Main.END,0);
        addState(statemap,beginstate);
        st.push(beginstate);
        
        while(!st.isEmpty()){
            State tmp = st.pop();
            for(Edge e:graph.get(tmp.locate)){
                if(e.starttime<tmp.time) break;
                
                State next = new State(e.arrival,e.arrivaltime,tmp.cost+e.cost);
                boolean add = addState(statemap,next);
                if(add) st.push(next);
            }
        }
    }
    private boolean addState(HashMap<String,LinkedList<State>> statemap,
                             State addstate){
        LinkedList<State> statelist = statemap.get(addstate.locate);
        ListIterator<State> iter = statelist.listIterator();
        boolean add = true;
        while(iter.hasNext()){
            State s = iter.next();
            if(s.cost>addstate.cost&&s.time>addstate.time){
                iter.remove();
            }
            if(s.cost<addstate.cost&&s.time<addstate.time){
                add = false;
            }
        }
        if(add) statelist.add(addstate);            
        return add;
    }
}

class State{
    String locate;
    int time;
    int cost;
    State(String locate, int time, int cost) {
        this.locate = locate;
        this.time = time;
        this.cost = cost;
    }
}

class Edge implements Comparable<Edge>{
    String arrival;
    int starttime;
    int arrivaltime;
    int cost;
    Edge(String arrival, int starttime, int arrivaltime, int cost) {
        this.arrival = arrival;
        this.starttime = starttime;
        this.arrivaltime = arrivaltime;
        this.cost = cost;
    }
    // to sort edges in descending starttime
    public int compareTo(Edge e){
        return -(this.starttime-e.starttime);
    }
    public boolean equals(Object o){
        Edge e = (Edge)o;
        return this.starttime==e.starttime;
    }
}