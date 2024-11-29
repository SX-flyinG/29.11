#include <iostream>
#include <ctime>

using namespace std;




class Auto {
    int wheels;
    int doors;
    int speed;
    int color;
    static enum Colors
    {
        purple = 0, 
        gray = 1,   
        blue = 2,   
        green = 3,  
        brown = 4,  
        pink = 5,   
        yellow = 6 
    };
public:


    Auto() {
        int col = rand() % 7;
        wheels = 4;
        doors = 4;
        speed = rand() % 200 + 100;
        ChooseColor(col);
    }

    void ChooseColor(int col) {
        if (col == 0)
            color = Colors::purple;
        else if (col == 1)
            color = Colors::gray;
        else if (col == 2)
            color = Colors::blue;
        else if (col == 3)
            color = Colors::green;
        else if (col == 4)
            color = Colors::brown;
        else if (col == 5)
            color = Colors::pink;
        else if (col == 6)
            color = Colors::yellow;
    }

    int getWheels() {
        return this->wheels;
    }

    int getDoors() {
        return this->doors;
    }

    int getSpeed() {
        return this->speed;
    }

    int getColor() {
        return color;
    }

    void AssingValues(const int wheels, const int doors, int speed , int color) {
        this->wheels = wheels;
        this->doors = doors;
        this->speed = speed;
        this->color = color;
    }

    void PrintInfo() {
        cout << "Your car : \n" << "Count of wheels : " << wheels << "\nCount of doors : " << doors << "\nSpeed of car : " << speed << "km\\h" << "\nColor of car : " << color << endl;
    }
};

class Parking {
    Auto* autos;
public:
    static int amountOfCars;

    Parking() {
        autos = new Auto[amountOfCars];
    }
    void Adder(Auto car) {
        Auto* tempArrOfCars = new Auto[amountOfCars];

        for (int i = 0; i < amountOfCars; i++) {
            tempArrOfCars[i].AssingValues(
                autos[i].getWheels(),
                autos[i].getDoors(),
                autos[i].getSpeed(),
                autos[i].getColor());
        }

        delete[] autos;
        autos = nullptr;

        IncrementAmountOfPoints();

        autos = new Auto[amountOfCars];

        for (int i = 0; i < amountOfCars - 1; i++) {
            tempArrOfCars[i].AssingValues(
                autos[i].getWheels(),
                autos[i].getDoors(),
                autos[i].getSpeed(),
                autos[i].getColor());
        }

        delete[] tempArrOfCars;
        tempArrOfCars = nullptr;

        autos[amountOfCars - 1].AssingValues(
            car.getWheels(),
            car.getDoors(),
            car.getSpeed(),
            car.getColor());
    }

    void Deleter() {
        Auto* tempArrOfCars = new Auto[amountOfCars - 1];
        int tempIndex = 0;

        for (int i = 0; i < amountOfCars - 1; i++) {
                tempArrOfCars[tempIndex].AssingValues(
                    autos[tempIndex].getWheels(),
                    autos[tempIndex].getDoors(),
                    autos[tempIndex].getSpeed(),
                    autos[tempIndex].getColor());
                tempIndex++;
        }


        DincrementAmountOfPoints();


        delete[] autos;
        autos = tempArrOfCars;
    }

    void printWholeCars() {
        for (int i = 0; i < Parking::amountOfCars; i++) {
            autos[i].PrintInfo();
        }
    }


    static void IncrementAmountOfPoints() {
        amountOfCars++;
    }
    static void DincrementAmountOfPoints() {
        amountOfCars--;
    }
};

int Parking::amountOfCars = 0;


int main()
{
    Auto obj;
    Parking obj2;
    int leave;
    int choose;
    srand(time(NULL));
    while (true) {
        cout << "1 - add , 2 - delete , 3 - write whole auto : ";
        cin >> choose;
        if (choose == 1 ) {
            cout << Parking::amountOfCars << endl;
            obj2.Adder(obj);
            cout << Parking::amountOfCars << endl;
        }
        else if (choose == 2 && Parking::amountOfCars > 0) {
            cout << Parking::amountOfCars << endl;
            obj2.Deleter();
            cout << Parking::amountOfCars << endl;
        }
        else if (choose == 3) {
            obj2.printWholeCars();
        }
        else {
            cout << "Do u want to leave from programm : [0 - yes]";
            cin >> leave;
            if (leave == 0) {
                return 0;
            }
            else {
                continue;
            }
        }
    }
}