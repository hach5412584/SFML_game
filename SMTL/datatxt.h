#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using  namespace  std;

class endgame{
private:
	string id; //���a�W��
	int num; //���a����
public:
	endgame() : id(""), num(0) {}
	endgame(string a, int m) :id(a), num(0) {
		input(a, m);
	}
	void input(string a, int m);
	string getid() { return id; } //�^�Ǫ��a�W��
	int getnum() { return num; } //�^�Ǫ��a����
	bool compare(endgame other); //�P�_�j�p
};

class datatxt
{
private:
	endgame* arr; //���a�ƦW�}�C
	int point; // �s���a����
	int arrlast; //�ѰO�R�F
	string name; //�s���a�W��
public:
	datatxt() :arr(NULL), name(""), point(0), arrlast(0) {}
	datatxt(int n, string h, int e) :arr(NULL), name(""), arrlast(0), point(0) {
		arr = new endgame[n]; arrlast = n; name = h; point = e;
	}
	void inputdata();//��J�ɮ�
	void ssort();//�Ƨ�
	void out();//���
	void outdata();//��X�ɮ�
	void Free(); //����ʺA�t�m���O����
	virtual ~datatxt(); //�Ѻc

};

