#ifndef ITERATOR
#define ITERATOR

template <typename T>class Iterator
{
public:
	virtual ~Iterator (){};
	Iterator(){};
	virtual bool IsDone () = 0; // Sprawdzenie, czy dotarliśmy do końca
	virtual T &operator* () = 0; // Pobranie bieżącej wartości
	virtual void operator++ () = 0; // Przesunięcie się o jedno miejsce dalej
};

#endif // ITERATOR