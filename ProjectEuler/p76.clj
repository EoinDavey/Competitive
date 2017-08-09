(def ways
  (memoize (fn [n k]
  (if (= n 0)
    1
    (reduce + (map #(ways (- n %) %) (range k (inc n))))))))

(println (dec (ways 100 1)))
