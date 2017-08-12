#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
using std::vector;

int main(void)
{
	int n;
	cin >> n;
	vector<int> length(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> length[i];
		length[i] /= 1024;
	}

	int sum = 0, avg = 0;
	for (int i = 0; i < length.size(); i++) {
		sum += length[i];
	}
	avg = sum / 2;

	vector<int> dp(avg + 1, 0);
	for (int i = 0; i < n; i++) {
		for (int j = avg; j >= length[i]; j--) {
			dp[j] = max(dp[j], dp[j - length[i]] + length[i]);
		}
	}

	int result = (sum - dp[avg]) * 1024;
	cout << result << endl;

	return 0;
}