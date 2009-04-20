import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            int m = sc.nextInt();
            if(n==0&&m==0) break;
            
            Directory root = new Directory(false);
            for(int i=0;i<n;i++){
                LinkedList<String> filepath = getFilePath(sc.next());
                root.add(filepath);
            }
            for(int j=0;j<m;j++){
                LinkedList<String> filepath1 = getFilePath(sc.next(),root);
                LinkedList<String> filepath2 = getFilePath(sc.next(),root);
                if(root.contains(filepath1)&&root.contains(filepath2)){
                    if(root.get(filepath1)==root.get(filepath2)) System.out.println("yes");
                    else System.out.println("no");
                }
                else{
                    System.out.println("not found");
                }
            }
        }
    }
    private static LinkedList<String> getFilePath(String line){
        StringTokenizer st = new StringTokenizer(line,"/\t\n\r\f");
        LinkedList<String> filepath = new LinkedList<String>();
        while(st.hasMoreTokens()){
            filepath.addLast(st.nextToken());
        }
        
        return filepath;
    }
    private static LinkedList<String> getFilePath(String line,Directory root){
        StringTokenizer st = new StringTokenizer(line,"/\t\n\r\f");
        LinkedList<String> filepath = new LinkedList<String>();
        while(st.hasMoreTokens()){
            filepath.addLast(st.nextToken());
        }
        
        if(root.containsDirectory(filepath)){
            filepath.addLast("index.html");
        }
        else if(line.charAt(line.length()-1)=='/') filepath.addLast("index.html");
        
        return filepath;
    }
}

class Directory{
    boolean isfile;
    HashMap<String,Directory> sub;
    Directory parent;
    Directory(boolean isfile){
        this.isfile = isfile;
        this.sub = new HashMap<String,Directory>();
        this.parent = null;
    }
    Directory(boolean isfile,Directory parent){
        this.isfile = isfile;
        this.sub = new HashMap<String,Directory>();
        this.parent = parent;
    }
    public void add(List<String> filepath){
        if(filepath.size()==1){
            String filename = filepath.get(0);
            sub.put(filename,new Directory(true,null));
        }
        else{
            String nextdir = filepath.get(0);
            if(sub.containsKey(nextdir)){
                sub.get(nextdir).add(filepath.subList(1,filepath.size()));
            }
            else{
                sub.put(nextdir,new Directory(false,this));
                sub.get(nextdir).add(filepath.subList(1,filepath.size()));
            }
        }
    }
    public boolean contains(List<String> filepath){
        if(filepath.size()==1){
            String filename = filepath.get(0);
            Directory file = sub.get(filename);
            if(file!=null&&file.isfile) return true;
            else return false;
        }
        else{
            String nextdirname = filepath.get(0);
            Directory nextdir;
            if(nextdirname.equals(".")) nextdir = this;
            else if(nextdirname.equals("..")) nextdir = this.parent;
            else nextdir = this.sub.get(nextdirname);
            
            if(nextdir==null) return false;
            else{
                return nextdir.contains(filepath.subList(1,filepath.size()));
            }
        }
    }
    public boolean containsDirectory(List<String> filepath){
        if(filepath.size()==0){
            return !isfile;
        }
        else{
            String nextdirname = filepath.get(0);
            Directory nextdir;
            if(nextdirname.equals(".")) nextdir = this;
            else if(nextdirname.equals("..")) nextdir = this.parent;
            else nextdir = this.sub.get(nextdirname);
            
            if(nextdir==null) return false;
            else{
                return nextdir.containsDirectory(filepath.subList(1,filepath.size()));
            }
        }
    }
    public Directory get(List<String> filepath){
        if(filepath.size()==1){
            String filename = filepath.get(0);
            Directory file = sub.get(filename);
            return file;
        }
        else{
            String nextdirname = filepath.get(0);
            Directory nextdir;
            if(nextdirname.equals(".")) nextdir = this;
            else if(nextdirname.equals("..")) nextdir = this.parent;
            else nextdir = this.sub.get(nextdirname);
                    
            return nextdir.get(filepath.subList(1,filepath.size()));
        }
    }
}