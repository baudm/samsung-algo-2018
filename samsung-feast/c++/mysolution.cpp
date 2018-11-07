#include <iostream>

int solve(int N, char A[2][10001]) {
	// counters for the first line
	unsigned int I1 = 0, E1 = 0, L1 = 0;
	// counters for the second line
	unsigned int I2 = 0, E2 = 0, L2 = 0;

	for (int i = 0; i < N; i++) {
		switch (A[0][i]) {
			case 'I':
				I1++;
				break;
			case 'E':
				E1++;
				break;
			case 'L':
				L1++;
		}
		switch (A[1][i]) {
			case 'I':
				I2++;
				break;
			case 'E':
				E2++;
				break;
			case 'L':
				L2++;
		}
	}

	unsigned int score = 0;

	unsigned int min = I1 < I2 ? I1 : I2;
	I1 -= min;
	I2 -= min;
	score += min;

	min = E1 < E2 ? E1 : E2;
	E1 -= min;
	E2 -= min;
	score += min;

	// Only one of E1 or I1 will be nonzero at this point
	if (L2) {
		if (E1) {
			min = E1 < L2 ? E1 : L2;
			E1 -= min;
		} else {
			min = I1 < L2 ? I1 : L2;
			I1 -= min;
		}
		//L2 -= min;
	}

	// Only one of E2 or I2 will be nonzero at this point
	/*
	if (L1) {
		if (E2) {
			min = E2 < L1 ? E2 : L1;
			E2 -= min;
		} else {
			min = I2 < L1 ? I2 : L1;
			I2 -= min;
		}
		L1 -= min;
	}
	*/

	// At this point, both L1 and L2 should be zero.
	// deduct E-I pairings
	score -= I1;
	score -= E1;


	//std::cout << I1 << ", " << E1 << ", " << L1 << std::endl;
	//std::cout << I2 << ", " << E2 << ", " << L2 << std::endl;

	return score;
}
