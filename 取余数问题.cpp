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
		temp=temp-1;
		if (temp<0)
		{
			temp=temp+n;
		}
		cout<<temp<<endl;
	}
	return 0;
}
