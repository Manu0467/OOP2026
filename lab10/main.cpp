#include <iostream>
#include "Array.h" 
using namespace std;

int compareInts(const int& a, const int& b) {
    if (a == b) return 0;
    return (a > b) ? 1 : -1;
}

class IntComparator : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int v1 = *(int*)e1;
        int v2 = *(int*)e2;
        if (v1 == v2) return 0;
        return (v1 > v2) ? 1 : -1;
    }
};

int main() {
    try {
        Array<int> arr(10);
        arr += 50;
        arr += 10;
        arr += 30;
        arr += 20;

        cout << "Elementele initiale: ";
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        arr.Insert(1, 100);
        cout << "Dupa inserare 100 la index 1: ";
        for (int i = 0; i < arr.GetSize(); i++) cout << arr[i] << " ";
        cout << endl;

        arr.Delete(2);
        cout << "Dupa stergere element la index 2: ";
        for (int i = 0; i < arr.GetSize(); i++) cout << arr[i] << " ";
        cout << endl;

        arr.Sort(compareInts);
        cout << "Dupa sortare: ";
        for (int i = 0; i < arr.GetSize(); i++) cout << arr[i] << " ";
        cout << endl;

        int pos = arr.BinarySearch(30);
        cout << "Elementul 30 gasit la indexul: " << pos << endl;

        cout << "Parcurgere cu iterator: ";
        auto it = arr.GetBeginIterator();
        auto end = arr.GetEndIterator();
        while (it != end) {
            cout << *it.GetElement() << " ";
            ++it;
        }
        cout << endl;

        cout << "Incercam sa accesam un index invalid..." << endl;
        cout << arr[100]; 

    }
    catch (const exception& e) {
        cout << "Am prins o exceptie: " << e.what() << endl;
    }

    return 0;
}