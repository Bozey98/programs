// ConsoleApplication17.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

class Matrix {
		
private:
	int row, col, **mas;
public:
	Matrix();
	Matrix(int, int);
	Matrix(Matrix&);
	~Matrix();
	void fill(char*);
	void show();
	Matrix operator+(Matrix);
	Matrix operator*(Matrix);
};


int main()
{
	setlocale(LC_ALL, "russian");
	char file1[25]="Matrix1.txt", file2[25]="Matrix2.txt";
	Matrix mas1,mas2;
	mas1.fill(file1);
	cout << "������ 1" << endl;
	mas1.show();
	mas2.fill(file2);
	cout << "������ 2" << endl;
	mas2.show();
	Matrix Sum = mas1 + mas2;
	cout << "�����" << endl;
	Sum.show();
	Matrix Comp = mas1*mas2;
	cout << "������������" << endl;
	Comp.show();

	system("pause");

    return 0;
}

Matrix::Matrix() {
	row = 4;
	col = 4;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
	}
}

Matrix::Matrix(int r, int c) {
	row = r;
	col = c;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
	}
}

Matrix::~Matrix() {
	for (int i = 0; i < row; i++) {
		delete[] mas[i];
	}

	delete[] mas;
}

Matrix::Matrix(Matrix&a) {
	row = a.row;
	col = a.col;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++) {
			mas[i][j] = a.mas[i][j];
		}
	}
}

void Matrix::fill(char*file) {
	ifstream fin1(file);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin1 >> mas[i][j];
		}
	}
}

void Matrix::show() {
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Matrix Matrix::operator+(Matrix a) {

	Matrix help(row, col);


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			help.mas[i][j] = mas[i][j] + a.mas[i][j];
		}
	}
	return help;
}

Matrix Matrix::operator*(Matrix a) {

	Matrix help(row, col);


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			help.mas[i][j] = 0;
			for (int k = 0; k < col; k++) {
				help.mas[i][j] += mas[i][k] * a.mas[k][j];
			}
		}
	}
	return help;
}