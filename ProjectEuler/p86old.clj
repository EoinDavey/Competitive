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

(defn shPath
  [a b c]
  (min (sz a b c) (sz b a c) (sz c a b)))

(defn isInt
  [x]
  (= x (int x)))

(def lim 100)
(def dims (for [a (range 1 lim) b (range a lim) c (range b lim)] (list a b c)))

(->> dims (filter #(isInt (apply shPath %))) count println)
