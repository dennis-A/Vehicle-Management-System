//Filename: Car.h
//Author: Ancheta, Dennis
//Date Written: 10-30-12
//Description: Interface file for the Car class

#include "Vehicle.h"
#pragma once

const int MAX_VIN = 10;

class Car : public Vehicle
{
	friend ostream& operator << (ostream& out, const Car& car);
	//Pre-condition: Calls display function and outputs Vehicle's 
	//				 display along with the vin.
	//Post-condition: Displays the contents in display function which
	//				  is contents in Vehicle along with vin.

	public:
		//Function prototypes

		Car(const char* mdl="", double pr=0.0, const char* nm="", const char* loc="", const char* vn="");
		//Pre-condition: mdl cannot be longer than 20 characters
		//				 nm cannot be longer than MAX_NAME characters
		//				 loc cannot be longer than MAX_LOC characters
		//				 pr must be non negative
		//				 vn cannot be longer than MAX_VIN characters
		//Post-condition: mdl, nm, loc, and gr will be stored in model, name, location,
		//				  and vin respectively. If pr is negative, 0 will be stored in 
		//				  price; otherwise pr will be stored in price. 

		Car(const Car& source);
		//Pre-condition: Copy constructor. 
		//Post-condition: Copies the exact same Car object that 
		//				  is passed in as &source and copies its
		//				  vin. 

		const Car& operator=(const Car& right);
		//Pre-condition: Must have a Car to be assigned to left 
		//				 car object.
		//Post-condition: Assigns Car object on right to left 
		//				  object 

		void setCar(const char* mdl="",double pr=0.0,const char* nm="",const char*loc="",const char*vn="");
		//Pre-condition: Must have met conditions for mdl, pr, nm, loc, 
		//				 vn and if not,	will be re-prompted. 
		//Post-condition: Sets model, price, name, location and vin
		//			      in car if conditions are met.

		void setVin(const char* vn = "");
		//Pre-condition: Must have entered a vin not exceeding 10 characters.
		//				 Otherwise, reprompts user.
		//Post-condition: Sets vin in car if condition is met

		const char* getVin()const;
		//Pre-condition: None
		//Post-condition: Returns vin

		virtual ~Car();
		//Pre-condition: When called, deletes vin. 
		//Post-condition: Deletes the contents in vin. 

		virtual void display(ostream& out)const;
		//Pre-condition: Called by ostream operator and passes out
		//				 as parameter.
		//Post-condition: Displays Vehicle's display along
		//				  with vin attached to end of it.


	private:
		char* vin;
};

