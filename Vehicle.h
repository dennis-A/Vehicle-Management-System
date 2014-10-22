//Filename: Vehicle.h
//Author: Ancheta, Dennis
//Date Written: 10-20-12
//Description: Interface file for the Vehicle class

const int MAX_MODEL = 20;

#pragma once
#include<iostream>
#include "Manufacturer.h"
using namespace std;

class Vehicle 
{
	friend ostream& operator<<(ostream& out, const Vehicle& vehicle);
	//Pre-condition: None
	//Post-condition: Allows Vehicle to use ostream

	public:
		//Function prototypes

		Vehicle(const char* mdl = "", double pr = 0.0, const char* nm = "", const char* loc = "");
		//Pre-condition: mdl cannot be longer than 20 characters
		//				 nm cannot be longer than MAX_NAME characters
		//				 loc cannot be longer than MAX_LOC characters
		//				 pr must be non negative
		//Post-condition: mdl, nm and loc will be stored in model, name and location,
		//				  respectively. If pr is negative, 0 will be stored in price;
		//				  otherwise pr will be stored in price.

		Vehicle(const Vehicle &source);
		//Pre-condition: Copy constructor. 
		//Post-condition: Copies the exact same Vehicle object that 
		//				  is passed in as &source and copies its
		//				  model and price.

		const Vehicle& operator=(const Vehicle& right);
		//Pre-condition: Must have a Vehicle to be assigned to left 
		//				 vehicle object.
		//Post-condition: Assigns vehicle object on right to left 
		//				  object

		virtual void display(ostream& out)const;
		//Pre-condition: Called by ostream operator and displays
		//				 model, price, name, and location.
		//Post-condition: Displays the contents in vehicle, which 
		//				  is the mdl, pr, nm, and loc. 

		virtual ~Vehicle();
		//Pre-condition: When called, deletes model. 
		//Post-condition: Deletes the contents in model.

		static void displayHdg();
		//Precondition: None
		//Postcondition Displays return heading.

		void setVehicle(const char* mdl="", double pr = 0.0, const char* nm="", const char* loc="");
		//Pre-condition: Must have entered mdl, pr, nm, loc, and if not,
		//				 will be re-prompted 
		//Post-condition: Sets model, price, manufacturer in vehicle
		//				  if conditions are met

		void setModel(const char* mdl = "");
		//Pre-condition: Must have entered a model not exceeding 20 characters.
		//				 If model is not NULL, deletes contents in model.
		//Post-condition: Sets model in vehicle if condition is met

		void setPrice(double pr = 0.0);
		//Pre-condition: Must have entered a valid floating point value,
		//				 otherwise user will be prompted to re-enter
		//Post-condition: Sets price in vehicle if the conditions are met

		void setName(const char* nm = "");
		//Pre-condition: Must have entered a name not exceeding
		//				 15 characters long
		//Post-condition: Sets name in vehicle if the conditions are met

		void setLocation(const char* loc = "");
		//Pre-condition: Must have entered a location not 
		//				 exceeding more than 15 characters long
		//Post-condition: Sets location in vehicle if the conditions are met

		void setManufacturer(const char* nm, const char* loc);
		//Pre-condition: Must have entered a name and location
		//				 not exceeding 15 characters
		//Post-condition: Sets nm and pr in vehicle if the conditions are met

		const char* getModel() const;
		//Pre-condition: None
		//Post-condition: Returns model

		double getPrice() const;
		//Pre-condition: None
		//Post-condition: Returns price

		const char* getName()const;
		//Pre-condition: None
		//Post-condition: Returns name

		const char* getLocation()const;
		//Pre-condition: None
		//Post-condition: Returns location

	private:
		char* model;
		double price;
		Manufacturer manufacturer;
		void copy(const Vehicle &source);
		//Pre-condition: Contents in source will be copied.
		//Post-condition: Copies model and price from source into
		//				  setModel and setPrice, which copies
		//				  model and price and stores in copied object
		
};