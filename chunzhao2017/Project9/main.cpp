#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int main(void)
{
	int n;
	cin >> n;
	vector<vector<char> > table(n, vector<char>(n, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> table[i][j];
		}
	}

	int max = 0;
	for (int j = 0; j < n; j++) {
		int length = 1;
		for (int i = 1; i < n; i++) {
			if (table[i][j] == table[i - 1][j]) {
				length++;
				if (length > max) {
					max = length;
				}
			}
			else {
				length = 1;
			}
		}
	}

	cout << max << endl;

	return 0;
}