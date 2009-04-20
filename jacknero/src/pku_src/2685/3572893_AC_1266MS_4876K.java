import java.util.*;

public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) {
        // TODO Auto-generated method stub
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            String s1 = sc.next();
            String s2 = sc.next();
            print_mcxi(mcxi_to_int(s1) + mcxi_to_int(s2));
        }
    }
    private static int mcxi_to_int(String s){
        int ret = 0;
        int index = 0;
        int prefix;
        char unit;
        while(index<s.length()){
            char c = s.charAt(index);
            if('2'<=c&&c<='9'){
                prefix = c - '0';
                index++;
                c = s.charAt(index);
            }
            else{
                prefix = 1;
            }
            
            unit = c;
            switch(unit){
            case 'm':
                ret += 1000 * prefix;
                break;
            case 'c':
                ret += 100 * prefix;
                break;
            case 'x':
                ret += 10 * prefix;
                break;
            case 'i':
                ret += prefix;
                break;
            default:
                throw new RuntimeException();
            }
            index++;
        }
        return ret;
    }
    private static void print_mcxi(int x){
        int pm = x/1000;
        int pc = (x/100)%10;
        int px = (x/10)%10;
        int pi = x%10;
        
        if(pm>=2){
            System.out.printf("%dm",pm);
        }
        else if(pm==1){
            System.out.printf("m");
        }
        
        if(pc>=2){
            System.out.printf("%dc",pc);
        }
        else if(pc==1){
            System.out.printf("c");
        }
        
        if(px>=2){
            System.out.printf("%dx",px);
        }
        else if(px==1){
            System.out.printf("x");
        }
        
        if(pi>=2){
            System.out.printf("%di",pi);
        }
        else if(pi==1){
            System.out.printf("i");
        }
        
        System.out.println();
    }
}