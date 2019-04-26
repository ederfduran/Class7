#ifndef BIRTH_DATE_H_
#define BIRTH_DATE_H_
#define CURRENT_YEAR 2019
#define CURRENT_MONTH 1
#define CURRENT_DAY 1

#include <string>

namespace cpp_class7_test {
	class TestBirthDate;
}

namespace cpp_class7 {
	enum ZodiacSign {
	ZS_INVALID=0,
    ZS_ARIES,
	ZS_TAURUS,
	ZS_GEMINI,
	ZS_CANCER,
	ZS_LEO,
	ZS_VIRGO,
	ZS_LIBRA,
	ZS_SCORPIO,
	ZS_SAGITTARIUS,
	ZS_CAPRICORN,
	ZS_AQUARIUS,
	ZS_PISCES
	};

	class BirthDate {

	private:
		unsigned short mMonth,mDay,mYear;
	public:
		friend class cpp_class7_test::TestBirthDate;
		BirthDate(const unsigned short inYear, 
			const unsigned short inDay,
			const unsigned short inMonth);
		BirthDate(const BirthDate& other);
		unsigned short getDay() const;
		unsigned short getMonth() const;
		unsigned short getYear() const;
		std::string toString()const ;
		ZodiacSign getZodicaSign() const;
		unsigned short getAge() const;
	};
}

#endif // !BIRTH_DATE_H_
