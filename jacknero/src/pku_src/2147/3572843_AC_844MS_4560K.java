import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int s=0;s<n;s++){
            int top[][] = new int[3][3];
            int front[][] = new int[3][3];
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    top[i][j] = sc.nextInt();
                }
            }
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    front[i][j] = sc.nextInt();
                }
            }
            
            Solver sol = new Solver(top, front);
            ArrayList<Integer> ans = sol.solve();
            if(ans.size()>0){
                Integer[] aans = new Integer[ans.size()];
                aans = ans.toArray(aans);
                Arrays.sort(aans);
                for(int x:aans){
                    System.out.print(x+" ");
                    // Caution! x+' ' is x+32
                }
                System.out.println();                
            }
            else{
                System.out.println(0);
            }
        }
    }
}

class Solver {
    private static final int pat[][] =
    {
        {1,2,3,5,4,6},
        {1,4,2,3,5,6},
        {1,5,4,2,3,6},
        {1,3,5,4,2,6},
        {2,6,3,1,4,5},
        {2,3,1,4,6,5},
        {2,1,4,6,3,5},
        {2,4,6,3,1,5},
        {3,1,2,6,5,4},
        {3,2,6,5,1,4},
        {3,6,5,1,2,4},
        {3,5,1,2,6,4},
        {4,1,5,6,2,3},
        {4,5,6,2,1,3},
        {4,6,2,1,5,3},
        {4,2,1,5,6,3},
        {5,6,4,1,3,2},
        {5,4,1,3,6,2},
        {5,1,3,6,4,2},
        {5,3,6,4,1,2},
        {6,2,4,5,3,1},
        {6,4,5,3,2,1},
        {6,5,3,2,4,1},
        {6,3,2,4,5,1}
    };
    private int cube[][][][];
    int top[][];
    int front[][];
    ArrayList<Integer> ans;
    public Solver(int[][] top, int[][] front) {
        this.top = top;
        this.front = front;
        cube = new int[3][3][3][6];
        ans = new ArrayList<Integer>();
    }
    public ArrayList<Integer> solve(){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    Arrays.fill(cube[i][j][k], 0);
                }
            }
        }
        
        for(int i=0;i<3;i++){
            for(int k=0;k<3;k++){
                cube[i][0][k][0] = top[2-i][k];
            }
        }
        for(int j=0;j<3;j++){
            for(int k=0;k<3;k++){
                cube[0][j][k][1] = front[j][k];
            }
        }
        
        search(0);
        
        return ans;
    }
    public void search(int index){
        if(index==27){
            int sum = rightSum();
            if(!ans.contains(sum)) ans.add(sum);
        }
        else{
            int i = (index/9)%3;
            int j = (index/3)%3;
            int k = index%3;
            
            int cond[] = new int[6];
            Arrays.fill(cond, 0);
            for(int f=0;f<6;f++) cond[f] = cube[i][j][k][f];
            if(i>0){
                cond[1] = cube[i-1][j][k][1];
            }
            if(j>0){
                cond[0] = cube[i][j-1][k][0];
            }
            if(k>0){
                cond[2] = cube[i][j][k-1][2];
            }
            ArrayList<Integer> pats = cond_to_pats(cond);
            // for(int f=0;f<6;f++) System.out.print(cond[f]+" ");
            // System.out.println("index:"+index+"size:"+pats.size());
            for(int p:pats){
                int[] ori = new int[6];
                for(int f=0;f<6;f++) ori[f] = cube[i][j][k][f];
                for(int f=0;f<6;f++) cube[i][j][k][f] = pat[p][f];
                search(index+1);
                for(int f=0;f<6;f++) cube[i][j][k][f] = ori[f];
            }
        }
    }
    // 与えられた条件をみたすパターンのリストを返す
    private static ArrayList<Integer> cond_to_pats(int[] cond){
        ArrayList<Integer> ret = new ArrayList<Integer>();
        for(int i=0;i<24;i++){
            boolean flag = true;
            for(int j=0;j<6;j++){
                if(cond[j]!=0 && pat[i][j]!=cond[j]) flag = false;
            }
            if(flag) ret.add(i);
        }
        return ret;
    }
    public int rightSum(){
        int ret = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                ret += cube[i][j][2][2];
            }
        }
        // System.out.println("r:"+ret);
        return ret;
    }
}