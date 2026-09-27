//快速幂

#include <iostream>

using namespace std;

bool isLeapYear(int y)
{
		return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int dayOfYear(int y, int m, int d)
{
	int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeapYear(y)) months[2] = 29;
	int days = 0;
	for (int i = 1; i < m; ++i) days += months[i];
	days += d;
	return days;
	
}

int main(void)
{
	int y, m, d;
	cin >> y >> m >> d;
	cout << dayOfYear(y, m, d) << endl;
	
	return 0;
}

