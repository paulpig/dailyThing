#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;


/*
���������
һ.����1.�����һλ����     2.���м�����һλ�������ĳ��Ȳ���ͬ�� 
��.�ģ�������޸�һλ �������ĳ�����ͬ�� 
*/ 
bool isEditDistanceOne(string a,string b);
int main(){
	string a="wubingchao1";
	string b="wubingceao1";

	if(!isEditDistanceOne(a,b)){
		cout<<"wrong";
	}
	else
		cout<<"right";
		/*
	char **a;
	int i;
	a = new char*[10];
	for(i=0;i<10;i++){
		a[i]=new char[10];
	}
	isEditDistanceOne(a);
	*/
}
bool isEditDistanceOne(string a,string b){
	int i =0 ,j= 0;
	int count=0;
	int a_len=a.length();
	int b_len=b.length();
	if(abs(a_len-b_len)>1){
		return 0;
	}
	while(i<a_len&&j<b_len){
		if(a[i]!=b[j]){                 
			count++;                   //������������string������Ĳ��ϵĸı䡣 
			if(count>1)
				return 0;
			if(a_len==b_len){              //�޸� 
				i++;
				j++;
			}
			else if(a_len>b_len){           //���� 
				i++;
			}
			else if(a_len<b_len){
				j++;
			}
		}
		else{
			i++;       
			j++;
		}
	}
	if(i<a_len||j<b_len){            //�ж��Ƿ����������ΪԪ�ء� 
		count++;
	}
	if(count==1)
		return 1;
}
