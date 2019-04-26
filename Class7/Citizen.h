#ifndef CITIZEN_H_
#define CITIZEN_H_
#include <string>


namespace cpp_class7_test {
	class TestCitizen;
}

namespace cpp_class7 {	
	class BirthDate;
	enum Gender {
		G_MALE=0,
		G_FEMALE
	};
	class Citizen {
	
	public:

		friend class cpp_class7_test::TestCitizen;
		Citizen();
		Citizen(const BirthDate & inBirth,const std::string & inName,
			const std::string& inSureName,const Gender& inSex);
		Citizen(const Citizen & other);
		~Citizen();
		const Citizen& operator =(const Citizen& other);

		BirthDate* getBirthDate()const;
		const std::string& getName()const;
		const std::string& getSureName()const;
		Gender getGender()const;
		bool isAdult() const;
		bool isTeenager()const;
		bool isChild()const;
		bool isRetired() const;

	private:
		BirthDate* mBirth;
		std::string mName, mSureName;
		Gender mSex;
	
	};
}

#endif // !CITIZEN_H_
