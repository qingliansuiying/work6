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

class Random		//随机算式类
{
public:
	int type;
    int num[5];
    char operation[4];
    void RandomNumber();
    void Randomoperation();
    int Randomexpression(char s[30]); 	 //生成随机式子
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
