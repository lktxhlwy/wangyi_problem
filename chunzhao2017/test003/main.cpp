#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
using namespace std;
using std::vector;
using std::list;

int main(void)
{
	int n;
	cin >> n;
	vector<int> height(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> height[i];
	}
	sort(height.begin(), height.end());

	int sum = 0;
	int mod = n % 4;
	switch (mod) {
	case(0):
		for (int i = 0; i < n; i++) {
			if (i <= (n / 2 - 2)) {
				sum -= 2 * height[i];
			}
			else if (i <= (n / 2 - 1)) {
				sum -= height[i];
			}
			else if (i <= n / 2) {
				sum += height[i];
			}
			else {
				sum += 2 * height[i];
			}
		}
		break;
	case(1):
		for (int i = 0; i < n; i++) {
			if (i <= (n - 1) / 2 - 1) {
				sum -= 2 * height[i];
			}
			else if (i <= (n - 1) / 2 + 1) {
				sum += height[i];
			}
			else {
				sum += 2 * height[i];
			}
		}
		break;
	case(2):
		for (int i = 0; i < n; i++) {
			if (i <= n / 2 - 2) {
				sum -= 2 * height[i];
			}
			else if (i <= n / 2 - 1) {
				sum -= height[i];
			}
			else if (i <= n / 2) {
				sum += height[i];
			}
			else {
				sum += 2 * height[i];
			}
		}
		break;
	case(3):
		for (int i = 0; i < n; i++) {
			if (i <= (n - 1) / 2 - 2) {
				sum -= 2 * height[i];
			}
			else if (i <= (n - 1) / 2) {
				sum -= height[i];
			}
			else {
				sum += 2 * height[i];
			}
		}
	default:
		break;

	}

	cout << sum << endl;

	return 0;

}