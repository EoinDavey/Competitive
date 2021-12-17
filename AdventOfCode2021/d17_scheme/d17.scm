(define (try-search pattern string)
    (regsexp-search-string-forward (compile-regsexp pattern) string))

(define matchNum 
  (lambda (var)
    `(group ,var (+ (alt #\- (char-in numeric))))))

; .*(?a[-0-9]+).*(?a[-0-9]+).*(?a[-0-9]+).*(?a[-0-9]+)
(define inp-match
  (list 'seq (matchNum 'x1) '(*? (any-char))
        (matchNum 'x2) '(*? (any-char))
        (matchNum 'y1) '(*? (any-char))
        (matchNum 'y2)))

(define get-rngs
  (lambda (grps)
    (let ((vs (map (lambda (x) (string->number (cdr x))) grps)))
        (cons (cons (first vs) (second vs))
              (cons (third vs) (fourth vs))))))

(define sim-flight-it
  (lambda (rng ov cnd pos v t)
    (if (not (cnd v))
        '()
        (let ((rest (sim-flight-it rng ov cnd (+ pos v) (- v 1) (+ t 1))))
            (if (and (<= (car rng) pos) (<= pos (cdr rng)))
                (cons (list t ov v) rest)
                rest)))))

(define sim-flight
  (lambda (rng v cnd)
    (sim-flight-it rng v cnd 0 v 0)))

(define find-ts
  (lambda (rng cnd d mx)
    (if (> d mx)
        '()
        (append (sim-flight rng d cnd)
                (find-ts rng cnd (+ d 1) mx)))))

(define find-matches
  (lambda (xs ys)
    (fold append '()
          (map (lambda (x)
                   (map (lambda (y) (cons (second x) (second y)))
                        (filter (lambda (y) (= (first x) (first y))) ys)))
               xs))))

(define add-x-stops
  (lambda (ys xstops)
    (fold append '()
          (map (lambda (y)
                   (map (lambda (x) (cons (second x) (second y)))
                        (filter (lambda (x) (>= (first y) (first x))) xstops)))
               ys))))

(define (remove-duplicates l)
  (cond ((null? l) '())
        ((member (car l) (cdr l)) (remove-duplicates (cdr l)))
        (else (cons (car l) (remove-duplicates (cdr l))))))

(define part-1
  (lambda (rngs)
    (let ((dy (- (abs (cadr rngs)) 1)))
      (/ (* dy (+ dy 1)) 2))))

(define part-2
  (lambda (rngs)
    (let* ((xs (find-ts (car rngs) (lambda (x) (>= x 0)) 0 (cdar rngs)))
           (ys (find-ts (cdr rngs) (lambda (y) (>= y (- (cadr rngs) 1))) (cadr rngs) (abs (cadr rngs))))
           (xstops (filter (lambda (x) (= (third x) 0)) xs)))
       (length (remove-duplicates (append (find-matches xs ys) (add-x-stops ys xstops)))))))

(with-input-from-file
 "d17.txt"
 (lambda ()
   (let* ((inp (read-line)) (rngs (get-rngs (drop (try-search inp-match inp) 2))))
     (begin
      (display "Part 1: ")
      (display (part-1 rngs))
      (newline)
      (display "Part 2: ")
      (display (part-2 rngs))
      (newline)))))
