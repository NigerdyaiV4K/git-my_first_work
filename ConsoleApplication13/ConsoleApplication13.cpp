// ConsoleApplication13.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<fstream>
using namespace std;

enum T { S0 = 0, S1 = 1, S2 = 2, S3 = 3, S4 = 4, S5 = 5, S6 = 6, S7 = 7, S8 = 8, S9 = 9, ERROR = -1 };
int FStates[] = { S4,S5,S8,S9,S1,S2 };
int CurState = 0;
char CurCh;

bool IsFinish(int State) {
	for (int i : FStates) if (State == i) return true;
	return false;
}

int Delta(int State, char Ch) {
	switch (State) {
	case S0:
		if (Ch == 'r' ) return S4;
		if (Ch == 't') return S8;
		break;
	case S1:
		break;
	case S2:
		if (Ch == 'e') return S1;
		break;
	case S3:
		if (Ch == 'e') return S2;
		if (Ch == 'r') return S3;
		break;
	case S4:
		if (Ch == 'r') return S3;
		if (Ch == 'e') return S5;
		break;
	case S5:
		if (Ch == 'e') return S5;
		break;
	case S6:
		if (Ch == 'e') return S1;
		break;
	case S7:
		if (Ch == 'e') return S6;
		break;
	case S8:
		if (Ch == 't') return S7;
		if (Ch == 'e') return S9;
		break;
	case S9:
		if (Ch == 'e') return S9;
		break;
	default: break;
	}
	return ERROR;
}

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");
	string name;
	cin >> name;
	for (int i = 0; i < name.size(); i++) {
		CurState = Delta(CurState, name[i]);
		if (CurState == ERROR) break;
	}
	cout << 10 << endl;
	if (IsFinish(CurState)) cout << "YES" << endl;
	else cout << "NO" << endl;
	system("pause");
	return 0;
}