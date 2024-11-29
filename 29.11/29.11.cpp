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
		purple = 0, // присваивается 0
		gray = 1,   // присваивается 1
		blue = 2,   // присваивается 2
		green = 3,  // присваивается 3
		brown= 4,  // присваивается 4
		pink = 5,   // присваивается 5
		yellow = 6 // присваивается 6
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

	void PrintInfo() {
		cout << "Your car : \n" << "Count of wheels : " << wheels << "\nCount of doors : "<< doors << "\nSpeed of car : " << speed << "km\\h" << "\nColor of car : " << color  << endl;
	}
};

class Parking {
    Auto* autos;
public:
    static int amountOfCars;

    Parking() {
        autos = new Auto[amountOfCars];
    }
    void Adder(Auto user) {
        Auto* tempArrOfCars = new Auto[amountOfCars];

        for (int i = 0; i < amountOfCars; i++) {
            tempArrOfCars[i].AssingValues(
                autos[i].getName(),
                autos[i].getSurname(),
                autos[i].getAge());
        }

        delete[] autos;
        autos = nullptr;

        IncrementAmountOfPoints();

        users = new User[amountOfUsers];

        for (int i = 0; i < amountOfUsers - 1; i++) {
            users[i].AssingValues(
                tempArrOfStudents[i].getName(),
                tempArrOfStudents[i].getSurname(),
                tempArrOfStudents[i].getAge());
        }

        delete[] tempArrOfStudents;
        tempArrOfStudents = nullptr;

        users[amountOfUsers - 1].AssingValues(
            user.getName(),
            user.getSurname(),
            user.getAge());
    }

    void Deleter(int indexToDelete) {
        if (indexToDelete < 0 || indexToDelete >= amountOfUsers) {
            cout << "Invalid index!" << endl;
            return;
        }
        User* tempArrOfStudents = new User[amountOfUsers - 1];
        int tempIndex = 0;

        for (int i = 0; i < amountOfUsers; i++) {
            if (i != indexToDelete - 1) {
                tempArrOfStudents[tempIndex].AssingValues(
                    autos[i].getName(),
                    autos[i].getSurname(),
                    autos[i].getAge()
                );
                tempIndex++;
            }
        }


        DincrementAmountOfPoints();


        delete[] autos;
        autos = tempArrOfStudents;
    }


    static void IncrementAmountOfPoints() {
        amountOfCars ++;
    }
    static void DincrementAmountOfPoints() {
        amountOfCars --;
    }
};

int Parking::amountOfCars = 0;


int main()
{
	srand(time(NULL));
	Auto obj;
	Auto obj2;
	obj.PrintInfo();
	obj2.PrintInfo();
}