//Filename: Manufacturer.cpp
//Author: Ancheta, Dennis
//Date Written: 10-20-12
//Description: Implementations for the Manufacturer class

#include<iostream>
#include"Manufacturer.h"
#include<iomanip>
#include<cassert>
using namespace std;


ostream& operator<<(ostream& out, const Manufacturer& manufacturer)
//Pre-condition: None
//Post-condition: Allows manufacturer to use ostream
{
	out<<setw(16)<<left<<manufacturer.name<<setw(16)<<left<<manufacturer.location;
	return out;
}

Manufacturer::Manufacturer(const char* nm, const char* loc)
//Pre-condition: nm cannot be longer than MAX_NAME characters
//				 loc cannot be longer than MAX_LOC characters
//Post-condition: nm and loc will be stored in name and location,
//				  respectively. 
{
	name = NULL;
	location = NULL;
	setName(nm);
	setLocation(loc);

}

Manufacturer::Manufacturer(const Manufacturer &source)
//Pre-condition: Copy constructor. 
//Post-condition: Copies the exact same Manufacturer object 
//                that is passed in as &source and copies 
//				  its name and location.
{
	name = NULL;
	location = NULL;
	copy(source);
}

const Manufacturer& Manufacturer::operator=(const Manufacturer& right)
//Pre-condition: Must have a Manufacturer to be assigned to 
//				 left vehicle object.
//Post-condition: Assigns Manufacturer object on right to 
//				  left object
{
	if(this!=&right)
		copy(right);
	
	return *this;
}

void Manufacturer::copy(const Manufacturer &source)
//Pre-condition: Contents in source will be copied.
//Post-condition: Copies name and location from source into
//				  setName and setLocation, which copies name 
//				  and location and stores in copied object
{
	setName(source.name);
	setLocation(source.location);
}

Manufacturer::~Manufacturer()
//Pre-condition: When called, deletes name and location.
//Post-condition: Deletes the contents in name and location.
{
	delete[]name;
	delete[]location;
}

void Manufacturer::setName(const char* nm) 
//Pre-condition: Must have entered a name not exceeding
//				 15 characters long. If name is not NULL,
//				 deletes contents in name.
//Post-condition: Sets name in vehicle if the conditions are met
{
    int length = MAX_NAME;
	if (name != NULL)
		delete [] name;
    if (strlen(nm)>length) 
	{
        cout <<"Name exceeds max length. Will be truncated." <<endl;
		name = new char[MAX_NAME + 1];
		assert(name != NULL);
        strncpy(name, nm, length);
        name[length] = '\0';
    }

    else 
	{
		name = new char[strlen(nm) + 1];
		assert(name != NULL);
		strcpy(name, nm);
	}
}

void Manufacturer::setLocation(const char* loc)
//Pre-condition: Must have entered a location not 
//				 exceeding more than 15 characters long. If
//				 location is not NULL, deletes contents
//			     in location.
//Post-condition: Sets location in vehicle if the conditions are met
{
    int length = MAX_LOCATION;
	if (location != NULL)
		delete [] location;
    if (strlen(loc)>length) 
	{
        cout <<"Location exceeds max length. Will be truncated." <<endl;
		location = new char[MAX_LOCATION + 1];
		assert(location != NULL);
        strncpy(location, loc, length);
        location[length] = '\0';
    }

    else 
	{
		location = new char[strlen(loc) + 1];
		assert(location != NULL);
		strcpy(location, loc);
	}
}

void Manufacturer::setManufacturer(const char* nm, const char* loc)
//Pre-condition: Must have entered a name and location
//				 not exceeding 15 characters
//Post-condition: Sets nm and pr in vehicle if the conditions are met
{
	setName(nm);
	setLocation(loc);
}

const char* Manufacturer::getName()const
//Pre-condition: None
//Post-condition: Returns name
{
    return name;
}

const char* Manufacturer::getLocation()const
//Pre-condition: None
//Post-condition: Returns location
{
    return location;
}