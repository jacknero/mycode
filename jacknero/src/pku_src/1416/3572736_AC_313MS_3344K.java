import java.util.*;

public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        while(true){
            int target = sc.nextInt();
            String input = sc.next();
            if(target==0&&input.equals("0")) break;
            int inputlen = input.length();
            int best = -1;
            int bestcut = -1;
            boolean reject = false;
            
            for(int i=0;i<(1<<(inputlen-1));i++){
                int cutval = cut(input,inputlen,i);
                if(cutval<=target){
                    if(cutval>best){
                        best = cutval;
                        bestcut = i;
                        reject = false;
                    }
                    else if(cutval==best){
                        reject = true;
                    }
                }
            }
            
            if(bestcut==-1) System.out.println("error");
            else if(reject) System.out.println("rejected");
            else{
                System.out.printf("%d ",best);
                print_cut(input,inputlen,bestcut);
            }
        }
    }
    private static int cut(String input,int inputlen,int cutcode){
        boolean[] cut = new boolean[inputlen];
        for(int i=0;i<inputlen-1;i++){
            cut[i] = ((cutcode>>i)%2)!=0;
        }
        cut[inputlen-1] = true;
        
        int acc = 0;
        int sum = 0;
        for(int i=0;i<inputlen;i++){
            acc *= 10;
            acc += char_to_int(input.charAt(i));
            if(cut[i]){
                sum += acc;
                acc = 0;
            }
        }
        return sum;
    }
    private static void print_cut(String input,int inputlen,int cutcode){
        boolean[] cut = new boolean[inputlen];
        for(int i=0;i<inputlen-1;i++){
            cut[i] = ((cutcode>>i)%2)!=0;
        }
        cut[inputlen-1] = false;
        
        for(int i=0;i<inputlen;i++){
            System.out.print(input.charAt(i));
            if(cut[i]) System.out.print(' ');
        }
        System.out.println();
    }
    private static int char_to_int(char c){
        return c-'0';
    }
}