//Filename: Vehicle.cpp
//Author: Ancheta, Dennis
//Date Written: 10-20-12
//Description: Implementations for the Vehicle class

#include"Vehicle.h"
#include<iomanip>
#include<cstring>
#include<cassert>
using namespace std;


ostream& operator<<(ostream& out, const Vehicle& vehicle)
//Pre-condition: None
//Post-condition: Prints out in format model, price, then manufacturer
{	
	vehicle.display(out);
	cout << endl;
	return out;
}

void Vehicle::display(ostream& out)const
//Pre-condition: Called by ostream operator and displays
//				 model, price, name, and location.
//Post-condition: Displays the contents in vehicle, which 
//				  is the mdl, pr, nm, and loc.
{
	out<<setw(21)<<left<<model
	   <<setw(11)<<fixed<<right<<setprecision(2)<<price<<"  "
	   <<setw(16)<<left<<manufacturer;
}

Vehicle::Vehicle(const char* mdl, double pr, const char* nm, const char* loc)
	:manufacturer(nm, loc)
//Pre-condition: mdl cannot be longer than 20 characters
//				 nm cannot be longer than MAX_NAME characters
//				 loc cannot be longer than MAX_LOC characters
//				 pr must be non negative
//Post-condition: mdl, nm and loc will be stored in model, name and location,
//				  respectively. If pr is negative, 0 will be stored in price,
//				  otherwise pr will be stored in price.
{
	model = NULL;
	setModel(mdl);
	setPrice(pr);
}

Vehicle::Vehicle(const Vehicle &source)
	:manufacturer(source.manufacturer)
//Pre-condition: Copy constructor. 
//Post-condition: Copies the exact same Vehicle object that 
//				  is passed in as &source and copies its
//				  model and price.
{
	model = NULL;
	copy(source);
}

const Vehicle& Vehicle::operator=(const Vehicle& right)
//Pre-condition: Must have a Vehicle to be assigned to left 
//				 vehicle object.
//Post-condition: Assigns vehicle object on right to left 
//				  object
{	
	//Check for self assignment
	if(this != &right)
	{
		copy(right);
		manufacturer = right.manufacturer;
	}
	return *this;
}

Vehicle::~Vehicle()
//Pre-condition: When called, deletes model. 
//Post-condition: Deletes the contents in model.
{
	delete[]model;
}

void Vehicle::copy(const Vehicle& source)
//Pre-condition: Contents in source will be copied.
//Post-condition: Copies model and price from source into
//				  setModel and setPrice, which copies
//				  model and price and stores in copied object
{
	setModel(source.model);
	setPrice(source.price);
}

void Vehicle::setVehicle(const char* mdl, double pr, const char* nm, const char* loc)
//Pre-condition: Must have entered mdl, pr, nm, loc, and if not,
//				 will be re-prompted 
//Post-condition: Sets model, price, manufacturer in vehicle
//				  if conditions are met
{
	setModel(mdl);
	setPrice(pr);
	setManufacturer(nm, loc);
}

void Vehicle::setModel(const char* mdl)
//Pre-condition: Must have entered a model not exceeding 20 characters.
//				 If model is not NULL, deletes contents in model.
//Post-condition: Sets model in vehicle if condition is met
{
    if (model!=NULL)
		delete[] model;
	if (strlen(mdl) > MAX_MODEL)
	{
		model = new char[MAX_MODEL + 1];
		assert(model!=NULL);
		strncpy(model, mdl, MAX_MODEL);
		model[MAX_MODEL] = '/0';
		cerr << " Model exceeds max length. Will be truncated."<<endl;
	}

	else
	{
		model = new char[strlen(mdl) + 1];
		assert(model!=NULL);
		strcpy(model,mdl);
	}
}

void Vehicle::setPrice(double pr)
//Pre-condition: Must have entered a valid floating point value,
//				 otherwise error message is displayed.
//Post-condition: Sets price in vehicle if the conditions are met
{
    if(pr < 0 ) 
	{
        cout <<"Price is negative. Will be set to 0"<<endl;
        price = 0;
    }
        
	else 
		price = pr;
}

void Vehicle::setName(const char* nm) 
//Pre-condition: Must have entered a name not exceeding
//				 15 characters long
//Post-condition: Sets name in vehicle if the conditions are met
{
	manufacturer.setName(nm);
}

void Vehicle::setLocation(const char* loc)
//Pre-condition: Must have entered a location not 
//				 exceeding more than 15 characters long
//Post-condition: Sets location in vehicle if the conditions are met
{
	manufacturer.setLocation(loc);	
}

void Vehicle::setManufacturer(const char* nm, const char* loc) 
//Pre-condition: Must have entered a name and location
//				 not exceeding 15 characters
//Post-condition: Sets nm and pr in vehicle if the conditions are met
{
    manufacturer.setManufacturer(nm,loc);
}

const char* Vehicle::getModel()const
//Pre-condition: None
//Post-condition: Returns model
{
    return model;
}

const char* Vehicle::getName()const
//Pre-condition: None
//Post-condition: Returns name
{
    return manufacturer.getName();
}

const char* Vehicle::getLocation()const
//Pre-condition: None
//Post-condition: Returns location
{
    return manufacturer.getLocation();
}

double Vehicle::getPrice()const
//Pre-condition: None
//Post-condition: Returns price
{
    return price;
}

void Vehicle::displayHdg()
//Pre-condition: None
//Post-condition: Displays the columns in specified format
{
    cout << setw(24)<<left<<"MODEL"
         << setw(11)<<right<<"PRICE"
         << setw(18)<<left<<"  MAKE"
         << setw(16)<<left<<"LOCATION"
		 << setw(10)<<left<<"VIN/GEAR"<<endl;
}