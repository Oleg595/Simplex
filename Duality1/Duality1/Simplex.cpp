#include"Simplex.h"

Simplex::Simplex(Matrix A, std::vector<double> st, std::vector<double> c) {
	std::vector<double> b = A.Gauss(st);
	for (size_t i = 0; i < A.get_n(); i++) {
		std::vector<double> time_vector;
		time_vector.push_back(b[i]);
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
	size_t max = 0;
	int count = 0;
	while ((max = Check()) != func.size()) {
		if (count < func.size()) {
			Choose(max + 1, Determine(max + 1));
			count++;
		}
		else {
			size_t var;
			size_t min = data[0].second;
			for (size_t i = 1; i < data.size(); i++) {
				if (data[i].second < min) {
					min = data[i].second;
				}
			}
			for (size_t i = 0; i < delta.size(); i++) {
				if (delta[i] > pow(10, -5)) {
					var = i;
					break;
				}
			}
			Choose(var + 1, min);
			count = 0;
		}
	}
}

size_t Simplex::Determine(size_t i) {
	size_t min1 = 0;
	for (min1 = 0; min1 < data.size(); min1++) {
		if (fabs(data[min1].first[i]) > pow(10, -5)) {
			break;
		}
	}
	for (size_t j = min1; j < data.size(); j++) {
		if ((fabs(data[j].first[i]) > pow(10, -5)) && (data[j].first[0] / data[j].first[i] < data[min1].first[0] / data[min1].first[i])) {
			min1 = j;
		}
	}
	return min1;
}

size_t Simplex::Check() {
	delta.clear();
	for (size_t i = 0; i < func.size(); i++) {
		delta.push_back(-func[i]);
	}
	answer = 0;
	for (size_t i = 0; i < data.size(); i++) {
		size_t num = data[i].second;
		answer += func[num] * data[i].first[0];
		for (size_t j = 0; j < delta.size(); j++) {
			delta[j] += func[num] * data[i].first[j + 1]; 
		}
	}
	size_t max = 0;
	for (size_t i = 1; i < delta.size(); i++) {
		if (delta[max] < delta[i]) {
			max = i;
		}
	}
	if (delta[max] < pow(10, -5)) {
		return delta.size();
	}
	return max;
}

void Simplex::Choose(size_t i, size_t min1) {
	size_t min = min1;
	for (size_t j = 0; j < data[min].first.size(); j++) {
		if (j != i) {
			data[min].first[j] /= data[min].first[i];
		}
	}
	data[min].second = i - 1;
	data[min].first[i] = 1.;
	for (size_t j = 0; j < data.size(); j++) {
		if (j != min) {
			for (size_t q = 0; q < data[j].first.size(); q++) {
				if (q != i) {
					data[j].first[q] -= data[min].first[q] * data[j].first[i];
				}
			}
			data[j].first[i] = 0.;
		}
	}
}

void Simplex::Answer() {
	std::cout << "x[i]:" << std::endl;
	for (size_t i = 0; i < data[0].first.size(); i++) {
		std::cout << data[0].first[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "F = " << answer << std::endl;
}