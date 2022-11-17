import example

print(example.add(1, 2))
print(example.add(5, 2))

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

arr_b = example.array([[1], [2, 4], [1, 1, 2]])
print(arr_b)