#ifndef CITY_H_
#define CITY_H_
#include <string>


namespace cpp_class7_test {
	class TestCity;
}

namespace cpp_class7 {

	class Citizen;
	class City {
	private:
		unsigned int length;
		unsigned int capacity;
		Citizen * citizens;
	public:

		friend class cpp_class7_test::TestCity;

		City(const City& other);
		City(unsigned int inCapacity);
		~City();
		unsigned int getCapacity() const;
		unsigned int getLength() const;
		bool addCitizen(const Citizen& citizen);
		unsigned int getRetiredCount()const;
		unsigned int getChildCount()const;
		unsigned int getTeenagerCount()const;
		unsigned int getManCount()const;
		unsigned int getWomanCount()const;
		const Citizen* getCitizenByName(const std::string& name, const std::string& sureName) const;

	};
}

#endif // !CITY_H_
