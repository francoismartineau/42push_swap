import subprocess
import sys

if (len(sys.argv) < 3 or not sys.argv[1].isdigit() or not sys.argv[2].isdigit()):
	print("Usage: python3 benchmark.py <number of elements> <number of tests>")
	exit(1)

average = 0
test_qty = int(sys.argv[2])
cmd = f'./push_swap $(python3 generator.py {sys.argv[1]})'
for _ in range(test_qty):
	res = subprocess.check_output(cmd, shell=True).decode('utf-8')
	average += len(res.split('\n')) - 1
print(f'Average number of instructions: {average / test_qty}')