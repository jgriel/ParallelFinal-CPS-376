import WorseNumPy

# ARRAY CLASS
y = WorseNumPy.Array([1, 2, 3, 4])
print(y[0])
y[0] = 7
print(y.toString())
y = y + 1
print(y.toString())
y += 1
print(y.toString() + "\n")

y = WorseNumPy.Array([1, 2, 3, 4])
y = y - 2
print(y.toString())
y -= 2
print(y.toString() + "\n")

z = WorseNumPy.Array([1, 2, 3, 4])
z = z * 2
print(z.toString())
z *= 2 
print(z.toString() + "\n")

 
z = WorseNumPy.Array([1, 2, 3, 4]) 
y = WorseNumPy.Array([1, 2, 3, 4])

print(z.toString() + "\n" + y.toString() + "\n")

aa = z + y
print(aa.toString() + "\n")

aa = z - y
print(aa.toString() + "\n")
 
aa = z * y
print(aa.toString() + "\n")

WorseNumPy.setProcessors(4)
print(WorseNumPy.getProcessors())
print()

aa = z + y
print(aa.toString())
a = WorseNumPy.Array([1, 1, 1, 1])
aa = aa.addArray(a)
print(aa.toString() + "\n")

aa = z + y
print(aa.toString())
a = WorseNumPy.Array([1, 1, 1, 1])
aa = aa.subtractArray(a)
print(aa.toString() + "\n")

aa = z + y
print(aa.toString())
a = WorseNumPy.Array([2, 2, 2, 2])
aa = aa.multiplyArray(a)
print(aa.toString() + "\n")

z = WorseNumPy.Array(5)
print(z.toString())
z = WorseNumPy.Array(5, 7)
print(z.toString() + "\n")

a = WorseNumPy.Array([1, 2, 3])
print(a.L1Norm())
a = WorseNumPy.Array([1, -2, 3])
print(a.L1Norm())