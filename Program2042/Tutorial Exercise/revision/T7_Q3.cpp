#include <iostream>
using namespace std;

class Car
{
public:
	Car()
	{
		// Your code for part (a) should be inserted here
		speed = 0;
	}

	void showSpeed()
	{
		cout << "The car is moving at " << speed << " km/h." << endl;
	}

	void accelerate(int a)
	{
		cout << "Accelerating ... " << endl;
		// Your code for part (b) should be inserted here
		if ((speed + a) <= 150)
		{
			speed += a;
		}
		else
		{
			speed = 150;
		}
	}

	// Your code for part (c) should be inserted here
	void decelerate(int a)
	{
		cout << "Decelerating ... " << endl;
		if ((speed - a) >= 0)
		{
			speed -= a;
		}
	}

	// Your code for part (d) should be inserted here
	void stop()
	{
		speed = 0;
		cout << "Stopping ..." << endl;
	}

private:
	int speed; // speed of the car, in km/h
};

int main()
{
	Car myCar;

	myCar.showSpeed();
	myCar.accelerate(70);
	myCar.showSpeed();
	myCar.decelerate(20);
	myCar.showSpeed();
	myCar.accelerate(120);
	myCar.showSpeed();
	myCar.decelerate(100);
	myCar.showSpeed();
	myCar.stop();
	myCar.showSpeed();

	return 0;
}
