#include <iostream>
#include <string>
using namespace std;
void swap(string &str,int i,int j){
	char temp=str[i];
	str[i]=str[j];
	str[j]=temp;
}
void fullarray(string str,int start,int end){
	if (start==end)
	{
		cout<<counter++<<"  "<<str<<endl;
	}
	else{
		for (int j=start;j<end;j++)
		{
			swap(str,start,j);
			fullarray(str,start+1,end);
			swap(str,start,j);
		}
	}
}
int main(){
	string str="abcde";
	fullarray(str,0,str.length());
	system("pause");
	return 0;
}
