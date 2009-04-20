import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while(true){
            int n = sc.nextInt();
            if(n==0) break;
            
            ArrayList<Order> orders = new ArrayList<Order>();
            for(int i=0;i<n;i++){
                String per = sc.next();
                String sdtype = sc.next();
                Ordertype dtype;
                if(sdtype.equals("SELL")) dtype = Ordertype.SELL;
                else dtype = Ordertype.BUY;
                String com = sc.next();
                int price = sc.nextInt();
                orders.add(new Order(per,dtype,com,price));
            }
            Solver sol = new Solver(orders);
            sol.solve();
            sol.print();
        }
    }
}

class Solver{
    ArrayList<Order> orders;
    TreeMap<String,ArrayList<Integer>> comdeallist;
    TreeMap<String,PersonData> perdatalist;
    LinkedList<Order> buyers;
    LinkedList<Order> sellers;

    Solver(ArrayList<Order> sorders){
        orders = sorders;
        comdeallist = new TreeMap<String,ArrayList<Integer>>();
        perdatalist = new TreeMap<String,PersonData>();
        buyers = new LinkedList<Order>();
        sellers = new LinkedList<Order>();
        for(Order o:orders){
            if(!perdatalist.containsKey(o.person))
                perdatalist.put(o.person,new PersonData());
            if(!comdeallist.containsKey(o.commodity))
                comdeallist.put(o.commodity,new ArrayList<Integer>());
        }
    }
    public void solve(){
        for(Order o:orders){
            if(o.dtype==Ordertype.BUY){
                newBuyer(o);
            }
            else{
                newSeller(o);
            }
        }
    }
    private void newBuyer(Order buy){
        Order sell = null;
        for(Order s:sellers){
            if(s.commodity.equals(buy.commodity)&&s.price<=buy.price
                    &&!s.person.equals(buy.person)){
                if(sell==null) sell = s;
                else if(s.price<sell.price) sell = s;
            }
        }
        
        if(sell==null){
            buyers.add(buy);
        }
        else{
            sellers.remove(sell);
            int dealprice = (sell.price+buy.price)/2;
            comdeallist.get(sell.commodity).add(dealprice);
            perdatalist.get(sell.person).recv += dealprice;
            perdatalist.get(buy.person).pay += dealprice;
        }
    }
    private void newSeller(Order sell){
        Order buy = null;
        for(Order b:buyers){
            if(b.commodity.equals(sell.commodity)&&b.price>=sell.price
                    &&!b.person.equals(sell.person)){
                if(buy==null) buy = b;
                else if(b.price>buy.price) buy = b;
            }
        }
        
        if(buy==null){
            sellers.add(sell);
        }
        else{
            buyers.remove(buy);
            int dealprice = (sell.price+buy.price)/2;
            comdeallist.get(sell.commodity).add(dealprice);
            perdatalist.get(sell.person).recv += dealprice;
            perdatalist.get(buy.person).pay += dealprice;
        }
    }
    public void print(){
        Set<Map.Entry<String,ArrayList<Integer>>> comset = comdeallist.entrySet();
        for(Map.Entry<String,ArrayList<Integer>> c:comset){
            ArrayList<Integer> v = c.getValue();
            if(v.size()>0){
                int min = Integer.MAX_VALUE;
                int max = Integer.MIN_VALUE;
                int sum = 0;
                for(Integer i:v){
                    if(i<min) min = i;
                    if(i>max) max = i;
                    sum += i;
                }
                int avg = sum/v.size();
                System.out.println(c.getKey()+" "+min+" "+avg+" "+max);
            }
        }
        System.out.println("--");
        
        Set<Map.Entry<String,PersonData>> perset = perdatalist.entrySet();
        for(Map.Entry<String,PersonData> p:perset){
            System.out.println(p.getKey()+" "+p.getValue().pay+" "+p.getValue().recv);
        }
        System.out.println("----------");
    }
}

class PersonData{
    int pay;
    int recv;
    PersonData(){
        pay = 0;
        recv = 0;
    }
}

class Order{
    String person;
    Ordertype dtype;
    String commodity;
    int price;
    Order(String oper,Ordertype odtype,String ocom,int oprice){
        person = oper;
        dtype = odtype;
        commodity = ocom;
        price = oprice;
    }
}

enum Ordertype{
    BUY,SELL;
}