# 🔄 Push_swap

## 📌 Description
A program that sorts a stack of integers using only a limited set of operations.
It outputs the shortest sequence of valid moves possible to perform the sorting.
The project is evaluated on algorithmic efficiency and clean code.

## 📂 Features
- Validates and parses input arguments.
- Detects duplicates and handles integer limits.
- Implements all required operations (sa, sb, pa, pb, ra, rb, etc.).
- Produces an optimized sequence of moves.
- Memory leak–free and fully Norm-compliant.

## 🚀 Usage
```sh
# Clone the repository
$ git clone https://github.com/dcuencag/push_swap.git
$ cd push_swap

# Compile the project
$ make

# Run with a list of integers
$ ./push_swap 2 1 3 6 5 8

# (Optional) Check result using a checker if available
$ ./push_swap 3 2 1 | ./checker_Mac 3 2 1
