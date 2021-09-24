#include<iostream>
#include "ResultStatus.h"

uint32_t main()
{
	ResultStatus resultStatus = 0;
	try
	{
		int a = 0;
		resultStatus = a;
		std::cout << "no iFail :: " << a << '\n';
	}
	catch (int iFail)
	{
		std::cout << "Caught iFail :: " << iFail << '\n';
	}
	return 0;
}