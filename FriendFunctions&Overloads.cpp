//17. Создать класс Complex, реализующий комплексное число.В классе
//перегрузить операторы унарный « + », возвращающий модуль комплексного
//числа(тип float), бинарный оператор « + », возвращающий сумму
//комплексных чисел(тип Complex), бинарный оператор « + », который
//добавляет к комплексному числу некоторое вещественное число.В этом
//случае операторная функция получает входным параметром вещественное
//число и возвращает объект типа Complex.Создать методы доступа к полям
//класса.Реализовать конструкторы(по умолчанию, с параметрами,
//	копирования).Реализовать friend - функции для операторов ввода / вывода в
//	поток для созданного класса



//Почему возникает ошибка сборки если менять местами кейсы????!!!

#include <iostream>
#include<math.h>
//#include <complex>

using namespace std;


class Complex {
	float realPart;
	float imaginaryPart;

public:
	Complex(float realPart = 0, float imaginaryPart = 0);
	friend void setData(float, float, Complex&);
	friend void showData(Complex&);
	float operator +();
	Complex operator +(Complex);
	Complex operator +(float);
};

Complex::Complex(float realPart, float imaginaryPart)
{
	this->realPart = realPart;
	this->imaginaryPart = imaginaryPart;
}

void setData(float realPart, float imaginaryPart, Complex& object)
{
	object.realPart = realPart;
	object.imaginaryPart = imaginaryPart;
}

void showData(Complex& object)
{
	cout << "current number: " << object.realPart << " + " << object.imaginaryPart << "i" << endl << endl;
}

float Complex::operator+()
{
	float module;
	module = realPart * realPart + imaginaryPart * imaginaryPart;
	module = sqrt(module);
	return module;
}

Complex Complex:: operator+(Complex	 object)
{
	this->realPart += object.realPart;
	this->imaginaryPart += object.imaginaryPart;
	return *this;
}

Complex Complex:: operator+(float real)
{
	this->realPart += real;
	return *this;
}

int main()
{
	float realPart, imaginaryPart, module;
	bool finish = false;
	int choice;
	cout << "enter a complex number" << endl;
	cout << "enter a real part:  ";
	cin >> realPart;
	cout << "enter an imaginary part:  ";
	cin >> imaginaryPart;

	Complex ComplexNumberMain;
	setData(realPart, imaginaryPart, ComplexNumberMain);
	showData(ComplexNumberMain);

	/*float real1;
	cout << "enter real1:  ";
	cin >> real1;
	ComplexNumberMain = ComplexNumberMain + real1;
	showData(ComplexNumberMain);
	*/


	do
	{
		cout << "What are you going to do:\n 1 - see the module of the complex number\n"
			" 2 - add another complex number to your complex number\n 3 - add a real number to your complex number\n"
			" 4 - finish the program\n";
		cin >> choice;

		switch (choice)
		{

		case 1:
			module = +ComplexNumberMain;
			cout << "Module of the number is: " << module << endl << endl;
			break;

		case 4:
			cout << "Goodbye\n";
			finish = true;
			break;

		case 3:
			float real1;
			cout << "Enter a real number:  ";
			cin >> real1;
			ComplexNumberMain = ComplexNumberMain + real1;
			showData(ComplexNumberMain);
			break;

		case 2:
			float realPart1, imaginaryPart1;
			cout << "Enter a complex numer\n";
			cout << "enter a real part:  ";
			cin >> realPart1;
			cout << "enter an imaginary part:  ";
			cin >> imaginaryPart1;
			Complex ComplexNumber1;
			setData(realPart1, imaginaryPart1, ComplexNumber1);
			ComplexNumberMain = ComplexNumberMain + ComplexNumber1;

			showData(ComplexNumberMain);
			break;


		}
	} while (finish != true);

}




