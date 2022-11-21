import example
import numpy

print(example.multiplyVectorMatrix([1,2,3], [[1,2,3], [4,5,6]]))


print(example.addVectorVector([1,2,3], [2,4,6]))
print(example.subtractVectorVector([2,4,6], [1,2,3]))
print(example.multiplyVectorVector([2,4,6], [2,4,6]))

print(example.scalarMatrix(2, [[1,2,3], [4,5,6]]))

print(example.scalarVector(2, [1,2,3,4,5]))
print(example.subtract(79, 10))
print(example.multiply(12, 5))

arr_a = example.array([1, 2, 3])
print(arr_a)

x = example.myArray([4, 5, 6])
print(x)
# print(arr_b)

# # x = example.Arrays()
# a = numpy.array([1,2 ])
# print(a)
# x = numpy.int(3)
# print(x)