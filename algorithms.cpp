#include <iostream>
#include <iterator>
#include <list>
#include <algorithm>
#include <cmath>

bool isPrime(int num) {
	num = std::abs(num);
	if(num == 0 || num == 1) {
		return false;
	}
		for(int div = 2; div <= std::sqrt(num); ++div) {
			if(num % div == 0) {
				return false;
			}
		}
	return true;
}
	int main()
	{
		std::list<int> l;
		for(int i = 1; i <= 6; ++i) {
		l.push_front(i);
		l.push_back(i);
	}
	for(const auto &i : l) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	l.erase(std::remove(l.begin(), l.end(),3), l.end());
	l.remove(4);
	for(const auto &i : l) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for_each(l.begin(), l.end(), [](int a) {std::cout << a + 1 << " ";});
	std::cout << std::endl;

	std::transform(l.begin(), l.end(), l.begin(), [](double d) { return d*d*d});

	for(const auto &i : l) {
		std::cout << i << " ";
	}
	
	
}
