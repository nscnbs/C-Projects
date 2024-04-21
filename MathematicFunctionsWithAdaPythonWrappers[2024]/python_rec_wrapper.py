# gcc -shared -o library_rec.so -fPIC library_rec.c -std=c99

import ctypes

library_rec = ctypes.CDLL("D:\\Studia\\VI sem\\Paradygmaty\\lista1\\C\\library_rec.so")  

class DiofanticResult(ctypes.Structure):
    _fields_ = [("x", ctypes.c_int),
                ("y", ctypes.c_int)]

library_rec.factorial.argtypes = [ctypes.c_int]
library_rec.factorial.restype = ctypes.c_int

library_rec.nwd.argtypes = [ctypes.c_int, ctypes.c_int]
library_rec.nwd.restype = ctypes.c_int

library_rec.diofantic.argtypes = [ctypes.c_int, ctypes.c_int, ctypes.c_int]
library_rec.diofantic.restype = DiofanticResult

def factorial(n):
    return library_rec.factorial(n)

def nwd(a, b):
    return library_rec.nwd(a, b)

def diofantic(a, b, c):
    return library_rec.diofantic(a, b, c)

if __name__ == "__main__":
    print("Python wrapper C")
    n = 5
    print(f"{n}! = {factorial(n)}")

    num1, num2 = 36, 48
    print(f"NWD: {num1} i {num2} = {nwd(num1, num2)}")

    a, b, c = 120, 144, 72
    result = diofantic(a, b, c)
    if result.x != -1 and result.y != -1:
        print(f"Rozwiazanie rownania {a}x + {b}y = {c} to x = {result.x}, y = {result.y}")
    else:
        print(f"Brak rozwiazania dla rownania {a}x + {b}y = {c}")
