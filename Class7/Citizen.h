#ifndef CITIZEN_H_
#define CITIZEN_H_
#include <string>


namespace cpp_class7_test {
	class TestCitizen;
}

namespace cpp_class7 {	
	class BirthDate;
	enum gender {
		G_MALE=0,
		G_FEMALE
	};
	class Citizen {
	
	public:

		friend class cpp_class7_test::TestCitizen;
		Citizen();
		Citizen(const BirthDate & inBirth,std::string & inName,
			std::string inSureName,const gender& inSex);
		Citizen(const Citizen & other);
		~Citizen();
		const Citizen& operator =(const Citizen& other);

		BirthDate* getBirthDate()const;
		std::string getName()const;
		std::string getSureName()const;
		gender getGender()const;
		bool isAdult() const;
		bool isTeenager()const;
		bool isChild()const;
		bool isRetired() const;

	private:
		BirthDate* birth;
		std::string name, sureName;
		gender sex;
	
	};
}

#endif // !CITIZEN_H_
