import sys
import random

if (len(sys.argv) < 2 or not sys.argv[1].isdigit()):
	print("Usage: python3 generator.py <number of elements>")
	exit(1)

numbers_qty = int(sys.argv[1])
numbers = list(range(numbers_qty))
random.shuffle(numbers)
for n in numbers:
    print(n, end=" ")