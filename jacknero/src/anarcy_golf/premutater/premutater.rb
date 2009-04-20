f=proc{|$_,v| v ? $_.to_s.gsub(/./){f[$`+$',v+$&]}:v+$/}
$><<f[gets,'']
