// A House is a Building (inheritance);
// A House has a Room (composition);
// A House has an occupant (aggregation);
// A House uses an internet provider (association);

#include<iostream>
using namespace std;

class Car {
	// Methods implementation and class/Instance members
	private:
        string color;
	    int maxSpeed; 
	public: 
		void carInfo()
		{
			cout << "Car Color= " << color << " Max Speed= " << maxSpeed;
		}
	
		void setColor(string color)
		{
			this->color = color;
		}
		void setMaxSpeed(int maxSpeed) 
		{
			this->maxSpeed = maxSpeed;
		}
};