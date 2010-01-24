(defn load-db [filename]
  (read-string (slurp filename)))

(println (load-db "test.txt"))
