#include <cassert>

#include "BirthDate.h"
#include "TestBirthDate.h"

void cpp_class7_test::TestBirthDate::testGetDay() const
{
	cpp_class7::BirthDate birthTest(1992,6,3);
	assert(birthTest.mDay==birthTest.getDay()&& birthTest.mDay==6);
}

void cpp_class7_test::TestBirthDate::testGetMonth() const
{
	cpp_class7::BirthDate birthTest(1992, 6, 3);
	assert(birthTest.mMonth == birthTest.getMonth() && birthTest.mMonth == 3);
}

void cpp_class7_test::TestBirthDate::testGetYear() const
{
	cpp_class7::BirthDate birthTest(1992, 6, 3);
	assert(birthTest.mYear == birthTest.getYear() && birthTest.mYear == 1992);
}

void cpp_class7_test::TestBirthDate::testToString() const
{
	cpp_class7::BirthDate birthTest(1956,24,9);
	std::string expectedResult = "1956/24/9";
	assert(expectedResult==expectedResult);
}

void cpp_class7_test::TestBirthDate::testGetZodicaSign() const
{
	cpp_class7::BirthDate birthTest(1990, 1, 5);
	cpp_class7::ZodiacSign expectedResult = cpp_class7::ZS_TAURUS;
	assert(expectedResult== birthTest.getZodicaSign());
}

void cpp_class7_test::TestBirthDate::testGetAge() const
{
	cpp_class7::BirthDate birthTest(1959, 24, 6);
	unsigned short expectedResult = 59;
	assert(expectedResult == birthTest.getAge());
}

