(define (fold proc init lis)
  (if (null? lis)
    init
    (fold proc (proc (car lis) init) #?=(cdr lis))))

(fold + 0 '(1 2 3 4 5 ))
