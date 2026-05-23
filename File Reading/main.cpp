#include <iostream>
#include <string>
#include <vector>
#include "Pupil.h"


static void clear_error_flags()
{
	// clear error flags
	std::cin.clear();
	// Wrong input remains on the stream, so you need to get rid of it
	std::cin.ignore(INT_MAX, '\n');
}

int get_age(int student_counter)
{
	int input;
	bool valid = false;
	while (!valid) { // repeat as long as the input is not valid
		std::cout << "Enter pupil " << student_counter << " age: ";
		std::cin >> input;
		if (std::cin.fail())
		{
			std::cout << "Wrong input! " <<  std::endl;
			clear_error_flags();
			
		}
		else if (input < 5 || input > 18)
		{
			std::cout << "Age must be between 05 and 18" << std::endl;
		}
		else
		{
			valid = true;
		}
	}
	return input;
}
int main() {
	std::cout << "Pupil Username Program" << std::endl;
	std::cout << "========================" << std::endl;
	// create a vector to hold the pupils
	std::vector<Pupil> pupils;
	// counter for pupils (also used in loop to show user which pupil they are entering details for)
	int student_counter = 1; 

	// loop to get details for 10 pupils
	while (student_counter <= 10) {

		// create variables to hold input
		std::string forename;
		std::string surname;
		int age;

		// get input from user
		std::cout << "Enter pupil " << student_counter << " firstname: ";
		std::cin >> forename;
		std::cout << "Enter pupil " << student_counter << " lastname: ";
		std::cin >> surname;
		age = get_age(student_counter);

		// create a Pupil object and add to vector
		Pupil pupil(forename, surname, age);
		pupils.push_back(pupil);

		// output the pupil details
		std::cout << pupil.toString() << std::endl;
		

		// increment pupil counter
		++student_counter;

	}

	return 0;
}
