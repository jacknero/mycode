99.downto(1){|n|puts"#{n} bottle#{"s"if n!=1} of beer on the wall, #{n} bottle#{"s"if n!=1} of beer."
puts(n!=1)?"Take one down and pass it around, #{n-1} bottle#{"s" if n-1!=1} of beer on the wall.\n\n":"Go to the store and buy some more, 99 bottles of beer on the wall.\n" }
