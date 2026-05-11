#pragma once
#include <exception>
#include <iostream>
using namespace std;

class exceptie1 : public exception
{
    virtual const char* what() const throw()
    {
        return "Indexul este inafara domeniului!";
    }
};

class Compare
{
public:
    virtual int CompareElements(void* e1, void* e2) = 0;
};
template<class T>
class ArrayIterator
{
private:
    int Current; 
    T** arrptr;
public:
    ArrayIterator(int pos, T** ptr) : Current(pos), arrptr(ptr) {};
    ArrayIterator& operator ++ () {
        Current++;
        return *this;
    };
    ArrayIterator& operator -- () {
        Current--;
        return *this;
    };
    bool operator= (const ArrayIterator<T>& other) {
        Current = other.Current;
        arrptr = other.arrptr;
    };
    bool operator!=(const ArrayIterator<T>& other) {
        return Current != other.Current;
    };
    T* GetElement() {
        return arrptr[Current];
    };
};
template<class T>
class Array
{
private:
    T** List; 
    int Capacity; 
    int Size; 
public:
    exceptie1 index_out_of_bounds;
    Array() {
        Capacity = 0;
        Size = 0;
    };
    ~Array() {

        for (int i = 0; i < Size; i++) {
            delete List[i]; 
        }
        delete[]List;
    }; 
    Array(int capacity) {
        Capacity = capacity;
        List = new T * [capacity];
    }; 
    Array(const Array<T>& otherArray) {
        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) {
            List[i] = new T(*otherArray.List[i]);
        }
    };

    T& operator[] (int index) {
    
        if (index < 0 || index > Size)
        {
        throw index_out_of_bounds;
        }
        return *List[index];
    }; // arunca exceptie daca index este out of range

    const Array<T>& operator+=(const T& newElem) {
    
        if (Capacity <= Size+1)
        {
            Capacity++;
        }
        List[Size] = new T(newElem);
        Size++;
        return *this;
    }; // adauga un element de tipul T la sfarsitul listei si returneaza this
    const Array<T>& Insert(int index, const T& newElem) {
    
            if (index > Size)
            {
                throw index_out_of_bounds;
            }
   
            for (int i = Size-1; i > index; i--)
            {
                List[i] = List[i - 1];
            }
        List[index] = new T(newElem);
        return *this;
    }; // adauga un element pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Insert(int index, const Array<T> otherArray) {
        
        if (index < 0 || index > Size) {
            throw index_out_of_bounds;
        }

        if (Size + otherArray.Size > Capacity)
        {
            Capacity = Size + otherArray.Size;
        }
        for (int i = Size - 1; i >= index; i--) {
            List[i + otherArray.Size] = List[i];
        }
        for (int i = 0; i < otherArray.Size; i++) {
            List[index + i] = new T(*otherArray.List[i]);
        }
        Size += otherArray.Size;
        return *this;
    }; // adauga o lista pe pozitia index, retureaza this. Daca index e invalid arunca o exceptie
    const Array<T>& Delete(int index) {
    
        if (index > Size)
        {
            throw index_out_of_bounds;
        }
        delete List[index];
        for (int i = index; i < Size-1; i++)
        {
            List[i] = List[i + 1];
        }
        Size--;
        return *this;
    }; // sterge un element de pe pozitia index, returneaza this. Daca index e invalid arunca o exceptie

    bool operator=(const Array<T>& otherArray) {
        if (this == &otherArray) {
            return true;
        }
        for (int i = 0; i < Size; i++) {
            delete List[i];
        } 
        delete[] List;

        Capacity = otherArray.Capacity;
        Size = otherArray.Size;
        List = new T * [Capacity];
        for (int i = 0; i < Size; i++) List[i] = new T(*otherArray.List[i]);
        return true;
    
    };

    void Sort() {
        for (int i = 0; i < Size - 1; i++) 
        {
            for (int j = i + 1; j < Size; j++) 
            {
                if (*List[i] > *List[j]) {
                    swap(List[i], List[j]);
                }
            }
        }

    }; // sorteaza folosind comparatia intre elementele din T
    void Sort(int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size - 1; i++) 
        {
            for (int j = i + 1; j < Size; j++) 
            {

                    if (compare(*List[i], *List[j]) > 0) {
                         swap(List[i], List[j]);
                    }
            }
        }
    }; // sorteaza folosind o functie de comparatie
    void Sort(Compare* comparator) {
        for (int i = 0; i < Size - 1; i++) 
        {
            for (int j = i + 1; j < Size; j++) 
            {
                if (comparator->CompareElements(List[i], List[j]) > 0) {
                    swap(List[i], List[j]);
                }
            }
        }
    }; // sorteaza folosind un obiect de comparatie

    // functii de cautare - returneaza pozitia elementului sau -1 daca nu exista
    int BinarySearch(const T& elem) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int m = (left + right) / 2;
            if (*List[m] == elem) {
                return m;
            }
            if (*List[m] < elem) {
                left = m + 1;
            }
            else {
                right = m - 1;
            }
        }
        return -1;
    }; // cauta un element folosind binary search in Array
    int BinarySearch(const T& elem, int(*compare)(const T&, const T&)) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int m = (left + right) / 2;
            int res = compare(*List[m], elem);
            if (res == 0) {
                return m;
            } 
            if (res < 0) {
                left = m + 1;
            } 
            else {
                right = m - 1;
            }      
        }   
        return -1;
    };//  cauta un element folosind binary search si o functie de comparatie
    int BinarySearch(const T& elem, Compare* comparator) {
        int left = 0, right = Size - 1;
        while (left <= right) {
            int m = (left + right) / 2;
            int res = comparator->CompareElements(List[m], (void*)&elem);
            if (res == 0) {
                return m;
            }
            if (res < 0) {
                left = m + 1;
            }
            else {
                right = m - 1;
            }
        }
        return -1;
    
    };//  cauta un element folosind binary search si un comparator

    int Find(const T& elem) {
        for (int i = 0; i < Size; i++) {
            if (*List[i] == elem) return i;
        }
        return -1;
    }; // cauta un element in Array
    int Find(const T& elem, int(*compare)(const T&, const T&)) {
        for (int i = 0; i < Size; i++) {
            if (compare(*List[i], elem) == 0) {
                return i;
            } 
        }
        return -1;
    };//  cauta un element folosind o functie de comparatie
    int Find(const T& elem, Compare* comparator) {
        for (int i = 0; i < Size; i++) {
            if (comparator->CompareElements(List[i], (void*)&elem) == 0) {
                return i;
            }
        }
        return -1;
    
    };//  cauta un element folosind un comparator

    int GetSize() {
        return Size;
    };
    int GetCapacity() {
        return Capacity;
    };

    ArrayIterator<T> GetBeginIterator() {
        return ArrayIterator<T>(0, List);
    };
    ArrayIterator<T> GetEndIterator() {
        return ArrayIterator<T>(Size, List);
    };
};
