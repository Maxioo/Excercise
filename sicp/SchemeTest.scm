(load "SchemeExample")

(define (continue-primes-fast n count)
  (cond ((= count 0)
         (display " are primes. "))
        ((fast-prime? n 10)
         (display n)
         (newline)
         (continue-primes-fast (next-odd n) (- count 1)))
        (else
         (continue-primes-fast (next-odd n) count))))


(define (test-foo1)
  (let ((start-time (real-time-clock)))
    (continue-primes-fast 100000000000 3)
    (- (real-time-clock) start-time)))

(define (test-foo)
  (let ((start-time (real-time-clock)))
    (continue-primes 100000000000 3)
    (- (real-time-clock) start-time)))

(define (examine-carminchael n times)
  (cond ((= times 0) true)
        ((fermat-test1 n times) (examine-carminchael? n (- times 1)))
        (else false)))

(define (fermat-test1 n a)
  (= (expmod a n n) a))

(define (rabin-test n)
  (define (try-it a)
    (= (expmod a (- n 1) n) 1))
  (try-it (+ 1 (random (- n 1)))))

(define (nontrivial-square-root? base m)
  (and (not (= base 0))
       (not (= base (- m 1)))
       (= (remainder (square base) m) 1)))

(define (fast-prime-rabin? n times)
  (cond ((= times 0) true)
        ((rabin-test n) (fast-prime-rabin? n (- times 1)))
        (else false)))

(fast-prime-rabin? 107 10)
