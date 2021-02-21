#pragma once
#include"Linear.h"
#include"Parser.h"

using namespace std;

struct Matrix;

class Simplex {
public:
	Simplex(Matrix A, vector<double> b, vector<double> c);
	void Answer();
private:
	vector<pair<vector<double>, size_t>> data;//�����������, � ������� ����������, ���������� ����� ������ ����������
	vector<double> b;//������ ��������� ������
	vector<double> func;//������, ���������� �������
	double answer;//�����
	double* ToDoubleArr(vector<double> vector);
	void Choose(size_t i);
	bool Check();
	void Express(pair<vector<double>, size_t> d);
};