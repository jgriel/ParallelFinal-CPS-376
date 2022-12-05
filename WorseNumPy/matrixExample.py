import WorseNumPy
import numpy
import time

a = WorseNumPy.MatrixInt([[]])
print(a)

a = WorseNumPy.MatrixInt([[5], [], [1, 3, 5], []])
print(a)

b = WorseNumPy.MatrixInt(3, 2, 1)
c = b + 1
print(c)
c = c.scalarAdd(1)
print(c)
c += 1
print(c)

c = b - 1
print(c)
c = c.scalarSubtract(1)
print(c)
c -= 1
print(c)

c = b * 3
print(c)
c = c.scalarMultiply(3)
print(c)
print(b)
b *= 3
print(b)

a = WorseNumPy.MatrixInt([[2, 3], [4, 23]])
b = WorseNumPy.MatrixInt([[1, 9], [13, 7]])
c = a + b
print(c)
c = a.addMatrix(b)
print(c)
print(a)
a += b
print(a)

c = a.multiplyMatrix(b)
print(c)
c = a * b
print(c)
c = WorseNumPy.multiplyMatrixMatrix([[2, 3], [4, 23]], [[1, 9], [13, 7]])
print(c)

c = a - b
print(c)
c = a.subtractMatrix(b)
print(c)
print(a, b)
a -= b
print(a)

c = a * b
print(c)
a *= b
print(a)

a = WorseNumPy.MatrixInt(5, 5, 1)
print(a)

a.setItem(0, 0, 5)
print(a)
print(a.getItem(0, 0))

a.setArray(0, [1, 3, 4, 5, 6])
print(a)
print(a.getArray(0))

a = WorseNumPy.MatrixDouble([[7, -2, 2, 2], 
                       [2, 8, -2, 3], 
                       [-3, 2, 11, -4], 
                       [-2, 3, 2, 10]])
print(a.L1Norm())
print(a.L2Norm())

a = WorseNumPy.MatrixFloat(5, 5, 1)
print(a)

print("\nPARALLELIZATION TESTING")
a = WorseNumPy.MatrixDouble([[99999999999999999999999999999999999999999999999999, 99999999999999999999999999999999999999999999999999], [99999999999999999999999999999999999999999999999999, 99999999999999999999999999999999999999999999999999]])
b = 99999999999

start = time.time()   
for i in range(5000000):
    a*=b
runtime = time.time() - start
print(runtime, "seconds")

a = WorseNumPy.MatrixDouble([[99999999999999999999999999999999999999999999999999, 99999999999999999999999999999999999999999999999999], [99999999999999999999999999999999999999999999999999, 99999999999999999999999999999999999999999999999999]])
b = 99999999999
WorseNumPy.setProcessors(4)
start = time.time()
for i in range(5000000):
    a*=b
runtime = time.time() - start
print(runtime, "seconds")
