#ifndef CIRCLE_H
#define CIRCLE_H

class Interaction	//用户交互类
{
private:
	int right;      //正确题数
    int wrong;      //错误题数
public:  
	int getright();		
	int getwrong();
	Interaction();
    void Statistics(int j);    //统计正误题数
};

class Random		//基类  
{
protected:
	int n;			//作为随机数使用 
public:
	virtual void random()=0;			//纯虚函数，留给派生类重载
};
class RandomNumber:virtual public Random			//生成随机数 
{
protected:
	int num[5];							//添加成员，存储随机数 
public: 
	void random();						//重载 
	int get_number(int i)	
	{
		return num[i];
	}
};
class RandomOperation:virtual public Random			//生成随机符号 
{
protected:
	char operation[4];					//添加成员，存储随机符号 
public:
	void random();						//重载 
	char get_operation(int i)
	{
		return operation[i];
	}
};
class RandomExpression:public RandomOperation,public RandomNumber		//随机式子部分 
{
public:
	RandomExpression();													//构造函数
	RandomExpression(RandomNumber &t1,RandomOperation &t2)				//构造函数 
	{
		for(int i=1;i<5;i++)
		{
			num[i]=t1.get_number(i);
		}
		for(int i=1;i<4;i++)
		{
			operation[i]=t2.get_operation(i);
		}
	}
	void random(){};
	void random(char s[30]);
};

class Calculate		//计算类
{
private:
    float result;             //生成式子的答案
public:
    float calculateresult(char s[30]);   //计算答案
};

class File			//文件读写类
{
public:					 //存储从文件中读取的语言
    void Language(int l,string lan[10]);        //调用语言文件
};

class Judge			//判断类
{ 
public:
	int answer;				//接受用户输入答案
    bool Judgeresult(float res);     //判断生成式子是否符合要求
    bool Judgeend(int j,int n);         //判断用户是否需要程序停止运行
    bool Judgeanswer(int ans,float result);     //判断用户回答是否正确
};


#endif
