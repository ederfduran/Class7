#include <cassert>
#include <cstdlib>
#include <ctime>

#include "BirthDate.h"
#include "Citizen.h"
#include "City.h"
#include "TestCity.h"

const char* cpp_class7_test::TestCity::letters = "abcdefghijklmnopqrstuvwxyz";
		

cpp_class7_test::TestCity::TestCity()
{
	srand(static_cast<unsigned int>(time(nullptr)));
}

std::string cpp_class7_test::TestCity::getRandomName()
{
	const size_t lettersLength = sizeof(TestCity::letters) - 1;
	std::string randomName;
	const unsigned int wordLength = rand() % MAX_NAME_LENGTH;
	for (unsigned int i = 0;i<wordLength;i++) {
		randomName += TestCity::letters[rand()%lettersLength];
	}
	return randomName;
}

void cpp_class7_test::TestCity::testGetCapacity() const
{
	const unsigned int testCapacity = 100;
	cpp_class7::City cityTest(testCapacity);
	assert(testCapacity==cityTest.mCapacity);
	
}

void cpp_class7_test::TestCity::testAddCitizen()
{
	const unsigned int testCapacity = 100;
	cpp_class7::City cityTest(testCapacity);

	const cpp_class7::BirthDate birthTest(1992, 6, 3);
	const unsigned int citizenNumTest = 10 ;
	for (unsigned int i=0;i<citizenNumTest;i++) {
		std::string name = TestCity::getRandomName();
		std::string sureName = TestCity::getRandomName();
		cpp_class7::Citizen citizenTest(birthTest, name, sureName, cpp_class7::G_MALE);
		if (!cityTest.addCitizen(citizenTest)) {
			i--;
		};
	}

	assert(cityTest.getLength()== cityTest.mLength && cityTest.mLength==10);
}

void cpp_class7_test::TestCity::testGetCount() const
{
	const unsigned int testCapacity = 100;
	cpp_class7::City cityTest(testCapacity);

	const cpp_class7::BirthDate retiredBirthTest(1942, 2, 11);
	const unsigned int retiredNumTest = 10;
	for (unsigned int i = 0; i<retiredNumTest; i++) {
		std::string name = TestCity::getRandomName();
		std::string sureName = TestCity::getRandomName();
		cpp_class7::Citizen citizenTest(retiredBirthTest, name, sureName, cpp_class7::G_MALE);
		if (!cityTest.addCitizen(citizenTest)) {
			i--;
		};
	}

	const cpp_class7::BirthDate childBirthTest(2011, 23, 8);
	const unsigned int childNumTest = 25;
	for (unsigned int i = 0; i<childNumTest; i++) {
		std::string name = TestCity::getRandomName();
		std::string sureName = TestCity::getRandomName();
		cpp_class7::Citizen citizenTest(childBirthTest, name, sureName, cpp_class7::G_MALE);
		if (!cityTest.addCitizen(citizenTest)) {
			i--;
		};
	}

	const cpp_class7::BirthDate teenagerBirthTest(2005, 3, 3);
	const unsigned int teenagerNumTest = 25;
	for (unsigned int i = 0; i<teenagerNumTest; i++) {
		std::string name = TestCity::getRandomName();
		std::string sureName = TestCity::getRandomName();
		cpp_class7::Citizen citizenTest(teenagerBirthTest, name, sureName, cpp_class7::G_FEMALE);
		if (!cityTest.addCitizen(citizenTest)) {
			i--;
		};
	}

	int a = cityTest.getChildCount();
	assert(cityTest.getChildCount()== childNumTest);
	assert(cityTest.getRetiredCount() == retiredNumTest);
	assert(cityTest.getTeenagerCount() == teenagerNumTest);
	assert(cityTest.getWomanCount() == teenagerNumTest);
	assert(cityTest.getManCount()== retiredNumTest+childNumTest);

}

void cpp_class7_test::TestCity::testGetCitizenByName() const
{
	const unsigned int testCapacity = 2;
	cpp_class7::City cityTest(testCapacity);

	const cpp_class7::BirthDate birthTest(1992, 6, 3);
	std::string nameTest = "Eder";
	std::string sureNameTest = "Duran";

	cpp_class7::Citizen citizenTest(birthTest, nameTest, sureNameTest, cpp_class7::G_MALE);
	cityTest.addCitizen(citizenTest);
	assert(cityTest.getCitizenByName(nameTest,sureNameTest));

}
