(defn cube [x] (*' (*' x x) x))
(def cubes (map cube (iterate inc 0)))

(def mp (map #(sort (str %)) cubes))

(def ans (loop [ls mp st {}]
  (let [[x & xs] ls g (get st x) n (if g g 0)]
    (if (= 5 (+ 1 n))
      x
      (recur xs (assoc st x (+ 1 n)))))))

(println (first (filter #(= ans (sort (str %))) cubes)))
