#include "Number.h"
#include "stdlib.h"
#include <string>


//Constructors & Destructors
Number::Number(const char* value, int base)
{
	strcpy_s(this->value, 300 , value);
	this->base = base;
	this->digitsCount = strlen(value);
	this->setBase10Value();

}

Number::Number(int n)
{
	base10value = n;
	base = 10;
	sprintf_s(this->value, 300, "%d", n);
	digitsCount = strlen(value);
}

Number::~Number()
{
	value[0] = '\0';
	digitsCount = 0;
	base = 0;
}

Number::Number(const Number& n) //copy constructor 
{
	strcpy_s(value, 300, n.value);
	base = n.base;
	digitsCount = n.digitsCount;
	base10value = n.base10value;
}

Number::Number(Number&& n) noexcept
{
	strcpy_s(value, 300, n.value);
	base = n.base;
	digitsCount = n.digitsCount;
	base10value = n.base10value;
	n.value[0] = '\0';
	n.digitsCount = 0;
	n.base = 0;
	n.base10value = 0;
}


//Arithmetic Operators
	
Number& Number::operator=(const char* n)
{
	strcpy_s(value, 300, n);
	this->digitsCount = strlen(n);
	this->setBase10Value();

	return *this;
}

Number& Number::operator=(int n)
{
	this->base10value = n;
	this->setValue();
	sprintf_s(this->value, 300, "%d", n);
	this->digitsCount = strlen(value);
	

	return *this;
}

Number& Number::operator=(const Number& n) {

	if (this == &n) {

		return *this;
	}
	else {

		strcpy_s(value, 300, n.value);
		base = n.base;
		digitsCount = n.digitsCount;
		base10value = n.base10value;

		return *this;
	}
	
}

char& Number::operator[](int index)
{
	return value[index];
}

Number operator+(const Number& n1, const Number& n2)
{
	int rezbase10vl = n1.base10value + n2.base10value;
	int rezbs;

	if (n1.base > n2.base)
	{
		rezbs = n1.base;
	}
	else {
		rezbs = n2.base;
	}
	
	Number res(rezbase10vl);
	res.SwitchBase(rezbs);
	return res;

	
}

Number operator-(const Number& n1, const Number& n2)
{
	int rezbase10vl = n1.base10value - n2.base10value;
	int rezbs;

	if (n1.base > n2.base)
	{
		rezbs = n1.base;
	}
	else {
		rezbs = n2.base;
	}

	Number res(rezbase10vl);
	res.SwitchBase(rezbs);
	return res;
}

Number& Number::operator+=(const Number& n)
{
	
	this->base10value += n.base10value;
	this->setValue();
	if (this->base < n.base)
	{
		this->SwitchBase(n.base);
	}
	
	
	return *this;
}

Number& Number::operator-=(const Number& n)
{
	this->base10value -= n.base10value;
	if (this->base < n.base)
	{
		this->SwitchBase(n.base);
	}

	return *this;
}

Number& Number::operator++() //forma prefix(++n) returneaza o referinta catre obiectul dat ca parametru, acest lucru permite inlantuirea operatiilor
{
	base10value++;
	int n = base10value;
	int i = digitsCount--;
	while (n) {
		value[i--] = n % 10 + '0';
		n /= 10;
	}
	return *this;
}

Number& Number::operator++(int) //n++ operatorul postfix returneaza valoarea pe care o avea obiectul inainte dar in acelasi timp ii modifica valoarea
{
	Number temp(*this);
	this->base10value++;
	int p = base10value;
	int i = digitsCount--;
	while (p) {
		value[i--] = p % 10 + '0';
		p /= 10;
	}

	return temp;
} 

Number& Number::operator--() //--n
{
	
	for (int i = 0; i < digitsCount; i++)
	{
		value[i] = value[i + 1];
	}
	digitsCount--;
	setBase10Value();

	return *this;
}

 Number& Number::operator--(int) //n--
{
	value[digitsCount - 1] = '\0';
	digitsCount--;
	setBase10Value();

	return *this;

}
	
//Logic operators

bool Number::operator>(Number n)
{
	return this->base10value > n.base10value;
}

bool Number::operator<(Number n)
{
	return this->base10value < n.base10value;
}

bool Number::operator==(Number n)
{
	return this->base10value == n.base10value;
}

bool Number::operator<=(Number n)
{
	return this->base10value <= n.base10value;
}

bool Number::operator>=(Number n)
{
	return this->base10value >= n.base10value;
}

//Class functions

void Number::SwitchBase(int newBase)
	{
		int nr = 0;
		int i = 0;
		char aux[300];
		//345

		//base 10 conversion
	
			for (int i = 0; i < digitsCount; i++) {
				int cif;
				if (value[i] >= '0' && value[i] <= '9') {

					cif = value[i] - '0';
				}
				else {
					cif = value[i] - 'A' + 10;
				}
				nr = nr * this->base + cif; 
			}

			base10value = nr;
	
			if (nr==0)
			{
				aux[i++] = '0';
			}
		while (nr) {

			int cif = nr % newBase;
			if (cif >= 0 and cif <= 9)
			{
				aux[i++] = cif + '0';
			}
			else {
				aux[i++] = (cif - 10) + 'A';
			}
			nr /= newBase;
		}
	
		for (int j = 0; j < i; j++)
		{
			value[j] = aux[i - j - 1];
		}
		digitsCount = i;
		value[i] = '\0';
		base = newBase;
	}

void Number::Print()
{
	printf("the number %s is in base %d \n", this->value, this->base);

}

int Number::GetDigitsCount()
{
	return this->digitsCount;
}

int Number::GetBase()
{
	return this->base;
}

//helper function

void Number::setBase10Value()
{
	int nr = 0;
	for (int i = 0; i < digitsCount; i++) {
		int cif;
		if (value[i] >= '0' && value[i] <= '9') {

			cif = value[i] - '0';
		}
		else {
			cif = value[i] - 'A' + 10;
		}
		nr = nr * this->base + cif;
	}

	base10value = nr;
}

void Number::setValue() {
	char aux[300];
	int nr = base10value;
	int cif;
	int i = 0, j = 0;
	while (nr) {
		cif = nr % base;
		if (cif <= 9)
		{
			aux[i++] = '0' + cif;
		}
		else {
			aux[i++] = (cif - 10) + 'A';
		}
		nr /= base;
	}

	digitsCount = i;
	i--;
	while (i >= 0) {

		value[j] = aux[i];
		j++;
		i--;
	}
	value[j] = '\0';
}