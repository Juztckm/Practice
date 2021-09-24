#pragma once
class ResultStatus
{
public:
	ResultStatus() {}
	virtual ~ResultStatus() {}
	ResultStatus& operator=(const int& ifail)
	{
		if (ifail != 0)
		{
			throw (ifail);
		}
		return *this;
	}
	ResultStatus(const int& ifail)
	{
		*this = ifail;
	}
private:
};

