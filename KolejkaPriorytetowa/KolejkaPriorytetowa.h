#ifndef KOLEJKAPRIORYTETOWA_H
#define KOLEJKAPRIORYTETOWA_H

#include <vector>
#include <iostream>

class Container 
{
protected:
    Container (){};
public:
    virtual unsigned int Count () const = 0;
    virtual bool IsEmpty () const {return Count()==0;};
    virtual bool IsFull () const = 0;
    virtual void MakeNull() = 0;
};
 

template <typename T>
class PriorityQueue : public Container
{
public:
    virtual void Enqueue (T element) = 0;
    virtual T  FindMin () const = 0;
    virtual T DequeueMin () = 0;
};

template <typename T>
class BinaryHeap : public PriorityQueue<T>
{
protected:
    int count;
    std::vector<T> data;
    
public:
    BinaryHeap(unsigned int n): count(0)
    {
        data.resize(n);
    }

    BinaryHeap()
    {
        count = 0;
    }

    ~BinaryHeap(){;}

    void MakeNull()
    {
        count = 0;
    }

    void Enqueue(T element)
    {
        if (count >= data.size())
        {
            data.resize(count + 1);
            std::cout << "Rozszerzono o jedno miejsce" << std::endl;
        }
        int i = count;
        while (i > 0 && data[(i-1)/2] > element)
        {
            data[i] = data[(i-1)/2];
            i = (i-1)/2;
        }
        data[i] = element; // dodajemy element
        count++;
    }

    T FindMin() const
    {
        if(count < 1) std::abort();
        return data[0];
    }

    T DequeueMin()
    {
       if (count < 1) std::abort();

        T minimalnyElem = data[0];
        T ostatni = data[count-1];
        count--;

        int i = 0;
        while (2 * i + 1 < count)
        {
            int LeftChild = 2 * i + 1;
            int RightChild = 2 * i + 2;

            // if (LeftChild >= count) break; // wezel "i" jest lisciem

            int minChild;
            if (RightChild < count && data[RightChild] < data[LeftChild]) minChild = RightChild;
            else minChild = LeftChild;

            if (ostatni <= data[minChild]) break;

            data[i] = data[minChild];
            i = minChild;
        }
        data[i] = ostatni;
        return minimalnyElem;
    }

    bool IsEmpty() const
    {
        return count <= 0;
    }

    bool IsFull () const
    {
        return data.size() == data.capacity();
    }

    void Wypisz() const
    {
        for (int i = 0; i < count; i++)
        {
            std::cout << data[i] << " ";
        }
        
        // for(auto el: data)
        // {
        //     std::cout << el << " ";
        // }
        std::cout << std::endl;
    }

    unsigned int Count() const {return count;}
};

#endif
