import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        for(int c=0;c<k;c++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            int n = sc.nextInt();
            int m = sc.nextInt();
            Robot[] rs = new Robot[n];
            Instruction[] insts = new Instruction[m];
            for(int i=0;i<n;i++){
                rs[i] = new Robot(sc.nextInt()-1, sc.nextInt()-1, sc.next().charAt(0));
            }
            for(int i=0;i<m;i++){
                insts[i] = new Instruction(sc.nextInt()-1, sc.next().charAt(0), sc.nextInt());
            }
            Solver sol = new Solver(a, b, n, m, rs, insts);
            sol.solve();
        }
    }
}

class Solver{
    int a;
    int b;
    int n;
    int m;
    Robot[] rs;
    Instruction[] insts;
    public Solver(int a, int b, int n, int m, Robot[] rs, Instruction[] insts) {
        super();
        // TODO Auto-generated constructor stub
        this.a = a;
        this.b = b;
        this.n = n;
        this.m = m;
        this.rs = rs;
        this.insts = insts;
    }
    public void solve(){
        try{
            for(int i=0;i<m;i++){
                Instruction inst = insts[i];
                for(int j=0;j<inst.iternum;j++){
                    rs[inst.operand].execute(inst.opecode);
                    if(check(inst.operand)){
                        throw new RuntimeException();
                    }
                }
            }
        }
        catch(RuntimeException e){
            // do nothing
            return;
        }
        System.out.println("OK");
    }
    private boolean check(int id){
        if(rs[id].x<0 || rs[id].x>=a || rs[id].y<0 || rs[id].y>=b){
            System.out.printf("Robot %d crashes into the wall\r\n", id+1);
            return true;
        }
        for(int i=0;i<n;i++){
            if(i==id) continue;
            if(rs[id].x==rs[i].x && rs[id].y==rs[i].y){
                System.out.printf("Robot %d crashes into robot %d\r\n", id+1, i+1);
                return true;
            }
        }
        return false;
    }
}

class Robot{
    int x;
    int y;
    int dx;
    int dy;
    public Robot(int x, int y, char c) {
        this.x = x;
        this.y = y;
        switch(c){
        case 'N':
            dx = 0;
            dy = 1;
            break;
        case 'E':
            dx = 1;
            dy = 0;
            break;
        case 'S':
            dx = 0;
            dy = -1;
            break;
        case 'W':
            dx = -1;
            dy = 0;
            break;
        }
    }
    public void execute(char opecode){
        int newdx, newdy;
        switch(opecode){
        case 'L':
            newdx = -dy;
            newdy = dx;
            dx = newdx;
            dy = newdy;
            break;
        case 'R':
            newdx = dy;
            newdy = -dx;
            dx = newdx;
            dy = newdy;
            break;
        case 'F':
            x += dx;
            y += dy;
            break;
        }
    }
}

class Instruction{
    int operand;
    char opecode;
    int iternum;
    public Instruction(int operand, char opecode, int iternum) {
        super();
        // TODO Auto-generated constructor stub
        this.operand = operand;
        this.opecode = opecode;
        this.iternum = iternum;
    }
}