import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            boolean[][] adj = new boolean[n][n];
            for(int i=0;i<n;i++) Arrays.fill(adj[i],false);
            
            for(int i=0;i<n;i++){
                String line = sc.next();
                for(int j=2;j<line.length();j++){
                    int c = line.charAt(j)-'A';
                    adj[i][c] = true;
                    adj[c][i] = true;
                }
            }
            
            if(colorable1(adj,n)) System.out.println("1 channel needed.");
            else if(colorable2(adj,n)) System.out.println("2 channels needed.");
            else if(colorable3(adj,n)) System.out.println("3 channels needed.");
            else System.out.println("4 channels needed.");
        }
    }
    public static boolean colorable1(boolean[][] adj,int n){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(adj[i][j]) return false;
            }
        }
        return true;
    }
    public static boolean colorable2(boolean[][] adj,int n){
        int[] col = new int[n];
        return colorable2(adj,n,col,0);
    }
    public static boolean colorable2(boolean[][] adj,int n,int[] col,int k){
        if(k==n) return true;
        
        col[k] = 0;
        boolean cont = false;
        for(int i=0;i<k;i++){
            if(adj[i][k]&&col[i]==col[k]){
                cont = true;
                break;
            }
        }
        if(!cont){
            if(colorable2(adj,n,col,k+1)) return true;
        }
        
        col[k] = 1;
        cont = false;
        for(int i=0;i<k;i++){
            if(adj[i][k]&&col[i]==col[k]){
                cont = true;
                break;
            }
        }
        if(!cont){
            if(colorable2(adj,n,col,k+1)) return true;
        }
        
        return false;
    }
    public static boolean colorable3(boolean[][] adj,int n){
        int[] col = new int[n];
        return colorable3(adj,n,col,0);
    }
    public static boolean colorable3(boolean[][] adj,int n,int[] col,int k){
        if(k==n) return true;
        
        col[k] = 0;
        boolean cont = false;
        for(int i=0;i<k;i++){
            if(adj[i][k]&&col[i]==col[k]){
                cont = true;
                break;
            }
        }
        if(!cont){
            if(colorable3(adj,n,col,k+1)) return true;
        }
        
        col[k] = 1;
        cont = false;
        for(int i=0;i<k;i++){
            if(adj[i][k]&&col[i]==col[k]){
                cont = true;
                break;
            }
        }
        if(!cont){
            if(colorable3(adj,n,col,k+1)) return true;
        }
        
        col[k] = 2;
        cont = false;
        for(int i=0;i<k;i++){
            if(adj[i][k]&&col[i]==col[k]){
                cont = true;
                break;
            }
        }
        if(!cont){
            if(colorable3(adj,n,col,k+1)) return true;
        }
        
        return false;
    }
}