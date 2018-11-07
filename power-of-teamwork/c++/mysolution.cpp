#include <limits>
#include <iostream>
//#include <cmath>

const int MAX_N = 100000;
const long long M = 1000000007;

static int * p_idx;
static int p_num = 0;


void powerup(int x, int y) {
	for (; x <= y; x++) {
		p_idx[x]++;
	}
}

long long * _fib_mod_M(long n) {
    //static long long LIM = std::sqrt(std::numeric_limits<long long>::max() / 2);
	static long long out[2];
	// make these static for efficiency
	static long long a, b, c, d;
	if (n == 0) {
		out[0] = 0;
		out[1] = 1;
		return out;
	} else {
		_fib_mod_M(n / 2);
		// all terms are in mod M
		a = out[0];
		b = out[1];
        //std::cout << "a = " << a << ", b = " << b << std::endl;
		//x = ((2 * b) % M - a) % M;
		// Fast doubling, in mod M
        c = a * (2 * b - a);
		//c = (a * (((2 * b) % M - a) % M)) % M;
		//d = ((a * a) + (b * b)) % M;
        d = a * a + b * b;
		if (n % 2 == 0) {
			out[0] = c % M;
			out[1] = d % M;
		} else {
			out[0] = d % M;
			out[1] = (c + d) % M;
		}
		return out;
	}
}

/**
 * Interface to _fib_mod_M
 */
long __fib_mod_M(long n) {
    // Take advantage of symmetry and periodicity of the outputs
    // to reduce the number of recursive calls
    // by finding an equivalent index which yields the same F mod M value.
    return _fib_mod_M(n)[0];
    /*
    if (n <= M) {
        long x = M - n + 1;
        if (x < M / 2) {
            return (n % 2 == 0) ? _fib_mod_M(x)[0] : M - _fib_mod_M(x)[0];
        } else {
            return _fib_mod_M(n)[0];
        }
    } else {
        // recursively reduce the index until its within [1, M]
        long x = n - M;
        return M - __fib_mod_M(x - 1);
    }*/
}

long fib_mod_M(long n) {
    // The Fibonacci sequence described in the problem is shifted by 1 index
    return __fib_mod_M(n + 1);
}

void init(int N, int P[100000]) {
	p_num = N;
	p_idx = P;
    
    //std::cout << "fib(x) = " << fib_mod_M(100000000000L) << std::endl;
}

#include <iostream>
int teamwork(int x, int y) {
    static unsigned long long ULL_MAX = std::numeric_limits<unsigned long long>::max();
    long n = 1000099999L;
    long ax = -668824126L;
    std::cout << "n = " << n << ", F(n) = " << fib_mod_M(n) << ",   " << ax % M << std::endl;
	 long long power = 0;
	int left, right;
	long p;
	for (int i = 0; i < p_num; i++) {
		p = p_idx[i];
		if (i >= x && i <= y) {
			left = i - 1;
			if (left < x) {
				left = y;
			}
			right = i + 1;
			if (right > y) {
				right = x;
			}
			p += p_idx[left] + p_idx[right];
		}
		power += fib_mod_M(p);
        // Reduce modulo operations by using the largest int variable
        // Only perform it just before overflowing
        if (power >= ULL_MAX - M) {
            // iteratively get the mod M value
            power %= M;
        }
	}
	return power % M;
}
