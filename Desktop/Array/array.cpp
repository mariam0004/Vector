#include <iostream>
#include "array.h"
#include <bitset>

int main()
{
    Array<int, 5> arrInt;
    Array<double, 7> arrDouble;
	arrInt[0] = 10;
	arrInt[1] = 20;
	for(size_t i = 0; i < 5; ++i){
		std::cin >> arrInt[i];
	}
	std::cout << "Tarverse Result is: " << std::endl;
	arrInt.traverse();
	std::cout << std::endl;
	arrDouble[0] = 10.5;
	std::cout << arrDouble[0] << std::endl;

	std::string binStr("011111");
    Array<bool, 8> boolArr("011111");
 //   Array<int, 8> res = boolArr.to_Array(boolArr);
    std::cout << "Result of traversal for the bool array: " << std::endl;
    res.traverse();

	
	
   return 0;
}
