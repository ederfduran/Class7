#include <cassert>

#include "BirthDate.h"



cpp_class7::BirthDate::BirthDate(const unsigned short inYear, const unsigned short inDay, const unsigned short inMonth)
	:year(inYear),day(inDay),month(inMonth)
{
	assert(inDay>0 && inDay <=31);
	assert(inMonth>0 && inMonth <= 12);
}

cpp_class7::BirthDate::BirthDate(const BirthDate & other)
	:year(other.getYear()),day(other.getDay()),month(other.getMonth())
{
}

unsigned short cpp_class7::BirthDate::getDay()const {
	return day;
}

unsigned short cpp_class7::BirthDate::getMonth()const {
	return month;
}

unsigned short cpp_class7::BirthDate::getYear()const {
	return year;
}

std::string cpp_class7::BirthDate::toString() const {
	return std::to_string(year)+"/"+ std::to_string(day)+"/"+ std::to_string(month);
}

cpp_class7::zodiacSign cpp_class7::BirthDate::getZodicaSign() const
{
	switch (month)
	{
	case 1:
	{
		return day >= 20 ? ZS_AQUARIUS : ZS_CAPRICORN;
	}
	case 2:
	{
		return day >= 19 ? ZS_PISCES : ZS_AQUARIUS;
	}
	case 3:
	{
		return day >= 21 ? ZS_ARIES : ZS_PISCES;
	}
	case 4:
	{
		return day >= 20 ? ZS_TAURUS : ZS_ARIES;
	}
	case 5:
	{
		return day >= 21 ? ZS_GEMINI : ZS_TAURUS;
	}
	case 6:
	{
		return day >= 21 ? ZS_CANCER : ZS_GEMINI;
	}
	case 7:
	{
		return day >= 23 ? ZS_LEO : ZS_CANCER;
	}
	case 8:
	{
		return day >= 23 ? ZS_VIRGO : ZS_LEO;
	}
	case 9:
	{
		return day >= 23 ? ZS_LIBRA : ZS_VIRGO;
	}
	case 10:
	{
		return day >= 23 ? ZS_SCORPIO : ZS_LIBRA;
	}
	case 11:
	{
		return day >= 22 ? ZS_AQUARIUS : ZS_SCORPIO;
	}
	case 12:
	{
		return day >= 22 ? ZS_CAPRICORN : ZS_SAGITTARIUS;
	}
	default:
		return ZS_INVALID;
	}
}

unsigned short cpp_class7::BirthDate::getAge() const
{
	if (CURRENT_MONTH >= month && CURRENT_DAY >= day) {
		return CURRENT_YEAR - year;
	}
	return CURRENT_YEAR - year-1;
}
