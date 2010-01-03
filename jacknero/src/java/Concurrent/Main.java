import java.util.ArrayList;  
import java.util.List;  
import java.util.concurrent.Callable;  
import java.util.concurrent.ExecutorService;  
import java.util.concurrent.Executors;  
import java.util.concurrent.Future;  

public class Main {  

  public static void main(String[] args) {  
    int threadsNum = Runtime.getRuntime().availableProcessors();  

    ExecutorService service = Executors.newFixedThreadPool(threadsNum);  

    List<Job> jobs = new ArrayList<Job>();  
    for (int i = 100001; i <= 200000; i++)  
      jobs.add(new Job(i));  

    try {  
      List<Future<String>> answers;  

      answers = service.invokeAll(jobs);  

      for (Future<String> future : answers)  
        System.out.println(future.get());  
    } catch (Exception e) {  
      e.printStackTrace();  
    } finally {  
      service.shutdown();  
    }  
  }  
}  

class Job implements Callable<String> {  
  private int number;  

  public Job(int number) {  
    this.number = number;  
  }  

  @Override  
    public String call() throws Exception {  
      return Math.factorization(number);  
    }  
}  

class Math {  
  public static String factorization(int number) {  
    StringBuilder answer = new StringBuilder();  
    answer.append(number);  
    answer.append(":");  
    int n = 2;  
    while (number > 1) {  
      if (number % n == 0) {  
        answer.append(" ");  
        answer.append(n);  
        number /= n;  
      } else  
        n++;  
    }  
    return answer.toString();  
  }  
}  
