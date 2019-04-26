#include <string.h>
#include <stdlib.h>

#include "BirthDate.h"
#include "City.h"
#include "Citizen.h"


cpp_class7::City::City(const City & other)
	: mLength(other.getLength()), mCapacity(other.getCapacity()), mCitizens(reinterpret_cast<Citizen*>(malloc(sizeof(Citizen)*other.getCapacity())))
{
	//std::copy(other.citizens, other.citizens + other.capacity, citizens);
	memcpy(mCitizens,other.mCitizens,sizeof(Citizen)*mCapacity);
}

cpp_class7::City::City(const unsigned int inCapacity)
	:mLength(0),mCapacity(inCapacity),mCitizens(reinterpret_cast<Citizen*>(malloc(sizeof(Citizen)*inCapacity)))
{
}

cpp_class7::City::~City()
{
	for (unsigned int i = 0; i < mLength; i++) {
		mCitizens[i].~Citizen();
	}

	free(mCitizens);
}

unsigned int cpp_class7::City::getCapacity() const
{
	return mCapacity;
}

unsigned int cpp_class7::City::getLength() const
{
	return mLength;
}

bool cpp_class7::City::addCitizen(const Citizen & citizen)
{
	if (mCapacity<=mLength) {
		return false;
	}
	for (unsigned int i = 0;i<mLength;i++) {
		if (mCitizens[i].getName()== citizen.getName()
			&& mCitizens[i].getSureName() == citizen.getSureName()) {
			return false;
		}
	}
	new (&mCitizens[mLength++]) Citizen(citizen);
	return true;
}

unsigned int cpp_class7::City::getRetiredCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0;i<mLength;i++) {
		if (mCitizens[i].isRetired()) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getChildCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<mLength; i++) {
		if (mCitizens[i].isChild()) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getTeenagerCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<mLength; i++) {
		if (mCitizens[i].isTeenager()) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getManCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<mLength; i++) {
		if (mCitizens[i].getGender()==G_MALE) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getWomanCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<mLength; i++) {
		if (mCitizens[i].getGender() == G_FEMALE) {
			count++;
		}
	}
	return count;
}

const cpp_class7::Citizen * cpp_class7::City::getCitizenByName(const std::string & name, const std::string & sureName) const
{
	for (unsigned int i = 0; i<mLength; i++) {
		if (mCitizens[i].getName() == name
			&& mCitizens[i].getSureName() == sureName) {
			return &mCitizens[i];
		}
	}
	return nullptr;
}
