/************************************************************************/
/* 枚举：以下代码的实质是取n个数字序列中3个数的所有可能的组合数  求一序列数中 组成直角三角形的最大面积*/
/************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int max_area(int *num,int length){
	int h=0,i,j,k;
	int max=0;
	for(i=0;i<MAX;i++)
		for(j=i+1;j<MAX;j++)
			for(k=j+1;k<MAX;k++){
				printf("%d %d %d \n",num[i],num[j],num[k]);
				if (num[i]*num[i]+num[j]*num[j]==num[k]*num[k])
				{
					int temp=0;
					temp=(int)0.5*num[i]*num[j];
					if (temp>max)
					{
						max=temp;
					}
				}
				h++;
			}
		return max;
}
int main(){
	int num[7]={3,4,5,6,8,9,10};
	int h=max_area(num,sizeof(num)/sizeof(num[0]));
	int t =sizeof(num);
	printf("%d",t);
	getchar();
	return 0;
}
