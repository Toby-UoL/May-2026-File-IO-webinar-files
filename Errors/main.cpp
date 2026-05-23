#include <iostream>
#include <string>
#include <vector>
#include <fstream>

double stod_e()
{
	std::string number = "Ten";
	double d_num = 0.0;
	d_num = std::stod(number);
	return d_num;
}

double stod_ex()
{
	std::string number = "Ten";
	double d_num = 0.0;
	try {
		d_num = std::stod(number);
	}
	catch (const std::exception& e) {
		std::cout << "Exception Hello!: " << e.what() << std::endl;
	}
	return d_num;
}

int vector_e()
{
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;
	// This will cause an out-of-bounds access
	int out = vec.at(5);
	return out;
}

int vector_ex()
{
	int out = 0;
	std::vector<int> vec = { 1, 2, 3, 4, 5 };
	for (int i = 0; i < vec.size(); ++i) {
		std::cout << vec.at(i) << " ";
	}
	std::cout << std::endl;

	// Use at() to perform bounds-checked access
	try {
		out = vec.at(5); // This will throw std::out_of_range
	}
	catch (const std::out_of_range& e) {
		std::cout << "Exception: " << e.what() << std::endl;
		std::cout << "***** vector_ex() ******" << std::endl;
	}
	return out;
}



int main()
{
	//stod_e();
	//stod_ex();
	// vector_e();
	vector_ex();
	return 0;
}
