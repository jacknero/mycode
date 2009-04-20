package p1163;

import java.util.Scanner;

public class Main {

public static void main(String[] args) {
a();
}


static void a() {
Scanner scanner = new Scanner(System.in);
n = scanner.nextInt();

list = new int[n][];
memo = new int[n][];
for (int i = 0; i < n; i++) {
int[] js = new int[i+1];
int[] mm = new int[i+1];
for (int j = 0; j <= i; j++) {
js[j] = scanner.nextInt();
mm[j] = -1;
}
list[i] = js;
memo[i] = mm;
}

int max = max(list[0][0], 0, 1);
System.out.println(max);
}

static int[][] list;
static int[][] memo;
static int n = 0;

static int max(int c, int p, int pos) {

if (n <= pos)
return c;
int l = memo[pos][p];
int r = memo[pos][p + 1];
if(l == -1){
memo[pos][p] = list[pos][p] + max(c, p, pos + 1);
l = memo[pos][p];
}
if(r == -1){
memo[pos][p + 1] = list[pos][p + 1] + max(c, p + 1, pos + 1);
r = memo[pos][p + 1];
}

return l < r ? r : l;
}

}