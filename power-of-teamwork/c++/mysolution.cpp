#include <limits>
//#include <iostream>
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

int * _fib_mod_M(unsigned n) {
    //static long long LIM = std::sqrt(std::numeric_limits<long long>::max() / 2);
    
    static const int CACHE_SIZE = 10000000;
    
    static int cache1[CACHE_SIZE] = {0};
    static int cache2[CACHE_SIZE] = {0};
    
    static int o1;
    
	static int out[2];
	// make these static for efficiency
	static long a, b, c, d;
    
    if (n < CACHE_SIZE) {
        o1 = cache1[n];
        // cache hit
        if (o1) {
            out[0] = o1;
            out[1] = cache2[n];
            return out;
        }
    }

	if (n == 0) {
		out[0] = 0;
		out[1] = 1;
		return out;
	} else {
		_fib_mod_M(n / 2);
		// all terms are in mod M
		a = out[0];
		b = out[1];
		// Fast doubling, in mod M
        c = a * (2 * b - a);
        d = a * a + b * b;
		if (n % 2 == 0) {
			out[0] = c % M;
			out[1] = d % M;
		} else {
			out[0] = d % M;
			out[1] = (c + d) % M;
		}
		/* 104030264 */
		if (n < CACHE_SIZE) {
            cache1[n] = out[0];
            cache2[n] = out[1];
        }
		return out;
	}
}

/**
 * Interface to _fib_mod_M
 */
inline int fib_mod_M(unsigned n) {
    // Make these static for efficiency
    //static long x;
    static int fib;
    static bool mirror;
    
    // The Fibonacci sequence described in the problem is shifted by 1 index
    n++;
    
    // Take advantage of symmetry and periodicity of the outputs
    // to reduce the number of recursive calls
    // by finding an equivalent index which yields the same F mod M value.
    
    // reduce the index until it's <= M
    // The Pisano period for M is 2,000,000,016. The maximum possible index is:
    // p = 3 * ((10e9 + 7) + 10e5 - 1) (power ups)
    mirror = false;
    while (n > M) {
        n -= M + 1;
        mirror = !mirror;
    }
    // upper half
    if (n > M / 2 + 1) {
        n = M - n + 1;
        fib = (n % 2 == 0) ? _fib_mod_M(n)[0] : M - _fib_mod_M(n)[0];
    } else {
        // lower half
        fib = _fib_mod_M(n)[0];
    }
    
    return mirror ? M - fib : fib;
}

void init(int N, int P[100000]) {
	p_num = N;
	p_idx = P;
}


int teamwork(int x, int y) {
    static unsigned long long MAX = std::numeric_limits<unsigned long long>::max() - M;
    static long long power;
	static int left, right, i;
	static unsigned p;
    
    power = 0;
	for (i = 0; i < p_num; i++) {
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
        if (power >= MAX) {
            // iteratively get the mod M value
            power %= M;
        }
	}
	return power % M;
}
