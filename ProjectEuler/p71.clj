(defn maxDiv
  [d]
  (last (take-while #(< % (/ 3 7)) (map #(/ % d) (range)))))
