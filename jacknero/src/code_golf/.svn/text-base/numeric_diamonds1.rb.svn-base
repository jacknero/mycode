number=6
num_1=number-1
first_num=1
1.upto(number){|i|
  num=number-i
  s =  " "*num*2
  if (first_num < 10)
    s+=" "
  end
  s+= (first_num).to_s
  j=num_1
  
  while(first_num-j > 0 && i*num_1-j >0 )
    s += " " + (first_num-j).to_s
    j+=num_1
  end
  
  first_num+=number
  puts s
}

first_num-=number
first_num+=1
#p first_num
space=1
(number-1).downto(1){|i|
  s = " "*(space) + (first_num).to_s
  add_num=i-1
  while(add_num >0)
    s+= " " + (first_num-number+1).to_s
    add_num-=1
  end
  puts s
  space+=1
  first_num+=1
} 

#num=i+number-1
#puts " "*(number-i) + num.to_s + " " + (num-num_1).to_s
#i+=1
#puts " "*(number-i) + (i+number-1).to_s + " " + (i).to_s

