 USAGE
// Recursion
//auto result = LCS(0, 0);

auto result = LCS();

std::string s1{ "abc" };
std::string s2{ "dadbdc" };

std::array<std::array<int, 7>, 4> matrix{};
// this is like matrix[4][7]

int LCS() {
	for (gsl::index i = 1; i < matrix.size(); ++i) {
		for (gsl::index j = 1; j < matrix[0].size(); ++j) {
			if (s1[i] == s2[j]) {
				// if match, 1 plus diagonal
				matrix[i][j] = 1 + matrix[i - 1][j - 1];
			}
			else {
				// if not match, max of 1 offs
				matrix[i][j] = std::max(matrix[i - 1][j], matrix[i][j - 1]);
			}
		}
	}
	return matrix[3][6];
}

/////////////
// Recursion
/////////////
//int LCS(int i, int j) {
//
//	if (i == s1.size() || j == s2.size()) {
//		return 0;
//	}
//
//	if (s1[i] != s2[j]) {
//		return std::max(LCS(i + 1, j), LCS(i, j + 1));
//	}
//	else {
//		return 1 + LCS(i + 1, j + 1);
//	}
//
//}
