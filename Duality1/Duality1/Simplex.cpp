#include"Simplex.h"

Simplex::Simplex(Matrix A, vector<double> st, vector<double> c) {
	b = A.Gauss(st);
	for (size_t i = 0; i < A.get_n(); i++) {
		vector<double> time_vector;
		for (size_t j = 0; j < A.get_m(); j++) {
			if (i == j)
				time_vector.push_back(1.);
			else
				time_vector.push_back(A[i][j]);
		}
		data.push_back({ time_vector, i });
	}
	size_t i = 0;
	answer = 0.;
	for (i = 0; i < c.size(); i++) {
		func.push_back(c[i]);
	}
	for (; i < A.get_m(); i++) {
		func.push_back(0.);
	}
	for (size_t i = 0; i < data.size(); i++) {
		Express(data[i]);
	}
	while (!Check()) {
		size_t max = 0;
		for (size_t i = 1; i < func.size(); i++) {
			if (func[i] > func[max]) {
				max = i;
			}
		}
		Choose(max);
	}
}

double* Simplex::ToDoubleArr(vector<double> vector) {
	double* arr = new double[vector.size()];
	for (size_t i = 0; i < vector.size(); i++) {
		arr[i] = vector[i];
	}
	return arr;
}

bool Simplex::Check() {
	for (size_t i = 0; i != func.size(); i++) {
		if (func[i] > 0) {
			return false;
		}
	}
	return true;
}

void Simplex::Express(pair<vector<double>, size_t> d) {
	size_t num = d.second;
	vector<double> vector = d.first;
	for (size_t i = 0; i < vector.size(); i++) {
		if (i != num) {
			func[i] += func[num] * vector[i];
		}
	}
	answer += func[num] * b[num];
	func[num] = 0;
}

/*void Simplex::Choose(size_t i) {
	size_t min = 0;
	for (size_t j = 1; j < data.size(); j++) {
		if (data[j].first[i] / b[j] < data[min].first[i])
			min = j;
	}
	data[min].first[data[min].second] = 1;
	b[min] /= data[min].first[i];
	for (size_t j = 0; j < data[min].first.size(); j++) {
		if (j != i) {
			data[min].first[j] /= data[min].first[i];
		}
	}
	data[min].first[i] = 0.;
	data[min].second = i;
	for (size_t j = 0; j < data.size(); j++) {
		if (j != min) {
			for (size_t q = 0; q < data[j].first.size(); q++) {
				if (q != i) {
					data[j].first[q] += data[min].first[q] * data[j].first[i];
				}
			}
			data[j].first[i] = 0.;
			b[j] += b[min] * data[j].first[i];
		}
	}
	for (size_t j = 0; j < func.size(); j++) {
		if (j != i - 1) {
			func[j] += func[i] * data[min].first[j];
		}
	}
	answer += b[min] * func[i];
	func[i] = 0.;
}*/

void Simplex::Choose(size_t i) {

}

void Simplex::Answer() {
	cout << func[0] << endl;
}