import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int p = sc.nextInt();
        int[] simplest = new int[p];
        Arrays.fill(simplest,0);
        boolean[] hardest = new boolean[p];
        Arrays.fill(hardest,false);
        for(int i=0;i<n;i++){
            int[] rating = new int[p];
            int min = 1001;
            int max = -1;
            for(int j=0;j<p;j++){
                rating[j] = sc.nextInt();
                if(min>rating[j]) min = rating[j];
                if(max<rating[j]) max = rating[j];
            }
            for(int j=0;j<p;j++){
                if(min==rating[j]) simplest[j]++;
                if(max==rating[j]) hardest[j] = true;
            }
        }
        boolean noverysimple = true;
        for(int i=0;i<p;i++){
            if(simplest[i]*2>n&&!hardest[i]){
                System.out.print((i+1)+" ");
                noverysimple = false;
            }
        }
        if(noverysimple) System.out.println(0);
        else System.out.println();
    }
}