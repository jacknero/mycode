#!/usr/bin/ruby
require 'net/http'
http = Net::HTTP.new('www.yahoo.co.jp')
response = http.post('/', 'ei=UTF-8&p=test')
p response.body

