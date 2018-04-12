#include <stdio.h>
#include <time.h>

const long double eps = 0.0001;
const long double SQRT5 = 2.236;

int main (int argc, const char * argv[]) 
{
    clock_t begin, end;
    begin = clock();
    double Time;
    long double result = 0;
    for (int i = 0; i<100000; i++) {
        result = 0;
        int Buf = 1;
        long double Fib = 1;
        int St = 36;
        int Fac = 1;
        int counter = 3;
        long double term =0;
        do {
            term = Fib  / (St * Fac);
            Fib = Fib + Buf;
            Buf = Fib - Buf;
            St = St * 4;
            Fac = Fac * counter++;

            if (counter % 2 ==0) {
                result -= term;
            } else {
                result += term;
            }
            
        } while (term>eps);
    }
    end = clock();
    Time = (float)(end-begin)/CLOCKS_PER_SEC;

    printf("| %Lf  | %f  | ",result, Time);
    return 0;
}
