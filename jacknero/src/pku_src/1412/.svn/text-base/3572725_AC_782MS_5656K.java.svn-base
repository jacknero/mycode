import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            String ans = sc.nextLine();
            if(ans.equals(".")) break;
            Polynomial anspoly = (new Evaluator(ans)).evaluate();
            while(true){
                String sample = sc.nextLine();
                if(sample.equals(".")) break;
                Polynomial samplepoly = (new Evaluator(sample)).evaluate();
                if(anspoly.equivalent(samplepoly)) System.out.println("yes");
                else System.out.println("no");
            }
            System.out.println(".");
        }
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
    public Polynomial evaluate(){
        return expr();
    }
    private Polynomial expr(){
        Polynomial ret = term();
        while(true){
            while(str.charAt(c)==' ') c++;
            if(str.charAt(c)=='+'){
                c++;
                ret = ret.plus(term());
            }
            else if(str.charAt(c)=='-'){
                c++;
                ret = ret.minus(term());
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
    private Polynomial term(){
        Polynomial ret = factor();
        while(true){
            while(str.charAt(c)==' ') c++;
            if(str.charAt(c)=='+'||str.charAt(c)=='-'||
                    str.charAt(c)==')'||str.charAt(c)=='$'){
                break;
            }
            else{
                ret = ret.mul(factor());
            }
        }
        return ret;
    }
    private Polynomial factor(){
        while(str.charAt(c)==' ') c++;
        if(str.charAt(c)=='('){
            c++;
            Polynomial ret = expr();
            c++;
            return ret;
        }
        else{
            if('0'<=str.charAt(c)&&str.charAt(c)<='9'){
                int retnum = num();
                Polynomial ret = new Polynomial(retnum);
                return ret;
            }
            else{
                Polynomial ret = atom();
                return ret;
            }
        }
    }
    private int num(){
        int retnum = 0;
        while('0'<=str.charAt(c)&&str.charAt(c)<='9'){
            retnum = retnum*10 + (str.charAt(c)-'0');
            c++;
        }
        return retnum;
    }
    private Polynomial atom(){
        char v = str.charAt(c);
        c++;
        while(str.charAt(c)==' ') c++;
        if(str.charAt(c)=='^'){
            c++;
            while(str.charAt(c)==' ') c++;
            int k = num();
            return new Polynomial(v,k);
        }
        else{
            return new Polynomial(v,1);
        }
    }
}

class Polynomial{
    TreeSet<Term> terms;
    public Polynomial(){
        terms = new TreeSet<Term>();
    }
    public Polynomial(int x){
        terms = new TreeSet<Term>();
        if(x!=0) terms.add(new Term(x));
    }
    public Polynomial(char v,int k){
        terms = new TreeSet<Term>();
        terms.add(new Term(v,k));
    }
    public Polynomial(Polynomial p){
        terms = new TreeSet<Term>(p.terms);
    }
    public boolean equivalent(Polynomial p){
        Polynomial p1 = new Polynomial(this);
        Polynomial p2 = new Polynomial(p);
        Polynomial sub = p1.minus(p2);
        return sub.terms.isEmpty();
    }
    public void add(Term t){
        if(terms.contains(t)){
            Term s = terms.tailSet(t).first();
            Term c = s.contract(t);
            terms.remove(s);
            if(c.coefficient!=0)terms.add(c);
        }
        else terms.add(t);
    }
    public Polynomial mul(Polynomial p){
        Polynomial ret = new Polynomial();
        for(Term t:this.terms){
            for(Term s:p.terms){
                ret.add(t.mul(s));
            }
        }

        return ret;
    }
    public Polynomial plus(Polynomial p){
        Polynomial ret = new Polynomial();
        for(Term t:this.terms) ret.add(t);
        for(Term t:p.terms) ret.add(t);
        
        return ret;
    }
    public Polynomial minus(Polynomial p){
        Polynomial ret = new Polynomial();
        for(Term t:this.terms) ret.add(t);
        for(Term t:p.terms) ret.add(t.neg());
        
        return ret;
    }
}

class Term implements Comparable<Term>{
    int coefficient;
    int pow[] = new int[26];
    
    public boolean equals(Object o){
        Term t = (Term)o;
        for(int i=0;i<26;i++){
            if(this.pow[i]!=t.pow[i]) return false;
        }
        return true;
    }
    
    public int compareTo(Term t){
        for(int i=0;i<26;i++){
            if(this.pow[i]!=t.pow[i]) return this.pow[i]-t.pow[i];
        }
        return 0;
    }
    
    //integer x
    public Term(int x){
        coefficient = x;
        for(int i=0;i<26;i++) pow[i] = 0;
    }
    
    //term a^k
    public Term(char v,int k){
        coefficient = 1;
        for(int i=0;i<26;i++) pow[i] = 0;
        pow[v-'a'] = k;
    }
    
    public Term mul(Term t){
        Term ret = new Term(0);
        for(int i=0;i<26;i++) ret.pow[i] = this.pow[i]+t.pow[i];
        ret.coefficient = this.coefficient*t.coefficient;
        return ret;
    }
    
    public boolean contractable(Term t){
        Term ret = new Term(0);
        for(int i=0;i<26;i++){
            if(this.pow[i]!=t.pow[i]) return false;
        }
        return true;
    }
    
    public Term contract(Term t){
        Term ret = new Term(0);
        for(int i=0;i<26;i++) ret.pow[i] = this.pow[i];
        ret.coefficient = this.coefficient + t.coefficient;
        return ret;
    }
    
    public Term neg(){
        Term ret = new Term(0);
        for(int i=0;i<26;i++) ret.pow[i] = this.pow[i];
        ret.coefficient = -this.coefficient;
        return ret;
    }
}