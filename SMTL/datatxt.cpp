#include "datatxt.h"

void datatxt::inputdata()
{
	ifstream  fraction("D:\\南台\\VS\\SMTL\\SMTL\\SMTL\\data\\data.txt");
	int join = 0;
	for (int x = 0; !fraction.eof(); x++) {
		string a = ""; int m = 0;
		fraction >> a >> m;
		arr[x].input(a, m);
		join = x;
	}
	arr[join].input(name, point);
	fraction.close();
}

void datatxt::ssort()
{
	for (int x = 0; x < 11; x++) {
		for (int y = x; y < 11; y++) {
			if (arr[x].compare(arr[y])) {
				endgame tmp = arr[x];
				arr[x] = arr[y];
				arr[y] = tmp;
			}
		}
	}
}

void datatxt::out()
{
	for (int x = 0; x < 10; x++) {	
		cout << "第" << x + 1 << "名: " << arr[x].getid() << " " << arr[x].getnum() << endl;
	}
}

void datatxt::outdata()
{
	ofstream fraction("D:\\南台\\VS\\SMTL\\SMTL\\SMTL\\data\\data.txt");
	for (int x = 0; x < 10; x++) {
		if (arr[x].getid() != "") {
			fraction << arr[x].getid() << " " << arr[x].getnum() << endl;
		}
	}
	fraction.close();
}

void datatxt::Free()
{
	if (arr != NULL)
	{
		delete[]arr;
		arr = NULL;
	}
}

datatxt::~datatxt()
{
	Free();
}

void endgame::input(string a, int m)
{
	id = a; num = m;
}

bool endgame::compare(endgame other)
{
	if (num < other.num) { return true; }
	return false;
}
