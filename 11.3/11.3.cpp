// 11.3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BasePlusCommissionEmployee.h"

int main()
{
    std::cout << "Hello World!\n";
	BasePlusCommissionEmployee *pBPCE = new BasePlusCommissionEmployee("Chuan", "Qin", "789-69-0524", 100000, 0.3, 999999);

	pBPCE->print();
	
	std::cout << "Earnings: " << pBPCE->earnings() << std::endl;

	delete pBPCE;
	pBPCE = nullptr;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
