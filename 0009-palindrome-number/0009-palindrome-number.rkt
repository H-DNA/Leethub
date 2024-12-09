(define/contract (is-palindrome x)
  (-> exact-integer? boolean?)
  (define (get-digits x)
    (if (= x 0)
      null
      (cons (remainder x 10)
            (get-digits (quotient x 10)))))

  (define (reverse l)
    (if (null? l)
      null
      (append (reverse (cdr l))
              (list (car l)))))
            
  (define (equal-list l1 l2)
    (cond ((null? l1) (null? l2))
          ((null? l2) false)
          ((= (car l1)
              (car l2))
           (equal-list (cdr l1)
                       (cdr l2)))
          (else false)))

  (define digits (get-digits x))

  (if (< x 0)
    false
    (equal-list digits
              (reverse digits))))