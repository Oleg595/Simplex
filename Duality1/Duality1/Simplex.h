#pragma once
#include"Linear.h"
#include"Parser.h"

struct Matrix;

class Simplex {
public:
	Simplex(Matrix A, std::vector<double> b, std::vector<double> c);
	void Answer();
private:
	std::vector<std::pair<std::vector<double>, size_t>> data;//�����������, � ������� ����������, ���������� ����� ������ ����������
	std::vector<double> func;//������, ���������� �������
	std::vector<double> delta;//������ delt
	double answer;//�����
	void Choose(size_t i, size_t min);
	size_t Determine(size_t i);
	size_t Check();
};