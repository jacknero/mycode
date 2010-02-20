require 'rubygems'
require 'spreadsheet'

# Excel ����ѥ��饤����Ȥ�ʸ������������=>Shift-JIS
#Spreadsheet.client_encoding = 'Shift-JIS'

# Excel Workbook ���󥹥��󥹺���
book = Spreadsheet::Workbook.new

# ���� WorkSheet ����=>schedule
sheet = book.create_worksheet :name => 'test'

# �����������񤯰٤˥ե����ޥåȥ��֥������Ȥ����
# ���������ꤹ�뿧����ꤹ��
# ���ȡ�[:top_color]
# ���ȡ�[:bottom_color]
# ���ȡ�[:left_color]
# ���ȡ�[:right_color]
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
