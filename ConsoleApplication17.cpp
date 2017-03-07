// ConsoleApplication17.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>

using namespace std;

class Matrix {
		
private:
	int row, col, **mas;
public:
	Matrix(int length = 4);
	Matrix(int, int);
	Matrix(const Matrix&);
	~Matrix();
	void fill(const char*);
	void show() const ;
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
};


int main()
{
	setlocale(LC_ALL, "russian");
	char file1[25]="Matrix1.txt", file2[25]="Matrix2.txt";
	Matrix mas1,mas2;
	mas1.fill(file1);
	cout << "Массив 1" << endl;
	mas1.show();
	mas2.fill(file2);
	cout << "Массив 2" << endl;
	mas2.show();
	Matrix Sum = mas1 + mas2;
	cout << "Сумма" << endl;
	Sum.show();
	Matrix Comp = mas1*mas2;
	cout << "Произведение" << endl;
	Comp.show();

	system("pause");

    return 0;
}

Matrix::Matrix(int length) {
	row = length;
	col = length;

	mas = new int*[row];
	for (int i = 0; i < row; i++) {
		mas[i] = new int[col];
		for (int j = 0; j < col; j++) {
			mas[i][j] = 0;
		}
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

Matrix::Matrix(const Matrix&a) {
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

void Matrix::fill( const char*file) {
	ifstream fin1(file);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			fin1 >> mas[i][j];
		}
	}
}

void Matrix::show() const {
	
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

Matrix Matrix::operator+(const Matrix& a) const {

	Matrix help(row, col);


	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			help.mas[i][j] = mas[i][j] + a.mas[i][j];
		}
	}
	return help;
}

Matrix Matrix::operator*(const Matrix& a) const {

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