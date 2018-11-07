@SuppressWarnings("unchecked")
public class mysolution {

    static boolean[][] S = new boolean[100000][100000];

	static void init(int N, int M, int[][] C) {
        for (int i = 0; i < M; i++) {
            int subordinate = C[i][0];
            int superior = C[i][1];
            S[subordinate][superior] = true;
        }
	}

	static int superior(int a, int b) {
	    return S[a][b] ? b : a;
	}
}
