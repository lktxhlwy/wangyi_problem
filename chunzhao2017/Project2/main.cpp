#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
using std::vector;

int main(void)
{
	int num;
	cin >> num;
	vector<int> car_x(num, 0);
	vector<int> car_y(num, 0);
	for (int i = 0; i < num; i++) {
		cin >> car_x[i];
	}
	for (int i = 0; i < num; i++) {
		cin >> car_y[i];
	}

	int office_x, office_y;
	cin >> office_x >> office_y;

	int walkTime, taxiTime;
	cin >> walkTime>>taxiTime;

	int time = (abs(office_x) + abs(office_y))*walkTime;
	for (int i = 0; i < num; i++) {
		int s1 = abs(car_x[i]) + abs(car_y[i]);
		int s2 = abs(car_x[i] - office_x) + abs(car_y[i] - office_y);
		int time_i = s1*walkTime + s2*taxiTime;
		time = min(time, time_i);
	}

	cout << time << endl;

	return 0;
}