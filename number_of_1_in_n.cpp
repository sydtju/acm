//ACM：数字0-n中 1的数量；
//解题思路：
/************************************************************************/
/*
0~9：1
0~99：20=10*1+10
0~999：300=10*20+100
0~9999：4000=10*300+1000
0~99999：50000=10*4000+10000
0~999999：600000=10*50000+100000  
 即0~9…9（m个9）之间1的个数为a(m)=10*a(m-1)+10^(m-1)个；

 例如，n=1234，计算步骤如下：
 (1) 将0~1234分为2个部分：0~999，1000~1234；
 (2) 有1个0~999，共300次；
 (3) 应该加上千位为1的次数，共234+1次，即n%1000+1=235次；
 (4) 此时，就剩下0~234了，不满1个0~999，故继续拆开：0~99，100~199，200~234；共有2个0~99，共2*20=40次；
 (5) 因百位数为2>1，故应该加上百位为1的次数，共100次；（从拆分的结果也很容易得出）
 (6) 此时，就剩下200~234了，实际上就是剩下0~34了，不满1个0~99，故继续拆开：0~9，10~19，20~29，30~34；共有3个0~9，共3*1=3次；
 (7) 因十位数为3>1，故应该加上十位为1的次数，共10次；
 (8) 此时，就剩下30~34了，实际上就是剩下0~4了，共1次（即因个位数为4>1，故应该加上个位为1的次数，共1次）；
 本程序是从最低位向最高位进行的  
*/
/************************************************************************/
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
using namespace std;
class Solution{
public:
	Solution (){};
	~Solution(){};
	int counter(const int counter);
} ;
int Solution::counter(const int counter){
	int temp_counter=counter;
	int i=0;
	int c_wei=0;
	int a=0;
	int weight=1;
	int count=0;
	if (counter<0) return 0;
	while (temp_counter)
	{
		c_wei=temp_counter%10;
		count=count+a*c_wei;
		if (c_wei>1) count=count+weight;
		else if (c_wei==1)
		{
			count=count+counter%weight+1;
		}
		a=a*10+weight;
		weight=weight*10;
		temp_counter=temp_counter/10;
	}
	return count;
}
int main(){
	Solution a;
	int h=a.counter(1234);
	cout<<h<<endl;
	system("pause");
	return 0;
}
