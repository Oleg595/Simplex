#include <iostream>
#include <fstream>
#include "Parser.h"
#include "Linear.h"
#include"Simplex.h"


int main(int argc, char* argv[]) {
	if (argc > 1) {
		Parser parser(argv[1]);
		Linear linear = parser.parse();
		Simplex simplex(linear.get_Matrix(), linear.get_b(), linear.get_func(), linear.task_Type());
		std::vector<double> optimal = linear.solve_task();
		simplex.Answer();

		std::cout << "\n\nOptimal:\n";
		for (auto elem : optimal) {
			std::cout << elem << " ";
		}

		Linear* dual = linear.get_dual_program();
		Simplex dual_Simplex(dual->get_Matrix(), dual->get_b(), dual->get_func(), dual->task_Type());
 		dual_Simplex.Answer();
		std::vector<double> dual_optimal = linear.get_dual_program()->solve_task();
		std::cout << "\n\nDual optimal:\n";
		for (auto elem : dual_optimal) {
			std::cout << elem << " ";
		}
	}
	return 0;
}