(define balance 100)

(define (withdraw amount)
  (if (>= balance amount)
    (begin (set! balance (- balance amount))
      balance)
    "Insufficient funds"))

(display (withdraw 25))
