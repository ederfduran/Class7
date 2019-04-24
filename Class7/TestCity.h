#ifndef TEST_CITY_H_
#define TEST_CITY_H_
#define MAX_NAME_LENGTH 15
#include <string>

namespace cpp_class7_test {

	class TestCity {
	public:

		TestCity();
		static const char* letters;
		static std::string getRandomName();

		void testGetCapacity() const;
		void testAddCitizen();
		void testGetCount()const;
		void testGetCitizenByName() const;


	};

}

#endif // !TEST_CITY_H_

