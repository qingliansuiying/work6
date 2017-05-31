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

void Random::RandomNumber()				//生成随机数 
{
	srand(time(0));
	int j;
	for(j=1;j<=4;j++)
	{
		num[j]=rand()%10;
	}
}
void Random::Randomoperation()			//生成符号 
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
	switch(type)						//生产成随机式子部分 
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
	string exp;					//做栈使用
	char postexp[30];			//后缀表达式
	float st[30];					//数值栈
	char ch;
	int i=0,j=0,top=-1;
	for(i=0;i<strlen(s);i++)			//将中缀表达式转化为后缀表达式
	{
		ch=s[i];
		if(ch=='(')						//左括号
		{
			top++;
			exp[top]=ch;
			
		}
		else if(ch==')')				//若遇到右括弧“）”，则连续出栈输出，直到遇到左括弧“（”为止。其中，左括弧出栈但是并不输出 
		{
			while(exp[top]!='(')
			{
				postexp[j]=exp[top];
				top--;
				j++;
			}
			top--;
		}
		else if(ch=='+'||ch=='-')		//为'+'或'-'时，其优先级不大于栈顶任何运算符的优先级，直到')' 
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
		else if(ch=='*'||ch=='/')		//为'*'或'/'时，其优先级不大于栈顶为'*'或'/'的优先级，直到')'  
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
		else if(ch>='0'&&ch<='9')		//为数字，直接存入
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
	for(i=0;i<strlen(postexp);i++)			//计算后缀表达式 
	{
		ch=postexp[i];
		if(ch=='+')							//遇到操作符就弹出两个数 并将结果进栈   
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
			if(st[top]==0)			//防止出现除数为0的情况
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
		result=st[top];			//若未出现除数为0的情况，则栈顶元素即为式子结果
	else
		result=-1;
	return result;
}

bool Judge::Judgeend(int j,int n)			//判断类
{
	if(j==n)
		return false;
	else
		return true;
}
bool Judge::Judgeresult(float res)			//判断式子是否符合要求 
{
	int test;
	test=res;
	if(test==res&&res>=0)
		return true;
	else
		return false;
}
bool Judge::Judgeanswer(int ans,float result)		//判断用户答案是否正确 
{
	if(ans==result)
		return true;
	else
		return false;
}

void File::Language(int l,string lan[10])		//语言读取这一部分存在小问题：不知道怎么处理才能读取不同的文件，还在尝试中 
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

