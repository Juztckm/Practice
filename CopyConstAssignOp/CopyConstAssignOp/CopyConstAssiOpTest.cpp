#include "CopyConstAssiOpTest.h"

CopyConstAssiOpTest::CopyConstAssiOpTest():id(0){}

CopyConstAssiOpTest::CopyConstAssiOpTest(const CopyConstAssiOpTest& rhs){	*this = rhs;}

CopyConstAssiOpTest& CopyConstAssiOpTest::operator=(const CopyConstAssiOpTest& rhs)
{
	this->id = rhs.id;
	return *this;
}

CopyConstAssiOpTest::CopyConstAssiOpTest(int id):id(id){}

std::ostream& operator<<(std::ostream& out, const CopyConstAssiOpTest& rhs)
{
	out << rhs.id << '\n';
	return out;
}
