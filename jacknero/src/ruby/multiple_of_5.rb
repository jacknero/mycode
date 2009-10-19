min = ARGV[0]
max = ARGV[1]

 p $*.min
 p $*.max
print (min.to_i..max.to_i).select { |e| e  if e % 5 == 0  }

for num in min.to_i..max.to_i do
  #p num if num % 5 == 0
end
