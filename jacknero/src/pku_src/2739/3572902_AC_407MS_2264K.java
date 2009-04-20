import java.util.*;

public class Main {
    static final int SIZE = 2000;
    static int[] primetable;
    public static void main(String[] args) {    
        //make prime number table
        makePrimeTable();
        
        //scanner
        Scanner sc = new Scanner(System.in);
    
        //solve
        int x;
        while((x = sc.nextInt())!=0){
            int ans = 0;
            for(int i=0;i<SIZE;i++){
                int sum = 0;
                for(int j=i;j<SIZE;j++){
                    sum += primetable[j];
                    if(x==sum){
                        ans++;
                        break;
                    }
                    if(x<sum) break;
                }
            }
            System.out.println(ans);
        }
    }
    private static void makePrimeTable(){
        primetable = new int[SIZE];
        int i = 0;
        int x = 2;
        
        boolean flag;
        while(i<SIZE){
            flag = false;
            for(int j=0;j<i;j++){
                if(x%primetable[j]==0){
                    x++;
                    flag = true;
                    break;
                }
            }
            if(flag) continue;
            
            primetable[i] = x;
            //System.out.println(x);
            i++;
            x++;
        }
    }
}