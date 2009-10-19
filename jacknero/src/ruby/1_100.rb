 a = (1..100).to_a
 a.map{|e| (e %3 == 0)?e: next}.compact
 p a.select{|e| e  % 3 ==0}
