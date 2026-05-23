#include <iostream>
#include <string>

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
			std::cout << "Wrong input! " << std::endl;
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
	int student_counter = 1;
	while (student_counter <= 20) {
		std::string forename;
		std::string surname;
		int age;
		std::cout << "Enter pupil " << student_counter << " firstname: ";
		std::cin >> forename;
		std::cout << "Enter pupil " << student_counter << " lastname: ";
		std::cin >> surname;
		age = get_age(student_counter);
		std::string username = "User" + std::to_string(student_counter);
		std::cout << "Pupil " << student_counter << " username: " << username << std::endl;
		++student_counter;
	}
	return 0;
}
