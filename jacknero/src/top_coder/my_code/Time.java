import java.math.*;
import java.util.*;
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Math.*;

public class Time
{
  public String whatTime(int s)
  {
    return (s/3600)+":"+(s%3600/60)+":"+s%60;
  }
  public static void main(String args[]){
    Time time = new Time();
    System.out.println(time.whatTime(3661));
  }

}
