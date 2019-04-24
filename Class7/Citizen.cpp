#include "BirthDate.h"
#include "Citizen.h"

cpp_class7::Citizen::Citizen():birth(nullptr),
name(""),sureName(""),sex(G_MALE)
{
}

cpp_class7::Citizen::Citizen(const BirthDate & inBirth, std::string & inName, std::string inSureName, const gender & inSex)
	:birth(new BirthDate(inBirth)),name(inName),sureName(inSureName),sex(inSex)
{
}

cpp_class7::Citizen::Citizen(const Citizen & other)
	: birth(new BirthDate(*other.birth)), name(other.name), 
	sureName(other.sureName), sex(other.sex)
{
}

cpp_class7::Citizen::~Citizen()
{
	delete birth;
}

const cpp_class7::Citizen & cpp_class7::Citizen::operator=(const Citizen & other)
{
	if (this == &other) {
		return *this;
	}
	delete birth;
	birth = new BirthDate(*other.getBirthDate());
	name = other.getName();
	sureName = other.getSureName();
	sex = other.getGender();
	return *this;
}

cpp_class7::BirthDate* cpp_class7::Citizen::getBirthDate() const
{
	return birth;
}

std::string cpp_class7::Citizen::getName() const
{
	return name;
}

std::string cpp_class7::Citizen::getSureName() const
{
	return sureName;
}

cpp_class7::gender cpp_class7::Citizen::getGender() const
{
	return sex;
}

bool cpp_class7::Citizen::isAdult() const
{
	return birth->getAge()>=18;
}

bool cpp_class7::Citizen::isTeenager() const
{
	return birth->getAge() >= 11 && birth->getAge() < 18;
}

bool cpp_class7::Citizen::isChild() const
{
	return birth->getAge() < 11 ;
}

bool cpp_class7::Citizen::isRetired() const
{
	if (sex==G_MALE) {
		return birth->getAge() >= 65;
	}
	return birth->getAge() >= 60;
}
