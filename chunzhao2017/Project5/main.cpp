#include<iostream>
#include<vector>
using namespace std;
using std::vector;

int main(void)
{
	int n;
	unsigned long k;
	cin >> n >> k;
	//vector<int> table(n, 0);
	int table[51];
	for (int i = 0; i < n; i++) {
		cin >> table[i];
	}

	for (unsigned long i = 0; i < k; i++) {
		int table0 = table[0];
		for (int j = 0; j < n - 1; j++) {
			table[j] = (table[j] + table[j + 1]) % 100;
		}
		table[n - 1] = (table[n - 1] + table0) % 100;
	}

	for (int i = 0; i < n; i++) {
		cout << table[i];
		if (i != n - 1) {
			cout << ' ';
		}
	}
	cout << endl;

	return 0;
}