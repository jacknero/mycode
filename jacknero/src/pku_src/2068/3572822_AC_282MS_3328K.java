import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            int s = sc.nextInt();
            int[] max = new int[2*n];
            for(int j=0;j<2*n;j++){
                max[j] = sc.nextInt();
            }
            
            boolean[][] table = new boolean[s][2*n];
            for(int j=0;j<2*n;j++) table[0][j] = false;
            for(int i=0;i<s;i++){
                for(int j=0;j<2*n;j++){
                    boolean win = false;
                    for(int k=Math.max(i-max[j],0);k<i;k++){
                        int nextj = (j+1)%(2*n);
                        if(table[k][nextj]==false){
                            win = true;
                            break;
                        }
                    }
                    table[i][j] = win;
                }
            }
            
            if(table[s-1][0]) System.out.println("1");
            else System.out.println("0");
        }
    }
}