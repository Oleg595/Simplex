#pragma once
#include"Linear.h"
#include"Parser.h"

struct Matrix;
enum TT;

class Simplex {
public:
	Simplex(Matrix A, std::vector<double> b, std::vector<double> c, TT type_task);
	void Answer();
private:
	std::vector<std::pair<std::vector<double>, size_t>> data;//�����������, � ������� ����������, ���������� ����� ������ ����������
	std::vector<double> func;//������, ���������� �������
	std::vector<double> delta;//������ delt
	double answer;//�����
	bool have_ans;
	void Choose(size_t i, size_t min);
	size_t Determine(size_t i);
	size_t Check();
	size_t Num_Var(std::vector<double> vector);
	bool Check_Data();
	void Positive_b();
};