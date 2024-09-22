#include "game.h"
#include <time.h>
#include "datatxt.h"
using namespace std;

string name;
int main()
{
	srand(time(NULL));
	int n = 11;
	cout << "請輸入玩家名稱(英文)：" << endl;
	cin >> name;
	game Game;
	Game.run();
	datatxt datatext(n, name, Game.getpoints());
	cout << endl;
	datatext.inputdata();
	datatext.ssort();
	datatext.out();
	datatext.outdata();
	return 0;
}