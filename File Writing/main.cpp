#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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

// Scans the entire CSV file to find the highest generated ID to ensure we do not create duplicates.
// We pass the filename as a constant reference (const std::string&) for memory efficiency.
static int initialise_pupil_counter(const std::string& filename)
{
	// Attempt to open the file in read-only mode using an input file stream.
	std::ifstream file{ filename };

	// If the file cannot be opened (e.g. it does not exist yet because this is the first run),
	// we safely return 0 so the program can start generating IDs from the beginning.
	if (!file.is_open()) {
		return 0;
	}

	std::string line;

	// We create a variable to track the highest ID number we find in the file.
	// It starts at 0. If we find a 1, it updates to 1. If we find a 5, it updates to 5.
	int max_id = 0;

	// A while loop is used with std::getline to read the file line by line, from top to bottom.
	// We do not store the whole file in memory. We just look at one line, process it, and move on.
	while (std::getline(file, line)) {

		// If someone accidentally added a blank line to the file, we skip it.
		// The 'continue' keyword tells the loop to immediately jump to the next iteration.
		if (line.empty()) {
			continue;
		}

		// We now need to extract data from the comma-separated string.
		// std::stringstream allows us to treat a string exactly like an input stream (like cin).
		std::stringstream ss(line);
		std::string token;
		std::string username;
		int comma_count = 0;

		// We read the stringstream up to every comma (',') and store the chunk in 'token'.
		// We are looking for the third column, which holds the username (e.g. "SmitJohn000005").
		while (std::getline(ss, token, ',')) {
			comma_count++;
			if (comma_count == 3) {
				username = token;
				break; // We found the username, so we exit this inner loop to save processing time.
			}
		}

		// The username generation logic dictates that it always ends with a 6-digit ID number.
		if (username.length() >= 6) {
			try {
				// std::string::substr extracts a smaller string from the main string.
				// By taking the total length and subtracting 6, we isolate just the numeric part at the end.
				std::string id_string = username.substr(username.length() - 6);

				// std::stoi converts the string representation of the number into a mathematical integer.
				int current_id = std::stoi(id_string);

				// We check if this newly found ID is higher than our current maximum.
				// If it is, we update max_id. This ensures that even if bad data exists later in the file,
				// we always remember the highest valid number we successfully read.
				if (current_id > max_id) {
					max_id = current_id;
				}
			}
			catch (...) {
				// The catch (...) block is a catch-all that traps ANY exception.
				// If a line has corrupted data (e.g., text where the ID should be), std::stoi will fail.
				// Instead of crashing the program, we catch the error, do nothing, and use 'continue' 
				// to safely skip the bad line and keep reading the rest of the file.
				continue;
			}
		}
	}

	// Always close the file once reading is complete to free up system resources.
	file.close();

	// Return the absolute highest ID found in the entire file so the program can resume counting safely.
	return max_id;
}

int main() {
	std::cout << "Pupil Username Program" << std::endl;
	std::cout << "========================" << std::endl;

	// Initialisation Step: Read file and update static object_number
	int last_used_id = initialise_pupil_counter("pupils.csv");
	Pupil::set_object_number(last_used_id);

	std::cout << "Resuming from ID sequence: " << last_used_id << "\n\n";

	// create a vector to hold the pupils
	std::vector<Pupil> pupils;

	// counter for pupils 
	int student_counter = 1;

	// Infinite loop to get details indefinitely until the sentinel value is triggered
	while (true) {

		// create variables to hold input
		std::string forename;
		std::string surname;
		int age;

		// get input from user, offering the highly specific sentinel value
		std::cout << "Enter pupil " << student_counter << " firstname (or type '$' to quit): ";
		std::cin >> forename;

		// Check for the sentinel value
		if (forename == "$") {
			std::cout << "\nExiting data entry. " << (student_counter - 1) << " pupils added during this session." << std::endl;
			break; // This immediately stops the infinite while loop
		}

		std::cout << "Enter pupil " << student_counter << " lastname: ";
		std::cin >> surname;
		age = get_age(student_counter);

		// create a Pupil object and add to vector
		Pupil pupil(forename, surname, age);
		pupils.push_back(pupil);

		// output the pupil details
		std::cout << pupil.toString() << "\n" << std::endl;

		// increment pupil counter
		++student_counter;

	}

	std::cout << "\nProgram complete. Press Enter to exit..." << std::endl;

	std::cin.ignore(INT_MAX, '\n'); // This line acts as a strict cleaner for the input buffer
	std::cin.get(); //  waits for the user to input a single character

	return 0;
}
