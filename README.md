## Calculator

The method of calculation - Revers Polish Notation.

More details about the algorithm https://habrahabr.ru/post/100869/


 This calculator check error like:
 ```
 "--1 + 2" double or more operands
 "12,,1 - 1"  double or more commas
 "12..1 - 1" double or more dots
 "((12.1 - 1)" double or more open parenthesis
 "(12.1 - 1))" double or more closing parenthesis
 "asd 12.1 - 1" incorrect elements
 "1+1" without whitespaces
 "1  +    1" one or more whitespaces
```

## Installation
 For install use makefile. Run make, then run make install
 
 For uninstall run make uninstall
 
 App name = calculator

## Tests

Unit tests based on CxxTest also included. 

CxxTest - https://github.com/CxxTest/cxxtest.git 

To run them you can run these commands:

make tests / ./runtests.sh - just run tests and print out a success rate.

make tests-verbose / ./runtests.sh -v - run tests and print out a success rate and some tracing information.


## Author

* **Sizykh Vladimir**
