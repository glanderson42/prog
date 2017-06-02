// tetelek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

//max search (value)
template<typename T>
T& getMax(std::vector<T>& v) {
	return *std::max_element(v.begin(), v.end());
}
//max search (index)
template<typename T>
int getMaxIndex(std::vector<T> v) {
	return std::distance(v.begin(), std::max_element(v.begin(), v.end()));
}
//sum
template<typename T>
T& getSum(std::vector<T>& v) {
	T sum = std::accumulate(v.begin(), v.end(), (T)0);
	return sum;
}
//count
template<typename T>
int getCount(std::vector<T> v) {
	return std::count_if(v.begin(), v.end(), [](const int i) {return i % 2 == 0; });
}
//select
template<typename T>
T getSelected(std::vector<T> v) {
	return *std::find_if(v.begin(), v.end(), [](const int i) {return i % 2 == 0; });
}

template<typename T>
int getSelectedIndex(std::vector<T> v) {
	return std::distance(v.begin(), std::find_if(v.begin(), v.end(), [](const int i) {return i % 2 == 0; }));
}

template<typename T>
std::ostream& operator<<(std::ostream& out, std::vector<T> v) {
	for (int i = 0; i < v.size(); ++i) {
		out << v[i] << " ";
	}
	out << std::endl;
	return out;
}

template<typename T>
void writeItOut(std::vector<T> v) {
	std::cout << "The elements of the vector: ";
	std::cout << v;

	std::cout << "__________IT ONLY WORKS WITH NON EMPTY VECTORS__________" << std::endl;

	std::cout << "The maximum element of the vector: " << getMax(v) << std::endl;
	std::cout << "The index if the maximum element of the vector(index from zero): " << getMaxIndex(v) << std::endl;

	std::cout << "The sum of vector elements: " << getSum(v) << std::endl;

	std::cout << "The number of even elements: " << getCount(v) << std::endl;

	std::cout << "The first even number: " << getSelected(v) << std::endl;
	std::cout << "The index of the first even number: " << getSelectedIndex(v) << std::endl;
}

int main() {
	std::vector<int> v = { 5, 188, 8, 198, 7, 9, 2984 };
	writeItOut(v);
	return 0;
}