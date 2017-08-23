#!/usr/bin/env inlein

'{:dependencies [[org.clojure/clojure "1.8.0"]
                 [org.clojure/math.numeric-tower "0.0.1"]]}

(require '[clojure.math.numeric-tower :as math])

(defn sq
  [x]
  (* x x))

(defn sz
  [a b c]
  (math/sqrt (+ (sq a) (sq (+ b c) ))))

(defn isInt
  [x]
  (= x (int x)))

(defn
  triples
  [m]
  (map list (filter #(isInt (math/sqrt (+ (sq m) (sq %)))) (range 2 m)) (repeatedly (constantly m))))

(defn
  triplesToTot
  [xs]
  (reduce + (map (fn [[a b]] (+ (int (/ a 2)) (int (/ b 2)))) xs)))

(def lim 101)

(->> (range 1 lim) (map triples) (map triplesToTot) (reduce +) println)

(println (triples 8))
(println (triplesToTot (triples 8)))
