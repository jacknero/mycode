min = ARGV[0]
max = ARGV[1]


for num in min.to_i..max.to_i do
  p num if num % 5 == 0
end
