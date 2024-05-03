#include<iostream>
#include<fstream>

int main() {
	std::ifstream fin;
	fin.open("tyson.txt");
	double num1;
	while (fin >> num1) {
		std::cout << num1 << std::endl;
	}
}