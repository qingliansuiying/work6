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

class Random		//�����ʽ��
{
public:
	int type;
    int num[5];
    char operation[4];
    void RandomNumber();
    void Randomoperation();
    int Randomexpression(char s[30]); 	 //�������ʽ��
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
