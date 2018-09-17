# Course 1

## The topic of this course

计算机科学的宗旨就是降低复杂度，它是一门降低复杂度的艺术。
全篇可以分为三个部分：

- Black-box abstraction  黑盒抽象
- Conventional interfaces  约定接口
- Metalinguistic abtraction 元编程抽象 也就是创造新语言 Eval<->Apply

## A Introduction to Lisp (General framework)

如果我们想要学习一门新的语言，一些基本的情况需要我们了解：
    
- Primitive Elements  基本元素有哪些
- Means of Combination 组合这些基本元素的方法
- Means of Absteaction 抽象的方法

### A Really start about Lisp

1.Primitive Elements
列如: + 3 17.3 这些都是基本元素

2.Combination
(+ 3 17.3 5) -> 25.4

其中括号内就是Combination
而Combination是由一个Operator 咧如 + 和一些 Operands 3 ...
然而Operands也可以是Combination.
Like: (+ 3 (* 5 6) * 2)
Lisp采用 Prefix notation 前缀表示法 可以想想成一个表达式树

3.Definition  

    （DEFINE A (* 5 5) )  
        (* A A) -> 625

    (DEFINE (SQUARE X) (* X X))  
        (SQUARE 10) -> 100

    (DEFINE SQUARE (LAMBDA (X) (* X X))) (syntatic sugar)  
SQUARE的值是Precedure

4.Case analysis

    (DEFINE (ABS X)  
        (COND ((< X 0) (-X))  
            ((= X 0) (0))  
            ((> X 0) X)))  
    (DEFINE (ABS X)  
        (IF (< X 0)  
        (- X)  
        X))  

算平方根的程序

    (DEFINE (TRY GUESS X)  
        (IF (GOOD-ENOUGH? GUESS X)  
        GUESS  
        (TRY (IMPROVE GURSS X))))  

    (DEFINE (SQURT X) (TRY 1 X))  

    (DEFINE (IMPROVE GUESS X)  
        (AVERAGE GUESS (/ X GUESS)))  

    (DEFINE (GOOD-ENOUGH? GUESS X)  
        (< (ABS (- (SQUARE GUESS) X))  
        .001))  

Another Try:  

    (DEFINE (SQRT X)  
        (DEFINE (IMPROVE GUESS)  
            (AVERAGE GUESS (/ X GUESS)))  
        (DEFINE (GOOD-ENOUGH? GUESS)  
            (< (ABS (- (SQUARE GUESS) X))  
            .001))  
        (DEFINE (TRY GUESS)  
            (IF (GOOD-ENOUGH? GUESS)  
            GUESS  
            (TRY (IMPROVE GUESS))))  
        (TRY 1))  


### Some example of lisp

    (DEFINE (SOS X Y)
        (+ (SQ X) (SQ Y)))
    (DEFINE (SQ X)
        (* X X))
    (SOS 3 4) -> 25
    
## Rules of how we understand programs

### Substitution Rule

To evaluate an application  
    Evaluate the operator to get procedure
    Evaluate the operands to get arguments
    Apply the procedure to the arguments 
        Copy the body of the procedure
            substituting the arguments supplied
            for the formal paramenters of the procedure
        Evaluate the resulting new body

#### Peano Arithmetic

Two ways to add whole numbers:

    ;; Linear Iteration
    (DEFINE (+ x y)
        (if (= x 0)
            y
            (+ (-1+ x) (1+ y))))
    时间复杂度 : O(x)
    空间复杂度 : O(1)
    
    ;; Linear Recursion
    (DEFINE (+ x y)
        (if (= x 0)
            y
            (1+ (+ (-1+ x) y))))
    时间复杂度 : O(x)
    空间复杂度 : O(x)
    
    
Fibonacci numbers

    (DEFINE (FIB N)
        (IF (< N 2)
            N
            (+ (FIB (- N 1))
               (FIB (- N 2)))))
               
Tower of Hanoi

    (DEFINE (MOVE N FROM TO SPARE)
        (COND ((= N 0) "DONE")
            (else
                (MOVE (-1+ N) FROM SPARE TO)
                (PRINT-MOVE FROM TO)
                (MOVE (-1+ N) SPARE TO FROM))))

## 练习

### 习题1.1

    10 -> 10
    (+ 5 3 4) -> 12
    (- 9 1) -> 8
    (/ 6 2) -> 3
    (+ (* 2 4) (- 4 6)) -> 6
    (define a 3) -> a
    (define b (+ a 1)) -> b
    (+ a b (* a b)) -> 19
    (= a b) -> #f
    (if (and (> b a) (< b (* a b)))
        b
        a) -> 4
    (cond ((= a 4) 6)
        (( = b 4) (+ 6 7 a))
        (else 25)) -> 16
    (+ 2 (if (> b a) b a)) -> 6
    (* (cond ((> a b) a)
             ((< a b) b)
             (else -1))
       (+ a 1)) -> 16
    
### 习题1.2
    
    (/ (+ 5 4 (- 2 (- 3 (+ 6 (/ 4 5)))))
       (* 3 (- 6 2) (- 2 7)))
       
### 习题1.3
    
    (define (maxSum x y z)
            (cond (((< x y) and (< x z)) (+ y z))
            (((< y z) and (< y x)) (+ x z))
            (((< z y) and (< z x)) (+ y x))))
            
### 习题1,4

如果b大于0，则该过程可以代替为 (+ a b)。如果b小于等于0,则该过程可以代替为 (- a b)。则它们的功能为a加上b的绝对值。
    
### 习题1.5

如果使用应用序，程序会陷入死循环。如果是正则序，则程序会返回0.

### 习题1.6

如果使用new-if则，程序会爆栈，因为new-if是一般过程，而一般过程则会把两个参数的值都求出来，而这样的情况，Scheme不会进行尾递归优化。使用if则不同。
    
### 习题1.7
    
    （define (sqrt-iter guess x)
        (if (good-enough? guess x)
            guess
            (sqrt-iter (improve guess x)
                       x)))
可以改为

    （define (sqrt-iter guess x)
        (if (good-enough? guess (improve guess x))
            guess
            (sqrt-iter (improve guess x) x)))
            
对于很小的数依旧不可以，因为精度太低.//Wrong
实践证明，对于很大很小的数依旧可以做到比较的效果

### 习题1.8

    （define (cuberoot guess x)
        (if (good-enough? guess (improve guess x))
            guess
            (cuberoot (improve guess x) x)))
    (define (improve guess x)
        (/ (+ (/ x (* guess guess)) (* 2 guess)) 3))
        

            
