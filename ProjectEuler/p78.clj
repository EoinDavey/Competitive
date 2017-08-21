(def cyc (iterate #(if (<= % 0) (inc (* -1 %)) (* -1 %)) 1))
(def pentas (map list (map (fn [m] (/ (* m (- (* 3 m) 1)) 2)) cyc) (cycle '(1 1 -1 -1))))

(def memo-p
  (memoize
    (fn
      [n]
      (if (= n 0)
        1
      (loop
        [out 0
         [[m k] & ms] pentas]
        (cond
          (= m n) (+' k out)
          (> m n) out 
          :else (recur (+' out (*' k (memo-p (-' n m)))) ms)))))))

(->> (range) (filter #(= 0 (mod (memo-p %) 1000000))) first println)
