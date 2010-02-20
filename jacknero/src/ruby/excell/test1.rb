require 'rubygems'
require 'spreadsheet'

# Excel 操作用クライアントの文字コード設定=>Shift-JIS
#Spreadsheet.client_encoding = 'Shift-JIS'

# Excel Workbook インスタンス作成
book = Spreadsheet::Workbook.new

# 新規 WorkSheet 作成=>schedule
sheet = book.create_worksheet :name => 'test'

# セルの枠線を書く為にフォーマットオブジェクトを作成
# 枠線に設定する色を指定する
# 上枠：[:top_color]
# 下枠：[:bottom_color]
# 左枠：[:left_color]
# 右枠：[:right_color]
formatter = Spreadsheet::Format.new(
  {
  :size=>10,
  :top_color => :blue,
  :bottom_color => :red,
  :left_color => :green,
  :right_color => :yellow
}
)
formatter.border = true

sheet.row(1).set_format(1, formatter)

sheet[1, 1] = "test"

filename = File.join(File.dirname(__FILE__), 'test.xls').to_s
book.write filename
