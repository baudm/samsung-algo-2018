int solve(int N, int A[100000]) {
	unsigned long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}
	return sum / N;
}
