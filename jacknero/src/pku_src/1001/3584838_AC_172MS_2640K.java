import java.util.*;
class Main{
  static{
    for(Scanner i=new Scanner(System.in);i.hasNext();)
      System.out.println(i.nextBigDecimal().pow(i.nextInt())
        .toPlainString().replaceAll("^0|\\.?0*$",""));
  }
}
