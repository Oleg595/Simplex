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
	vector<pair<vector<double>, size_t>> data;//неравенства, в которых переменные, выражаются через другие переменные
	vector<double> b;//вектор свободных членов
	vector<double> func;//вектор, содержащий функцию
	double answer;//ответ
	double* ToDoubleArr(vector<double> vector);
	void Choose(size_t i);
	bool Check();
	void Express(pair<vector<double>, size_t> d);
};