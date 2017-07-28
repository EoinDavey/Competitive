(def groups (map (partial map dec) (list '(1 7 8) '(2 8 9) '(3 9 10) '(4 10 6) '(5 6 7))))

(defn perms
  [xs]
  (if (= 1 (count xs))
    (list xs)
    (for [head xs
          tail (perms (disj (set xs) head))]
      (cons head tail))))

(def orders(->> (range 1 10) perms (map #(into [] (cons 10 %)))))
(def g (first groups))

(defn sumgroup
  [xs p]
  (reduce (fn [x y] (+ x (p y))) 0 xs))

(defn check
  [p]
  (every? #(= % (sumgroup g p)) (map #(sumgroup % p) groups)))

(->> orders (filter check) (map #(vector (apply min (take 5 %)) %)) sort reverse println)
