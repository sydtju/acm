#include<iostream>
#include<cstdio>
#include <set>
using namespace std;
typedef unsigned char uchar;
typedef unsigned int uint;
uchar atoi_ip(char dat[],int &location){
	int i=location;
	uchar temp=0;
	uchar temp0=0;
	while(1)
	{
		if (dat[i]<'0'||dat[i]>'9')
		{
			break;
		}
		else{
			temp0=dat[i]-'0';
			temp=temp*10+temp0;
		}
		i++;
		location=i;
	}
	return temp;
} 
void strtoip(uchar a[4],char str[]){
	int loca=0;
	for(int i=0;i<4;i++){
		a[i]=atoi_ip(str,loca);
		loca++;
	}
}
void uchartouint(uint &h,uchar a[4]){
	for(int i=0;i<4;i++){
		h=h<<8;
		h=h+a[i];
	}
}
int main(){
	uchar ip[4]={0};
	char dat[20]={0};
	int T=0,M=0,N=0;
	int i=0,j=0;
	set<uint> s0;
	set<uint> s1;
	set<uint>::iterator it;
	scanf("%d",&T);
	while (i<T)
	{
		scanf("%d %d",&N,&M);
		while (N--)
		{
			uint h=0;
			scanf("%s",dat);
			strtoip(ip,dat);
			uchartouint(h,ip);
			s0.insert(h);
		}	
		i++;
		printf("Case #%d:\n",i);
		while (M--)
		{
			uint h=0;
			scanf("%s",dat);
			strtoip(ip,dat);
			uchartouint(h,ip);
			for (it=s0.begin();it!=s0.end();it++)
			{
				s1.insert(h&(*it));
			}
			printf("%d\n",s1.size());
			s1.clear();
		}
		s0.clear();
	}
	//system("pause");
	return 0;
}
