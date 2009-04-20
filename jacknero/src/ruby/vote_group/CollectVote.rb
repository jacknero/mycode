dir="."
#dir="test_group"

Dir.new(dir).grep(/txt$/).each do |x|
   open(x,"r") do |f|
     p f.read
   end
end
