import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        while(true){
            int f = sc.nextInt();
            if(f==0) break;
            
            int c = cbrt(f);
            
            int c1 = c;
            int c2 = 0;
            int max = csum(c1,c2);
            while(c1>=0){
                if(csum(c1,c2+1)<=f){
                    c2++;
                    if(max<csum(c1,c2)){
                        max=csum(c1,c2);
                    }
                }
                else{
                    c1--;
                }
            }
            
            System.out.println(max);
        }
    }

    private static int cbrt(int f) {
        int root=0;
        root=0;
        while(root*root*root<=f) root++;
        root--;
        return root;
    }
    
    private static int cont1(int n){
        return n*n*n;
    }
    private static int cont2(int n){
        return n*(n+1)*(n+2)/6;
    }
    private static int csum(int n1,int n2){
        return cont1(n1)+cont2(n2);
    }
}