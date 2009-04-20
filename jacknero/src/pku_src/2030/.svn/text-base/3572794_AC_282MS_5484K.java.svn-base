import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int w = sc.nextInt();
            int h = sc.nextInt();
            if(w==0&&h==0) break;
            char[][] table = new char[h][w];
            for(int i=0;i<h;i++){
                String line = sc.next();
                table[i] = line.toCharArray();
            }
            Solver sol = new Solver(w,h,table);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    int w;
    int h;
    char[][] table;
    BigInteger[][] valtable;
    Solver(int sw,int sh,char[][] stable){
        w = sw;
        h = sh;
        table = stable;
        valtable = new BigInteger[h][w];
    }
    public BigInteger solve(){
        for(int i=0;i<Math.min(h,w);i++){
            compute(i,i);
            for(int j=i+1;j<w;j++) compute(i,j);
            for(int j=i+1;j<h;j++) compute(j,i);
        }
        
        BigInteger ret = BigInteger.ZERO;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                ret = ret.max(valtable[i][j]);
            }
        }
        return ret;
    }
    public void compute(int i,int j){
        if(!isDisit(table[i][j])) valtable[i][j] = BigInteger.ZERO;
        else{
            if(i>0&&j>0){
                valtable[i][j] = (valtable[i-1][j].max(valtable[i][j-1]))
                    .multiply(BigInteger.TEN).add(new BigInteger(Character.toString(table[i][j])));
            }
            else if(i>0){
                valtable[i][j] = valtable[i-1][j]
                    .multiply(BigInteger.TEN).add(new BigInteger(Character.toString(table[i][j])));
            }
            else if(j>0){
                valtable[i][j] = valtable[i][j-1]
                    .multiply(BigInteger.TEN).add(new BigInteger(Character.toString(table[i][j])));
            }
            else{
                valtable[i][j] = new BigInteger(Character.toString(table[i][j]));
            }
        }
    }
    public static boolean isDisit(char c){
        if('0'<=c&&c<='9') return true;
        else return false;
    }
}