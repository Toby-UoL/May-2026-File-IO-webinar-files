// import the necessary libraries
#include <iostream>
#include <string>



int main() {
	std::cout << "Pupil Username Program" << std::endl;
	std::cout << "========================" << std::endl;

	// Student counter initialization - used to count the number of students, and for the username
	int student_counter = 1;

	// Loop to get details for 20 students
	while (student_counter <= 10) {

		// initialize variables to hold student details
		std::string forename;
		std::string surname;
		int age;

		// Get student details from user

		// ask for firstname
		std::cout << "Enter pupil " << student_counter << " firstname: ";
		// read firstname from user input into forename variable
		std::cin >> forename;

		// ask for surname
		std::cout << "Enter pupil " << student_counter << " lastname: ";
		// read surname from user input into surname variable
		std::cin >> surname;

		
		// ask for age
		std::cout << "Enter pupil " << student_counter << " age: ";
		// read surname from user input into surname variable
		std::cin >> age;

		// Generate username
		std::string username = "User" + std::to_string(student_counter);

		// Output the generated username
		std::cout << "Pupil " << student_counter << " username: " << username << std::endl;

		// Increment student counter
		++student_counter;
	} // end of while loop

	// End of program
	return 0;
}
