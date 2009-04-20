import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashMap<String,Integer> dictionary = new HashMap<String,Integer>();
        while(true){
            String atom = sc.next();
            if(atom.equals("END_OF_FIRST_PART")) break;
            int weight = sc.nextInt();
            dictionary.put(atom,weight);
        }
        
        Solver sol = new Solver(dictionary);
        
        while(true){
            String molecule = sc.next();
            if(molecule.equals("0")) break;
            int ans = sol.solve(molecule);
            if(ans<0) System.out.println("UNKNOWN");
            else System.out.println(ans);
        }
    }
}

class Solver{
    HashMap<String,Integer> dictionary;
    String input;
    int c;
    
    Solver(HashMap<String, Integer> dictionary) {
        // TODO Auto-generated constructor stub
        this.dictionary = dictionary;
    }
    
    public int solve(String input){
        this.input = input.concat("$");
        this.c = 0;
        int ret;
        try{
            return molecule();
        }
        catch(UnknownException e){
            return -1;
        }
    }
    private int molecule() throws UnknownException{
        int ret = 0;
        while(true){
            if(input.charAt(c)==')'|input.charAt(c)=='$'){
                c++;
                break;
            }
            else if(input.charAt(c)=='('){
                c++;
                int m = molecule();
                if(isDisit(input.charAt(c))) m *= number();
                ret += m;
            }
            else{
                int a = atom();
                if(isDisit(input.charAt(c))) a *= number();
                ret += a;
            }
        }
        return ret;
    }
    private int atom() throws UnknownException{
        String a;
        if(isSmall(input.charAt(c+1))){
            a = input.substring(c,c+2);
            c++;
            c++;
        }
        else{
            a = input.substring(c,c+1);
            c++;
        }
        
        if(dictionary.containsKey(a)){
            return dictionary.get(a);
        }
        else{
            throw new UnknownException();
        }
    }
    private int number(){
        int ret;
        if(isDisit(input.charAt(c+1))){
            ret = ctoi(input.charAt(c))*10+ctoi(input.charAt(c+1));
            c++;
            c++;
        }
        else{
            ret = ctoi(input.charAt(c));
            c++;
        }
        return ret;
    }
    private boolean isCapital(char c){
        return 'A'<=c&&c<='Z';
    }
    private boolean isSmall(char c){
        return 'a'<=c&&c<='z';
    }
    private boolean isDisit(char c){
        return '0'<=c&&c<='9';
    }
    private int ctoi(char c){
        return c-'0';
    }
}
class UnknownException extends Exception{
    
}