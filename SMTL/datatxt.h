#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using  namespace  std;

class endgame{
private:
	string id; //玩家名稱
	int num; //玩家分數
public:
	endgame() : id(""), num(0) {}
	endgame(string a, int m) :id(a), num(0) {
		input(a, m);
	}
	void input(string a, int m);
	string getid() { return id; } //回傳玩家名稱
	int getnum() { return num; } //回傳玩家分數
	bool compare(endgame other); //判斷大小
};

class datatxt
{
private:
	endgame* arr; //玩家排名陣列
	int point; // 新玩家分數
	int arrlast; //忘記刪了
	string name; //新玩家名稱
public:
	datatxt() :arr(NULL), name(""), point(0), arrlast(0) {}
	datatxt(int n, string h, int e) :arr(NULL), name(""), arrlast(0), point(0) {
		arr = new endgame[n]; arrlast = n; name = h; point = e;
	}
	void inputdata();//輸入檔案
	void ssort();//排序
	void out();//顯示
	void outdata();//輸出檔案
	void Free(); //釋放動態配置的記憶體
	virtual ~datatxt(); //解構

};

