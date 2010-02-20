keyword= ARGV[0]

require "rexml/document" 
require 'net/http'
Net::HTTP.version_1_2  
Net::HTTP.start('api.iknow.co.jp', 80) {|http|
  #response = http.get('/index.html')
  response = http.get("/items/matching/#{keyword}.xml")
  doc = REXML::Document.new response.body
  doc.elements.each('/vocabulary/items/item') do|line|
    print line.elements['cue/text'].text 
    print " "
    print line.elements['responses/response/text'].text
    print "\n"
  end
}
