#include<iostream>
#include<ctime>
#include <fstream>
#include<string>
#include<stdlib.h>
#include<string.h>
#include "head.h"
using namespace std;

Interaction::Interaction()
{
	right=0;
	wrong=0;
}
int Interaction::getright()			
{
	return right;
}
int Interaction::getwrong()
{
	return wrong;
}
void Interaction::Statistics(int j)
{
	if(j==1)
		right++;
	else
		wrong++;
}

void Random::RandomNumber()				//��������� 
{
	srand(time(0));
	int j;
	for(j=1;j<=4;j++)
	{
		num[j]=rand()%10;
	}
}
void Random::Randomoperation()			//���ɷ��� 
{
	srand(time(0));
	int choose,j;
	for(j=1;j<=3;j++)
	{
		choose=rand()%4;
    	switch(choose)
		{
          	case 0:operation[j]='+';break;
        	case 1:operation[j]='-';break;
			case 2:operation[j]='*';break;
			default:operation[j]='/';
		}
	}
}
int Random::Randomexpression(char s[30])
{
	srand(time(0));
	type=rand()%6;
	switch(type)						//���������ʽ�Ӳ��� 
	{
	case 0:
		s[0]=char(num[1]+'0');
		s[1]=operation[1];
		s[2]=char(num[2]+'0');
		s[3]=operation[2];
		s[4]=char(num[3]+'0');
		s[5]=operation[3];
		s[6]=char(num[4]+'0');
		break;
	case 1:
		s[0]='(';
		s[1]=char(num[1]+'0');
		s[2]=operation[1];
		s[3]=char(num[2]+'0');
		s[4]=operation[2];
		s[5]=char(num[3]+'0');
		s[6]=')';
		s[7]=operation[3];
		s[8]=char(num[4]+'0');
		break;
	case 2:
		s[0]=char(num[1]+'0');
		s[1]=operation[1];
		s[2]='(';
		s[3]=char(num[2]+'0');
		s[4]=operation[2];
		s[5]=char(num[3]+'0');
		s[6]=operation[3];
		s[7]=char(num[4]+'0');
		s[8]=')';
		break;
	case 3:
		s[0]='(';
		s[1]=char(num[1]+'0');
		s[2]=operation[1];
		s[3]=char(num[2]+'0');
		s[4]=')';
		s[5]=operation[2];
		s[6]=char(num[3]+'0');
		s[7]=operation[3];
		s[8]=char(num[4]+'0');
		break;
	case 4:
		s[0]=char(num[1]+'0');
		s[1]=operation[1];
		s[2]=char(num[2]+'0');
		s[3]=operation[2];
		s[4]='(';
		s[5]=char(num[3]+'0');
		s[6]=operation[3];
		s[7]=char(num[4]+'0');
		s[8]=')';
		break;
	default:
		s[0]='(';
		s[1]=char(num[1]+'0');
		s[2]=operation[1];
		s[3]=char(num[2]+'0');
		s[4]=')';
		s[5]=operation[2];
		s[6]='(';
		s[7]=char(num[3]+'0');
		s[8]=operation[3];
		s[9]=char(num[4]+'0');
		s[10]=')';
		break;
	}
	return type;
}

float Calculate::calculateresult(char s[30])
{
	int flag=0;
	string exp;					//��ջʹ��
	char postexp[30];			//��׺���ʽ
	float st[30];					//��ֵջ
	char ch;
	int i=0,j=0,top=-1;
	for(i=0;i<strlen(s);i++)			//����׺���ʽת��Ϊ��׺���ʽ
	{
		ch=s[i];
		if(ch=='(')						//������
		{
			top++;
			exp[top]=ch;
			
		}
		else if(ch==')')				//����������������������������ջ�����ֱ������������������Ϊֹ�����У���������ջ���ǲ������ 
		{
			while(exp[top]!='(')
			{
				postexp[j]=exp[top];
				top--;
				j++;
			}
			top--;
		}
		else if(ch=='+'||ch=='-')		//Ϊ'+'��'-'ʱ�������ȼ�������ջ���κ�����������ȼ���ֱ��')' 
		{
			while(top!=-1&&exp[top]!='(')
			{
				postexp[j]=exp[top];
				top--;
				j++;
			}
			top++;
			exp[top]=ch;
		}
		else if(ch=='*'||ch=='/')		//Ϊ'*'��'/'ʱ�������ȼ�������ջ��Ϊ'*'��'/'�����ȼ���ֱ��')'  
		{
			while(top!=-1&&exp[top]!='('&&(exp[top]=='*'||exp[top]=='/'))
			{
				postexp[j]=exp[top];
				j++;
				top--;
			}
			top++;
			exp[top]=ch;
		}
		else if(ch>='0'&&ch<='9')		//Ϊ���֣�ֱ�Ӵ���
		{
			postexp[j]=ch;
			j++;
		}
		else
		{
			continue;
		}
	}
	while(top!=-1)
	{
		postexp[j]=exp[top];
		j++;
		top--;
	}
	postexp[j]='\0';
	top=-1;
	for(i=0;i<strlen(postexp);i++)			//�����׺���ʽ 
	{
		ch=postexp[i];
		if(ch=='+')							//�����������͵��������� ���������ջ   
		{
			st[top-1]=st[top-1]+st[top];
			top--;
		}
		if(ch=='-')
		{
			st[top-1]=st[top-1]-st[top];
			top--;
		}
		if(ch=='*')
		{
			st[top-1]=st[top-1]*st[top];
			top--;
		}
		if(ch=='/')
		{
			if(st[top]==0)			//��ֹ���ֳ���Ϊ0�����
			{
				flag=1;
				break;
			}
			else
			{
				st[top-1]=st[top-1]/st[top];
				top--;
			}
		}
		if(ch>='0'&&ch<='9')
		{
			top++;
			st[top]=ch-'0';	
		}
	}
	if(flag==0)
		result=st[top];			//��δ���ֳ���Ϊ0���������ջ��Ԫ�ؼ�Ϊʽ�ӽ��
	else
		result=-1;
	return result;
}

bool Judge::Judgeend(int j,int n)			//�ж���
{
	if(j==n)
		return false;
	else
		return true;
}
bool Judge::Judgeresult(float res)			//�ж�ʽ���Ƿ����Ҫ�� 
{
	int test;
	test=res;
	if(test==res&&res>=0)
		return true;
	else
		return false;
}
bool Judge::Judgeanswer(int ans,float result)		//�ж��û����Ƿ���ȷ 
{
	if(ans==result)
		return true;
	else
		return false;
}

void File::Language(int l,string lan[10])		//���Զ�ȡ��һ���ִ���С���⣺��֪����ô������ܶ�ȡ��ͬ���ļ������ڳ����� 
{
	ifstream fin("1.txt");
	int i=0;
	string t;
	for(;!fin.eof();)
	{
 	   getline(fin,lan[i],'\n');
 	   i++;
	}
}

