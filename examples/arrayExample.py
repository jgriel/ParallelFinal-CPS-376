import example

# ARRAY CLASS
y = example.Array([1, 2, 3, 4])
print(y[0])
y[0] = 7
print(y.toString())
y = y + 1
print(y.toString())
y += 1
print(y.toString() + "\n")

y = example.Array([1, 2, 3, 4])
y = y - 2
print(y.toString())
y -= 2
print(y.toString() + "\n")

z = example.Array([1, 2, 3, 4])
z = z * 2
print(z.toString())
z *= 2 
print(z.toString() + "\n")

 
z = example.Array([1, 2, 3, 4]) 
y = example.Array([1, 2, 3, 4])

print(z.toString() + "\n" + y.toString() + "\n")

aa = z + y
print(aa.toString() + "\n")

aa = z - y
print(aa.toString() + "\n")
 
aa = z * y
print(aa.toString() + "\n")

example.setProcessors(4)
print(example.getProcessors())
print()

aa = z + y
print(aa.toString())
a = example.Array([1, 1, 1, 1])
aa = aa.addArray(a)
print(aa.toString() + "\n")

aa = z + y
print(aa.toString())
a = example.Array([1, 1, 1, 1])
aa = aa.subtractArray(a)
print(aa.toString() + "\n")

aa = z + y
print(aa.toString())
a = example.Array([2, 2, 2, 2])
aa = aa.multiplyArray(a)
print(aa.toString() + "\n")