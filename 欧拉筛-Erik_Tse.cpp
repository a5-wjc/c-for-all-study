#include<iostream>
using namespace std;
long long sum = 0;


inline bool isprime(int x)
{
	for(int i = 2; i <= x - 1; ++i)
		if(x % i == 0)return 0;
	return 1;
}

int main()
{
	int N;
	cin >> N;
	for(int i = 0; i < N; ++i)
		cout << isprime(sum) ;
	return 0;
}

