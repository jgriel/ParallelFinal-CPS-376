import example
import numpy

a = example.Matrix([[]])
print(a.toString())

a = example.Matrix([[5], [], [1, 3, 5], []])
print(a.toString())

b = example.Matrix(3, 2, 1)
c = b + 1
print(c.toString())

c = b - 1
print(c.toString())

c = b * 3
print(c.toString())

a = example.Matrix([[2, 3], [4, 23]])
b = example.Matrix([[1, 9], [13, 7]])
c = a + b
print(c.toString())

c = a - b
print(c.toString())