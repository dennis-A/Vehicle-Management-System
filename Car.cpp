//Filename: Car.cpp
//Author: Ancheta, Dennis
//Date Written: 10-30-12
//Description: Implementations for the Car class

#include "Car.h"
#include<iomanip>
#include<cassert>

ostream& operator<<(ostream& out, const Car& car)
//Pre-condition: Calls display function and outputs Vehicle's 
//				 display along with the vin.
//Post-condition: Displays the contents in display function which
//				  is contents in Vehicle along with vin. 
{
	car.display(out);
	out << endl;
	return out;
}

Car::Car(const char* mdl, double pr, const char* nm, const char* loc, const char* vn)
	:Vehicle(mdl, pr, nm, loc)
//Pre-condition: mdl cannot be longer than 20 characters
//				 nm cannot be longer than MAX_NAME characters
//				 loc cannot be longer than MAX_LOC characters
//				 pr must be non negative
//				 vn cannot be longer than MAX_VIN characters
//Post-condition: mdl, nm, loc, and gr will be stored in model, name, location,
//				  and vin respectively. If pr is negative, 0 will be stored in 
//				  price; otherwise pr will be stored in price.
{
	vin = NULL;
	setVin(vn);
}

Car::Car(const Car& source)
	:Vehicle(source)
//Pre-condition: Copy constructor. 
//Post-condition: Copies the exact same Car object that 
//				  is passed in as &source and copies its
//				  vin.
{
	vin = NULL;
	setVin(source.vin);
}

const Car& Car::operator=(const Car& right)
//Pre-condition: Must have a Car to be assigned to left 
//				 car object.
//Post-condition: Assigns Car object on right to left 
//				  object
{
	if(this != &right)
	{
		Vehicle::operator=(right);   
		setVin(right.vin);
	}

	return *this;
}

void Car::setCar(const char* mdl, double pr, const char* nm, const char* loc, const char* vn)
//Pre-condition: Must have met conditions for mdl, pr, nm, loc, 
//				 vn and if not,	will be re-prompted. 
//Post-condition: Sets model, price, name, location and vin
//			      in car if conditions are met.
{
	setVehicle(mdl, pr, nm, loc);
	setVin(vn);
}

void Car::setVin(const char* vn)
//Pre-condition: Must have entered a vin not exceeding 10 characters.
//				 Otherwise, reprompts user.
//Post-condition: Sets vin in car if condition is met
{
	if(vin != NULL)
		delete[]vin;
	
	if(strlen(vn) > MAX_VIN)
	{
		vin = new char[MAX_VIN + 1];
		assert(vin != NULL);
		strncpy(vin, vn, MAX_VIN);
		vin[MAX_VIN] = '\0';
		cout<<"VIN exceeds max length. Will be truncated" << endl;
	}

	else
	{
		vin = new char[strlen(vn) + 1];
		assert(vin != NULL);
		strcpy(vin, vn);
	}
}

const char* Car::getVin()const
//Pre-condition: None
//Post-condition: Returns vin
{
	return vin;
}

Car::~Car()
//Pre-condition: When called, deletes vin. 
//Post-condition: Deletes the contents in vin. 
{
	delete[]vin;
}

void Car::display(ostream& out) const
//Pre-condition: Called by ostream operator and passes out
//				 as parameter.
//Post-condition: Displays Vehicle's display along
//				  with vin attached to end of it.
{
	Vehicle::display(out);
	out<<setw(8)<<left<<vin;
}









	






