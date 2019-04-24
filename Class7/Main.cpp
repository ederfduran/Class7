
#include "TestBirthDate.h"
#include "TestCitizen.h"
#include "TestCity.h"

int main() {
	
	cpp_class7_test::TestBirthDate test;
	test.testGetAge();
	test.testGetDay();
	test.testGetMonth();
	test.testGetYear();
	test.testGetZodicaSign();
	test.testToString();

	cpp_class7_test::TestCitizen test2;
	test2.testGetBirthDate();
	test2.testGetGender();
	test2.testGetName();
	test2.testGetSureName();
	test2.testIsAdult();
	test2.testIsChild();
	test2.testIsRetired();
	test2.testIsTeenager();

	cpp_class7_test::TestCity test3;
	test3.testAddCitizen();
	test3.testGetCapacity();
	test3.testGetCitizenByName();
	test3.testGetCount();
	return 0;
}