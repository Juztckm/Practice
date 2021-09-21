#include <iostream>
#pragma once
class CopyConstAssiOpTest
{
public:
	CopyConstAssiOpTest();
	CopyConstAssiOpTest(const CopyConstAssiOpTest& rhs);
	CopyConstAssiOpTest& operator =(const CopyConstAssiOpTest& rhs);
	friend std::ostream& operator <<(std::ostream& out, const CopyConstAssiOpTest& rhs);
	CopyConstAssiOpTest(int id);
private:
	int id;
};

