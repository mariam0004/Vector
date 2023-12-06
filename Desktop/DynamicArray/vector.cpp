
#include <iostream>
#include "vector.h"

int main()
{

	Vector<int> v = {1,4,5,2};
	for(Vector<int>::iterator it = v.begin(); it != v.end(); ++it){
		std::cout << *it <<  " ";
	}
	std::cout << std::endl;
/*
for (const auto& value : vec) {
        std::cout << value << " ";
    }	

	Vector<int> m;
	Vector<int> p = m;
	std::cout << "Using init list - ";
	Vector<char> i = {'a','b','c'};
	std::cout << i << std::endl;
	m.push_back(10);
	std::cout << "After push_bakc(val) - " << m << std::endl;
	m.push_back(100);
	m.push_back(10);
	for(size_t i = 0; i < m.vec_size(); ++i) {
		std::cout << m[i] << " ";
	}	
	std::cout << "\nCap of m = " << m.vec_cap()  << std::endl;
	std::cout << std::endl;
	Vector<const char*> stringVector = {"Hello ", "Poqrik ", ", Cheers", " To ", "You "};
	std::cout << stringVector << " " << std::endl;
	std::cout << "After invoke pop_back - ";
	stringVector.pop_back();
	std::cout << stringVector << " " << std::endl;
	std::cout << "Size of stringVector - " << stringVector.vec_size() << std::endl;
	std::cout << "\nUSE SHRINK_TO_FIT\n";

	Vector<int> intVec;
    for (int i = 0; i <= 10; ++i) {
        intVec.push_back(i);
    }
    std::cout << "Before shrink_to_fit: cap is - " << intVec.vec_cap() << std::endl;
    intVec.shrink_to_fit();
    std::cout << "After shrink_to_fit: cap is - " << intVec.vec_cap() << std::endl;
	
	std::cout << "Using Insert functions - \n";
	Vector<char> cV = {'m','t','a','a'};
	for(int i = 0; i < cV.vec_size(); ++i) {
		std::cout << "Idx - " << i << " - " << cV[i] << std::endl;
	}
	
	char ch = 'P';
	size_t idx = 1;
	cV.insert(ch, idx);
	std::cout << "\nAfter insert - \n";
	for(int i = 0; i < cV.vec_size(); ++i) {
		std::cout << "Idx - " << i << " - " << cV[i] << std::endl;
	}
	std::cout << "Invoking delete - \n";
	cV.deleteItem(2);
	for(int i = 0; i < cV.vec_size(); ++i) {
		std::cout << "Idx - " << i << " - " << cV[i] << std::endl;
	}
	std::cout << "Invoking delete(index,count)\n";
	cV.deleteItem(1, 2);
	for(int i = 0; i < cV.vec_size(); ++i) {
		std::cout << "Idx - " << i << " - " << cV[i] << std::endl;
	}
	cV.search('a');
	cV.search('H');
*/
	
/*
	std::cout << "Insert static array -\n";
	char c[] = {'A','B'};
	cV.insert(c, 1);
	for(int i = 0; i < cV.vec_size(); ++i) {
		std::cout << "Idx - " << i << " - " << cV[i] << std::endl;
	}

	std::cout << "Insert from index count of elem \n";
	cV.insert('P', 3, 1);
    std::cout << "\nAfter insert:\n";
    for (size_t i = 0; i < cV.vec_size(); ++i) {
        std::cout << "Idx - " << i << " - " << cV[i] << std::endl;
    }*/
/*	Vector<int> v;
	for(int i = 0; i < 5; ++i) {
		v.push_back(i);
	}
	std::cout << "Orig - ";
	for(int i = 0; i < v.vec_size(); ++i) {
		std::cout << v[i];
	}
	std::cout << std::endl;
	v.resize(10);
	std::cout << "After resizing- ";
	for(int i = 0; i < v.vec_size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	v.resize(7,7);
	for(int i = 0; i < v.vec_size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;
	v.resize(5);
	for(int i = 0; i < v.vec_size(); ++i) {
		std::cout << v[i] << " ";
	}
	std::cout << std::endl;*/
}

