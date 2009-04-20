import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            int p1 = sc.nextInt();
            int p2 = sc.nextInt();
            if(n==0&&p1==0&&p2==0) break;
            ArrayList<Question> ques = new ArrayList<Question>();
            for(int i=0;i<n;i++){
                int x = sc.nextInt()-1;
                int y = sc.nextInt()-1;
                boolean a = sc.next().equals("yes");
                ques.add(new Question(x,y,a));
            }
            
            Solver sol = new Solver(p1,p2,ques);
            sol.solve();
        }
    }
}

class Solver{
    int p;
    int p1;
    int p2;
    Question[] ques;
    
    int[] group;
    boolean[] relative;
    
    int groupnum;
    boolean[] assign;
    int[] assign_yes;
    int[] assign_no;
    HashMap<SearchState,Boolean> searched;
    
    boolean ans_exist;
    boolean[] ansassign;
    
    Solver(int p1, int p2,ArrayList<Question> ques) {
        this.p1 = p1;
        this.p2 = p2;
        this.p = p1 + p2;
        this.ques = new Question[ques.size()];
        this.ques = ques.toArray(this.ques);
        group = new int[p];
        relative = new boolean[p];
        for(int i=0;i<p;i++){
            group[i] = i;
            relative[i] = true;
        }
    }
    
    public void solve(){
        //Step1 merge the groups
        merge_groups();
        
        //Step2 rename the group id
        groupnum = rename_groups();
        
        //Step3 search
        search_init();
        search();
        
        //Step4 print
        print();
    }

    private void print(){
        if(!ans_exist) System.out.println("no");
        else{
            boolean ans[] = new boolean[p];
            for(int i=0;i<p;i++){
                ans[i] = relative[i] ^ !ansassign[group[i]];
            }
            for(int i=0;i<p;i++){
                if(ans[i]) System.out.println(i+1);
            }
            System.out.println("end");
        }
    }
    
    private void search_init(){
        assign_yes  = new int[groupnum];
        assign_no = new int[groupnum];
        
        for(int i=0;i<groupnum;i++){
            assign_yes[i] = 0;
            assign_no[i] = 0;
        }
        for(int i=0;i<p;i++){
            if(relative[i]) assign_yes[group[i]]++;
            else assign_no[group[i]]++;
        }
        
        assign = new boolean[groupnum];
        searched = new HashMap<SearchState,Boolean>();
    }
    
    private void search(){
        ans_exist = false;
        ansassign = null;
        
        try{
            search_sub(0,0,0);
        }
        catch(AnswerNotExistsException e){
            //do nothing
        }
    }
    
    private void search_sub(int lp1,int lp2,int k) throws AnswerNotExistsException{
        // leaf of DFS
        if(k==groupnum){
            if(lp1==p1&&lp2==p2){
                if(ans_exist){
                    ans_exist = false;
                    ansassign = null;
                    throw new AnswerNotExistsException();
                }
                else{
                    ans_exist = true;
                    ansassign = new boolean[groupnum];
                    for(int i=0;i<groupnum;i++) ansassign[i] = assign[i];
                }
            }
        }
        // node of DFS
        else{
            SearchState tmp = new SearchState(lp1,lp2,k);
            
            //when this state has searched yet
            if(searched.containsKey(tmp)){
                if(searched.get(tmp)){
                    ans_exist = false;
                    ansassign = null;
                    throw new AnswerNotExistsException();
                }
                else{
                    return;
                }
            }
            //when this state has not searchet yet
            else{
                searched.put(tmp,false);
                
                boolean ori_ans_exist = ans_exist;
                
                //search next state
                assign[k] = true;
                if(lp1<=p1&&lp2<=p2) search_sub(lp1+assign_yes[k],lp2+assign_no[k],k+1);
                assign[k] = false;
                if(lp1<=p1&&lp2<=p2) search_sub(lp1+assign_no[k],lp2+assign_yes[k],k+1);
                
                // find solution from this state
                if(!ori_ans_exist&&ans_exist){
                    searched.put(tmp,true);
                }
            }
        }
    }
    
    private void merge_groups() {
        for(int i=0;i<ques.length;i++){
            int x = ques[i].x;
            int y = ques[i].y;
            boolean ans = ques[i].ans;
            if(group[x]!=group[y]){
                if(ans) merge_yes(x,y);
                else merge_no(x,y);
            }
        }
    }
    
    private void merge_yes(int x,int y){
        int gx = group[x];
        int gy = group[y];
        if(relative[x]!=relative[y]){
            for(int i=0;i<p;i++){
                if(group[i]==gy) relative[i] = !relative[i];
            }
        }
        
        for(int i=0;i<p;i++){
            if(group[i]==gy) group[i] = gx;
        }
    }
    private void merge_no(int x,int y){
        int gx = group[x];
        int gy = group[y];
        if(relative[x]==relative[y]){
            for(int i=0;i<p;i++){
                if(group[i]==gy) relative[i] = !relative[i];
            }
        }
        
        for(int i=0;i<p;i++){
            if(group[i]==gy) group[i] = gx;
        }
    }
    private int rename_groups(){
        int groupnum = 0;
        for(int i=0;i<p;i++){
            if(i==group[i]) groupnum++;
        }
        
        HashMap<Integer,Integer> m = new HashMap<Integer,Integer>();
        int gidcnt = 0;
        for(int i=0;i<p;i++){
            if(i==group[i]){
                m.put(i,gidcnt);
                gidcnt++;
            }
        }
        
        for(int i=0;i<p;i++){
            group[i] = m.get(group[i]);
        }
        
        return groupnum;
    }
}

class SearchState{
    int p1;
    int p2;
    int k;
    SearchState(int p1, int p2, int k) {
        this.p1 = p1;
        this.p2 = p2;
        this.k = k;
    }
    public boolean equals(Object o){
        SearchState s = (SearchState)o;
        return this.p1==s.p1&&this.p2==s.p2&&this.k==s.k;
    }
    public int hashCode(){
        return p1<<24+p2<<8+k;
    }
}

class Question{
    int x;
    int y;
    boolean ans;
    Question(int x, int y, boolean ans) {
        this.x = x;
        this.y = y;
        this.ans = ans;
    }
}

class AnswerNotExistsException extends Exception{
   
}