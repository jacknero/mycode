(defn fib [n] 
      (if (= n 0) 0
                (if (= n 1) 1
                              (+ (fib (- n 1)) (fib (- n 2))))))        

(defn lazy-seq-fibo 
      ([] 
               (concat [0 1] (lazy-seq-fibo 0 1))) 
      ([a b] 
               (let [n (+ a b)] 
                             (lazy-seq 
                                               (cons n (lazy-seq-fibo b n))))))
(print (take 10 (lazy-seq-fibo)))
(print (fib 20))
