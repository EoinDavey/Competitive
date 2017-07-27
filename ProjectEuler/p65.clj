(def cyc (cons 2 (flatten (map (fn [x] (list 1 (* 2 x) 1)) (iterate inc 1)))))
(defn gen
  [[x & xs]]
  (if xs
    (+ x (/ 1 (gen xs)))
    x))

(->> (take 100 cyc) gen numerator str (map #(- (int %) (int \0))) (reduce +) println)
