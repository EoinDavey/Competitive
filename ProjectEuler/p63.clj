(defn exp
  [b e]
  (.pow (biginteger b) e))

(defn len
  [x]
  (count (str x)))

(def ans (take-while #(>= (len (exp 9 %)) %) (iterate inc 1)))
(def out (map (fn [x] (count (filter #(= x (len (exp % x))) (range 1 10)))) ans))
(println (reduce + out))
