require 'rubygems'
require 'spreadsheet'
#require 'spreadsheet/excel'
book = Spreadsheet::Workbook.new
sheet = book.create_worksheet
sheet.name = 'some sheet'
sheet[1,1] = "test"
sheet[2,1] = "this is the test"
book.write('filename.xls')
