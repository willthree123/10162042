#include <iostream>
using namespace std;

class Car
{
public:
    Car()
    {
        speed = 0;
    }

    void showSpeed()
    {
        cout << "The car is movie at " << speed << " km/h." << endl;
    }

    void accelerate(int a)
    {
        cout << "Accelerating ... " << endl;
        speed = speed + a;
        if (speed >= 150)
            speed = 150;
    }

    void decelerate(int d)
    {
        cout << "Decelrating ... " << endl;
        speed = speed - d;
        if (speed < 0)
            speed = 0;
    }

    void stop()
    {
        cout << "Stopping ... " << endl;
        speed = 0;
    }

private:
    int speed;
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