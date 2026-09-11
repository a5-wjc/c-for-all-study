//埃式筛，求质数 

#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxN = 1000000;
bool primes[maxN];//做标记 

int a[200000];
// 1 -- n 筛出质数 

bool frist_edition(){//朴素筛 O(nlogn)
		for (int i = 2; i <= n; ++i){
		bool flag = true;
		for (int j = 2; j < i; ++j){
			if(i % j == 0){
				flag =  false;
				break;
			}
		}
		if(flag) cout << i << "";
	}
} 
bool second_edition(){//朴素筛 O(nlogn)优化 
		for (int i = 2; i <= n; ++i){
		bool flag = ture;
		for (int j = 2; j * j <= i; ++j){
			if(i % j == 0){
				flag =  false;
				break;
			}
		}
		if(flag) cout << i << "";
	}
}
int mian(void){
	int n; 
	cin >> n;

	//埃式筛O(nloglogn) 
	memset(primes, true, sizeof(bool) * n);
	primes[0] = false;
	primes[1] = false;
	for(int i = 2; i <= n/*优化：i * i <= n */; ++i) {
		for(int j = i * 2/*等效与i + i*/; j <= n; j += i) {
			//for(int a = 1; a <= i; ++a) j = a * i;所以说n的最大质因子就是n算数平方根 
			primes[j] = false;
		}
	}
	for(int i = 0; i <= n; ++i){
		if(primes[i]) cout << i << " ";
	}
	return 0;
}

//埃氏筛法（Eratosthenes' Sieve）是一种用于寻找一定
//范围内所有素数的高效算法。在C++中实现埃氏筛法，
//可以通过创建一个布尔数组来标记每个数是否为素数，
//然后通过迭代标记所有已知素数的倍数为非素数，
//从而筛选出所有素数。
