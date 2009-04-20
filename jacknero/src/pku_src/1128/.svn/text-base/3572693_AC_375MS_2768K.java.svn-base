import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            int h = sc.nextInt();
            int w = sc.nextInt();
            char[][] table = new char[h][w];
            for(int i=0;i<h;i++) table[i] = sc.next().toCharArray();
            Solver sol = new Solver(h,w,table);
            sol.printSolution();
        }
    }
}

class Solver{
    int h;
    int w;
    char[][] table;
    int letternum;
    char[] letterset;
    HashMap<Character,Integer> dict;
    boolean[][] less;
    Solver(int h, int w, char[][] table) {
        this.h = h;
        this.w = w;
        this.table = table;
        makeLetterSet();
    }
    public void printSolution(){
        makeLessTable();
        char[] output = new char[letternum];
        boolean[] used = new boolean[letternum];
        Arrays.fill(used,false);
        printSolution(0,output,used);
    }
    private void printSolution(int k,char[] output,boolean[] used){
        if(k==letternum) System.out.println(output);
        for(int i=0;i<letternum;i++){
            if(used[i]) continue;
            output[k] = letterset[i];
            
            boolean cont = false;
            int l = dict.get(output[k]);
            for(int j=0;j<k;j++){
                int m = dict.get(output[j]);
                if(less[l][m]){
                    cont = true;
                    break;
                }
            }
            if(cont) continue;
            
            used[i] = true;
            printSolution(k+1,output,used);
            used[i] = false;
        }
    }
    private void makeLessTable(){
        less = new boolean[letternum][letternum];
        for(int i=0;i<letternum;i++) Arrays.fill(less[i],false);
        
        for(int k=0;k<letternum;k++){
            char c = letterset[k];
            int hmin = h;
            int hmax = -1;
            int wmin = w;
            int wmax = -1;
            for(int i=0;i<h;i++){
                for(int j=0;j<w;j++){
                    if(table[i][j]==c){
                        if(i<hmin) hmin = i;
                        if(i>hmax) hmax = i;
                        if(j<wmin) wmin = j;
                        if(j>wmax) wmax = j;
                    }
                }
            }
            
            for(int i=hmin;i<=hmax;i++){
                if(table[i][wmin]!=c){
                    char d = table[i][wmin];
                    int l = dict.get(d);
                    less[k][l] = true;
                }
                if(table[i][wmax]!=c){
                    char d = table[i][wmax];
                    int l = dict.get(d);
                    less[k][l] = true;
                }
            }
            
            for(int j=wmin;j<=wmax;j++){
                if(table[hmin][j]!=c){
                    char d = table[hmin][j];
                    int l = dict.get(d);
                    less[k][l] = true;
                }
                if(table[hmax][j]!=c){
                    char d = table[hmax][j];
                    int l = dict.get(d);
                    less[k][l] = true;
                }
            }
        }
    }
    private void makeLetterSet(){
        boolean[] find = new boolean[26];
        Arrays.fill(find,false);
        
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(table[i][j]=='.') continue;
                int c = table[i][j] - 'A';
                if(!find[c]) find[c] = true;
            }
        }
        
        int cnt = 0;
        for(int i=0;i<26;i++){
            if(find[i]) cnt++;
        }
        letternum = cnt;
        letterset = new char[letternum];
        
        dict = new HashMap<Character,Integer>();
        cnt = 0;
        for(int i=0;i<26;i++){
            if(find[i]){
                letterset[cnt] = (char)('A'+i);
                dict.put(letterset[cnt],cnt);
                cnt++;
            }
        }
    }
}