#include <iostream>
#include "Array.h"

using namespace std;

int main() {
  

    //test 1 - constructorul de copiere
    cout << "Test 1" << endl;
    Array<int> arr1;
    arr1 += 100;
    Array<int> arr2 = arr1; 

    if (arr2[0] != 100) {
        cout << "[EROARE]: arr2[0] este " << arr2[0] << " in loc de 100." << endl;
    }
    else {
        cout << "[OK]: Constructorul de copiere functioneaza." << endl;
    }
    cout << endl;

    //test 2 - verificare index_out_of_bounds
    cout << "Test 2" << endl;
    try {
        int marime = arr1.GetSize(); 
        int elementIlegal = arr1[marime];

        cout << "[EROARE]: Clasa a permis accesarea indexului Size!" << endl;
    }
    catch (const index_out_of_bounds& e) {
        cout << "[OK]: Exceptia a fost prinsa corect: " << e.what() << endl;
    }
    cout << endl;

    //test 3 - verificare eroare la pierderea datelor
    cout << "Test 3" << endl;
    Array<int> arr3(2);
    arr3 += 10;
    arr3 += 20;
    arr3 += 30; 

    if (arr3[0] != 10) {
        cout << "[EROARE]: Dupa realocare primul element este " << arr3[0] << " in loc de 10." << endl;
    }
    else {
        cout << "[OK]: Realocarea pastreaza toate datele." << endl;
    }
    cout << endl;

    //verificare eroare 4 - sortarea 
    cout << "Test 4" << endl;
    Array<int> arr4;
    arr4 += 50;
    arr4 += 10;
    arr4 += 30;
    arr4.Sort();

    // Verificam daca sortarea este crescatoare
    if (arr4[0] > arr4[1]) {
        cout << "[EROARE]: Sortarea s-a facut gresit! Elementele sunt: "
            << arr4[0] << " " << arr4[1] << " " << arr4[2] << endl;
    }
    else {
        cout << "[OK]: Sortarea functioneaza crescator." << endl;
    }
    cout << endl;
    //eroare 5 - verificare Size dupa Delete
    cout << "Test 5" << endl;
    Array<int> arr5;
    arr5 += 7;
    arr5 += 8;
    int dimensiuneInainte = arr5.GetSize(); // 2

    arr5.Delete(0); // Ar trebui sa ramana un singur element
    int dimensiuneDupa = arr5.GetSize();

    if (dimensiuneInainte == dimensiuneDupa) {
        cout << "[EROARE]: Size nu a fost modificat!" << endl;
    }
    else {
        cout << "[OK]: Size s-a actualizat corespunzator." << endl;
    }
    cout << endl;
    return 0;
}