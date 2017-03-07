// ConsoleApplication16.cpp: îïğåäåëÿåò òî÷êó âõîäà äëÿ êîíñîëüíîãî ïğèëîæåíèÿ.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>


using namespace std;

int main()
{
	system("chcp 1251");
	int line = 1;
	char file1[20], file2[20], buff1[256], buff2[256];
	cout << "Ââåäèòå èìÿ ôàéëîâ äëÿ ñğàâíåíèÿ"<< endl;
	cin >> file1 >> file2;
	ifstream  fin1, fin2;
	fin1.open(file1);
	if (!fin1.is_open())
	{
		cout << "Ôàéë íå íàéäåí.";
	}
	fin2.open(file2);
	if (!fin2.is_open())
	{
		cout << "Ôàéë íå íàéäåí.";
	}

	fstream fout;
	fout.open("File3.txt");

	while (!fin1.eof() || !fin2.eof())
	{
		fin1.getline(buff1, 256);
		fin2.getline(buff2, 256);
		if (strcmp(buff1, buff2))
		{
			
			fout << file1 << " " << line << " " << buff1 << endl;
			fout << file2 << " " << line << " " << buff2 << endl;
		}
		line++;
	}
	system("pause");

    return 0;
}

