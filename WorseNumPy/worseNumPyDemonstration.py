import WorseNumPy

print("---MATRIX DEMONSTRATION---\n")
# DEMONSTRATE CONSTRUCTOR
print("Constructor method: 4 x 2 prefilled matrix with 3s (int)")
a = WorseNumPy.MatrixInt(4, 2, 3)
print(a, "\n")

print("Constructor method: providing a matrix (float)")
a = WorseNumPy.MatrixFloat([[2.32, 42.89, 4], 
                            [1.34, 4.52, 25.3], 
                            [1.76, 3.43, 0.54]])
print(a, "\n")

# DEMONSTRATE SCALAR-MATRIX OPERATIONS
# scalar add, scalar subtract, scalar multiply
print("Scalar add demonstration")
a = WorseNumPy.MatrixInt([[2, 0, 4], 
                          [1, 3, 7]])
print("Before addition:    a =", a)
b = a + 5
print("After addition: a + 5 =", b, "\n")

print("Scalar subtraction deomonstration")
print("Before subtraction: a =", a)
b = a - 5
print("After addition: a - 5 =", b, "\n")

print("scalar multiply demonstration")
print("Before multiplicaiton:    a =", a)
b = a * 5
print("After multiplication: a * 5 =", b, "\n")

# DEMONSTRATE MATRIX-MATRIX OPERATIONS
# matrix add, matrix substract, matrix multiply
print("Matrix add demonstration")
a = WorseNumPy.MatrixDouble([[2.5, 0, 4.3], 
                             [1.4, 3, 7]])
b = WorseNumPy.MatrixDouble([[3, 0, 2.4], 
                             [1, 3.9, 7]])
print("Before addition:")
print("                    a =", a)
print("                    b =", b)
c = a + b
print("After addition: a + b =", c, "\n")

print("Matrix subtract demonstration")
a = WorseNumPy.MatrixDouble([[2.5, 0, 4.3], 
                             [1.4, 3, 7]])
b = WorseNumPy.MatrixDouble([[3, 0, 2.4], 
                             [1, 3.9, 7]])
print("Before subtraction:")
print("                       a =", a)
print("                       b =", b)
c = a - b
print("After subtraction: a - b =", c, "\n")

print("Matrix multiply demonstration")
a = WorseNumPy.MatrixInt([[2, 0, 4], 
                          [1, 3, 7]])
b = WorseNumPy.MatrixInt([[3, 5, 2], 
                          [1, 3, 7], 
                          [4, 12, 9]])
print("Before multiplication:")
print("                          a =", a)
print("                          b =", b)
c = a * b
print("After multiplication: a * b =", c, "\n")

#DEMONSTRATE GET AND SET OPERATIONS
print("Get/set item demonstration demonstration")
a = WorseNumPy.MatrixInt([[2, 0, 4], 
                          [1, 3, 7]])
print("Matrix:", a)
print("Get item [1][2]:", a.getItem(1, 2))
a.setItem(1, 2, 45)
print("Set item [1][2] = 45:", a)
print("Get item [1][2]:", a.getItem(1, 2), "\n")

print("Get/set row demonstration")
a = WorseNumPy.MatrixInt([[2, 0, 4], 
                          [1, 3, 7], 
                          [4, 2, 99]])
print("Matrix:", a)
print("Get row [1]:", a.getRow(1))
a.setRow(1, [1, 2, 45])
print("Set row [1] = [1, 2, 45]:", a)
print("Get row [1]:", a.getRow(1), "\n")

# DEMONSTRATE NORM OPERATIONS
# L1 Norm, L2 Norm
print("L1 and L2 norm demonstration")
a = WorseNumPy.MatrixInt([[7, -2, 2, 2], 
                             [2, 8, -2, 3], 
                             [-3, 2, 11, -4], 
                             [-2, 3, 2, 10]])
print("Matrix:", a)
print("L1 Norm:", a.L1Norm())
print("L2 Norm:", a.L2Norm())

print("\n\n---ARRAY DEMONSTRATION---\n")
# DEMONSTRATE CONSTRUCTOR
print("Constructor method: ")


print("Constructor method: ")


# DEMONSTRATE SCALAR-VECTOR OPERATIONS
# scalar add, scalar subtract, scalar multiply
print("Scalar add demonstration")

print("Scalar subtraction deomonstration")


print("scalar multiply demonstration")


# DEMONSTRATE MATRIX-MATRIX OPERATIONS
# matrix add, matrix substract, matrix multiply
print("Vector add demonstration")


print("Vector subtract demonstration")


print("Vector multiply demonstration")

#DEMONSTRATE GET AND SET OPERATIONS
print("Get/set item demonstration demonstration")


# DEMONSTRATE NORM OPERATIONS
# L1 Norm, L2 Norm
print("L1 and L2 norm demonstration")
