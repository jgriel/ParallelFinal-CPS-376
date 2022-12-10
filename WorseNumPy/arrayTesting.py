import WorseNumPy
import numpy
import time

def meAA(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 *= a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def mAA(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 * a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")
    
def seAA(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 -= a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def sAA(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 - a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def aeAA(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 += a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def aAA(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 + a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")


def meAF(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = 12345.12
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 *= a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def mAF(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = 12345.12
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 * a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def seAF(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = 12345.12
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 -= a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def sAF(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = 12345.12
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 - a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def aeAF(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = 12345.12
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 += a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")

def aAF(p):
    a1 = WorseNumPy.ArrayFloat(1000000, 12345.12)
    a2 = 12345.12
    WorseNumPy.setProcessors(p)
    
    start = time.time()
    a1 + a2
    runtime = time.time() - start
    
    print(runtime, "seconds -", p, "processors")


if __name__ == "__main__":
    print("ARRAY PARALLELIZATION TIMING TESTING\n")
    
    print("ARRAY-ARRAY (float)")
    print("*=")
    p = 1
    while p < 33:
        meAA(p)
        p *= 2
    
    print("\n*")
    p = 1
    while p < 33:
        mAA(p)
        p *= 2
    
    print("\n-=")
    p = 1
    while p < 33:
        seAA(p)
        p *= 2
    
    print("\n-")
    p = 1
    while p < 33:
        sAA(p)
        p *= 2
    
    print("\n+=")
    p = 1
    while p < 33:
        aeAA(p)
        p *= 2
    
    print("\n+")
    p = 1
    while p < 33:
        aAA(p)
        p *= 2
        

    print("\n\nARRAY-FLOAT")
    print("*=")
    p = 1
    while p < 33:
        meAF(p)
        p *= 2
    
    print("\n*")
    p = 1
    while p < 33:
        mAF(p)
        p *= 2
    
    print("\n-=")
    p = 1
    while p < 33:
        seAF(p)
        p *= 2
    
    print("\n-")
    p = 1
    while p < 33:
        sAF(p)
        p *= 2
    
    print("\n+=")
    p = 1
    while p < 33:
        aeAF(p)
        p *= 2
    
    print("\n+")
    p = 1
    while p < 33:
        aAF(p)
        p *= 2