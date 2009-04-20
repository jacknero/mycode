import java.util.*;



public class Main {

    static final int[] dis = { 0, 1, 0, -1 };

    static final int[] djs = { 1, 0, -1, 0 };

    static final int INF = Integer.MAX_VALUE / 4;

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int casenum = sc.nextInt();

        for(int caseiter=0;caseiter<casenum;caseiter++){

            int w = sc.nextInt();

            int h = sc.nextInt();

            char[][] board = new char[2*h+1][2*w+1];

            Arrays.fill(board[0], '#');

            for(int i=1;i<=2*h-1;i++){

                board[i][0] = '#';

                for(int j=1;j<=2*w-1;j++) board[i][j] = ' ';

                board[i][2*w] = '#';

            }

            Arrays.fill(board[2*h], '#');

            for(int i=0;i<=2*h;i+=2){

                for(int j=0;j<=2*w;j+=2){

                    board[i][j] = '#';

                }

            }

            char[] path = sc.next().toCharArray();

            int m = sc.nextInt();

            int[] wx1s = new int[m];

            int[] wy1s = new int[m];

            int[] wx2s = new int[m];

            int[] wy2s = new int[m];

            for(int k=0;k<m;k++){

                wx1s[k] = sc.nextInt();

                wy1s[k] = sc.nextInt();

                wx2s[k] = sc.nextInt();

                wy2s[k] = sc.nextInt();

                int j1 = 2*wx1s[k] + 1;

                int i1 = 2*h - 1 - 2*wy1s[k];

                int j2 = 2*wx2s[k] + 1;

                int i2 = 2*h - 1 - 2*wy2s[k];

                board[(i1+i2)/2][(j1+j2)/2] = '#';

            }

            

            // check if the path intersects walls

            boolean[][] used = new boolean[2*h+1][2*w+1];

            int nowi = 2*h - 1, nowj = 1;

            used[nowi][nowj] = true;

            boolean valid = true;

            for(int k=0;k<path.length;k++){

                int nexti = nowi, nextj = nowj;

                switch(path[k]){

                case 'U':

                    nexti -= 2; break;

                case 'R':

                    nextj += 2; break;

                case 'D':

                    nexti += 2; break;

                case 'L':

                    nextj -= 2; break;

                default:

                    throw new RuntimeException();

                }

                if(board[(nowi+nexti)/2][(nowj+nextj)/2]=='#'){

                    valid = false;

                    break;

                }

                nowi = nexti;

                nowj = nextj;

                used[nowi][nowj] = true;

            }

            if(!valid){

                System.out.println("INCORRECT");

                continue;

            }

            

            int goalx = nowj / 2;

            int goaly = (2*h-nowi-1) / 2;

            

            // check if the path is shortest

            int pathlen = path.length * 2;

            int[][] fromstart = new int[2*h+1][2*w+1];

            int[][] fromgoal = new int[2*h+1][2*w+1];

            calcDist(board, w, h, 0, 0, fromstart);

            calcDist(board, w, h, goalx, goaly, fromgoal);

            

            if(fromgoal[2*h-1][1]<pathlen){

                System.out.println("INCORRECT");

                continue;

            }

            

            // check if the shortest path is unique

            for(int i=1;i<=2*h-1;i+=2){

                for(int j=1;j<=2*w-1;j+=2){

                    if(!used[i][j]&&fromstart[i][j]+fromgoal[i][j]==pathlen){

                        valid = false;

                        break;

                    }

                }

            }

            if(!valid){

                System.out.println("INCORRECT");

                continue;

            }

            

            // check if walls are necessary

            for(int k=0;k<m;k++){

                int j1 = 2*wx1s[k] + 1;

                int i1 = 2*h - 1 - 2*wy1s[k];

                int j2 = 2*wx2s[k] + 1;

                int i2 = 2*h - 1 - 2*wy2s[k];

                if( fromstart[i1][j1]+fromgoal[i2][j2]>pathlen &&

                    fromstart[i2][j2]+fromgoal[i1][j1]>pathlen){

                    valid = false;

                    break;

                }

            }

            

            if(valid) System.out.println("CORRECT");

            else System.out.println("INCORRECT");

        }

    }

    static void printBoard(char[][] board){

        for (char[] line : board)

            System.out.println(line);

    }

    static void calcDist(char[][] board, int w, int h, int fromx, int fromy,

            int[][] dist){

        int fromi = 2 * h - 1 - 2 * fromy;

        int fromj = 2 * fromx + 1;

        for (int i = 0; i <= 2 * h; i++)

            Arrays.fill(dist[i], INF);

        Queue<State> q = new LinkedList<State>();

        State from = new State(fromi, fromj, 0);

        q.offer(from);

        dist[from.i][from.j] = from.d;

        while (!q.isEmpty()) {

            State s = q.poll();

            for (int dir = 0; dir < 4; dir++) {

                int ni = s.i + dis[dir];

                int nj = s.j + djs[dir];

                int nd = s.d + 1;

                if (board[ni][nj] == ' ' && dist[ni][nj] == INF) {

                    q.offer(new State(ni, nj, nd));

                    dist[ni][nj] = nd;

                }

            }

        }

    }

}



class State {

    int i, j, d;

    State(int i, int j, int d){

        this.i = i;

        this.j = j;

        this.d = d;

    }

}