//Filename: proj4.cpp
//Author: Ancheta, Dennis
//Date Written: 10-20-12
//Description: This client program will test the functionality of
//			   the vehicle, manufacturer, bicycle, and car classes.
//			   This program will be able to copy the list of vehicle's
//			   as well as create a bicycle or a car and modify its
//			   information. It will test to see if it can successfully 
//			   store vehicle's of the bicycle and car class.

#include<iostream>
#include<cstring>
#include<cstdlib>
#include"Vehicle.h"
#include"Car.h"
#include"Bicycle.h"
using namespace std;

//Function prototypes

void programIntro();
//Pre-condition: None
//Post-condition: Displays program intro

int getMenuOption();
//Pre-condition: None
//Post-condition: Prompts the user with a menu selection

int getValidNonNegInt(char* prompt);
//Pre-condition: None
//Post-condition: Verifies if the integer is non-negative

double getValidNonNegDouble(char* prompt); 
//Pre-condition: None
//Post-condition: Verifies if the type double is non-negative

void getString(char* str, int length, char* prompt);
//Pre-condition: str is the model, name, or location.
//				 length defines the max length that should not
//				 be exceeded. prompt is asking for user input
//Post-condition: If length is exceeded, user will be prompted
//				  to re-enter information.

Vehicle* getVehicleInfo();
//Pre-conditon: None
//Post-condition: Returns model, price, name and location in vehicle

Bicycle* getBicycleInfo();
//Pre-conditon: None
//Post-condition: Returns model, price, name, location and
//				  gear in bicycle

Car* getCarInfo();
//Pre-conditon: None
//Post-condition: Returns model, price, name, location and
//				  vin in car

void changeBicycleInfo(Vehicle* list[], int index);
//Pre-condition: List must have at least one entry
//Post-condition: Prompts the user with a selection to modify bicycle's info

void changeCarInfo(Vehicle* list[], int index);
//Pre-condition: List must have at least one entry
//Post-condition: Prompts the user with a selection to modify car's info

int changeBicycleGetMenuOption();
//Pre-condition: User must have selected modify a bicycle option
//Post-condition: Displays the menu to change the information of a bicycle.
//                Prompts the user with a selection to modify a bicycle's info

int changeCarGetMenuOption();
//Pre-condition: User must have selected modify a car option
//Post-condition: Displays the menu to change the information of a car.
//                Prompts the user with a selection to modify a car's info 

int main()
{		
    const int MAX = 10;
    Vehicle *list[MAX], *copyList[MAX];
    int index = 0, copyIndex = 0;
    int menuOption;
    programIntro();
    //Display the menu and get the menu option
    do
    {
        menuOption = getMenuOption();
        switch(menuOption)
        {
            case 1: //Enter information for a bicycle
                if(index >= MAX)
                    cout <<"List is full." << endl;
                else 
                    list[index++] = getBicycleInfo();
					cout<<endl<<"*****************************"<< endl
						<<"Bicycle successfully created!"<< endl
						<<"*****************************"<< endl;
                break;

			case 2: //Enter information for a car 
                if(index >= MAX)
                    cout <<"List is full." << endl;
                else 
                    list[index++] = getCarInfo(); 
					cout<<endl<<"*****************************"<< endl
						<<"Car successfully created!"<< endl
						<<"*****************************"<< endl;
                break;

            case 3: //Change a Bicycle's information
				Bicycle* bicyclePtr;
                if (index == 0)
                    cout<< "List is empty." << endl;
                else					
                    changeBicycleInfo(list, index);
                break;

			case 4: //Change a Car's information
				Car* carPtr;
				if(index == 0)
					cout << "List is empty." << endl;
				else
					changeCarInfo(list, index);
				break;

			case 5: //Display the list of vehicles
				if(index == 0)
					cout << "List is empty." << endl;
				else
				{
					Vehicle::displayHdg();
					for(int i = 0; i<index; i++)
					{
						carPtr = dynamic_cast<Car*>(list[i]);
						if(carPtr != NULL)
							cout<<i+1 <<". " << *carPtr<<endl;
						else
						{
							bicyclePtr = dynamic_cast<Bicycle*>(list[i]);
							cout<<i+1<<". "<< *bicyclePtr << endl;
						}
					}
				}
				break;

			case 6: //Copy the list of vehicles
				for(int i=0; i<copyIndex; i++)
					delete copyList[i];
				for(int i=0; i<index; i++)
				{
					carPtr = dynamic_cast<Car*>(list[i]);
					if(carPtr != NULL)
						copyList[i] = new Car(*carPtr);
					else
						copyList[i] = new Bicycle(*(dynamic_cast<Bicycle*>(list[i])));
				}

				copyIndex = index;
				cout<<"List copied successfully"<<endl;
				break;

			case 7: //Display the copied list of vehicles.
				if(copyIndex == 0)
					cout<<"List is empty"<<endl;
				else
				{
					Vehicle::displayHdg();
					for(int i = 0; i <copyIndex; i++)
					{
						carPtr = dynamic_cast<Car*>(copyList[i]);
						if(carPtr != NULL)
							cout<<i+1<<". "<<*carPtr<<endl;
						else
						{					
							bicyclePtr = dynamic_cast<Bicycle*>(copyList[i]);
							cout<<i+1<<". "<<*bicyclePtr<<endl;
						}					
					}
				}
				break;
					
			case 8: //Terminate	
				for(int i = 0; i < index; i++)
					delete list[i];
				for(int i = 0; i < copyIndex; i++)
					delete copyList[i];
				cout<<"Program terminating"<<endl;
				break;

            default: //Invalid menu option
                cout <<"Invalid menu option. Please re-enter: " <<endl;
                break;
        }//end switch statement
    } while(menuOption !=8); // end do while loop

    system("PAUSE");
    return 0;
}//end main

void programIntro()
//Pre-condition: None
//Post-condition: Displays program intro
{
    cout << "=====================================================================\n"
         << "This client program will test the functionality of the vehicle,\n"
         << "manufacturer, bicycle, and car classes. This program will be able to\n"
		 << "copy the list of vehicle's as well as create a bicycle or a car and\n"
		 << "modify its information. It will test to see if it can successfully\n"
		 << "store vehicle's of the bicycle and car class.\n"
         << "====================================================================="<<endl;
} 

int getMenuOption()
//Pre-condition: Prompts the user with a menu selection
//Post-condition: Returns the option the user chooses
{
    cout << "\nVehicle Change Menu Options"<<endl;
    cout << "1. Enter information for a bicycle."<<endl;
    cout << "2. Enter information for a car."<<endl;
    cout << "3. Change a bicycle's information."<<endl;
	cout << "4. Change a car's information."<<endl;
	cout << "5. Display the list of vehicles."<< endl;
	cout << "6. Copy the list of vehicles."<<endl;
	cout << "7. Display the copied list of vehicles."<< endl;
	cout << "8. Exit the program." << endl;
    int menuOption = getValidNonNegInt("Enter a menu option: ");
    cout << "" << endl;
    return menuOption;
}

int getValidNonNegInt(char* prompt)
//Pre-condition: Prompts the user to select an option
//Post-condition: Verifies if the option chose is 
//				  a non-negative integer
{
    const int MAX = 80;
    char buffer[MAX];
    int i;
    cout << prompt;
    cin.getline(buffer,MAX);//reprompted
    cin.clear();//clear the error bits for the cin input stream
    cin.sync();//synchonize the input buffer, discarding any leftover characters in the buffer
    
    while(strlen(buffer) != strspn(buffer,"0123456789"))
    {
        cout <<"Invalid integer. Please re-enter. ";
        cin.getline(buffer,MAX);
        cin.clear();
        cin.sync();
    }//end while loop

    i = atoi(buffer);
    return i;
}

double getValidNonNegDouble(char* prompt)
//Pre-condition: None
//Post-condition: Verifies if the type double is non-negative, if
//				  not, prompts the user to re-enter a non-negative
//				  double
{
     const int MAX = 80;
     char buffer[MAX];
     double d;
     cout << prompt;
     cin.getline(buffer,MAX);
     cin.clear();//clear the error bits for the cin input stream
     cin.sync();//synchonize the input buffer, discarding any leftover characters in the buffer
    
     while(strlen(buffer) != strspn(buffer,".0123456789"))
     {
         cout <<"Invalid floating point value. Please re-enter. ";
         cin.getline(buffer,MAX);
         cin.clear();
         cin.sync();
     }//end while loop

     d = atof(buffer);
     return d;
}

void getString(char* str, int length, char* prompt)
//Pre-condition: Prompts the user to enter string
//				 and determines if it exceeds its maximum length
//Post-condition: If length is exceeded, user will be prompted
//				  to re-enter information.
{
      const int MAX_BUF = 120;
      char buffer[MAX_BUF];
      cout << prompt;
      cin.getline(buffer, MAX_BUF);
      cin.clear();
      cin.sync();

      while (length < strlen(buffer))
	  {
           cout << "Entry is too long, please re-enter. ";
           cin.getline(buffer, MAX_BUF);
           cin.clear();
           cin.sync();
      }

      strcpy(str,buffer);
}

Bicycle* getBicycleInfo()
//Pre-conditon: None
//Post-condition: Returns model, price, name, location and
//				  gear in bicycle 
{
	int gear;
	Vehicle* vehiclePtr = getVehicleInfo();
	gear = getValidNonNegInt("Enter a non-negative integer for the gear of the bicycle: ");
	Bicycle* bicyclePtr=new Bicycle(vehiclePtr->getModel(),vehiclePtr->getPrice(),vehiclePtr->getName(),
						vehiclePtr->getLocation(), gear);
	return bicyclePtr;
}

Car* getCarInfo()
//Pre-conditon: None
//Post-condition: Returns model, price, name, location and
//				  vin in car 
{
	char vin[MAX_VIN + 1];
	Vehicle* vehiclePtr = getVehicleInfo();
	getString(vin, MAX_VIN, "Enter the vin(max 10 characters): ");
	Car* carPtr = new Car(vehiclePtr->getModel(), vehiclePtr->getPrice(), vehiclePtr->getName(),
						  vehiclePtr->getLocation(), vin);
	return carPtr;
}

Vehicle* getVehicleInfo()
//Pre-condition: Prompts user to enter model, price, name and location of the vehicle
//Post-condition: Returns vehicle
{
    char model[MAX_MODEL +1];
    double price;
    char name[MAX_NAME +1];
    char location[MAX_LOCATION +1];
    
    getString(model,MAX_MODEL,"Enter the model of the vehicle (max 20 characters): ");
    price = getValidNonNegDouble("Enter the non-negative price of the vehicle: ");
    getString(name, MAX_NAME,"Enter the manufacturer name(max 15 characters): ");
    getString(location, MAX_LOCATION,"Enter the location(max 15 characters): ");
    Vehicle* vehPtr = new Vehicle(model, price, name, location);
    return vehPtr;
}

void changeBicycleInfo(Vehicle* list[], int index)
//Pre-condition: List must have at least one entry
//Post-condition: Prompts the user with a selection to modify bicycle's info
{
	char model[MAX_MODEL +1];
    double price;
	int gear;
    char name[MAX_NAME +1];
    char location[MAX_LOCATION +1];	
	char vin[MAX_VIN + 1];
	Bicycle* bicyclePtr;

	Vehicle::displayHdg();
	for(int i=0; i<index; i++)
	{
		bicyclePtr = dynamic_cast<Bicycle*>(list[i]);
		if(bicyclePtr != NULL)
			cout<<i+1<<". "<<*bicyclePtr<<endl;
		
	}
	
	int selection;
	int myIndex;
	bicyclePtr = NULL;  //set to equal to NULL
	myIndex = getValidNonNegInt("Enter index number to change vehicle's information: ") - 1;
			
	for(int i = 0; i<index; i++)
	{
		if (myIndex == i)
			bicyclePtr = dynamic_cast<Bicycle*>(list[i]);
	}

	while(bicyclePtr == NULL)
	{
		if(myIndex >= index || myIndex < 0)
		{
			while(myIndex >= index || myIndex < 0)
			{
				cout << "Invalid index" << endl;
				myIndex = getValidNonNegInt("Enter index number to change vehicle's information: ") - 1;
				for(int i = 0; i < index; i++)
				{
					if(myIndex == i)
					bicyclePtr = dynamic_cast<Bicycle*>(list[i]);
				}
			}
		}

		if(bicyclePtr == NULL)
		{
			cout<<"Wrong index. Is not a Bicycle."<<endl;
			myIndex = getValidNonNegInt("Enter index number to change vehicle's information: ") - 1;
			for(int i = 0; i<index; i++)
			{
				if(myIndex == i)
					bicyclePtr = dynamic_cast<Bicycle*>(list[i]);
			}
		}
	}
		
	do
	{
		selection = changeBicycleGetMenuOption();
		switch(selection)
		{
			case 1: //Change model              
				getString(model,MAX_MODEL,"Enter the new model of the bicycle (max 20 characters): ");
				list[myIndex]->setModel(model);				
				break;

			case 2: //Change a vehicles price
				list[myIndex]->setPrice(getValidNonNegDouble("Enter a non-negative price for bicycle: "));
				break;

			case 3: //Change manufacturer name
				getString(name, MAX_NAME, "Enter the manufacturer name(max 15 characters): ");
				list[myIndex]->setName(name);				        
				break;
			
			case 4: //Change manufacturer location
				getString(location, MAX_LOCATION, "Enter the location(max 15 characters): ");
				list[myIndex]->setLocation(location);
				break;

			case 5: //Change the bicycle's gear
				gear = getValidNonNegInt("Enter a non-negative integer for the gear of the bicycle: ");
				bicyclePtr = dynamic_cast<Bicycle*>(list[myIndex]);
				bicyclePtr->setGear(gear);
				break;

			case 6: //Exit the program
				cout <<"Returning to previous menu"<<endl;
				break;

			default: //Invalid menu option
				cout <<"Invalid menu option. Please re-enter: " <<endl;
				break;
		}//end switch statement
	} while(selection !=6); // end do while loop
}

void changeCarInfo(Vehicle* list[], int index)
//Pre-condition: List must have at least one entry
//Post-condition: Prompts the user with a selection to modify car's info
{
	char model[MAX_MODEL +1];
    double price;
    char name[MAX_NAME +1];
    char location[MAX_LOCATION +1];
	char vin[MAX_VIN + 1];
	Car* carPtr;

	Vehicle::displayHdg();
	for(int i=0; i<index; i++)
	{
		carPtr = dynamic_cast<Car*>(list[i]);
		if(carPtr != NULL)
			cout<<i+1<<". "<<*carPtr<<endl;
		
	}
	
	int selection;
	int myIndex;
	carPtr = NULL;  //set to equal to NULL
	myIndex = getValidNonNegInt("Enter index number to change vehicle's information: ") - 1;
		
	for(int i = 0; i<index; i++)
	{
		if (myIndex == i)
			carPtr = dynamic_cast<Car*>(list[i]);
	}

	while(carPtr == NULL)
	{
		if(myIndex >= index || myIndex < 0)
		{
			while(myIndex >= index || myIndex < 0)
			{
				cout << "Invalid index" << endl;
				myIndex = getValidNonNegInt("Enter index number to change vehicle's information: ") - 1;
				for(int i = 0; i < index; i++)
				{
					if(myIndex == i)
					carPtr = dynamic_cast<Car*>(list[i]);
				}
			}
		}

		if(carPtr == NULL)
		{
			cout<<"Wrong index. Is not a Car."<<endl;
			myIndex = getValidNonNegInt("Enter index number to change vehicle's information: ") - 1;
			for(int i = 0; i<index; i++)
			{
				if(myIndex == i)
					carPtr = dynamic_cast<Car*>(list[i]);
			}
		}
	}
	
	do
	{
		selection = changeCarGetMenuOption();
		switch(selection)
		{
			case 1: //Change model              
				getString(model,MAX_MODEL,"Enter the new model of the car (max 20 characters): ");
				list[myIndex]->setModel(model);
				break;

			case 2: //Change a vehicles price
				list[myIndex]->setPrice(getValidNonNegDouble("Enter a non-negative price for car: "));
				break;

			case 3: //Change manufacturer name
				getString(name, MAX_NAME, "Enter the manufacturer name (max 15 characters): ");
				list[myIndex]->setName(name);				        
				break;
			
			case 4: //Change manufacturer location
				getString(location, MAX_LOCATION, "Enter the location (max 15 characters): ");
				list[myIndex]->setLocation(location);
				break;

			case 5: //Change the car's vin
				getString(vin, MAX_VIN, "Enter the vin(max 10 characters): ");
				carPtr = dynamic_cast<Car*>(list[myIndex]);
				carPtr->setVin(vin);				
				break;

			case 6: //Exit the program
				cout <<"Returning to previous menu"<<endl;
				break;

			default: //Invalid menu option
				cout <<"Invalid menu option. Please re-enter: " <<endl;
				break;
		}//end switch statement
	} while(selection !=6); // end do while loop
}

int changeBicycleGetMenuOption()
//Pre-condition: User must have selected modify a bicycle option
//Post-condition: Displays the menu to change the information of a bicycle.
//                Prompts the user with a selection to modify a bicycle's info
{
	cout << "\nBicycle Change Menu Options"<< endl;
    cout << "1. Change the bicycle's model." <<endl;
    cout << "2. Change the bicycle's price." <<endl;
    cout << "3. Change the bicycle's manufacturer." <<endl;
	cout << "4. Change the bicycle's location."<<endl;
	cout << "5. Change the bicycle's gears." << endl;
	cout << "6. Return to main menu." << endl;
    int menuOption = getValidNonNegInt("Enter a menu option: ");
    cout << "" << endl;
    return menuOption;
}

int changeCarGetMenuOption()
//Pre-condition: User must have selected modify a car option
//Post-condition: Displays the menu to change the information of a car.
//                Prompts the user with a selection to modify a car's info
{
	cout << "\nCar Change Menu Options"<< endl;
    cout << "1. Change the car's model." <<endl;
    cout << "2. Change the car's price." <<endl;
    cout << "3. Change the car's manufacturer." <<endl;
	cout << "4. Change the car's location."<<endl;
	cout << "5. Change the car's VIN." << endl;
	cout << "6. Return to main menu." << endl;
    int menuOption = getValidNonNegInt("Enter a menu option: ");
    cout << "" << endl;
    return menuOption;
}

