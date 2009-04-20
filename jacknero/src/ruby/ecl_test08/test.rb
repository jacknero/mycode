file1 =  ARGV[0]
file_correct  =  ARGV[1]

file1 ="test.txt" if file1.nil?
file_correct ="test.txt" if file_correct.nil?


require 'csv'


CSV.open(file1, 'r') do |row|
  CSV.open(file_correct, 'r') do |correct_row|
    if row.size == correct_row.size
    end

  end
end

