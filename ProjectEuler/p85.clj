(defn abs
  [n]
  (max n (-' n)))
(defn c2
  [n]
  (/ (*' n (-' n 1)) 2))

(defn nRect
  [n m]
  (*' (c2 (inc n)) (c2 (inc m))))

(def recs (for [n (range 1 100) m (range 1 100)] (list (nRect n m) (list n m))))
(println (apply min-key (fn [[a b]] (abs (- 2000000 a))) recs))
