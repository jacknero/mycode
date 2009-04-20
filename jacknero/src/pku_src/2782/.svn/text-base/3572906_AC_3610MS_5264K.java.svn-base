import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int b = sc.nextInt();
        int[] ls = new int[n];
        for(int i=0;i<n;i++) ls[i] = sc.nextInt();
        
        Arrays.sort(ls);
        
        int inf = 0;
        int sup = n-1;
        int cnt = 0;
        while(true){
            cnt++;
            int x = ls[sup];
            sup--;
            if(inf>sup) break;
            
            int y = ls[inf];
            if(x+y<=b) inf++;
            if(inf>sup) break;
        }
        System.out.println(cnt);
    }
}