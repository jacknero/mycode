f=proc{|$_,v|
  /./?gsub(/./){f[$`+$',v+$&]}  : v+$/
}
puts f[gets,'']

