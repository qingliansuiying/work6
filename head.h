#ifndef CIRCLE_H
#define CIRCLE_H

class Interaction	//�û�������
{
private:
	int right;      //��ȷ����
    int wrong;      //��������
public:  
	int getright();		
	int getwrong();
	Interaction();
    void Statistics(int j);    //ͳ����������
};

class Random		//����  
{
protected:
	int n;			//��Ϊ�����ʹ�� 
public:
	virtual void random()=0;			//���麯������������������
};
class RandomNumber:virtual public Random			//��������� 
{
protected:
	int num[5];							//��ӳ�Ա���洢����� 
public: 
	void random();						//���� 
	int get_number(int i)	
	{
		return num[i];
	}
};
class RandomOperation:virtual public Random			//����������� 
{
protected:
	char operation[4];					//��ӳ�Ա���洢������� 
public:
	void random();						//���� 
	char get_operation(int i)
	{
		return operation[i];
	}
};
class RandomExpression:public RandomOperation,public RandomNumber		//���ʽ�Ӳ��� 
{
public:
	RandomExpression();													//���캯��
	RandomExpression(RandomNumber &t1,RandomOperation &t2)				//���캯�� 
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

class Calculate		//������
{
private:
    float result;             //����ʽ�ӵĴ�
public:
    float calculateresult(char s[30]);   //�����
};

class File			//�ļ���д��
{
public:					 //�洢���ļ��ж�ȡ������
    void Language(int l,string lan[10]);        //���������ļ�
};

class Judge			//�ж���
{ 
public:
	int answer;				//�����û������
    bool Judgeresult(float res);     //�ж�����ʽ���Ƿ����Ҫ��
    bool Judgeend(int j,int n);         //�ж��û��Ƿ���Ҫ����ֹͣ����
    bool Judgeanswer(int ans,float result);     //�ж��û��ش��Ƿ���ȷ
};


#endif
