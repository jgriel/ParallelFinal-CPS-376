import WorseNumPy
import time

print("\nMATRIX PARALLELIZATION TESTING")
a = WorseNumPy.MatrixDouble(999, 999, 2)
b = WorseNumPy.MatrixDouble(999, 999, 3)
print("matrix matrix multiplication")
WorseNumPy.setProcessors(1)

start = time.time()  
a*b
runtime = time.time() - start
print(runtime, "seconds - serial")

a = WorseNumPy.MatrixDouble(999, 999, 2)
b = WorseNumPy.MatrixDouble(999, 999, 3)
numProcesses = 32
WorseNumPy.setProcessors(numProcesses)

start = time.time()
a*b
runtime = time.time() - start
print(runtime, "seconds - parallel", numProcesses, "processors")


print("\nmatrix matrix addition")
a = WorseNumPy.MatrixDouble(30000, 30000, 2)
b = WorseNumPy.MatrixDouble(30000, 30000, 3)
WorseNumPy.setProcessors(1)

start = time.time()  
a+b
runtime = time.time() - start
print(runtime, "seconds - serial")

a = WorseNumPy.MatrixDouble(30000, 30000, 2)
b = WorseNumPy.MatrixDouble(30000, 30000, 3)
numProcesses = 8
WorseNumPy.setProcessors(numProcesses)

start = time.time()
a+b
runtime = time.time() - start
print(runtime, "seconds - parallel", numProcesses, "processors")


print("\n\nARRAY PARALLELIZATION TESTING")
print("Array Array Multiplication")
a = WorseNumPy.ArrayDouble(999999, 12423)
b = WorseNumPy.ArrayDouble(999999, 12423)
WorseNumPy.setProcessors(1)

start = time.time()
a*b
runtime = time.time() - start

print(runtime, "seconds - serial")

a = WorseNumPy.ArrayDouble(999999, 12423)
b = WorseNumPy.ArrayDouble(999999, 12423)
numProcesses = 4
WorseNumPy.setProcessors(numProcesses)

start = time.time()
a*b
runtime = time.time() - start

print(runtime, "seconds - parallel", numProcesses, "processors")