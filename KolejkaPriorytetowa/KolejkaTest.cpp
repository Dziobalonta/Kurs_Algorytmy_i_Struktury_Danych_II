#include <iostream>
#include "KolejkaPriorytetowa.h"

using std::cout;
using std::endl;

int main()
{
    
    // Utwórz kolejkę (dlugosc wektora 10)
    BinaryHeap<int> Kolejka(10);

    // Sprawdź, czy jest pusta
    cout << "Czy pusta: " << (Kolejka.IsEmpty() ? "true" : "false") << endl;

    Kolejka.Enqueue(5);

    // Sprawdź, czy jest pusta
    cout << "Czy pusta: " << (Kolejka.IsEmpty() ? "true" : "false") << endl;
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;
    Kolejka.Enqueue(6);
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;

    Kolejka.Enqueue(8);
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;

    Kolejka.Enqueue(3);
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;

    Kolejka.Enqueue(9);
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;

    Kolejka.Enqueue(2);
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;

    Kolejka.Enqueue(1);
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;
    Kolejka.DequeueMin();
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;
    Kolejka.DequeueMin();
    Kolejka.Wypisz();
    cout << "Element minimalny: " << Kolejka.FindMin() << endl;
    Kolejka.MakeNull();

    // Sprawdź, czy jest pusta
    cout << "Czy pusta: " << (Kolejka.IsEmpty() ? "true" : "false") << endl;
    
    // Wykonaj te same testy, gdy wektor data ma długość 2. 
    return 0;
}