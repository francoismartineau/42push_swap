# 42push_swap

Push Swap is an exercise where the program must give a list of instructions to sort a stack. The stack is a list of distinct numbers given as arguments. An initially empty secondary stack is avalaible. The possible instructions are as follows:<br>
<br>
sa: swap the top and second elements of stack a <br>
sb: same for stack b<br>
ss: same for both stacks<br>
<br>
ra: move the top element of stack a to bottom<br>
rb: same for stack b<br>
rr: same for both stacks<br>
<br>
rra: move the last element of stack a to top<br>
rrb: same for stack b<br>
rrr: same for both stacks<br>
<br>
pa: push a's top element to b's top<br>
pb: push b's top element to a's top<br>
<br>
The program should print the smallest possible list of instructions that sorts the stack.<br>
Compilation:<br>
$ make<br>
The exercise's bonus is a program that reads a list of instructions and checks if they successfully sort the stack.<br>
Compilation:<br>
$ make bonus<br>
The generator.py script gives a randomly ordered list of numbers.<br>
Testing the correctness of push_swap:<br>
$ ARG="$(python3 generator.py 100)"; ./push_swap $ARG | ./checker $ARG<br>
<br>
Here's the threshold for a perfect score:<br>
Number of elements: maximum number of instructions<br>
3: 3<br>
5: 12<br>
100: 699<br>
500: 5499<br>
<br>
Testing the performance of push_swap once:<br>
$ ARG="$(python3 generator.py 100)"; ./push_swap $ARG | wc -l<br>
<br>
The benchmark.py gives an average performance given multiple tests:<br>
$ python3 benchmark.py 3 1000 <br>
'python3 benchmark.py 3 1000<br>
Average number of instructions: 1.151<br>
Maximum number of instructions: 2<br>
Minimum number of instructions: 0'<br>
$ python3 benchmark.py 5 1000<br>
'Average number of instructions: 6.459<br>
Maximum number of instructions: 12<br>
Minimum number of instructions: 0'<br>
$ python3 benchmark.py 100 1000<br>
'Average number of instructions: 579.828<br>
Maximum number of instructions: 647<br>
Minimum number of instructions: 529'<br>
$ python3 benchmark.py 500 1000 <br>
'Average number of instructions: 5132.158<br>
Maximum number of instructions: 5373<br>
Minimum number of instructions: 4812'<br>
