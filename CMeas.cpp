#include "CMeas.h"
#include <string>

void CMeas::Test() {
	for (int i = 0; i < N; ++i)
		if (iData[i] < 0)
			throw std::overflow_error("Value mustn't be negative.");
}

CMeas::CMeas() {
	for (int i = 0; i < N; ++i)
		iData[i] = 0;
	iSize = 0;
}

CMeas::CMeas(const double aBegin, const double aEnd, size_t aStep) {
	if ((aBegin < aEnd && aStep < 0))
		throw std::range_error("Values cannot be generated. Step is not positive");
	else if (aBegin > aEnd&& aStep > 0)
		throw std::range_error("Values cannot be generated. Step is not negative");
	else {
		int i = 0;
		double curr = aBegin;
		while (i < N && curr < aEnd) {
			iData[i] = curr;
			curr += aStep;
			++i;
		}
		iSize = i + 1;
	}
}

CMeas::CMeas(const char* aStr) {
	std::string curr = "";
	char ch = ' ';
	int i = 0, j = 0;
	while (ch != '\0' && j < N) {
		ch = aStr[i];
		if ((ch == ';')) {
			iData[j] = std::stod(curr);
			++j, ++iSize;
			curr = "";
		}
		else if(aStr[i + 1] == '\0'){
			curr += ch;
			iData[j] = std::stod(curr);
			++j, ++iSize;
		}
		else 
			curr += ch;
		++i;
	}
}

CMeas::CMeas(const double aVal) {
	iData[0] = aVal;
	iSize = 1;
}

CMeas::CMeas(double aData[], size_t aSize) {
	size_t i = 0;
	for (i; (i < aSize) && (i < N); ++i)
		iData[i] = aData[i];
	iSize = i;
}

bool CMeas::operator >= (const CMeas& aMeas) {
	return (double(*this) >= double(aMeas));
}

std::ostream& operator <<(std::ostream& aOStream, const CMeas& aMeas) {
	aOStream << '[';
	for (size_t i = 0; i < aMeas.iSize; ++i) {
		aOStream << aMeas.iData[i];
		if (i < aMeas.iSize - 1)
			aOStream << ';';
	}
	aOStream << ']';
	return aOStream;
}

CMeas::operator double() const {
	double aver = 0;
	for (size_t i = 0; i < iSize; ++i)
		aver += iData[i];
	aver /= iSize;
	return aver;
}

CMeas& CMeas::operator =(const CMeas& aMeas) {
	for (size_t i = 0; i < aMeas.iSize; ++i) {
		iData[i] = aMeas.iData[i];
	}
	iSize = aMeas.iSize;
	return *this;
}

CMeas& CMeas::operator++() {
	for (size_t i = 0; i < iSize; ++i)
		iData[i] += 1;
	return *this;
}

CMeas& CMeas::operator +=(const CMeas& aMeas) {
	for (size_t i = 0; i < aMeas.iSize; ++i) {
		this[i] += aMeas.iData[i];
	}
	return *this;
}

CMeas& CMeas::operator *(const double aVal) {
	for (size_t i = 0; i < iSize; ++i)
		iData[i] *= aVal;
	return *this;
}

CMeas CMeas::operator -(const CMeas& aMeas) const {
	CMeas ret_meas = *this;
	for (size_t i = 0; i < aMeas.iSize; ++i)
		ret_meas.iData[i] -= aMeas.iData[i];
	return ret_meas;
}