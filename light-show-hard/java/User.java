public class User {

	private static boolean DEBUG = false;

	private static long[] idx2bits(long[] buttons, int M, int[] L, int[][] B) {
		for (int i = 0; i < M; i++) {
			for (int j = 0; j < L[i]; j++) {
				buttons[i] |= 1 << B[i][j];
			}
		}
		return buttons;
	}

	static long solve(int N, int M, int[] L, int[][] B) {
		final long[] buttons = new long[M];
		idx2bits(buttons, M, L, B);
		if (DEBUG) {
			for (int i = 0; i < M; i++) {
				System.out.println(String.format("%3s", Long.toBinaryString(buttons[i])).replace(' ', '0'));
			}
		}
		long state = 0;
		long prevState = 0;
		long length = 0;
		for (int i = 0; i < Math.pow(2, N); i++) {
			long newState = Long.MAX_VALUE;
			int idx = -1;
			for (int j = 0; j < M; j++) {
				final long s = state ^ buttons[j];
				if (prevState < s && s < newState) {
					newState = s;
					idx = j;
				}
			}
			if (newState == Long.MAX_VALUE) {
				break;
			}
			length++;
			prevState = state;
			state = newState;
			if (DEBUG) {
				System.out.println("i = " + idx + ", " + String.format("%3s", Long.toBinaryString(state)).replace(' ', '0'));
			}

		}
		return length;
	}
}
