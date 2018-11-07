/*
 * Prelim:
 *
 * A light can take two states: ON (1) or OFF (0). Given N lights,
 * we can represent the state of the system at any given time using
 * an N-bit vector.
 *
 * Likewise, for each button, we can use an N-bit vector to encode
 * which light is toggled by it. Each 1 bit in the button vector
 * corresponds to a light in the same position.
 *
 * The act of pressing a button and toggling the current light state
 * can be modelled by a series of XOR (^) operations. Because of the properties of XOR,
 * e.g. A ^ A = 0, the state S, at any given time, will be an XOR combination
 * of the M buttons, S = k1B1 ^ k2B2 ^ ... ^ kMBM, where the coefficients k{1..M} is from {0, 1}
 * There will never be more than M terms in the equation.
 *
 * Even though M can be >= N, we know that the state is N bits only, which means that
 * we should expect a maximum of N basis bit vectors. The other M - N buttons
 * are only XOR combinations of the N basis vectors.
 *
 * The total number of unique states, U, is just a function of the number of basis vectors, V,
 * such that U = 2eV. This means that we can find the longest sequence of button presses
 * without actually generating the sequence. To generate the actual sequence, we simply generate
 * V-bit Gray codes and use the bits as the coefficients for the corresponding basis vectors.
 */

void idx2bits(unsigned int buttons[], int M, int L[10], int B[10][3]) {
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < L[i]; j++) {
			buttons[i] |= (unsigned int)1 << B[i][j];
		}
	}                                                                                                                                                      
}

unsigned short get_msb_pos(unsigned int num) {
	if (num == 0) {
		return 0;
	}
	unsigned short n = 0;
	while (num > 1) {
		num >>= 1;
		n++;
	}
	return n;
}

unsigned int bin2gray(unsigned int bin, int n) {
	unsigned int orig = bin;
	for (int i = 0; i < n; i++) {
		// if Dn-1 is 1...
		if (bin & (1 << (i + 1))) {
			// toggle Dn
			bin ^= (1 << i);
		}
	}
	return bin;
}

int solve(int N, int M, int L[10], int B[10][3], int out[]) {
	// Preprocess the inputs such that we can represent each button as an N-bit vector
	unsigned int* buttons = new unsigned int[M]();
	idx2bits(buttons, M, L, B);

	int num_basis = 0;
	unsigned int basis_idx[3] = {0};
	// Gaussian elimination to find the basis bit vectors (independent buttons)
	for (int i = 0; i < M; i++) {
		if (buttons[i]) {
			basis_idx[num_basis++] = i;
		} else {
			// Skip 'dependent' buttons
			continue;
		}
		unsigned int msb = 1 << get_msb_pos(buttons[i]);
		// find buttons with the same MSB
		for (int j = i + 1; j < M; j++) {
			// and toggle it so that only the current button has an MSB at that position
			if (buttons[j] & msb) {
				buttons[j] ^= buttons[i];
			}
		}
	}
	delete [] buttons;

	// Since the act of pressing a button is equivalent to XOR The light state can be modelled as a running linear combination of the inputs (buttons),
	// We can define the group as the set of all binary vectors [0, 2eN - 1], and the group operation as XOR.
	// The sequence of outputs can be computed by a matrix multiplication of Gray code * independent buttons.
	// This means that the number of outputs is simply a function of the length of the Gray code,
	// which is basically determined by the number of independent buttons (M - dependent).
	// Finally, we subtract 1 to account for the initial state, 0.
	unsigned int length = (1 << num_basis) - 1;

	unsigned int gray = 0;
	for (int i = 1; i < length + 1; i++) {
		unsigned int g = bin2gray(i, num_basis);
		// get bit position of change
		unsigned int pos = get_msb_pos(g ^ gray);
		gray = g;
		out[i - 1] = basis_idx[pos];
	}

	return length;
}
