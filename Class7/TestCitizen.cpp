#include <cassert>

#include "BirthDate.h"
#include "Citizen.h"
#include "TestCitizen.h"

void cpp_class7_test::TestCitizen::testGetBirthDate() const
{
	const cpp_class7::BirthDate birthTest(1992, 6, 3);
	std::string nameTest = "Eder";
	std::string sureNameTest = "Duran";

	cpp_class7::Citizen citizenTets(birthTest,nameTest,sureNameTest,cpp_class7::G_MALE);
	const cpp_class7::BirthDate* birthDateTest = citizenTets.getBirthDate();
	assert(birthDateTest->getDay()==6 && birthDateTest->getMonth() == 3 && birthDateTest->getYear() == 1992 );
}

void cpp_class7_test::TestCitizen::testGetName() const
{
	cpp_class7::BirthDate birthTest(1997, 17, 10);
	std::string nameTest = "Benito";
	std::string sureNameTest = "Fulanito";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_MALE);
	assert(citizenTets.name== citizenTets.getName());
}

void cpp_class7_test::TestCitizen::testGetSureName() const
{
	cpp_class7::BirthDate birthTest(1992, 31, 3);
	std::string nameTest = "Benito";
	std::string sureNameTest = "Fulanito";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_MALE);
	assert(citizenTets.sureName == citizenTets.getSureName());
}

void cpp_class7_test::TestCitizen::testGetGender() const
{
	cpp_class7::BirthDate birthTest(1956, 24, 9);
	std::string nameTest = "James";
	std::string sureNameTest = "Rodriguez";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_MALE);
	assert(citizenTets.getGender()== cpp_class7::G_MALE);
}

void cpp_class7_test::TestCitizen::testIsAdult() const
{
	cpp_class7::BirthDate birthTest(1992, 6, 3);
	std::string nameTest = "Falcao";
	std::string sureNameTest = "Garcia";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_MALE);
	assert(citizenTets.isAdult());
}

void cpp_class7_test::TestCitizen::testIsTeenager() const
{
	cpp_class7::BirthDate birthTest(1997, 17, 10);
	std::string nameTest = "Mariana";
	std::string sureNameTest = "Pajon";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_FEMALE);
	assert(!citizenTets.isTeenager());
}

void cpp_class7_test::TestCitizen::testIsChild() const
{
	cpp_class7::BirthDate birthTest(2002, 16, 9);
	std::string nameTest = "Tina";
	std::string sureNameTest = "Turner";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_FEMALE);
	assert(!citizenTets.isChild());
}

void cpp_class7_test::TestCitizen::testIsRetired() const
{
	cpp_class7::BirthDate birthTest(1946, 24, 9);
	std::string nameTest = "James";
	std::string sureNameTest = "Bond";
	cpp_class7::Citizen citizenTets(birthTest, nameTest, sureNameTest, cpp_class7::G_MALE);
	assert(citizenTets.isAdult());
}
