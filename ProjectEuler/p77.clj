(def primeLim 100)
(defn prime?
  [x]
  (let [l (inc (int (Math/sqrt x)))]
    (loop [d 2]
      (cond
        (> d l) true
        (= 0 (mod x d)) false
        :else (recur (inc d))))))

(def primes (into [] (cons 2 (filter prime? (range 2 primeLim)))))
(def nprimes (count primes))

(def ways
  (memoize (fn [n k]
  (if (= n 0)
    1
    (reduce + (for [i (range k nprimes)
          :let [p (nth primes i)]
          :while (<= p n)]
      (ways (- n p) i)))))))

(->> (range) (filter #(>= (ways % 0) 5000)) first println)
