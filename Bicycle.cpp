//Filename: Bicycle.cpp
//Author: Ancheta, Dennis
//Date Written: 11-6-12
//Description: Implementations for the Bicycle class

#include "Bicycle.h"
#include<iomanip>
#include<cassert>

ostream& operator<<(ostream& out, const Bicycle& bicycle)
//Pre-condition: Calls display function and outputs Vehicle's 
//				 display along with the gear.
//Post-condition: Displays the contents in display function which
//				  is contents in Vehicle along with gear.
{
	bicycle.display(out);
	cout << endl;
	return out;
}

Bicycle::Bicycle(const char* mdl, double pr, const char* nm, const char* loc, int gr)
	:Vehicle(mdl, pr, nm, loc)
//Pre-condition: mdl cannot be longer than 20 characters
//				 nm cannot be longer than MAX_NAME characters
//				 loc cannot be longer than MAX_LOC characters
//				 pr must be non negative
//				 gr cannot be longer than MAX_GEAR characters
//Post-condition: mdl, nm, loc, and gr will be stored in model, name, location,
//				  and gear respectively. If pr is negative, 0 will be stored in 
//				  price; otherwise pr will be stored in price.
{
	gear = NULL;
	setGear(gr);
}

void Bicycle::setBicycle(const char* mdl, double pr, const char* nm, const char* loc, int gr)
//Pre-condition: Must have met conditions for mdl, pr, nm, loc, 
//				 gr and if not,	will be re-prompted. 
//Post-condition: Sets model, price, name, location and gear
//			      in bicycle if conditions are met.
{
	setVehicle(mdl, pr, nm, loc);
	setGear(gr);
}

void Bicycle::setGear(int gr)
//Pre-condition: Must have entered a gear that is a non-negative
//				 integer, otherwise user is re-prompted.
//Post-condition: gr is assigned to gear.
{
	gear = gr;
}

int Bicycle::getGear()const
//Pre-condition: None
//Post-condition: Returns gear
{
	return gear;
}

void Bicycle::display(ostream& out)const
//Pre-condition: Called by ostream operator and passes out
//				 as parameter.
//Post-condition: Displays Vehicle's display along
//				  with gear attached to end of it.
{
	Vehicle::display(out);
	out<<setw(8)<<right<<gear;
}

