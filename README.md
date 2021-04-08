# big_int

`big_int` is an implementation of big integer library in C++

#### Contents

* [Overview](#Overview)
* [Usage](#Usage)
* [Features](#Features)
* [Insights](#Insights)
* [Contributing](#Contributing)
* [License](#License)

## Overview

* `big_int` is a header-only library for working with integer values larger than the C++ built-in data types
* Simple to get started. Simply download the [header file][file-link], include it in your code and start using the library
* No additional dependencies required
* Works well with modern versions of C++ (C++11 / C++14 / C++17)

## Usage

#### Getting started

Download the [header file][file-link] to any location in your project folder. Then `#include` it in your code depending upon where you put the file :

```c++
#include "big_int.hpp"
```
or

```c++
#include "folder_name/big_int.hpp"
```

#### Creating objects

An object of the `big_int` class can be instantiated in multiple ways :

   ```c++
// default value
big_int a;                             // 'a' gets the value 0

// 'int' as an argument
big_int b(49);                         // 'b' gets the value 49

// 'long long' as an argument
// Make sure value fits in long long
big_int c(-9223372036854775808);       // 'c' gets the value -9223372036854775808

// 'std::string' as an argument
big_int d("9223372036854775899");      // 'd' gets the value 9223372036854775899

// using the assignment operator
big_int e = -49;                       // 'e' gets the value -49
big_int f = 9223372036854775807;       // 'f' gets the value 9223372036854775807
big_int g = std::string("98765432198");// 'g' gets the value 98765432198 
   ```

## Features

### Operators

* #### Assignment : `=`
  An instance can be assigned value using the assignment `=` operator. The second operand can be either a `big_int`, an integer (fitting in the `long long` range), or a `std::string`.
  ```c++
  a = 987654;
  b = std::string("123456789");
  b = a;

  std::string str = "123456";
  a = str;
  ```

* #### Increment and decrement : `++`, `--`
  ```c++
  // pre-increment/decrement
  big_int a = 1;
  big_int b = ++a;        // a = 2, b = 2
  b = --a;                // a = 1, b = 1

  //post-increment/decrement
  big_int c = 1;
  big_int d = c++;        // c = 2, d = 1
  d = c--;                // c = 1, d = 2
  ```

* #### Arithmetic : `+`, `-`, `*`, `/`, `%`
  Both the operands must be instances of the `big_int` class.

  ```c++
  big_int a("987654321987654321");
  big_int b("123456789123456789");

  big_int c = a + b;        // c = 1111111111111111110
  big_int d = a - b;        // d = 864197532864197532 
  big_int e = a * b;        // e = 121932631356500531347203169112635269
  big_int f = a / b;        // f = 8
  big_int g = a % b;        // g = 9000000009
  ```

* #### Arithmetic - assignment : `+=`, `-=`, `*=`, `/=`, `%=`
  Both the operands must be instances of the `big_int` class.
  ```c++
  big_int a("987654321987654321");
  big_int b(123456789);
  a += b;                 // a = 987654322111111110
  a -= b;                 // a = 987654321987654321
  a *= b;                 // a = 121932631234567900112635269
  a /= b;                 // a = 987654321987654321
  a %= b;                 // a = 111111201
  ```

* #### Relational / Comparison : `==`, `!=`, `>=`, `<=`, `>`, `<`
  Both the operands must be instances of the `big_int` class.
  ```c++
  big_int a(12345);
  big_int b(54321);
  big_int c(98765);

  if(a >= b || b != c || a > c) {...}
  if(b == c && a <= b && a < c) {...}
  ```

* #### I/O stream : `>>`, `<<`
  ```c++
  big_int a, b;
  std::cin >> a >> b;
  std::cout << a << " " << b << std::endl;
  ```

### Instance methods

 * #### `.absolute()`
    Returns the absolute value of an instance.

    ```c++
    big_int a(-49);
    big_int b = a.absolute();       // b = 49
    ```

  * #### `.digit_count()`
    Returns the number of digits in an instance.

    ```c++
    big_int a(12345), b(-1234), c("-0000023");
    std::cout << a.digit_count();    // 5
    std::cout << b.digit_count();    // 4
    std::cout << c.digit_count();    // 2
    ```

  * #### `.multiply_10(int count)`
    Returns a `big_int` instance with the value equals `value of the current instance` multiplied by 10, `count` times. If `count` is not specified, then its value is taken as 1. This is much faster than multiplying using the `*` operator.

    ```c++
    big_int a(1234);
    big_int b = a.multiply_10(5);      // b = 123400000
    big_int c = a.multiply_10();       // c = 12340
    ```

  * #### `.divide_10(int count)`
    Returns a `big_int` instance with the value equals `value of the current instance` divided by 10, `count` times. If `count` is not specified, then its value is taken as 1. This is much faster than dividing using the `/` operator.

    ```c++
    big_int a(123456);
    big_int b = a.divide_10(4);      // b = 12
    big_int c = a.divide_10();       // c = 12345
    ```

  * #### `.fits_in_ll()`
    Returns whether an instance lies in the range of `long long` or not.

    ```c++
    big_int a("9223372036854775807");
    big_int b("-9223372036854775809");
    std::cout << a.fits_in_ll();      // 1
    std::cout << b.fits_in_ll();      // 0
    ```

  * #### `.is_zero()`
    Returns whether the value of an instance is `0` or not.

    ```c++
    big_int a;
    big_int b(1);
    std::cout << a.is_zero();        // 1
    std::cout << b.is_zero();        // 0 
    ```

## Insights

* An instance can be printed by using the output stream `std::cout <<`, but the `.print()` instance method can also be used.

* An instance can be taken input by using the input stream `std::cin >>`, but the `.read()` instance method can also be used.

* Arithmetic operations can also be done by using instance methods upon the object which is left operand of the operation. `+`, `-`, `*`, `/` and `%` can be performed by `.add(big_int)`, `.subtract(big_int)`, `.multiply(big_int)`, `.divide(big_int)` and `.modulo(big_int)` respectively.

* The `.set_value()` instance method can also be used an alternative to the assignment `=` operator by passing the right operand as the argument.

* Multiplication is implemented using the traditional slow multiplication algorithm and a faster [Karatsuba multiplication algorithm][karatsuba-wiki]. The feasible one is used depending upon the operands.

* As of now, the modulo `%` method does not returns the correct result for **negative** integers which are out of the `long long` range.


## Contributing

Contributions are welcome. Fork this repository, make the desired changes, open a pull request or an issue.
Make sure your changes does not introduce any bugs and all the tests are passing.

## License

This project is licensed under the terms of [MIT License][license-link].



[license-link]: https://github.com/devanshu-raj/big_int/blob/master/LICENSE
[karatsuba-wiki]: https://en.wikipedia.org/wiki/Karatsuba_algorithm
[file-link]: https://github.com/devanshu-raj/big_int/blob/master/big_int.hpp
