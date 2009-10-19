#print "Hellow";

@array = (0..1000);
foreach  (@array ){
 #   print $_
}

print (map { $_ * 2 } @array );
