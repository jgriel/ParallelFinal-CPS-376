import WorseNumPy
import time

# ArrayInt CLASS
print("ARRAY-INT +") 
y = WorseNumPy.ArrayInt([1, 2, 3, 4])
print(y.getItem(0))
y.setItem(0, 7)
print(y)
y = y + 1
print(y)
y += 1
print(str(y) + "\n")

print("ARRAY-INT -") 
y = WorseNumPy.ArrayInt([1, 2, 3, 4])
y = y - 2
print(y)
y -= 2
print(str(y) + "\n")

print("ARRAY-INT *") 
z = WorseNumPy.ArrayInt([1, 2, 3, 4])
z = z * 2
print(z)
z *= 2 
print(str(z) + "\n")

 
print("ARRAY-ARRAY") 
z = WorseNumPy.ArrayInt([1, 2, 3, 4]) 
y = WorseNumPy.ArrayInt([1, 2, 3, 4])
print("z: " + str(z) + "\n" + "y: " + str(y) + "\n")

print("z + y") 
aa = z + y
print(str(aa) + "\n")

print("z - y") 
aa = z - y
print(str(aa) + "\n")
 
print("z * y") 
aa = z * y
print(str(aa) + "\n")

print("SET/GET PROC") 
# WorseNumPy.setProcessors(4)
# print(WorseNumPy.getProcessors())
print()

print("ARRAY-ARRAY HELPER CALLS") 
aa = z + y
print(aa)
a = WorseNumPy.ArrayInt([1, 1, 1, 1])
aa = aa.addArray(a)
print(str(aa) + "\n")

aa = z + y
print(aa)
a = WorseNumPy.ArrayInt([1, 1, 1, 1])
aa = aa.subtractArray(a)
print(str(aa) + "\n")

aa = z + y
print(aa)
a = WorseNumPy.ArrayInt([2, 2, 2, 2])
aa = aa.multiplyArray(a)
print(str(aa) + "\n")

print("ARRAY-CONSTUCTOR") 
z = WorseNumPy.ArrayInt(5)
print(z)
z = WorseNumPy.ArrayInt(5, 7)
print(str(z) + "\n")

z = WorseNumPy.ArrayFloat(5, 7)
print(str(z) + "\n")

print("ARRAY-NORM") 
a = WorseNumPy.ArrayInt([1, 2, 3])
print(a.L1Norm())
a = WorseNumPy.ArrayInt([1, -2, 3])
print(a.L1Norm())

a = WorseNumPy.ArrayInt([1, 2, 3])
print(a.L2Norm())
a = WorseNumPy.ArrayInt([1, -2, 3])
print(a.L2Norm())

print("\nPARALLELIZATION TESTING")
a = WorseNumPy.ArrayDouble(9999999999999999, 12423)
b = WorseNumPy.ArrayDouble(9999999999999999, 12423)

WorseNumPy.setProcessors(1)
print(WorseNumPy.getProcessors())
start = time.time()
for i in range(5000000):
    a*b
runtime = time.time() - start
print(runtime, "seconds")

a = WorseNumPy.ArrayDouble(9999999999999999, 12423)
b = WorseNumPy.ArrayDouble(9999999999999999, 12423)
WorseNumPy.setProcessors(4)
print(WorseNumPy.getProcessors())
start = time.time()
for i in range(5000000):
    a*b
runtime = time.time() - start
print(runtime, "seconds")
