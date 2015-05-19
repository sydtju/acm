
/************************************************************************/
/* 并查集基础应用                                                     */
/************************************************************************/
// 有n个人（1..n），如果i和j是亲戚，j和k是亲戚，那么j和k也是亲戚，题目给定n各人的m对亲戚关系，然后提出q各问题，问某两个人是不是亲戚//
#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX=100;
int member[MAX];
void Make_set(int dat[],int length);
int find(int x);
void Union(int x,int y);
int main(){
	int n=0;
	int m=0;
	int q=0;
	cout<<"please input n=";
	cin>>n;
	Make_set(member,n);
	cout<<"\n please input m=";
	cin>>m;
	while (m--)
	{
		int a,b;
		cout<<"\n input relation:";
		cin>>a>>b;
		a=find(a);
		b=find(b);
		if (a!=b)
		{
			Union(a,b);
		}
	}
	cout<<"\n please input q=";
	cin>>q;
	while (q--)
	{
		int a,b;
		cout<<"\n input request:";
		cin>>a>>b;
		a=find(a);
		b=find(b);
			cout<<((a==b)?"YES":"NO");
	}
	system("pause");
	return 0;
}
void Make_set(int dat[],int length){
	for (int i=1;i<=length;i++)
	{
		dat[i]=i;
	}
}
int find(int x){
	while (member[x]!=x)
	{
		x=member[x];
	}
	return x;
}
//缩短路径    
int find1(int x){
	int x_temp=x;
	while (member[x]!=x)
	{
		x=member[x];
	}
	while (member[x_temp]!=x_temp)
	{
		int temp=0;
		temp=member[x_temp];
		member[x_temp]=x;
		x_temp=temp;
	}
}
void Union(int x,int y){
	if (rand()%2)
	{
		member[x]=y;
	}
	else{
		member[y]=x;
	}
}
