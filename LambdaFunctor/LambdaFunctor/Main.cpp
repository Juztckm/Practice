#include <iostream>

#if 0
int funct(const std::string& name)
{
	std::cout << "Hello " << name << '\n';
	return 1;
}
#endif

int main()
{
	int a = 12;
	auto lambda = [=](std::string value) mutable
	{
		a = 14;
		std::cout << "Hello " << value << "\na = " << a << '\n'; 
	};
	lambda("Chandan");
#if 0
	typename int(*fun)(const std::string&);
	fun = funct;
	//auto fun = funct;
	//int(*fun)(const std::string&) = funct;
	fun("CKM");
	fun("JUZT");
	fun("SIVA");
	fun("CHANDAN");
#endif
	return 0;
}