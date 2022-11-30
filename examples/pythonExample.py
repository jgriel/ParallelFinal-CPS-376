import example
import numpy

# CLASS FUNCTIONS
print(example.addInt(1, 2))
print(example.addInt(5, 2))
print(example.subtractInt(79, 10))
print(example.multiplyInt(12, 5))
print()

print(example.multiplyVectorMatrix([1,2,3], [[1,2,3], [4,5,6]]))
print()

print(example.addVectorVector([1,2,3], [2,4,6]))
print(example.subtractVectorVector([2,4,6], [1,2,3]))
print(example.multiplyVectorVector([2,4,6], [2,4,6]))
print()

print(example.scalarMatrixMultiply(2, [[1,2,3], [4,5,6]]))
print()


print(example.scalarMultiplyVector(2, [1,2,3,4,5]))
print(example.subtractInt(79, 10))
print(example.multiplyInt(12, 5))

print(example.scalarMultiplyVector(2, [1,2,3,4,5]))
print()

print(example.multiplyMatrixMatrix( [[1,2,3], [4,5,6]], [[6,5], [4,3], [2,1]] ))
print(example.multiplyMatrixMatrix( [[6,5], [4,3], [2,1]], [[1,2,3], [4,5,6]] ))
print(example.addMatrixMatrix( [[1,2,3], [4,5,6]], [[4,5,6], [1,2,3]] ))
print(example.subtractMatrixMatrix( [[1,2,3], [4,5,6]], [[1,2,3], [4,5,6]] ))


# x = example.Arrays()
a = numpy.array([1,2,3])
b = numpy.array([[1,2,3],[4,5,6]])
x = numpy.multiply(b,a)
print(x)
print()
