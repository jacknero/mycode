import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            // make dictionary
            HashMap<String,ArrayList<String>> dictionary = 
                new HashMap<String,ArrayList<String>>();
            for(int i=0;i<n;i++){
                String word = sc.next();
                String seq = toButtonSequence(word);
                if(dictionary.containsKey(seq)){
                    dictionary.get(seq).add(word);
                }
                else{
                    dictionary.put(seq,new ArrayList<String>());
                    dictionary.get(seq).add(word);
                }
            }
            
            // analyze input sequence
            String input = sc.next();
            Stack<State> st = new Stack<State>();
            TreeSet<Sentence> sentenceset = new TreeSet<Sentence>();
            st.push(new State(input));
            while(!st.empty()){
                State state = st.pop();
                if(state.isEnd()){
                    String[] sentence = new String[state.rwords.size()];
                    sentence = state.rwords.toArray(sentence);
                    sentenceset.add(new Sentence(sentence));
                }
                for(int i=1;i<=50&&i<=state.buffer.length();i++){
                    String rbuf = state.buffer.substring(0,i);
                    if(dictionary.containsKey(rbuf)){
                        ArrayList<String> hitwordlist = dictionary.get(rbuf);
                        for(String w:hitwordlist){
                            State newstate = new State(state);
                            newstate.buffer = newstate.buffer.substring(i);
                            newstate.rwords.add(w);
                            st.push(newstate);
                        }
                    }
                }
            }
            
            //output
            for(Sentence set:sentenceset){
                String[] words = set.words;
                int wordnum = words.length;
                for(int i=0;i<wordnum;i++){
                    if(i==wordnum-1) System.out.print(words[i]);
                    else System.out.print(words[i]+" ");
                }
                System.out.println(".");
            }
            System.out.println("--");
        }
    }

    public static char toButton(char c){
        if     (c<='c') return '2';
        else if(c<='f') return '3';
        else if(c<='i') return '4';
        else if(c<='l') return '5';
        else if(c<='o') return '6';
        else if(c<='s') return '7';
        else if(c<='v') return '8';
        else            return '9';
    }
    public static String toButtonSequence(String s){
        char[] seq = new char[s.length()];
        for(int i=0;i<s.length();i++){
            seq[i] = toButton(s.charAt(i));
        }
        return new String(seq);
    }
}

class State{
    ArrayList<String> rwords;
    String buffer;
    State(String buf){
        rwords = new ArrayList<String>();
        buffer = buf;
    }
    State(State s){
        rwords = new ArrayList<String>(s.rwords);
        buffer = new String(s.buffer);
    }
    public boolean isEnd(){
        if(buffer.length()==0) return true;
        else return false;
    }
}

class Sentence implements Comparable<Sentence>{
    String[] words;
    Sentence(String[] words) {
        this.words = words;
    }
    public int compareTo(Sentence s){
        int l1 = this.words.length;
        int l2 = s.words.length;
        for(int i=0;i<l1&&i<l2;i++){
            if(this.words[i].compareTo(s.words[i])!=0)
                return this.words[i].compareTo(s.words[i]);
        }
        return l1-l2;
    }
}