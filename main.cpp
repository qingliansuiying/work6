#include<iostream>
#include<ctime>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include "head.h"
using namespace std;

int main()
{
	string lan[10];						//存储语言
	char s[30];							//s存储表达式
	int i=0,sum=0,language,type,answer=0;
	float check=0;						//用于储存式子答案
	Interaction inter;
	File file;
	Calculate caculate;
	Random random;
	Judge judge;
	cout<<"Welcom!"<<"Please choose the language you need:"<<endl;		//进行语言选择
	cout<<"1.中文"<<"	"<<"2.英文"<<endl;
	cin>>language;
	file.Language(language,lan);	
	cout<<lan[0];
	cin>>sum;
	while(judge.Judgeend(i,sum))
	{
		random.RandomNumber();
		random.Randomoperation();
		type=random.Randomexpression(s);
		check=caculate.calculateresult(s);
		if(judge.Judgeresult(check))					//输出式子 
		{
			i++;
			cout<<s<<'=';
			cin>>answer;
			if(judge.Judgeanswer(answer,check))			//判断答案正误 
			{
				cout<<lan[1]<<endl;
				inter.Statistics(1);
			}
			else
			{
				cout<<lan[2]<<check<<endl;
				inter.Statistics(0);
			}
		}
	}
	cout<<lan[3]<<inter.getright()<<endl;				//输出统计结果 
	cout<<lan[4]<<inter.getwrong()<<endl;
	return 0;
}