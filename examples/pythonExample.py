import example
import numpy

print(example.addInt(1, 2))
print(example.addInt(5, 2))
print(example.subtractInt(79, 10))
print(example.multiplyInt(12, 5))

print(example.multiplyVectorMatrix([1,2,3], [[1,2,3], [4,5,6]]))

print(example.addVectorVector([1,2,3], [2,4,6]))
print(example.subtractVectorVector([2,4,6], [1,2,3]))
print(example.multiplyVectorVector([2,4,6], [2,4,6]))

print(example.scalarMatrix(2, [[1,2,3], [4,5,6]]))

print(example.scalarVector(2, [1,2,3,4,5]))
print(example.subtractInt(79, 10))
print(example.multiplyInt(12, 5))

# arr_a = example.array([1, 2, 3])
# print(arr_a)

x = example.my2dArray([[6, 2], [2, 5, 7], [], [3, 2, 3, 4, 5 ,6], []])
print("2d:", x.toString())
xx = example.my2dArray([])
print("2d:", xx.toString())
y = example.my1dArray([5, 3, 4, 5])
print("1d:", y.toString())
yy = example.my1dArray([])
print("1d:", yy.toString())
# print(arr_b)

print(example.multiplyMatrixMatrix( [[1,2,3], [4,5,6]], [[6,5], [4,3], [2,1]] ))
print(example.multiplyMatrixMatrix( [[6,5], [4,3], [2,1]], [[1,2,3], [4,5,6]] ))
print(example.addMatrixMatrix( [[1,2,3], [4,5,6]], [[4,5,6], [1,2,3]] ))
print(example.subtractMatrixMatrix( [[1,2,3], [4,5,6]], [[1,2,3], [4,5,6]] ))

# x = example.Arrays()
a = numpy.array([1,2,3])
b = numpy.array([[1,2,3],[4,5,6]])
x = numpy.multiply(b,a)
print(x)
