import java.util.*;

public class Main {
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int cnt = 0;
        while(true){
            int w = sc.nextInt();
            int h = sc.nextInt();
            if(w==0 && h==0) break;
            cnt++;
            char image[][] = new char[h][w];
            for(int i=0;i<h;i++){
                String s = sc.next();
                for(int j=0;j<w;j++){
                    image[i][j] = s.charAt(j);
                }
            }
            Solver sol = new Solver(w, h, image);
            sol.solve();
            System.out.printf("Throw %d\r\n", cnt);
            sol.printAnswer();
            System.out.println();
        }
    }
}

class Solver{
    private int w;
    private int h;
    private char[][] floor;
    private ArrayList<Integer> ans;
    private int cnt;
    public Solver(int w, int h, char[][] floor) {
        // TODO Auto-generated constructor stub
        this.w = w;
        this.h = h;
        this.floor = floor;
        this.ans = new ArrayList<Integer>();
    }
    public void solve(){
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(floor[i][j]=='*' || floor[i][j]=='X'){
                    detectDie(i, j);
                    detectDots(i, j);
                }
            }
        }
    }
    public void printAnswer(){
        Integer ans_array[] = new Integer[ans.size()];
        ans_array = ans.toArray(ans_array);
        Arrays.sort(ans_array);
        for(int i:ans_array){
            System.out.print(i+" ");
        }
        System.out.println();
    }
    private void detectDots(int y, int x){
        cnt = 0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(floor[i][j]=='#'){
                    detectDot(i, j);
                    cnt++;
                }
            }
        }
        ans.add(cnt);
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(floor[i][j]=='@'){
                    floor[i][j] = '.';
                }
            }
        }
    }
    private void detectDot(int y, int x){
        floor[y][x] = '!';
        while(true){
            boolean end = true;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(floor[i][j]=='#'){
                        if(i>0 && floor[i-1][j]=='!'){
                            floor[i][j] = '!';
                            end = false;
                        }
                        else if(i<h-1 && floor[i+1][j]=='!'){
                            floor[i][j] = '!';
                            end = false;
                        }
                        else if(j>0 && floor[i][j-1]=='!'){
                            floor[i][j] = '!';
                            end = false;
                        }
                        else if(j<w-1 && floor[i][j+1]=='!'){
                            floor[i][j] = '!';
                            end = false;
                        }
                    }
                }
            }
            if(end) break;
        }
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(floor[i][j]=='!') floor[i][j] = '@';
            }
        }
    }
    private void detectDie(int y, int x){
        if(floor[y][x]=='*') floor[y][x] = '@';
        else if(floor[y][x]=='X') floor[y][x] = '#';
        else throw new RuntimeException();
        
        while(true){
            boolean end = true;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(floor[i][j]=='*' || floor[i][j]=='X'){
                        if(i>0 && (floor[i-1][j]=='@' || floor[i-1][j]=='#')){
                            if(floor[i][j]=='*') floor[i][j] = '@';
                            else floor[i][j] = '#';
                            end = false;
                        }
                        else if(i<h-1 && (floor[i+1][j]=='@' || floor[i+1][j]=='#')){
                            if(floor[i][j]=='*') floor[i][j] = '@';
                            else floor[i][j] = '#';
                            end = false;
                            
                        }
                        else if(j>0 && (floor[i][j-1]=='@' || floor[i][j-1]=='#')){
                            if(floor[i][j]=='*') floor[i][j] = '@';
                            else floor[i][j] = '#';
                            end = false;
                        }
                        else if(j<w-1 && (floor[i][j+1]=='@' || floor[i][j+1]=='#')){
                            if(floor[i][j]=='*') floor[i][j] = '@';
                            else floor[i][j] = '#';
                            end = false;
                        }
                    }
                }
            }
            if(end) break;
        }
    }
}