# Data Structures & Algorithms in C

A collection of data structure and algorithm implementations written in plain C while learning DSA. Every file is a small, self-contained program with its own `main()`, so you can compile and run any of them on its own.

## What's inside

### Linked lists
| File | Description |
|------|-------------|
| [SinglyLinkedList.c](SinglyLinkedList.c) | Menu-driven singly linked list: insert / delete at beginning, end or position, search, update, display, reverse display |
| [LL.c](LL.c) | Another singly linked list implementation |
| [DoublyLinkedList.c](DoublyLinkedList.c), [dll.c](dll.c) | Doubly linked list with forward and reverse traversal |
| [CircularLinkedList.c](CircularLinkedList.c), [cll.c](cll.c) | Circular linked list operations |
| [Lab_02.txt](Lab_02.txt) | Linked list lab: insert, insert at position, reverse display |

### Stacks & queues
| File | Description |
|------|-------------|
| [stack-Arr.c](stack-Arr.c) | Stack using an array (push, pop, peek, isEmpty, isFull) |
| [stack-LL.c](stack-LL.c) | Stack using a linked list |
| [queue-Arr.c](queue-Arr.c) | Queue using an array (enqueue, dequeue, peek, rear, display) |
| [queue-LL.c](queue-LL.c) | Queue using a linked list |
| [dsa stack and queues/](<dsa stack and queues/dsa stack and queues/>) | Alternate stack and queue implementations (array and linked list) |

### Stack applications
| File | Description |
|------|-------------|
| [ValidParantheses.c](ValidParantheses.c), [t.c](t.c) | Balanced brackets checker (array stack) |
| [bracketsStack2.c](bracketsStack2.c), [final.c](final.c) | Balanced brackets checker (linked list stack) |
| [2005.c](2005.c) | Palindrome checker using a stack |
| [exprressionEval1.c](exprressionEval1.c) | Postfix expression evaluation |
| [exprressionEval2.c](exprressionEval2.c) | Infix calculator with `+`, `-` and parentheses |
| [stack-exercises/StackOverflowUnderflow.c](stack-exercises/StackOverflowUnderflow.c) | Stack overflow / underflow handling demo |
| [stack-exercises/DecimalToBinary.c](stack-exercises/DecimalToBinary.c) | Decimal to binary conversion using a stack |

### Sorting
| File | Description |
|------|-------------|
| [Algo/Lab_07_01.c](Algo/Lab_07_01.c) – [Lab_07_03.c](Algo/Lab_07_03.c) | Selection sort (ascending, descending, applied example) |
| [Algo/Lab_08.c](Algo/Lab_08.c) | Bubble sort |
| [Algo/sortlab.c](Algo/sortlab.c), [sortlab2.c](Algo/sortlab2.c), [empty.c](empty.c) | Insertion sort |
| [Algo/Sorting.c](Algo/Sorting.c) | Insertion, selection and bubble sort side by side |

### Recursion
| File | Description |
|------|-------------|
| [Algo/Lab_09_01.c](Algo/Lab_09_01.c) – [Lab_09_05.c](Algo/Lab_09_05.c) | Factorial, Fibonacci, multiplication by repeated addition, prime check, number pattern |
| [Recursion/factorial.c](Recursion/factorial.c) | Tail-recursive factorial |
| [Recursion/NonRecurionFacoria;.c](<Recursion/NonRecurionFacoria;.c>) | Iterative factorial, for comparison |
| [Recursion/Fibonacchi.c](Recursion/Fibonacchi.c) | Recursive Fibonacci |
| [Recursion/Lab_10_01.c](Recursion/Lab_10_01.c) – [Lab_10_07.c](Recursion/Lab_10_07.c) | Countdown, factorial, string traversal, GCD (Euclid), reverse array, decimal to binary, mutual recursion (odd/even) |

## Getting started

You need a C compiler such as GCC or Clang. On Windows, MinGW-w64 works.

Each file is a standalone program, so compile it on its own:

```bash
gcc SinglyLinkedList.c -o SinglyLinkedList
./SinglyLinkedList
```

```bash
gcc Recursion/Lab_10_04.c -o gcd
./gcd
```

Most of the data structure programs are menu-driven: run them and choose an operation by number.

> **Note:** [CMakeLists.txt](CMakeLists.txt) currently puts every file into a single executable. Because each file has its own `main()`, that build fails at link time. Use `gcc` per file as shown above.

## Topics covered

- Singly, doubly and circular linked lists
- Stacks and queues, each built on arrays and on linked lists
- Stack applications: bracket matching, palindromes, postfix evaluation, base conversion
- Selection, bubble and insertion sort
- Recursion: direct, tail and mutual

## License

Released under the [MIT License](LICENSE).
