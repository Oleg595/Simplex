#pragma once
#include"Linear.h"
#include"Parser.h"

struct Matrix;

class Simplex {
public:
	Simplex(Matrix A, std::vector<double> b, std::vector<double> c);
	void Answer();
private:
	std::vector<std::pair<std::vector<double>, size_t>> data;//неравенства, в которых переменные, выражаются через другие переменные
	std::vector<double> func;//вектор, содержащий функцию
	std::vector<double> delta;//вектор delt
	double answer;//ответ
	void Choose(size_t i, size_t min);
	size_t Determine(size_t i);
	size_t Check();
};