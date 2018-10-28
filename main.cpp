#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * Trimming before the first a and after the last u.
 */
bool trim(string &s)
{
	size_t first, last;

	if ((first = s.find_first_of('a')) == string::npos) {
		return false;
	}

	char *u = new char('u');
	if ((last = s.find_last_of(u, string::npos, s.length() - 1 - first)) == string::npos) {
		delete u;
		return false;
	}
	delete u;

	s = s.substr(first, last - first + 1);

	return true;
}

/**
 * Returns maximum of 2 variables.
 */
int max(int const &a, int const &b)
{
	if (a > b) {
		return a;
	}

	return b;
}

/**
 * Recursively traverses the matrix to get the
 * maximum value.
 *
 * if the given row is true, go right
 *
 * if not:
 *
 * if can't go down, go right
 *
 * else:
 *
 * try both right and down, get the max value
 */
int recursive(vector<vector<pair<bool, int>>> &matrix, int x, int y, bool canGoDown)
{
	int temp;

	// If it's over the reach of the matrix,
	// it will return 0.
	if (x == matrix.size() || y == matrix[0].size()) {
		return 0;
	}

	if (matrix[x][y].second != 0) {
		return matrix[x][y].second;
	}

	// If it reaches to the right edge of the matrix but
	// it isn't the lowest row, it means the substring
	// doesn't end with 'u'. This will return -1.
	if (x < matrix.size() - 1 && y == matrix[0].size() - 1) {
		return matrix[x][y].second = -1;
	}

	// If the current cell is true, it will go right
	// no matter what.
	if (matrix[x][y].first) {
		canGoDown = true;
		temp = recursive(matrix, x, y + 1, canGoDown);
		return matrix[x][y].second = (temp == -1) ? temp : temp + 1;
	}

	// If can't go down, will go right no matter what.
	if (!canGoDown) {
		return matrix[x][y].second = recursive(matrix, x, y + 1, canGoDown);
	}

	// Will try both, get the max
	return matrix[x][y].second = max(recursive(matrix, x, y + 1, false),
	                                 recursive(matrix, x + 1, y, false));
}

/**
 * Trims the string.
 *
 * Creates an unordered map to be able to get the
 * integer values for (a, e, i, o, u) that matches
 * with (0, 1, 2, 3, 4) accordingly.
 *
 * Creates a matrix out of the given string that
 * consists of 5 rows (a, e, i, o, u) and s.length()
 * columns.
 *
 * Calls the the recursive function and gets a maximum
 * value.
 *
 * Returns it.
 */
int calculateMagic(string s)
{
	if (!trim(s)) {
		return 0;
	}

	unordered_map<char, int> keys;

	keys.insert(make_pair<char, int>('a', 0));
	keys.insert(make_pair<char, int>('e', 1));
	keys.insert(make_pair<char, int>('i', 2));
	keys.insert(make_pair<char, int>('o', 3));
	keys.insert(make_pair<char, int>('u', 4));

	vector<vector<pair<bool, int>>> matrix;

	// Creating the matrix.
	for (int i = 0; i < 5; i++) {
		matrix.emplace_back(vector<pair<bool, int>>(s.length()));
	}

	// Filling the matrix.
	// example: a u will create the matrix:
	//	1 0 -> row for 'a'
	//	0 0 -> row for 'e'
	//	0 0 -> row for 'i'
	//	0 0 -> row for 'o'
	//	0 1 -> row for 'u'
	for (int i = 0; i < s.length(); i++) {
		matrix[keys.at(s[i])][i].first = true;
	}

	int result = recursive(matrix, 0, 0, false);

	// If there is no possible substring, the
	// recursive function will return -1.
	if (result < 0) {
		return 0;
	}

	return result;
}

int main()
{
	string s;
	cin >> s;
	cout << calculateMagic(s);
	return 0;
}
