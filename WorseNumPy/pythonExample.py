import WorseNumPy
import numpy
import time 

# CLASS FUNCTIONS
print(WorseNumPy.addInt(1, 2))
print(WorseNumPy.addInt(5, 2))
print(WorseNumPy.subtractInt(79, 10))
print(WorseNumPy.multiplyInt(12, 5))
print()

print(WorseNumPy.multiplyVectorMatrix([1,2,3], [[1,2,3], [4,5,6]]))
print()

print(WorseNumPy.addVectorVector([1,2,3], [2,4,6]))
print(WorseNumPy.subtractVectorVector([2,4,6], [1,2,3]))
print(WorseNumPy.multiplyVectorVector([2,4,6], [2,4,6]))
print()

print(WorseNumPy.scalarMatrixMultiply(2, [[1,2,3], [4,5,6]]))
print()


print(WorseNumPy.scalarMultiplyVector(2, [1,2,3,4,5]))
print(WorseNumPy.subtractInt(79, 10))
print(WorseNumPy.multiplyInt(12, 5))

print(WorseNumPy.scalarMultiplyVector(2, [1,2,3,4,5]))
print()

print(WorseNumPy.multiplyMatrixMatrix( [[1,2,3], [4,5,6]], [[6,5], [4,3], [2,1]] ))
print(WorseNumPy.multiplyMatrixMatrix( [[6,5], [4,3], [2,1]], [[1,2,3], [4,5,6]] ))
print(WorseNumPy.addMatrixMatrix( [[1,2,3], [4,5,6]], [[4,5,6], [1,2,3]] ))
print(WorseNumPy.subtractMatrixMatrix( [[1,2,3], [4,5,6]], [[1,2,3], [4,5,6]] ))


# x = WorseNumPy.Arrays()
a = numpy.array([1,2,3])
b = numpy.array([[1,2,3],[4,5,6]])
x = numpy.multiply(b,a)
print(x)
print()
