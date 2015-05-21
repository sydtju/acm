//百度之星热身赛
#include <iostream>
#include <cstdio>
#include <cstdio>
using namespace std;
int main(){
	int n,m;
	while (cin>>n>>m)
	{

		int temp=m%n;
		temp=temp-1;//当为零的时候  后面会出现负数
		if (temp<0)
		{
			temp=temp+n;//使用加一个周期的方式进行
		}
		cout<<temp<<endl;
	}
	return 0;
}
