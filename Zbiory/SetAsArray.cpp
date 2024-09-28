#include <iostream>
#include "SetAsArray.h"

// SET AS ARRAY METODY

SetAsArray::SetAsArray (unsigned int N) : Set(N){
    array.resize(N);
    for (int i = 0; i < N; i++)
    {
        array[i] = false;
    }
}

void SetAsArray::Insert (int element)
{
    if(array[element] == false){
        array[element] = true;
        count++;
    }
}

void SetAsArray::Withdraw (int element)
{
    if(array[element] == true){
        array[element] = false;
        count--;
    }
}

SetAsArray operator + (SetAsArray const& s, SetAsArray const& t)
{
    if (s.universeSize == t.universeSize)
    {
        int rozmiar = s.universeSize;
        SetAsArray result(rozmiar);
        result.count = 0; // Reset count
        for (int i = 0; i < rozmiar; i++)
        {
            result.array[i] = s.array[i] || t.array[i];
            if (result.array[i]) result.count++;
        }
        return result;
    }
    else
    {
        // Tworzymy nowy pusty obiekt, gdy rozmiary są rozne
        SetAsArray result(0);
        return result;
    }
}


SetAsArray operator - (SetAsArray const& s, SetAsArray const& t)
{
    if (s.universeSize == t.universeSize)
    {
        int rozmiar = s.universeSize;
        SetAsArray result(rozmiar);
        result.count = 0; // Reset count
        for (int i = 0; i < rozmiar; i++)
        {
            result.array[i] = s.array[i] &&! t.array[i];
            if (result.array[i]) result.count++;
        }
        return result;
    }
    else
    {
        // Tworzymy nowy pusty obiekt, gdy rozmiary są rozne
        SetAsArray result(0);
        return result;
    }
}

SetAsArray operator * (SetAsArray const& s, SetAsArray const& t)
{
    if (s.universeSize == t.universeSize)
    {
        int rozmiar = s.universeSize;
        SetAsArray result(rozmiar);
        result.count = 0; // Reset count
        for (int i = 0; i < rozmiar; i++)
        {
            result.array[i] = s.array[i] && t.array[i];
            if (result.array[i]) result.count++;
        }
        return result;
    }
    else
    {
        // Tworzymy nowy pusty obiekt, gdy rozmiary są rozne
        SetAsArray result(0);
        return result;
    }
}
bool operator == (SetAsArray const& s, SetAsArray const& t)
{
    if (s.universeSize == t.universeSize)
    {
        int rozmiar = s.universeSize;
        for (int i = 0; i < rozmiar; i++)
        {
            if (s.array[i] != t.array[i]) return false;
        }
        return true;
    } else return false;

}
bool operator <= (SetAsArray const& s, SetAsArray const& t)
{
    if (s.universeSize == t.universeSize)
    {
        int rozmiar = s.universeSize;
        for (int i = 0; i < rozmiar; i++)
        {
            if (s.array[i] > t.array[i]) return false;
        }
        return true;
    } else return false;
}

void SetAsArray::Wypisz() const
{
    //std::cout << "count: " << count << std::endl;
    for (int i = 0; i < universeSize; i++)
    {
        std::cout << array[i];
    }
    std::cout << std::endl;
}

void SetAsArray::MakeNull()
{
    count = 0;   
}
bool SetAsArray::IsMember(int element) const
{
    return array[element];
}

void SetAsArray::Accept(Visitor<int> &v)
{
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i]==true) v.Visit(i);
        if (v.IsDone())
        {
            std::cout << "Zakonczono przegladanie na indeksie: " << i << std::endl;
            return;
        }
    }
}

// VISITORY METODY

void Odd_Visitor::Visit(int &element) 
{
    if (element%2==1) 
    {
        IsDone_ = true;
    } else IsDone_ = false;
}

void Adding_Visitor::Visit(int &element) 
{
    sum += element;
}
