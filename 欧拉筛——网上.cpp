#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 100000; // 最大范围
bool isPrime[MAXN + 1]; // 标记是否为素数
vector<int> primes; // 存储所有素数
vector<bool> isNotPrime;

void getPrimes(int n) {
   isNotPrime.assign(n + 1, false);
   for (int i = 2; i <= n; i++) {
       if (!isNotPrime[i]) primes.push_back(i);
       for (int j = 0; j < primes.size() && i * primes[j] <= n; j++) {
           isNotPrime[i * primes[j]] = true;
           if (i % primes[j] == 0) break; // 保证每个合数只被最小质因子筛一次
       }
   }
}

void eulerSieve(int n) {
	
   memset(isPrime, true, sizeof(isPrime)); // 初始化所有数为素数
   
   for (int i = 2; i <= n; i++) {
   	
       if (isPrime[i]) primes.push_back(i); // 如果是素数，加入素数列表
       
       for (int p = 0; p < primes; ++p) {
       	
           if (i * p > n) break; // 超出范围，停止标记
           
           isPrime[i * p] = false; // 标记合数
           
           if (i % p == 0) break; // 如果 i 是 p 的倍数，停止标记
       }
       
   }
   
}

int main() {
   int n;
   cout << "请输入筛选范围：";
   cin >> n;
   eulerSieve(n);
   cout << "范围内的所有素数为：" << endl;
   for (int prime : primes) {
       cout << prime << " ";
   }
   cout << endl;
   return 0;
}
