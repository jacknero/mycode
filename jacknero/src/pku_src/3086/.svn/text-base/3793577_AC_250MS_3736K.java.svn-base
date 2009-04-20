import java.util.Scanner;

public class Main {

public static void main(String[] args) {

int[] tbl = createTable2();

Scanner scanner = new Scanner(System.in);
int n = scanner.nextInt();
for(int i=1;i<=n;i++){
int p = scanner.nextInt();
System.out.println(i + " " + p + " " + tbl[p]);
}

}

static int[] createTable2() {
int[] tbl = createTable();
int[] tbl2 = new int[tbl.length - 1];
tbl2[0] = 0;
for (int i = 1; i < tbl2.length; i++) {
tbl2[i] = tbl2[i - 1] + (i * tbl[i + 1]);
}
return tbl2;
}

static int[] createTable() {
int[] tbl = new int[302];
tbl[0] = 0;
for (int i = 1; i < tbl.length; i++) {
tbl[i] = tbl[i - 1] + i;
}
return tbl;
}
}