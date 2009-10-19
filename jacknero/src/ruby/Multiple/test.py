import sys

argvs = sys.argv
argc = len(argvs)
min = int(argvs[1])
max = int(argvs[2]) +1 ;

for i in range(min, max):
  if i % 5 == 0:
    print i

