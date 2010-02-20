keyword= "apple"

require 'net/http'
Net::HTTP.version_1_2  
Net::HTTP.start('eow.alc.co.jp', 80) {|http|
  #response = http.get('/index.html')
  response = http.get('/apple/UTF-8/')
  puts response.body
}
