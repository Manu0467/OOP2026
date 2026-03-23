#pragma once
class Number
{
	char value[300];
	int base;
	int digitsCount;
public:
	int base10value;
	Number(const char* value, int base); // where base is between 2 and 16
	Number(int n);
	~Number();

	Number(const Number &n); //doar copiaza informatiile din el dat ca parametru
	Number(Number&& n) noexcept; //constructor copy&move copiaza informatiile din n si elibereaza memoria din elementul dat ca parametru

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);
	Number& operator+=(const Number& n);
	Number& operator-=(const Number& n);
	Number& operator=(const Number& n);
    Number& operator=(const char * n);
	Number& operator=(int n);
    char& operator[](int index);

	  
	Number& operator++(); //++n
	Number& operator--(); //ptr --n
	Number& operator--(int); //n--
	Number& operator++(int); //n++

	bool operator>(Number n);
	bool operator<(Number n);
	bool operator==(Number n);
	bool operator<=(Number n);
	bool operator>=(Number n);

	void SwitchBase(int newBase);
	void Print();
	int  GetDigitsCount(); // returns the number of digits for the current number
	int  GetBase(); // returns the current base
	void setBase10Value();
	void setValue();
};


