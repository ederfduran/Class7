#include "BirthDate.h"
#include "Citizen.h"

cpp_class7::Citizen::Citizen():mBirth(nullptr),
mName(""),mSureName(""),mSex(G_MALE)
{
}

cpp_class7::Citizen::Citizen(const BirthDate & inBirth, const std::string & inName, const std::string& inSureName, const Gender & inSex)
	:mBirth(new BirthDate(inBirth)),mName(inName),mSureName(inSureName),mSex(inSex)
{
}

cpp_class7::Citizen::Citizen(const Citizen & other)
	: mBirth(new BirthDate(*other.mBirth)), mName(other.mName), 
	mSureName(other.mSureName), mSex(other.mSex)
{
}

cpp_class7::Citizen::~Citizen()
{
	delete mBirth;
}

const cpp_class7::Citizen & cpp_class7::Citizen::operator=(const Citizen & other)
{
	if (this == &other) {
		return *this;
	}
	if (mBirth) {
		delete mBirth;
	}
	mBirth = new BirthDate(*other.getBirthDate());
	mName = other.getName();
	mSureName = other.getSureName();
	mSex = other.getGender();
	return *this;
}

cpp_class7::BirthDate* cpp_class7::Citizen::getBirthDate() const
{
	return mBirth;
}

const std::string& cpp_class7::Citizen::getName() const
{
	return mName;
}

const std::string& cpp_class7::Citizen::getSureName() const
{
	return mSureName;
}

cpp_class7::Gender cpp_class7::Citizen::getGender() const
{
	return mSex;
}

bool cpp_class7::Citizen::isAdult() const
{
	return mBirth->getAge()>=18;
}

bool cpp_class7::Citizen::isTeenager() const
{
	return mBirth->getAge() >= 11 && mBirth->getAge() < 18;
}

bool cpp_class7::Citizen::isChild() const
{
	return mBirth->getAge() < 11 ;
}

bool cpp_class7::Citizen::isRetired() const
{
	if (mSex==G_MALE) {
		return mBirth->getAge() >= 65;
	}
	return mBirth->getAge() >= 60;
}
