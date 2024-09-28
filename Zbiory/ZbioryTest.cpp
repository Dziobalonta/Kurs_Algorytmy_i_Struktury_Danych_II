#include <iostream>
#include "SetAsArray.h"

using std::cout;
using std::endl;

int main()
{
    // Utwórz zbiory A,B,C i D (zbiór uniwersalny rozmiar 10)
    int size = 10;
    SetAsArray A(size), B(size), C(size), D(size);

    for (int i = 0; i < size; i++)
    {
        // Do zbioru A wstaw elementy parzyste
        // Do zbioru B wstaw elementy nieparzyste
        if (i % 2)
        {
            B.Insert(i);
        }
        else A.Insert(i);        
    }

    C=A+B;
    D=C-B;
    cout << "Zbior A:" << endl;
    A.Wypisz();
    cout << "Zbior B:" << endl;
    B.Wypisz();
    cout << "Zbior C:" << endl;
    C.Wypisz();
    cout << "Zbior D:" << endl;
    D.Wypisz();

    // sprawdź, czy:
    // 	 "D==A" 
    //   "D<=A" 
    // 	 "C==B" 
    // 	 "B<=C"
    cout << "Wynik operacji D==A: " << ((D == A) ? "true" : "false") << endl;
    cout << "Wynik operacji D<=A: " << ((D <= A) ? "true" : "false") << endl;
    cout << "Wynik operacji C==B: " << ((C == B) ? "true" : "false") << endl;
    cout << "Wynik operacji B<=C: " << ((B <= C) ? "true" : "false") << endl;


    // Do zbioru A wstaw elementy wartość 1

    A.Insert(1);
    
    cout << "Zbior A:" << endl;
    A.Wypisz();
    
    // sprawdź, czy: 
    // 	 "D==A" 
    //   "D<=A"
    cout << "Wynik operacji D==A: " << ((D == A) ? "true" : "false") << endl;
    cout << "Wynik operacji D<=A: " << ((D <= A) ? "true" : "false") << endl;

    // NOWA CZESC TESTOW
    cout << "\n——— NOWA CZESC TESTOW ———\n";

    A.Insert(5);
    Adding_Visitor av_A;
    A.Accept(av_A);
    cout << "Suma policzona przez v_A: " << av_A.Sum() << endl;

    SetAsArray E = A * B;
    cout << "Zbior E:" << endl;
    E.Wypisz();
    Adding_Visitor av_E;
    E.Accept(av_E);
    cout << "Suma policzona przez v_E: " << av_E.Sum() << endl;

    E.Withdraw(1);
    E.Wypisz();

    cout << "Suma policzona przez v_E: " << av_E.Sum() << endl;


    Odd_Visitor ov_B;
    B.Accept(ov_B);
    cout << "Czy w zbiorze B jest nieparzysta: " << ov_B.IsDone() << endl;

    Odd_Visitor ov_A;
    A.Accept(ov_A);
    cout << "Czy w zbiorze A jest nieparzysta: " << ov_A.IsDone() << endl;

    A.Withdraw(1);
    //A.Withdraw(5);
    cout << "Zbior A:" << endl;
    A.Wypisz();
    A.Accept(ov_A);
    cout << "Czy w zbiorze A jest nieparzysta: " << ov_A.IsDone() << endl;

    // NOWA CZESC TESTOW
    cout << "\n——— JESZCZE NOWSZA CZESC TESTOW ———\n";

    cout << "Elementy zbioru A:" << endl;
    SetAsArray::Iter iterA(A.getArray(), A.getUniverseSize());
    while (!iterA.IsDone())
    {
        cout << *iterA << " ";
        ++iterA;
    }
    cout << endl;

    cout << "Elementy zbioru B:" << endl;
    SetAsArray::Iter iterB(B.getArray(), B.getUniverseSize());
    while (!iterB.IsDone())
    {
        cout << *iterB << " ";
        ++iterB;
    }
    cout << endl;
    
    return 0;
}

