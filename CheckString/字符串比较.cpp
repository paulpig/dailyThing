#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;


/*
两个情况：
一.增：1.在最后一位增加     2.在中间增加一位（两个的长度不相同） 
二.改：随意的修改一位 （两个的长度相同） 
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
			count++;                   //核心在与两个string的坐标的不断的改变。 
			if(count>1)
				return 0;
			if(a_len==b_len){              //修改 
				i++;
				j++;
			}
			else if(a_len>b_len){           //增加 
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
	if(i<a_len||j<b_len){            //判断是否多出来最后以为元素。 
		count++;
	}
	if(count==1)
		return 1;
}
