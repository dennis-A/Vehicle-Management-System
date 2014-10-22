//Filename: Manufacturer.h
//Author: Ancheta, Dennis
//Date Written: 10-20-12
//Description: Interface file for the Manufacturer class

#pragma once
#include <iostream>
using namespace std;

const int MAX_NAME = 15;
const int MAX_LOCATION = 15;

class Manufacturer
{
	friend ostream& operator<<(ostream& out, const Manufacturer& manufacturer);	
	//Pre-condition: None
	//Post-condition: Allows for manufacturer to use ostream 

	public:
		//Function prototypes

		Manufacturer(const char* nm = "", const char* loc = "");
		//Pre-condition: nm cannot be longer than MAX_NAME characters
		//				 loc cannot be longer than MAX_LOC characters
		//Post-condition: nm and loc will be stored in name and location,
		//				  respectively.

		Manufacturer(const Manufacturer& source);
		//Pre-condition: Copy constructor. 
		//Post-condition: Copies the exact same Manufacturer object 
		//                that is passed in as &source and copies
		//				  its name and location.

		const Manufacturer& operator=(const Manufacturer& right);
		//Pre-condition: Must have a Manufacturer to be assigned to 
		//				 left vehicle object.
		//Post-condition: Assigns Manufacturer object on right to 
		//				  left object

		~Manufacturer();
		//Pre-condition: When called, deletes name and location.
		//Post-condition: Deletes the contents in name and location.

		void setName(const char* nm = "");
		//Pre-condition: Must have entered a name not exceeding
		//				 15 characters long. If name is not NULL,
		//				 deletes contents in name.
		//Post-condition: Sets name in vehicle if the conditions are met

		void setLocation(const char* loc = "");
		//Pre-condition: Must have entered a location not 
		//				 exceeding more than 15 characters long. If
		//				 location is not NULL, deletes contents
		//			     in location.
		//Post-condition: Sets location in vehicle if the conditions are met

		void setManufacturer(const char* nm = "", const char* loc = "");
		//Pre-condition: Must have entered a name and location
		//				 not exceeding 15 characters
		//Post-condition: Sets nm and pr in vehicle if the conditions are met

		const char* getName()const;
		//Pre-condition: None
		//Post-condition: Returns name

		const char* getLocation()const;
		//Pre-condition: None
		//Post-condition: Returns location


	private:
		char* name;
		char* location;
		void copy(const Manufacturer &source);
		//Pre-condition: Contents in source will be copied.
		//Post-condition: Copies name and location from source into
		//				  setName and setLocation, which copies name 
		//				  and location and stores in copied object
		
};