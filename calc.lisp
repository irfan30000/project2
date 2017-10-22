;;;Title:-Implement an calculator (64 bit Binary Multiplication) application using concurrent lisp.
;;;Assignmnet no:-
;;;Batch:-T2
(defvar a)
(defvar b)
(defvar c)
(defun :bits (value &optional (size 64))
(format t "~v,'~b" size value))

(write-line "Enter 1st numbers: ")
(setq  a(read))
(write-line "Enter 2nd numbers: ")
(setq  b(read))     

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(+ a b))
		            (print "Addition is: ")
				(print c ))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(- a b))
				(print "Subtraction is: ")
				(print c))))

 	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* a b))
				(print "Multiplication is: ")
				(print c))))
      (sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(/ a b))
                        (print "Division is:")
                        (print c))))
	
	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* a a))
				(print "Square of number 1: ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(* b b b))
				(print "Cube of number 2: ")
				(print c))))	

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(sin a))
				(print "Sine of number 1 : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(tan a))
				(print "Tan of number 2 : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(cos a))
				(print "Cosine of number 1 : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(min a b))
				(print "Minimum number : ")
				(print c))))

	(sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(max a b))
				(print "Maximum number : ")
				(print c))))

      (sb-thread:make-thread(lambda()(progn(sleep 0)
				(setf c(mod a b))
				(print "Modulus of numbers : ")
				(print c))))

      
(exit)

;;;*******************OUTPUT********************
swl-08@Comp-SWL-08:~$ cd POOJ@P3
swl-08@Comp-SWL-08:~/POOJ@P3$ sbcl
This is SBCL 1.3.1.debian, an implementation of ANSI Common Lisp.
More information about SBCL is available at <http://www.sbcl.org/>.

SBCL is free software, provided as is, with absolutely no warranty.
It is mostly in the public domain; some portions are provided under
BSD-style licenses.  See the CREDITS and COPYING files in the
distribution for more information.
* (load "calc.lisp")
Enter 1st numbers: 
12
Enter 2nd numbers: 
2

"Addition is: " 
14 
"Subtraction is: " 
10 
"Multiplication is: " 
24 
"Division is:" 
6 
"Square of number 1: " 
144 
"Cube of number 2: " 
8 
"Sine of number 1 : " 
-0.53657293 
"Tan of number 2 : " 
-0.6358599 
"Cosine of number 1 : " 
0.84385395 
"Minimum number : " 
2 
"Maximum number : " 
12 
"Modulus of numbers : " 
0 
