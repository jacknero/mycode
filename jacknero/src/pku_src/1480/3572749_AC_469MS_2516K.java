import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            cnt++;
            
            int x[] = new int[n];
            int y[] = new int[n];
            for(int i=0;i<n;i++){
                x[i] = sc.nextInt();
            }
            for(int i=0;i<n;i++){
                y[i] = sc.nextInt();
            }
            Solver sol = new Solver(n, x, y);
            sol.solve();
            
            System.out.printf("Program %d\r\n", cnt);
            sol.printAnswer();
            System.out.println();
        }
    }
}

class Solver{
    int n;
    int[] x;
    int[] y;
    
    int[][] stack;
    int top;
    
    int[][] save1; // save of stack[][top-1]
    int[][] save2; // save of stack[][top-2]
    int[] savetop; // save of top
    
    int[] prog;
    int[] ans;
    int anslen;
    public Solver(int n, int[] x, int[] y) {
        // TODO Auto-generated constructor stub
        this.n = n;
        this.x = x;
        this.y = y;
        
        stack = new int[n][16];
        for(int i=0;i<n;i++) stack[i][0] = x[i];
        top = 1;
        
        save1 = new int[10][n];
        save2 = new int[10][n];
        savetop = new int[10];
        
        prog = new int[10];
        ans = new int[10];
        anslen = Integer.MAX_VALUE;
    }
    public void solve(){
        search(0);
    }
    public void printAnswer(){
        if(anslen==Integer.MAX_VALUE){
            System.out.println("Impossible");
        }
        else if(anslen==0){
            System.out.println("Empty sequence");
        }
        else{
            for(int i=0;i<anslen;i++){
                switch(ans[i]){
                case 0:
                    System.out.print("ADD ");
                    break;
                case 1:
                    System.out.print("DIV ");
                    break;
                case 2:
                    System.out.print("DUP ");
                    break;
                case 3:
                    System.out.print("MUL ");
                    break;
                case 4:
                    System.out.print("SUB ");
                    break;
                }
            }
            System.out.println();
        }
    }
    public void search(int depth){
        if(depth>=anslen) return;
        if(check()){
            if(depth<anslen){
                anslen = depth;
                for(int i=0;i<anslen;i++) ans[i] = prog[i];
                
                return;
            }
        }
        if(depth<10){
            if(top>=2 && top + depth <=9){
                save(depth); 
                prog[depth] = 0; if(add()) search(depth+1); restore(depth);
                prog[depth] = 1; if(div()) search(depth+1); restore(depth);
                prog[depth] = 2; if(dup()) search(depth+1); restore(depth);
                prog[depth] = 3; if(mul()) search(depth+1); restore(depth);
                prog[depth] = 4; if(sub()) search(depth+1); restore(depth);
            }
            else if(top>=2){
                save(depth);
                prog[depth] = 0; if(add()) search(depth+1); restore(depth);
                prog[depth] = 1; if(div()) search(depth+1); restore(depth);
                prog[depth] = 3; if(mul()) search(depth+1); restore(depth);
                prog[depth] = 4; if(sub()) search(depth+1); restore(depth);
            }
            else if(top + depth<=8){
                save(depth);
                prog[depth] = 2; if(dup()) search(depth+1); restore(depth);
            }
        }
    }
    public boolean add(){
        if(top<2) return false;
        for(int i=0;i<n;i++){
            stack[i][top-2] = stack[i][top-1] + stack[i][top-2];
        }
        top--;
        return notOverflow();
    }
    public boolean div(){
        if(top<2) return false;
        for(int i=0;i<n;i++){
            if(stack[i][top-1]==0) return false;
        }
        for(int i=0;i<n;i++){
            stack[i][top-2] = stack[i][top-2] / stack[i][top-1];
        }
        top--;
        return notOverflow();
    }
    public boolean dup(){
        for(int i=0;i<n;i++){
            stack[i][top] = stack[i][top-1];
        }
        top++;
        return true;
    }
    public boolean mul(){
        if(top<2) return false;
        for(int i=0;i<n;i++){
            stack[i][top-2] = stack[i][top-1] * stack[i][top-2];
        }
        top--;
        return notOverflow();
    }
    public boolean sub(){
        if(top<2) return false;
        for(int i=0;i<n;i++){
            stack[i][top-2] = stack[i][top-2] - stack[i][top-1];
        }
        top--;
        return notOverflow();
    }
    public boolean notOverflow(){
        for(int i=0;i<n;i++){
            if(Math.abs(stack[i][top-1])>30000) return false;
        }
        return true;
    }
    public boolean check(){
        if(top==1){
            for(int i=0;i<n;i++){
                if(stack[i][0]!=y[i]) return false;
            }
            return true;
        }
        return false;
    }
    public void save(int d){
        savetop[d] = top;
        if(top==1){
            for(int i=0;i<n;i++) save1[d][i] = stack[i][0];
        }
        else{
            for(int i=0;i<n;i++){
                save1[d][i] = stack[i][top-1];
                save2[d][i] = stack[i][top-2];
            }
        }
    }
    public void restore(int d){
        top = savetop[d];
        if(top==1){
            for(int i=0;i<n;i++) stack[i][0] = save1[d][i];
        }
        else{
            for(int i=0;i<n;i++){
                stack[i][top-1] = save1[d][i];
                stack[i][top-2] = save2[d][i];
            }
        }
    }
}