(def N 100)

(defn gcd
  [a b]
  (if (= b 0)
    a
    (recur b (mod a b))))

(defn phi
  [n]
  (filter #(= 1 (gcd % N)) (range 1 n)))

(defn maxNum
  [d n]
  (- n (mod n d)))

(def denoms (into #{} (map #(maxNum % N) (phi N))))
(println (phi N))
(println denoms)
(println (reduce #(+ %1 (dec %2)) 0 denoms))
