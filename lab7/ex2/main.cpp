#include <iostream>
#include <string>
#include "Tree.h" // Presupunând că ai salvat clasa în Tree.h

// 1. Funcție de comparare pentru metoda FIND
// Verificăm dacă valorile sunt egale
bool compareValues(const int& a, const int& b) {
    return a == b;
}

// 2. Funcție de comparare pentru metoda SORT
// Returnează true dacă primul e mai mare (pentru sortare crescătoare)
bool sortAscending(const int& a, const int& b) {
    return a > b;
}

int main() {
    Tree<int> arbore;

    std::cout << "--- Testare Adaugare (add_node) ---\n";
    arbore.add_node(10); 
    auto root = &arbore.get_node(nullptr, 0);
    
    arbore.add_node(30, root); 
    arbore.add_node(20, root); 
    arbore.add_node(50, root); 
    
    std::cout << "Total noduri in arbore (fara radacina): " << arbore.count(nullptr) << "\n\n";

    std::cout << "--- Testare Inserare (insert) ---\n";
    arbore.insert(25, root, 1);
    std::cout << "Dupa inserare, primul copil: " << arbore.get_node(root, 0).data << "\n";
    std::cout << "Dupa inserare, al doilea copil (cel inserat): " << arbore.get_node(root, 1).data << "\n\n";

    std::cout << "--- Testare Cautare (find) ---\n";
    int deCautat = 25;
    auto nodGasit = arbore.find(deCautat, compareValues);
    if (nodGasit) {
        std::cout << "Am gasit nodul cu valoarea: " << nodGasit->data << "\n";
    } else {
        std::cout << "Nodul nu a fost gasit.\n";
    }

    std::cout << "\n--- Testare Sortare (sort) ---\n";
    std::cout << "Ordine inainte de sortare: ";
    for(int i = 0; i < 4; i++) std::cout << arbore.get_node(root, i).data << " ";
    
    arbore.sort(root, sortAscending);
    
    std::cout << "\nOrdine dupa sortare (crescator): ";
    for(int i = 0; i < 4; i++) std::cout << arbore.get_node(root, i).data << " ";
    std::cout << "\n\n";

    std::cout << "--- Testare Stergere (delete_node) ---\n";
   
    auto copilDeSters = &arbore.get_node(root, 0);
    arbore.delete_node(copilDeSters);
    std::cout << "Dupa stergere nod (valoare resetata la default): " << copilDeSters->data << "\n";
    std::cout << "Numar descendenti radacina: " << arbore.count(root) << "\n";

    return 0;
}