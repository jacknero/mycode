import java.util.*;

public class Main {
        public static void main(String[] args) {
                Scanner sc = new Scanner(System.in);
                while(true){
                        int w = sc.nextInt();
                        int h = sc.nextInt();
                        if(w==0&&h==0) break;
                        int[][] inittable = new int[h][w];
                        for(int i=0;i<h;i++){
                                for(int j=0;j<w;j++) inittable[i][j] = sc.nextInt();
                        }
                        
                        Solver sol = new Solver(w,h,inittable);
                        System.out.println(sol.solve());
                }
        }
}

class Solver{
        int w,h;
        int[][] inittable;
        Queue<State> q;
        Solver(int sw,int sh,int[][] stable){
                w = sw;
                h = sh;
                inittable = stable;
        }
        public int solve(){
                // BFS initialize
                q = new LinkedList<State>();
                State init = new State(w,h,inittable);
                q.offer(new State(w,h,inittable));
                // BFS
                while(true){
                        State st= q.poll();
                        if(st.end()){
                                return st.numc;
                        }
                        Locate criticalloc = st.criticalLocate();
                        int ca = criticalloc.a;
                        int cb = criticalloc.b;
                        for(int k=Math.max(h,w);k>0;k--){
                                for(int s=0;s<k;s++){
                                        for(int t=0;t<k;t++){
                                                // if next state is need for BFS, add it to queue
                                                addNextState(st,ca-s,ca+k-s,cb-t,cb+k-t);
                                        }
                                }
                        }
                }
        }
        private void addNextState(State st,int a1,int a2,int b1,int b2){
                if(st.coverable(a1,a2,b1,b2)){
                        State tmp = st.cover(a1,a2,b1,b2);
                        
                        //tmp is need for BFS?
                        boolean tmpneed = true;
                        if(tmp.lesser(st)) tmpneed = false;
                        else{
                                for(State state:q){
                                        if(tmp.lesser(state)){
                                                tmpneed = false;
                                                break;
                                        }
                                }
                        }
                        
                        //when tmp is need add to queue
                        if(tmpneed){
                                q.offer(tmp);
                        }
                }
        }
}

class State{
        int w,h;
        int numc;
        int[][] table;
        State(int sw,int sh,int[][] stable){
                w = sw;
                h = sh;
                numc = 0;
                table = stable;
        }
        State(State s){
                w = s.w;
                h = s.h;
                numc = s.numc;
                table = new int[h][w];
                for(int i=0;i<h;i++){
                        for(int j=0;j<w;j++) table[i][j] = s.table[i][j];
                }
        }
        public boolean end(){
                boolean ret = true;
                for(int i=0;i<h;i++){
                        for(int j=0;j<w;j++){
                                if(table[i][j]==1){
                                        ret = false;
                                }
                        }
                }
                return ret;
        }
        public Locate criticalLocate(){
                for(int i=0;i<h;i++){
                        for(int j=0;j<w;j++){
                                if(table[i][j]==1) return new Locate(i,j);
                        }
                }
                return null; // this code mustn't be executed
        }
        public boolean coverable(int a1,int a2,int b1,int b2){
                if(a1<0||a2>h||b1<0||b2>w) return false;
                
                boolean ret = true;
                for(int i=a1;i<a2;i++){
                        for(int j=b1;j<b2;j++){
                                if(table[i][j]==0){
                                        ret = false;
                                        break;
                                }
                        }
                }
                return ret;
        }
        public State cover(int a1,int a2,int b1,int b2){
                State ret = new State(this);
                for(int i=a1;i<a2;i++){
                        for(int j=b1;j<b2;j++){
                                ret.table[i][j] = -1;
                        }
                }
                ret.numc++;
                return ret;
        }
        public boolean lesser(State s){
                boolean ret = true;
                for(int i=0;i<h;i++){
                        for(int j=0;j<w;j++){
                                if(table[i][j]!=1&&s.table[i][j]==1){
                                        ret = false;
                                        break;
                                }
                        }
                }
                return ret;
        }
}

class Locate{
        int a,b;
        Locate(int pa,int pb){
                a = pa;
                b = pb;
        }
}