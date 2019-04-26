#include <cassert>

#include "BirthDate.h"



cpp_class7::BirthDate::BirthDate(const unsigned short inYear, const unsigned short inDay, const unsigned short inMonth)
	:mYear(inYear),mDay(inDay),mMonth(inMonth)
{
	assert(inDay>0 && inDay <=31);
	assert(inMonth>0 && inMonth <= 12);
}

cpp_class7::BirthDate::BirthDate(const BirthDate & other)
	:mYear(other.getYear()),mDay(other.getDay()),mMonth(other.getMonth())
{
}

unsigned short cpp_class7::BirthDate::getDay()const {
	return mDay;
}

unsigned short cpp_class7::BirthDate::getMonth()const {
	return mMonth;
}

unsigned short cpp_class7::BirthDate::getYear()const {
	return mYear;
}

std::string cpp_class7::BirthDate::toString() const {
	return std::to_string(mYear)+"/"+ std::to_string(mDay)+"/"+ std::to_string(mMonth);
}

cpp_class7::ZodiacSign cpp_class7::BirthDate::getZodicaSign() const
{
	switch (mMonth)
	{
	case 1:
	{
		return mDay >= 20 ? ZS_AQUARIUS : ZS_CAPRICORN;
	}
	case 2:
	{
		return mDay >= 19 ? ZS_PISCES : ZS_AQUARIUS;
	}
	case 3:
	{
		return mDay >= 21 ? ZS_ARIES : ZS_PISCES;
	}
	case 4:
	{
		return mDay >= 20 ? ZS_TAURUS : ZS_ARIES;
	}
	case 5:
	{
		return mDay >= 21 ? ZS_GEMINI : ZS_TAURUS;
	}
	case 6:
	{
		return mDay >= 21 ? ZS_CANCER : ZS_GEMINI;
	}
	case 7:
	{
		return mDay >= 23 ? ZS_LEO : ZS_CANCER;
	}
	case 8:
	{
		return mDay >= 23 ? ZS_VIRGO : ZS_LEO;
	}
	case 9:
	{
		return mDay >= 23 ? ZS_LIBRA : ZS_VIRGO;
	}
	case 10:
	{
		return mDay >= 23 ? ZS_SCORPIO : ZS_LIBRA;
	}
	case 11:
	{
		return mDay >= 22 ? ZS_AQUARIUS : ZS_SCORPIO;
	}
	case 12:
	{
		return mDay >= 22 ? ZS_CAPRICORN : ZS_SAGITTARIUS;
	}
	default:
		return ZS_INVALID;
	}
}

unsigned short cpp_class7::BirthDate::getAge() const
{
	if (CURRENT_MONTH >= mMonth && CURRENT_DAY >= mDay) {
		return CURRENT_YEAR - mYear;
	}
	return CURRENT_YEAR - mYear-1;
}
