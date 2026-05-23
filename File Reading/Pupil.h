#pragma once
// Ensures the header file is only included once during compilation.
// Prevents multiple definition errors.



#include <string>
#include <iostream>


// Class definition for Pupil
class Pupil
{
	public:

		// Constructor: Takes forename, surname, and age as input.
		// The ampersands (&) indicate **pass by reference** for strings.
		// This avoids copying the entire string object, improving performance.
		// The `const` keyword ensures the function does not modify the passed strings.
		Pupil(const std::string& forename, const std::string& surname, int age);

		// Returns the generated username for the pupil.
		std::string get_username();

		// Returns a string representation of the pupil's details.
		std::string toString();

	private:
		// Member variables to store pupil details

		// STRINGS
		std::string forename;
		std::string surname;
		std::string username;

		// INTEGER
		int age;


		// Static variable shared across all Pupil objects.
		// Used to count how many Pupil objects have been created
		// STATIC INTEGER
		static int object_number;

		// Helper methods for internal operations.
		// 
		// Generates a unique username for the pupil.
		void create_username();		

		// Writes the pupil's details to a specified file.
		void write_to_file(std::string file);

		// Creates a CSV formatted line of the pupil's details.
		std::string create_csvLine() const;
};

