class String
  def hoge
    return "hoge" if self.empty?
    self
  end
end

1.upto(99999) {|i| ## �Ȥꤢ����99�ޤ�
  puts("%2d:%s"%[i,((["Fizz"]+[""]*2)[i%3]+(["Buzz"]+[""]*4)[i%5]).hoge])
}

