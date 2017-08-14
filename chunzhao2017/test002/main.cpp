#include<iostream>
#include<list>
using namespace std;
using std::list;

int main(void)
{
	int n;
	cin >> n;
	list<long long> a;
	for (int i = 0; i < n; i++) {
		long long number;
		if (i % 2 == 0) {
			cin >> number;
			a.push_back(number);
		}
		else {
			cin >> number;
			a.push_front(number);
		}
	}

	if (n % 2 == 0) {
		for (list<long long>::iterator i = a.begin(); i != a.end(); i++) {
			if (i == a.begin()) {
				cout << *i;
			}
			else {
				cout << " " << *i;
			}
		}
		cout << endl;
	}
	else {
		list<long long> temp;
		for (list<long long>::iterator i = a.begin(); i != a.end(); i++) {
			long long number = *i;
			temp.push_front(*i);
		}

		for (list<long long>::iterator i = temp.begin(); i != temp.end(); i++) {
			if (i == temp.begin()) {
				cout << *i;
			}
			else {
				cout << " " << *i;
			}
		}
		cout << endl;
	}

	return 0;
}