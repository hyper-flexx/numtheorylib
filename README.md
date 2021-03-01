# numtheorylib
Lightweight template library, that could do some basic operations with the number divisors.
_You can freely use and modify it._
## Library linking
The library consists of a single header file __numtheorylib.hpp__, that could be simply included by `#include "numtheorylib.hpp"` into your source file.
If you're using an online IDE, such as _ideone_, you can copy the _MNumTheory_ namespace into the source file.
## Basic library usage
#### Solver initialization
```C++
MNumTheory::solver<> solver;
```
#### Greatest common divisor
```C++
solver(X, Y);
```
#### Least common multiple
```C++
solver[{X, Y}];
```
#### Divisor operations
Will be added in the next update.
