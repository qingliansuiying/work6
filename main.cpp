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
	string lan[10];						//�洢����
	char s[30];							//s�洢���ʽ
	int i=0,sum=0,language,type,answer=0;
	float check=0;						//���ڴ���ʽ�Ӵ�
	Interaction inter;
	File file;
	Calculate caculate;
	RandomNumber randomnumber;
	RandomOperation randomoperation;
	Judge judge;
	cout<<"Welcom!"<<"Please choose the language you need:"<<endl;		//��������ѡ��
	cout<<"1.����"<<"	"<<"2.Ӣ��"<<endl;
	cin>>language;
	file.Language(language,lan);	
	cout<<lan[0];
	cin>>sum;
	while(judge.Judgeend(i,sum))
	{
		randomnumber.random();
		randomoperation.random();
		RandomExpression randomexpression(randomnumber,randomoperation);
		randomexpression.random(s);
		check=caculate.calculateresult(s);
		if(judge.Judgeresult(check))					//���ʽ�� 
		{
			i++;
			for(i=0;i<strlen(s);i++)
			{
				cout<<s[i];
			}
			cout<<'=';
			cin>>answer;
			if(judge.Judgeanswer(answer,check))			//�жϴ����� 
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
	cout<<lan[3]<<inter.getright()<<endl;				//���ͳ�ƽ�� 
	cout<<lan[4]<<inter.getwrong()<<endl;
	return 0;
}