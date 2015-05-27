//贪心算法：
//给你一个非负数整数n，判断n是不是一些数（这些数不允许重复使用，且为正数）的阶乘之和，如9=1!+2!+3!，如果是，则输出Yes，否则输出No；
//每组测试数据有一个正整数n<1000000;
#include <iostream>
#include <utility>
using namespace std;
int dat[10]={0};
void init(){
	int s=1;
	for(int i=0;i<10;i++){
		
		s=s*(i+1);
		dat[i]=s;
		//cout<<"  "<<dat[i];
	}
}
int main(){
	int n=0;
	init();
	cin>>n;
	while (n--)
	{
		int m=0;
		bool flag=false;
		cin>>m;
		for (int i=9;i>=0;i--)
		{
			if(m>=dat[i])
				m=m-dat[i];
			if (m==0)
			{
				flag=true;
			}
		}
		if (flag)
		{
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	system("pause");
	return 0;
}
