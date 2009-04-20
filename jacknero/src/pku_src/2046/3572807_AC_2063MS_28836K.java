import java.util.*;

class State{
    byte table[][];
    int turn;
    
    public State(byte card[][]){
        int i,j,sx,sy;
        table = new byte[4][8];
        for(i=0;i<4;i++) table[i][0] = (byte)(10*(i+1)+1);
        for(i=0;i<4;i++){
            for(j=1;j<8;j++){
                table[i][j] = card[i][j-1];
            }
        }
        
        for(i=0;i<4;i++){
            for(j=1;j<8;j++){
                if(table[i][j]==11 || table[i][j]==21 
                || table[i][j]==31 || table[i][j]==41)
                table[i][j] = 0;
            }
        }
        turn = 0;
    }
    
    // copy constructor
    public State(State t){
        table = new byte[4][8];
        int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<8;j++){
                table[i][j] = t.table[i][j];
            }
        }
        turn = t.turn;
    }
    
    public boolean canFillGap(int x,int y){
        if(table[x][y] != 0) return false;
        else if(table[x][y-1] == 0 || (table[x][y-1])%10 == 7) return false;
        else return true;
    }
    
    public void fillGap(int x,int y){
        int s,sx,sy,i,j;
        sx = sy = -1;
        
        s = table[x][y-1] + 1;
        
        for(i=0;i<4;i++){
            for(j=0;j<8;j++){
                if(table[i][j] == s){
                    sx = i;
                    sy = j;
                }
            }
        }
        
        table[x][y] = table[sx][sy];
        table[sx][sy] = 0;
        
        turn++;
    }
    
    boolean isEnd(){
        int i,j;
        for(i=0;i<4;i++){
            for(j=0;j<7;j++){
                if(table[i][j]!=(10*(i+1)+(j+1))) return false;
            }
            if (table[i][7]!=0) return false;
        }
        
        return true;
    }
    
    public boolean equals(Object o){
        State s = (State)o;
        int i,j;
        for(i=0;i<4;i++){
            for(j=1;j<8;j++){
                if(table[i][j]!=s.table[i][j]) return false;
            }
        }
        return true;
    }
    
    public int hashCode(){
        int value = 0;
        int i,j;
        for(i=0;i<4;i++){
            for(j=1;j<8;j++){
                value+=table[i][j];
                value*=2;
            }
        }
        
        return value;
    }
}

class Solver{
    State table;
    
    Solver(State t){
        table = new State(t);
    }
    
    int solve(){
        Queue<State> q = new LinkedList<State>();
        HashSet<State> h = new HashSet<State>();
        
        //prepare for BFS
        boolean end = false;
        int ans = Integer.MAX_VALUE;
        int i,j;
        State init = new State(table);
        q.offer(init);
        h.add(init);
        
        if(init.isEnd()) return 0;
        
        //BFS
        while(!q.isEmpty()&&!end){
            State s = q.poll();
            for(i=0;i<4;i++){
                for(j=1;j<8;j++){
                    if(s.canFillGap(i,j)){
                        State temp = new State(s);
                        temp.fillGap(i,j);
                        // find answer
                        if(temp.isEnd()){
                            end = true;
                            ans = temp.turn;
                        }
                        // if unsearched state, add it to queue and hash
                        else if(!h.contains(temp)){
                            q.offer(temp);
                            h.add(temp);
                        }
                    }
                }
            }
        }
        
        if(ans==Integer.MAX_VALUE) ans = -1;
        
        return ans;
    }
}

public class Main{
    public static void main(String args[]){
        int n;
        byte card[][] = new byte [4][7];
        State tb;
        Solver sol;
        int i,j,k;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        for(i=0;i<n;i++){
            for(j=0;j<4;j++){
                for(k=0;k<7;k++){
                    card[j][k] = sc.nextByte();
                }
            }
            tb = new State(card);
            sol = new Solver(tb);
            System.out.println(sol.solve());
        }    
    }
}