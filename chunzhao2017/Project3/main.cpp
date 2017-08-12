#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
using std::string;

#define BG 0
#define GB 1

int bg_sort(string queue, int direct) {
	int result = 0;
	for (int i = 0; i < queue.size(); i++) {
		for (string::iterator p = queue.begin(); p < queue.end()-1; p++) {
			if (direct == BG)
			{
				if ((*p == 'G') && (*(p + 1) == 'B')) {
					*p = 'B';
					*(p + 1) = 'G';
					result++;
				}
			}
			else if (direct == GB) {
				if ((*p == 'B') && (*(p + 1) == 'G')) {
					*p = 'G';
					*(p + 1) = 'B';
					result++;
				}
			}
		}
	}

	return result;
}

int main(void) {
	string s;
	cin >> s;
	int result = min(bg_sort(s, BG), bg_sort(s, GB));

	cout << result << endl;

	return 0;
}