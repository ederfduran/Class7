#include <string.h>

#include "City.h"
#include "Citizen.h"


cpp_class7::City::City(const City & other)
	: length(other.getLength()), capacity(other.getCapacity()), citizens(new Citizen[other.getCapacity()])
{
	//std::copy(other.citizens, other.citizens + other.capacity, citizens);
	memcpy(citizens,other.citizens,sizeof(Citizen)*capacity);
}

cpp_class7::City::City(unsigned int inCapacity)
	:length(0),capacity(inCapacity),citizens(new Citizen[inCapacity])
{
}

cpp_class7::City::~City()
{
	delete[] citizens;
}

unsigned int cpp_class7::City::getCapacity() const
{
	return capacity;
}

unsigned int cpp_class7::City::getLength() const
{
	return length;
}

bool cpp_class7::City::addCitizen(const Citizen & citizen)
{
	if (capacity<=length) {
		return false;
	}
	for (unsigned int i = 0;i<length;i++) {
		if (citizens[i].getName()== citizen.getName()
			&& citizens[i].getSureName() == citizen.getSureName()) {
			return false;
		}
	}
	citizens[length++] = citizen;
	return true;
}

unsigned int cpp_class7::City::getRetiredCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0;i<length;i++) {
		if (citizens[i].isRetired()) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getChildCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<length; i++) {
		if (citizens[i].isChild()) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getTeenagerCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<length; i++) {
		if (citizens[i].isTeenager()) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getManCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<length; i++) {
		if (citizens[i].getGender()==G_MALE) {
			count++;
		}
	}
	return count;
}

unsigned int cpp_class7::City::getWomanCount() const
{
	unsigned int count = 0;
	for (unsigned int i = 0; i<length; i++) {
		if (citizens[i].getGender() == G_FEMALE) {
			count++;
		}
	}
	return count;
}

const cpp_class7::Citizen * cpp_class7::City::getCitizenByName(const std::string & name, const std::string & sureName) const
{
	for (unsigned int i = 0; i<length; i++) {
		if (citizens[i].getName() == name
			&& citizens[i].getSureName() == sureName) {
			return &citizens[i];
		}
	}
	return nullptr;
}
