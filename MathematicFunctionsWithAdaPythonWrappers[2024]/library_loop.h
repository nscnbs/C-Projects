#define library_loop
#ifdef library_loop

// Struktura do przechowywania wyników równania diofantycznego
typedef struct
{
    int x;
    int y;
} DiofanticResult;

// Funkcja obliczająca silnię n!
int factorial(int);

// Funkcja obliczająca największy wspólny dzielnik dwóch liczb naturalnych
int nwd(int, int);

// Funkcja rozwiązująca równanie diofantyczne ax + by = c
DiofanticResult diofantic(int, int, int);

#endif // library_loop
