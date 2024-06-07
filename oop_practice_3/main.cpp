#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CVehicle {
protected:
	int price;
	int speed;
	int constructionYear;
public:
	CVehicle(int price, int speed, int constructionYear) {
		this->price = price;
		this->speed = speed;
		this->constructionYear = constructionYear;
	}
	virtual void printDetails() const = 0;

};

class CPlane : public CVehicle {
	int maxHeight;
	int capacity;
public:
	CPlane(int price, int speed, int constructionYear, int maxHeight, int capacity) : 
		CVehicle(price, speed, constructionYear) {
		this->maxHeight = maxHeight;
		this->capacity = capacity;
	}
	void printDetails() const override {
		cout << "Тип транспорта: самолёт" << endl;
		cout << "Цена: " << price << endl;
		cout << "Скорость: " << speed << endl;
		cout << "Год производства: " << constructionYear << endl;
		cout << "Максимальная высота полёта: " << maxHeight << endl;
		cout << "Вместимость: " << capacity << endl;
	}
};

class CCar : public CVehicle {
public:
	CCar(int price, int speed, int constructionYear) : CVehicle(price, speed, constructionYear) {}

	virtual void printDetails() const override {
		cout << "Тип транспорта: автомобиль" << endl;
		cout << "Цена: " << price << endl;
		cout << "Скорость: " << speed << endl;
		cout << "Год производства: " << constructionYear << endl;
	}
};

class CShip : public CVehicle {
	int capacity;
	string port;
public:
	CShip(int price, int speed, int constructionYear, int capacity, string port) : 
		CVehicle(price, speed, constructionYear) {
		this->capacity = capacity;
		this->port = port;
	}

	virtual void printDetails() const override {
		cout << "Тип транспорта: корабль" << endl;
		cout << "Цена: " << price << endl;
		cout << "Скорость: " << speed << endl;
		cout << "Год производства: " << constructionYear << endl;
		cout << "Порт приписки: " << port << endl;
		cout << "Вместимость: " << capacity << endl;
	}
};

void getVehicleDetails(int& price, int& speed, int& constructionYear) {
	cout << "Введите цену: ";
	cin >> price;
	cout << "Введите скорость: ";
	cin >> speed;
	cout << "Введите год производства: ";
	cin >> constructionYear;
}

int main() {
	setlocale(LC_ALL, "Rus");

	int choice;
	int maxHeight = 0;
	int capacity = 0;
	string port;
	vector<CVehicle*> transport;

	int planePrice, planeSpeed, planeConstructionYear, planeMaxHeight, planeCapacity;
	int carPrice, carSpeed, carConstructionYear;
	int shipPrice, shipSpeed, shipConstructionYear, shipCapacity;

	while (true) {
		cout << "Что вы хотите:" << endl;
		cout << "1. Самолёт" << endl;
		cout << "2. Автомобиль" << endl;
		cout << "3. Корабль" << endl;
		cout << "0. Выход" << endl;
		cin >> choice;
		if (!choice)
			break;

		switch (choice) {
		case 1: {
			getVehicleDetails(planePrice, planeSpeed, planeConstructionYear);

			cout << "Введите максимальную высоту полёта: ";
			cin >> planeMaxHeight;
			cout << "Введите вместимость вашего транспорта: ";
			cin >> planeCapacity;

			transport.push_back(new CPlane(planePrice, planeSpeed,
				planeConstructionYear, planeMaxHeight, planeCapacity));
			break;
		}

		case 2: {
			getVehicleDetails(carPrice, carSpeed, carConstructionYear);

			transport.push_back(new CCar(carPrice, carSpeed, carConstructionYear));
			break; }

		case 3: {
			getVehicleDetails(shipPrice, shipSpeed, shipConstructionYear);

			cout << "Введите вместимость вашего транспорта: ";
			cin >> shipCapacity;
			cout << "Введите порт приписки: ";
			getline(cin, port);

			transport.push_back(new CShip(shipPrice, shipSpeed, shipConstructionYear, shipCapacity, port));
			break; }

		default:
			cout << "Неверный ввод" << endl;
			break;
		}
	}
	
	cout << endl;
	
	for (int i = 0; i != transport.size(); ++i) {



		transport[i]->printDetails();
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}

	/*for (auto& vehicle : transport) {
		vehicle->printDetails();
		cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << endl;
	}*/

	for (auto& vehicle : transport) {
		delete vehicle;
	}

}