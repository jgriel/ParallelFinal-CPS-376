import WorseNumPy
import numpy

a = WorseNumPy.Matrix([[]])
print(a.toString())

a = WorseNumPy.Matrix([[5], [], [1, 3, 5], []])
print(a.toString())

b = WorseNumPy.Matrix(3, 2, 1)
c = b + 1
print(c.toString())
c = c.scalarAdd(1)
print(c.toString())

c = b - 1
print(c.toString())
c = c.scalarSubtract(1)
print(c.toString())

c = b * 3
print(c.toString())
c = c.scalarMultiply(3)
print(c.toString())

a = WorseNumPy.Matrix([[2, 3], [4, 23]])
b = WorseNumPy.Matrix([[1, 9], [13, 7]])
c = a + b
print(c.toString())
c = a.addMatrix(b)
print(c.toString())

c = a.multiplyMatrix(b)
print(c.toString())
c = a * b
print(c.toString())
c = WorseNumPy.multiplyMatrixMatrix([[2, 3], [4, 23]], [[1, 9], [13, 7]])
print(c)

c = a - b
print(c.toString())
c = a.subtractMatrix(b)
print(c.toString())

c = a * b
print(c.toString())
a *= b
print(a.toString())

a = WorseNumPy.Matrix(5, 5, 1)
print(a.toString())

a.setItem(0, 0, 5)
print(a.toString())
print(a.getItem(0, 0))

a.setArray(0, [1, 3, 4, 5, 6])
print(a.toString())
print(a.getArray(0))

a = WorseNumPy.Matrix([[7, -2, 2, 2], 
                       [2, 8, -2, 3], 
                       [-3, 2, 11, -4], 
                       [-2, 3, 2, 10]])
print(a.L1Norm())
print(a.norm(1))
print(a.norm(2))
