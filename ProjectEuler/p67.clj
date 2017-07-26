(def stdin (java.io.BufferedReader. *in*))
(def triangle
  (into [] (map 
    (fn [x]
      (into [] (map #(Integer/parseInt %) (clojure.string/split x #"\s+"))))
  (line-seq stdin))))

(def N (count triangle))

(def trav
  (memoize (fn
    [x y]
    (if (>= x N)
      0
      (+ ((triangle x) y) (max (trav (inc x) y) (trav (inc x) (inc y))))))))

(println (trav 0 0))
