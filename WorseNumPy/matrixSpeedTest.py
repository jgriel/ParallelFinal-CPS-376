import WorseNumPy
import numpy
import time

def testMatrixMultiply(p):
    a = WorseNumPy.MatrixFloat(1200, 1200, 2)
    b = WorseNumPy.MatrixFloat(1200, 1200, 3)
    print("matrix matrix multiplication *")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a*b
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testMatrixMultiplyOverload(p):
    a = WorseNumPy.MatrixFloat(1200, 1200, 2)
    b = WorseNumPy.MatrixFloat(1200, 1200, 3)
    print("matrix matrix multiplication *=")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a*=b
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testAddMatrix(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    b = WorseNumPy.MatrixFloat(12000, 12000, 3)
    print("matrix matrix addition +")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a+b
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testAddMatrixOverload(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    b = WorseNumPy.MatrixFloat(12000, 12000, 3)
    print("matrix matrix addition +=")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a+=b
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testSubtractMatrix(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    b = WorseNumPy.MatrixFloat(12000, 12000, 3)
    print("matrix matrix subtraction -")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a-b
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testSubtractMatrixOverload(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    b = WorseNumPy.MatrixFloat(12000, 12000, 3)
    print("matrix matrix subtraction -=")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a-=b
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

# Scalar Matrix
def testScalarMatrixMultiply(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    scalar = 5.0
    print("scalar matrix multiply *")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a * scalar
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testScalarMatrixMultiplyOverload(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    scalar = 5.0
    print("scalar matrix multiply *=")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a *= scalar
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testScalarMatrixAdd(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    scalar = 5.0
    print("scalar matrix add +")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a + scalar
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testScalarMatrixAddOverload(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    scalar = 5.0
    print("scalar matrix add +=")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a += scalar
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testScalarMatrixSubtract(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    scalar = 5.0
    print("scalar matrix subtraction -")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a - scalar
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

def testScalarMatrixSubtractOverload(p):
    a = WorseNumPy.MatrixFloat(12000, 12000, 2)
    scalar = 5.0
    print("scalar matrix subtraction -=")
    WorseNumPy.setProcessors(p)

    start = time.time()  
    a -= scalar
    runtime = time.time() - start
    print(runtime, "seconds - num processors:", p)

# numpy Matrix-Matrix Tests
def testNumpyMultiplyMatrix():
    a = numpy.full([1200, 1200], 2.0, dtype = float)
    b = numpy.full([1200, 1200], 3.0, dtype = float)
    print("numpy matrix matrix multiplication *")

    start = time.time()  
    a*b
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyMultiplyMatrixOverload():
    a = numpy.full([1200, 1200], 2.0, dtype = float)
    b = numpy.full([1200, 1200], 3.0, dtype = float)
    print("numpy matrix matrix multiplication *=")

    start = time.time()  
    a*=b
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyAddMatrix():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    b = numpy.full([12000, 12000], 3.0, dtype = float)
    print("numpy matrix matrix addition +")

    start = time.time()  
    a+b
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyAddMatrixOverload():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    b = numpy.full([12000, 12000], 3.0, dtype = float)
    print("numpy matrix matrix addition +=")

    start = time.time()  
    a+=b
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpySubtractMatrix():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    b = numpy.full([12000, 12000], 3.0, dtype = float)
    print("numpy matrix matrix subtraction -")

    start = time.time()  
    a-b
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpySubtractMatrixOverload():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    b = numpy.full([12000, 12000], 3.0, dtype = float)
    print("numpy matrix matrix subtraction -=")

    start = time.time()  
    a-=b
    runtime = time.time() - start
    print(runtime, "seconds")

# Numpy Matrix Scalar Tests
def testNumpyScalarMatrixMultiply():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    scalar = 5.0
    print("numpy scalar matrix multiply *")

    start = time.time()  
    a * scalar
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyScalarMatrixMultiplyOverload():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    scalar = 5.0
    print("numpy scalar matrix multiply *=")

    start = time.time()  
    a *= scalar
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyScalarMatrixAddition():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    scalar = 5.0
    print("numpy scalar matrix Addition +")

    start = time.time()  
    a + scalar
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyScalarMatrixAdditionOverload():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    scalar = 5.0
    print("numpy scalar matrix Addition +=")

    start = time.time()  
    a += scalar
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyScalarMatrixSubtraction():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    scalar = 5.0
    print("numpy scalar matrix subtraction -")

    start = time.time()  
    a - scalar
    runtime = time.time() - start
    print(runtime, "seconds")

def testNumpyScalarMatrixSubtractionOverload():
    a = numpy.full([12000, 12000], 2.0, dtype = float)
    scalar = 5.0
    print("numpy scalar matrix Addition -=")

    start = time.time()  
    a -= scalar
    runtime = time.time() - start
    print(runtime, "seconds")


def main():
    print("---TESTING NUMPY SPEED---\n")
    testNumpyMultiplyMatrix()
    testNumpyMultiplyMatrixOverload()
    testNumpyAddMatrix()
    testNumpyAddMatrixOverload()
    testNumpySubtractMatrix()
    testNumpySubtractMatrixOverload()

    testNumpyScalarMatrixMultiply()
    testNumpyScalarMatrixMultiplyOverload()
    testNumpyScalarMatrixAddition()
    testNumpyScalarMatrixAdditionOverload()
    testNumpyScalarMatrixSubtraction()
    testNumpyScalarMatrixSubtractionOverload()
    
    print("\n---TESTING WORSENUMPY SPEED---\n")
    i = 1
    while (i < 33):
        testMatrixMultiply(i)
        i *= 2
    print()

    i = 1
    while (i < 33):
        testMatrixMultiplyOverload(i)
        i *= 2
    print()

    i = 1
    while (i < 33):
        testAddMatrix(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testAddMatrixOverload(i)
        i *= 2
    
    print()
    i = 1
    while (i < 33):
        testSubtractMatrix(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testSubtractMatrixOverload(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testScalarMatrixMultiply(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testScalarMatrixMultiplyOverload(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testScalarMatrixAdd(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testScalarMatrixAddOverload(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testScalarMatrixSubtract(i)
        i *= 2

    print()
    i = 1
    while (i < 33):
        testScalarMatrixSubtractOverload(i)
        i *= 2
main()