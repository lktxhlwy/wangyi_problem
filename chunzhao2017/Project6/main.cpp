#include<iostream>
#include<vector>
#include<set>
#include<string>
using namespace std;
using std::vector;
using std::string;
using std::set;

void func(vector<string> &person, set<char> &job, int index, int &res)
{
	if (index >= person.size()) {
		res++;
		return;
	}

	for (string::iterator j = person[index].begin(); j != person[index].end(); j++) {
		if (job.find(*j) == job.end()) {
			job.insert(*j);
			func(person, job, index + 1, res);
			job.erase(*j);
		}
	}


}


int main(void)
{
	int n;
	cin >> n;
	vector<string> person;
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		person.push_back(str);
	}

	set<char> job;
	int res = 0;
	func(person, job, 0, res);

	cout << res << endl;

	return 0;
}