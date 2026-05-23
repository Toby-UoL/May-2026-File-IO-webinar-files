#include "Pupil.h"
#include <string>
#include <iostream>
#include <fstream>



//int age;

// Initialize the static member variable
int Pupil::object_number = 0; 


// Constructor definition.
// Uses an initializer list to set forename, surname, and age.
// Calls helper methods to create username and write data to file.
// Parameters:
// - forename: The pupil's first name.
// - surname: The pupil's last name.
//	 - age: The pupil's age.
Pupil::Pupil(const std::string& forename, const std::string& surname, int age)
    : forename(forename), surname(surname), age(age)
{
    object_number++; // Increment the static object counter
	create_username(); // Generate a unique username based on name and ID
    write_to_file("pupils.csv"); // Append the pupil's data to the file
}


// Returns the username.
std::string Pupil::get_username()
{
	return username;
}

// Create a username from the first four letters of the name and the student ID
void Pupil::create_username() {
		
	// Convert the ID to a string
	std::string string_id = std::to_string(object_number);
	// Add leading zero if ID is less than 100000
	while (string_id.length() < 6) {
		string_id = "0" + string_id; // Add leading zero if ID is less than 100000
	}
	// Combine surname and forename
	std::string name =  surname + forename;

	// Add x if combined surname and forename is less than 4 characters
	// unlikely, but possible
	while
		(name.length() < 4) {
		name = name + "x"; // Add x if name is less than 4 characters
	}
	// Create username from first four letters of name and (padded) string_id
	username = name.substr(0, 4) + string_id;

}
	
// Appends the pupil's details to a specified file in CSV format.
void Pupil::write_to_file(std::string file)
{
	// Open the file in append mode
	std::ofstream ost{ file, std::ios_base::app };
	// Check if the file opened successfully
	if (!ost) {
		// if not, print an error message and return (exiting the method)
		std::cerr << "Error: Could not open file " << file << " for writing.\n";
		return;
	}
	// Write the CSV line to the file
	ost << create_csvLine();
}

// Creates a CSV formatted line of the pupil's details.
std::string Pupil::create_csvLine() const
{
	return (forename + "," + surname + "," + username + "," + std::to_string(age) + "\n");
}

// Returns a string representation of the pupil's details.
std::string Pupil::toString() {
	return (forename + " " + surname +" username: "+ username);
};


	
