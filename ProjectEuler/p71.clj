(def f (/ 3 7))
(defn mxN
  [d]
  (/ (int (/ (* 3 d) 7)) d))

(def mxs
  (map mxN (range 1 1000000)))

(->> mxs (filter (partial not= f)) (apply max) numerator println)
