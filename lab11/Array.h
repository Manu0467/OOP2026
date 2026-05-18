#pragma once
#include <iostream>
#include <exception>

using namespace std;

class index_out_of_bounds : public exception {
public:
	virtual const char* what() const throw() {
		return "Indexul este inafara domeniului";
	}
};

template <class T>
class Array
{
	int Capacity;
	int Size;
	T* List;

public:
	Array() {
		Capacity = 10;
		Size = 0;
		List = new T[Capacity];
	};
	Array(int capacity) {
		Capacity = capacity;
		Size = 0;
		List = new T[Capacity];
	};

	Array(const Array& other) {
		Capacity = other.Capacity;
		Size = other.Size;
		List = new T[Capacity](); // Alocă memorie cu 0 (zero-initialized)
		//eroare 1 - nu am mai copiat elementele din other in this

	}

	~Array() {
		delete[] List;
	};

	T& operator[] (int index) {
		//eroare 2 - folosesc > in loc de >= si astfel accesez un index invalid
		if (index < 0 || index > Size)
		{
			throw index_out_of_bounds();
		}
		return List[index];
	};

	Array& operator=(const Array& other) {
		if (this == &other) return *this;

		delete[] List;

		Capacity = other.Capacity;
		Size = other.Size;
		List = new T[Capacity];
		for (int i = 0; i < Size; i++) {
			List[i] = other.List[i];
		}
		return *this;
	}

	const Array<T>& operator+=(const T& newElem) {
		if (Size >= Capacity)
		{
			Capacity *= 2;
			T* newList = new T[Capacity];
			for (int i = 1; i < Size; i++) { //eroare 3 - am pornit de la 1 in loc de la 0 si astfel la fiecare alocare noua a unui el, primul se pierde
				newList[i] = List[i];
			}
			delete[] List;
			List = newList;
		}
		List[Size] = newElem;
		Size++;
		return *this;
	};

	void Sort() {
		for (int i = 0; i < Size - 1; i++)
		{
			for (int j = i + 1; j < Size; j++)
			{
				if (List[i] < List[j]) { //eroare 4 - sorteaza descrescator in loc de crescator
					swap(List[i], List[j]);
				}
			}
		}
	};

	const Array<T>& Delete(int index) {
		if (index < 0 || index >= Size)
		{
			throw index_out_of_bounds();
		}

		for (int i = index; i < Size - 1; i++)
		{
			List[i] = List[i + 1];
		}
		//eroare 5 - nu am mai decrementat Size
		return *this;
	};
	int GetSize() const {
		return Size;
	};
	int GetCapacity() const {
		return Capacity;
	};
};