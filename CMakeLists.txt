cmake_minimum_required(VERSION 3.26)
project(DSA C)

set(CMAKE_C_STANDARD 11)

add_executable(DSA
        Algo/Lab_07_01.c
        Algo/Lab_07_02.c
        Algo/Lab_07_03.c
        Algo/Lab_08.c
        Algo/sortlab.c
        Algo/sortlab2.c
        "dsa stack and queues/dsa stack and queues/QueueWithArrays.c"
        "dsa stack and queues/dsa stack and queues/QueueWithLinkedList.c"
        "dsa stack and queues/dsa stack and queues/StackWithArrays.c"
        "dsa stack and queues/dsa stack and queues/StackWithLinkedList.c"
        bracketsStack2.c
        CircularLinkedList.c
        cll.c
        dll.c
        DoublyLinkedList.c
        exprressionEval1.c
        exprressionEval2.c
        LL.c
        queue-Arr.c
        queue-LL.c
        SinglyLinkedList.c
        stack-Arr.c
        stack-LL.c
        t.c
        ValidParantheses.c
        Algo/Lab_09_01.c
        Recursion/factorial.c
        "Recursion/NonRecurionFacoria\;.c"
        Recursion/Fibonacchi.c
        empty.c
        Recursion/Lab_10_07.c
        Recursion/Lab_10_01.c
        Recursion/Lab_10_02.c
        Recursion/Lab_10_03.c
        Recursion/Lab_10_04.c
        Recursion/Lab_10_05.c
        Recursion/Lab_10_06.c
        stack-exercises/StackOverflowUnderflow.c
        stack-exercises/DecimalToBinary.c
        2005.c
        final.c
)
