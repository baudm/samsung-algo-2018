@SuppressWarnings("unchecked")
public class mysolution {

    private static final long M = 1000000007;
    
    private static int N;
    private static int[] P;

	static void init(int N, int[] P) {
        mysolution.N = N;
        mysolution.P = P;
	}

	static void powerup(int x, int y) {
        for (; x <= y; x++) {
            P[x]++;
        }
	}

	static int teamwork(int x, int y) {
	    int power = 0;
        int left, right;
        long p;
        for (int i = 0; i < N; i++) {
            p = P[i];
            if (i >= x && i <= y) {
                left = i - 1;
                if (left < x) {
                    left = y;
                }
                right = i + 1;
                if (right > y) {
                    right = x;
                }
                p += P[left] + P[right];
            }
            power += fib_mod_M(p);
            // iteratively get the mod M value
            power %= M;
        }
        return power;
	}

    static int[] _fib_mod_M(long n) {
        if (n == 0) {
            return new int[]{0, 1};
        } else {
            long a, b, c, d;
            int[] out = _fib_mod_M(n / 2);
            // all terms are in mod M
            a = out[0]; //% M;
            b = out[1];// % M;
            //x = ((2 * b) % M - a) % M;
            // Fast doubling, in mod M
            c = (a * (((2 * b) % M - a) % M)) % M;
            d = ((a * a) % M + (b * b) % M) % M;
            if (n % 2 == 0) {
                out[0] = (int)c;
                out[1] = (int)d;
            } else {
                out[0] = (int)d;
                out[1] = (int)((c + d) % M);
            }
            return out;
        }
    }

    /**
    * Interface to _fib_mod_M
    */
    static int fib_mod_M(long n) {
        // The fib_mod_M sequence described in the problem is shifted by 1 index
        return _fib_mod_M(n + 1)[0];
    }
}
