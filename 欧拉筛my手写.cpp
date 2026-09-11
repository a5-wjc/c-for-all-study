/*欧拉筛子 优化 6 = 3 * 2与 6 = 2 * 3
质数乘合数为合数，合数乘以合数也是合数
用两个容器，一个盛放质数，另一个打标记。 
当前数和收集起来的质数为合数，这个结果打标记。 
确保每个合数只在它最小质因子与对应
因数相乘时，才被标记为合数 。 
*/
#include<iostream>
#include<string.h> 
 
using namespace std;

const int maxN = 10000;
int primes[maxN];//收集质数  因从最小开始收集，故为升序 
bool vis[maxN];//打合数的标记  

int main(void){
	int n; 
	cin >> n;
	memset(primes, false, sizeof(bool) * n);
	//假设都被标记为合数 
	int pos = 0;//收集质数 
	
	for (int i = 2; i <= n; ++i){
		if(!vis[i])//先判断是不是质数（素数） 
		{
			primes[pos++] = i;//i是质数收集 
			 
		/*不懂*/	for(int j = 0; j < pos && i * primes[j] <= n;/*用这个质数去乘i（当前这个数）*/ ++j){
				vis[i * primes[j]] = true;//这是合数   不应该为false 
			} 
		 } else{/*判断这个合数是不是乘的最小质因子*/ 
		 	//当前这个合数 * 已经确认的质数（从最小的开始） = 合数
			//但当前这个合数很可能是 某个最小质数的倍数，所以如果用它继续筛就筛多了
			//必须判断它是哪个最小质数的倍数
			for(int j = 0; j < pos && i * primes[j] <= n;/*这个也就是说从质数数列里面从最小的取出来和i去乘，判断是否大于了目标值n*/ ++j){
				vis[i * primes[j]] = true;//标记为合数 
				if(i % primes[j] == 0){
					break;
//证明不是最小质数了，可以是primes[j]的倍数，那么这个primes[j]在后续可以帮他继续筛完
				//即 当前的i就不用去做没意义的筛了。				
				}
			} 
		 } 
	} 
		
	
	
	return 0;
}
