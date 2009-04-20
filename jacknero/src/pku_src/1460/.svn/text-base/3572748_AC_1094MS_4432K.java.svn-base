import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            String left = sc.next();
            String right = sc.next();
            Solver sol = new Solver(left,right);
            if(sol.solve()){
                System.out.println("yes");
            }
            else{
                System.out.println("no");
            }
        }
    }
}

class Solver{
    String left;
    String right;
    Solver(String l,String r){
        left = l;
        right = r;
    }
    public boolean solve(){
        int quesnum = countques(left);
        int[] quesloc = new int[quesnum];
        
        int counter = 0;
        for(int i=0;i<left.length();i++){
            if(left.charAt(i)=='?'){
                quesloc[counter] = i;
                counter++;
            }
        }
        
        int rightval = Integer.parseInt(right);
        
        if(quesnum==0){
            Evaluator eval = new Evaluator(left);
            try{
                return rightval==eval.evaluate();
            }
            catch(Exception e){
                return false; // this code mustn't be executed
            }
        }

        for(int i=0;i<1<<(2*quesnum);i++){
            char[] concleftc = left.toCharArray();
            for(int j=0;j<quesnum;j++){
                int symbol = (i>>(2*j))%4;
                switch (symbol){
                case 0:
                    concleftc[quesloc[j]] = '+';
                    break;
                case 1:
                    concleftc[quesloc[j]] = '-';
                    break;
                case 2:
                    concleftc[quesloc[j]] = '*';
                    break;
                case 3:
                    concleftc[quesloc[j]] = '/';
                    break;
                }
            }
            String concleft = new String(concleftc);
            Evaluator eval = new Evaluator(concleft);
            try{
                int leftval = eval.evaluate();
                if(leftval==rightval) return true;
            }
            catch(Exception e){
                // do nothing
            }
        }

        return false;
    }
    private static int countques(String s){
        int len = s.length();
        int counter = 0;
        for(int i=0;i<len;i++){
            if(s.charAt(i)=='?') counter++;
        }
        return counter;
    }
}

class Evaluator{
    String str;
    int size;
    int c;
    Evaluator(String s){
        str = s.concat("$");
        size = s.length();
        c = 0;
    }
    public int evaluate() throws Exception{
        return expr();
    }
    private int expr() throws Exception{
        int ret = term();
        while(true){
            if(str.charAt(c)=='+'){
                c++;
                ret += term();
            }
            else if(str.charAt(c)=='-'){
                c++;
                ret -= term();
            }
            else if(str.charAt(c)==')'||str.charAt(c)=='$'){
                break;
            }
            else{
                //
            }
        }
        return ret;
    }
    private int term() throws Exception{
        int ret = factor();
        while(true){
            if(str.charAt(c)=='*'){
                c++;
                ret *= factor();
            }
            else if(str.charAt(c)=='/'){
                c++;
                int f = factor();
                if(f==0) throw new Exception();
                ret /= f;
            }
            else if(str.charAt(c)=='+'||str.charAt(c)=='-'||
                    str.charAt(c)==')'||str.charAt(c)=='$'){
                break;
            }
            else{
                //
            }
        }
        return ret;
    }
    private int factor() throws Exception{
        if(str.charAt(c)=='('){
            c++;
            int ret = expr();
            c++;
            return ret;
        }
        else{
            int ret = num();
            return ret;
        }
    }
    private int num(){
        int ret = 0;
        while('0'<=str.charAt(c)&&str.charAt(c)<='9'){
            ret = ret*10 + (str.charAt(c)-'0');
            c++;
        }
        return ret;
    }
}