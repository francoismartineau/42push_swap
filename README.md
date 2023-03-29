# 42push_swap

Push Swap is an exercise where the program must give a list of instructions to sort a stack. The stack is a list of distinct numbers given as arguments. 
An initially empty secondary stack is avalaible.
The possible instructions are as follows:

sa: swap the top and second elements of stack a
sb: same for stack b
ss: same for both stacks

ra: move the top element of stack a to bottom
rb: same for stack b
rr: same for both stacks

rra: move the last element of stack a to top
rrb: same for stack b
rrr: same for both stacks

pa: push a's top element to b's top
pb: push b's top element to a's top

The program should print the smallest possible list of instructions that sorts the stack.
Compilation:
$ make
The exercise's bonus is a program that reads a list of instructions and checks if they successfully sort the stack.
Compilation:
$ make bonus
The generator.py script gives a randomly ordered list of numbers.
Testing the correctness of push_swap:
$ ARG="$(python3 generator.py 100)"; ./push_swap $ARG | ./checker $ARG

Here's the threshold for a perfect score:
Number of elements: maximum number of instructions
3: 3
5: 12
100: 699
500: 5499

Testing the performance of push_swap once:
$ ARG="$(python3 generator.py 100)"; ./push_swap $ARG | wc -l

The benchmark.py gives an average performance given multiple tests:
$ python3 benchmark.py 3 1000 
'python3 benchmark.py 3 1000
Average number of instructions: 1.151
Maximum number of instructions: 2
Minimum number of instructions: 0'
$ python3 benchmark.py 5 1000
'Average number of instructions: 6.459
Maximum number of instructions: 12
Minimum number of instructions: 0'
$ python3 benchmark.py 100 1000
'Average number of instructions: 579.828
Maximum number of instructions: 647
Minimum number of instructions: 529'
$ python3 benchmark.py 500 1000 
'Average number of instructions: 5132.158
Maximum number of instructions: 5373
Minimum number of instructions: 4812'
