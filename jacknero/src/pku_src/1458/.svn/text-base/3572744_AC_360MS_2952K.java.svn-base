import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(sc.hasNext()){
            String s1 = sc.next();
            String s2 = sc.next();
            Solver sol = new Solver(s1,s2);
            System.out.println(sol.solve());
        }
    }
}

class Solver{
    String s1;
    String s2;
    Solver(String is1,String is2){
        s1 = is1;
        s2 = is2;
    }
    public int solve(){
        int len1 = s1.length();
        int len2 = s2.length();
        int[][] table = new int[len1+1][len2+1];
        
        for(int i=0;i<=len1;i++) table[i][0] = 0;
        for(int j=0;j<=len2;j++) table[0][j] = 0;
        
        for(int k=1;k<=Math.min(len1,len2);k++){
            if(s1.charAt(k-1)==s2.charAt(k-1)){
                table[k][k] = max3(table[k-1][k-1]+1,table[k][k-1],table[k-1][k]);
            }
            else{
                table[k][k] = max3(table[k-1][k-1],table[k][k-1],table[k-1][k]);
            }
            
            for(int i=k+1;i<=len1;i++){
                if(s1.charAt(i-1)==s2.charAt(k-1)){
                    table[i][k] = max3(table[i-1][k-1]+1,table[i][k-1],table[i-1][k]);
                }
                else{
                    table[i][k] = max3(table[i-1][k-1],table[i][k-1],table[i-1][k]);
                }
            }
            
            for(int j=k+1;j<=len2;j++){
                if(s1.charAt(k-1)==s2.charAt(j-1)){
                    table[k][j] = max3(table[k-1][j-1]+1,table[k][j-1],table[k-1][j]);
                }
                else{
                    table[k][j] = max3(table[k-1][j-1],table[k][j-1],table[k-1][j]);
                }
            }
        }
        
        return table[len1][len2];
    }
    public static int max3(int x,int y,int z){
        return Math.max(x,Math.max(y,z));
    }
}