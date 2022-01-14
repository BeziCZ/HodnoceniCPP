#include <iostream>
#define N 4

class CMeas {
	double iData[N] = {0,0,0,0};
	size_t iSize = 0;
private:
	void Test();

public:
	CMeas();
	CMeas(const double aBegin, const double aEnd, size_t aStep = 1);
	CMeas(const char* aStr);
	CMeas(const double aVal);
	CMeas(double aData[], size_t aSize);

	bool operator >= (const CMeas& aMeas);
	friend std::ostream& operator <<(std::ostream& aOStream, const CMeas& aMeas);
	operator double() const;
	CMeas& operator =(const CMeas& aMeas);
	CMeas& operator++();
	CMeas& operator +=(const CMeas& aMeas);
	CMeas& operator *(const double aVal);
	CMeas operator -(const CMeas& aMeas) const;
};