import example

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

print(example.multiplyMatrixMatrix( [[1,2,3], [4,5,6]], [[6,5], [4,3], [2,1]] ))
print(example.multiplyMatrixMatrix( [[6,5], [4,3], [2,1]], [[1,2,3], [4,5,6]] ))
print(example.addMatrixMatrix( [[1,2,3], [4,5,6]], [[4,5,6], [1,2,3]] ))
print(example.subtractMatrixMatrix( [[1,2,3], [4,5,6]], [[1,2,3], [4,5,6]] ))


y = example.Array([5, 3, 4, 5])
print("Arr:", y.toString())
yy = example.Array([])
print("Arr:", yy.toString())

y = y + 1
