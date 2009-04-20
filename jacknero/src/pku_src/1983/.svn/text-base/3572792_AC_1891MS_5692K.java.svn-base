import java.util.*;

public class Main{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            String tmp[][] = new String[n][2];
            for(int i=0;i<n;i++){
                String line = sc.next();
                tmp[i][0] = line.substring(0,line.indexOf('-'));
                tmp[i][1] = line.substring(line.indexOf('-')+1);
            }
            
            ArrayList<String> l = new ArrayList<String>();
            
            for(int i=0;i<n;i++){
                if(!l.contains(tmp[i][0])) l.add(tmp[i][0]);
                if(!l.contains(tmp[i][1])) l.add(tmp[i][1]);
            }
            
            int size = l.size();
            System.out.println(size);
            
            int matrix[][] = new int[size][size];
            
            for(int i=0;i<size;i++){
                for(int j=0;j<size;j++){
                    matrix[i][j] = 0;
                }
            }
            
            for(int i=0;i<n;i++){
                int x = l.indexOf(tmp[i][0]);
                int y = l.indexOf(tmp[i][1]);
                matrix[x][y] = 1;
            }
            
            AMatrix a = new AMatrix(size,matrix);
            a.makepath();
            
            int m = sc.nextInt();
            
            for(int i=0;i<m;i++){
                String line = sc.next();
                String str1 = line.substring(0,line.indexOf('-'));
                String str2 = line.substring(line.indexOf('-')+1);
                int x = l.indexOf(str1);
                int y = l.indexOf(str2);
                int p = a.searchpath(x,y);
                if(p%2==1) System.out.println("YES");
                if(p%2==0) System.out.println("NO");
            }
        }
    }
}

class AMatrix{
    int size;
    int adj[][];
    
    AMatrix(int s,int m[][]){
        size = s;
        adj = m;
    }
    
    public void makepath(){
        for(int i=0;i<size;i++){
            for(int j=i+1;j<size;j++){
                for(int k=0;k<size;k++){
                    if(k==i || k==j) continue;
                    if((adj[i][k]==1&&adj[j][k]==1)||(adj[k][i]==1&&adj[k][j]==1)){
                        int flag;
                        flag = 0;
                        for(int l=0;l<size;l++){
                            if(adj[i][l]==1&&adj[l][j]==1){
                                flag =1;
                                break;
                            }
                            if(adj[l][i]==1&&adj[j][l]==1){
                                flag = 1;
                                break;
                            }
                        }
                        if(flag==0){
                            adj[i][j] = 2;
                            adj[j][i] = 2;
                        }
                    }
                }
            }
        }
    }
    
    public int searchpath(int x,int y){
        if(x<0 || y<0) return 0;
        
        LinkedList<Pair> l = new LinkedList<Pair>();
        HashSet<Integer> s = new HashSet<Integer>();
        l.offer(new Pair(x,0));
        s.add(x);
        while(!l.isEmpty()){
            Pair v = l.poll();
            for(int i=0;i<size;i++){
                if(adj[v.first][i]>0){
                    if(i==y){
                        return v.second + adj[v.first][i];
                    }
                    else{
                        if(!s.contains(i)){
                            Pair u = new Pair(i,v.second+adj[v.first][i]);
                            l.offer(u);
                            s.add(i);
                        }
                    }
                }
            }
        }
        
        return 0;
    }
}

class Pair{
    int first;
    int second;
    Pair(int a,int b){
        first = a;
        second = b;
    }
}