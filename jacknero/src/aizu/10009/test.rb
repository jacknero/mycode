999999.times do |n|
  io =IO.popen("./main", "r+")
  io2 =IO.popen("./main_ans", "r+")
  io.puts "#{n}"
  io2.puts "#{n}"
  print test = io.gets
  print ans = io.gets
  if test != ans
    print "#{test} : #{ans}"
  elsif
    print "#{n} : not equal"
  end
end
