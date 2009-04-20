import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            int c = sc.nextInt();
            if(n==0&&c==0) break;
            int table[][] = new int[n+2][n+2];
            
            for(int j=0;j<n+2;j++) table[0][j] = 10;
            for(int i=1;i<=n;i++){
                table[i][0] = 10;
                for(int j=1;j<=i;j++) table[i][j] = sc.nextInt();
                for(int j=i+1;j<n+2;j++) table[i][j] = 10;
            }
            for(int j=0;j<n+2;j++) table[n+1][j] = 10;
            
            Solver sol = new Solver(n,c,table);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int n;
    int c;
    int[][] table;
    int[][] remove;
    Solver(int n, int c, int[][] table) {
        this.n = n;
        this.c = c;
        this.table = table;
    }
    public int solve(){
        int max = Integer.MIN_VALUE;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                int tmp = put(i,j);
                if(tmp>max) max = tmp;
            }
        }
        return max;
    }
    public int put(int x,int y){
        if(table[x][y]!=0) return Integer.MIN_VALUE;
        
        remove = new int[n+2][n+2];
        for(int i=0;i<n+2;i++){
            for(int j=0;j<n+2;j++){
                remove[i][j] = table[i][j];
            }
        }
        remove[x][y] = c;
        
        computeRemove();
        
        int score = computeScore();
        
        return score;
    }
    
    private int computeScore() {
        int score;
        score = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(remove[i][j]>0){
                    int s = remove[i][j];
                    if(s==c) score--;
                    else score++;
                }
            }
        }
        return score;
    }
    
    private void computeRemove(){
        for(int i=0;i<n;i++) computeRemoveSub();
    }
    
    private void computeRemoveSub(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(remove[i][j]<=0) continue;
                int s = remove[i][j];
                if(remove[i-1][j-1]==0||remove[i-1][j-1]==-s){
                    remove[i][j] = -s;
                    continue;
                }
                if(remove[i-1][j]==0||remove[i-1][j]==-s){
                    remove[i][j] = -s;
                    continue;
                }
                if(remove[i][j-1]==0||remove[i][j-1]==-s){
                    remove[i][j] = -s;
                    continue;
                }
                if(remove[i+1][j+1]==0||remove[i+1][j+1]==-s){
                    remove[i][j] = -s;
                    continue;
                }
                if(remove[i+1][j]==0||remove[i+1][j]==-s){
                    remove[i][j] = -s;
                    continue;
                }
                if(remove[i][j+1]==0||remove[i][j+1]==-s){
                    remove[i][j] = -s;
                    continue;
                }
            }
        }
    }
}