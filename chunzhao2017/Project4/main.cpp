#include<iostream>
#include<vector>
using namespace std;
using std::vector;


int main(void) {
	int num;
	cin >> num;
	vector<int> a(num, 0);
	for (int i = 0; i < num; i++) {
		cin >> a[i];
	}

	vector<int> flag_table(1001, 0);
	vector<int> result;
	for (int i = num - 1; i >= 0; i--) {
		if (flag_table[a[i]] == 0) {
			result.push_back(a[i]);
			flag_table[a[i]] = 1;
		}
	}

	for (int i = result.size() - 1; i >= 0; i--) {
		cout << result[i];
		if (i != 0) {
			cout << ' ';
		}
	}

	cout << endl;

	return 0;
}