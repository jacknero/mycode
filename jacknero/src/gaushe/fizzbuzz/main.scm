(use srfi-1)
(define numbers (iota 100 1))

(print (map (lambda(n) (if (zero? (modulo n 15)) "FizzBuzz"
                         (if (zero? (modulo n 5)) "Buzz"
                           (if (zero? (modulo n 3)) "Fizz"
                             n))))numbers))
