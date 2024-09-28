#include <vector>

template <typename T>
class Visitor
{
public:
    virtual void Visit (T & element) = 0;
    virtual bool IsDone ()
	{ return false; }
};

template <typename T>class Iterator
{
public:
	virtual ~Iterator (){};
	Iterator(){};
	virtual bool IsDone () const = 0; // Sprawdzenie, czy dotarliśmy do końca
	virtual T &operator* () = 0; // Pobranie bieżącej wartości
	virtual void operator++ () = 0; // Przesunięcie się o jedno miejsce dalej
};

template <typename T>
class Container 
{protected:
    
    Container (){};
 public:
    virtual int Count () const = 0;
    virtual bool IsEmpty () const {return Count()==0;};
    virtual bool IsFull () const = 0;
   	virtual void MakeNull() = 0;
 	virtual void Accept (Visitor<T> & v)=0; 
 };
 
template <typename T>
class Set : public virtual Container<T>
{
protected:
  int count;
  int universeSize;
public:
	Set (int n) : universeSize (n) {}
	int UniverseSize() const {return universeSize;}
	int Count() const {return count;};
	virtual void Insert (T element)=0;
	virtual bool IsMember (T element) const=0;
	virtual void Withdraw (T element)=0;
 };


class SetAsArray : public Set<int>
{
  std::vector<bool> array;
public:
  SetAsArray (unsigned int);
	void MakeNull();//metody z containera
  void Insert (int element);
	bool IsMember (int element) const;
	void Withdraw (int element);
	bool IsFull () const {return (Count()==UniverseSize());};
	void Accept (Visitor<int> & v);
	//friend- funkcja uzyska prawo dostepu do prywatnych elementow danej klasy.

	friend SetAsArray operator + (
												SetAsArray const&, SetAsArray const&);
	friend SetAsArray operator - (
												SetAsArray const&, SetAsArray const&);
  friend SetAsArray operator * (
												SetAsArray const&, SetAsArray const&);
  friend bool operator == (
												SetAsArray const&, SetAsArray const&);
  friend bool operator <= (
												SetAsArray const&, SetAsArray const&);
    
  void Wypisz() const;

	class Iter:public Iterator<int>
	{
		std::vector<bool> data;
		int universeSize;
		int index;
	public:
		Iter(std::vector<bool> array, int us)
		{
				data = array;
				universeSize = us;
				for (int i = 0; i < universeSize; i++)
				{
						if (data[i] == true)
						{
								index = i;
								break;
						}
				}
		};

		~Iter(){};

		int &operator* (){return index;};

		void operator++()
		{
			for (int i = index+1; i < universeSize; i++)
				{
						if (data[i] == true)
						{
							index = i;
							return;
						}
				}
				index = universeSize;
		};
		bool IsDone () const
		{
			return (index == universeSize)?true:false;
		};
	};

	// Potrzebne gettery
	const std::vector<bool>& getArray() const { return array; }
	int getUniverseSize() const { return universeSize; }
};

class Odd_Visitor:public Visitor<int>
{
protected:
	bool IsDone_;
public:
	Odd_Visitor():	IsDone_(false){};
	void Visit(int &element);
	bool IsDone(){return IsDone_;}
};


class Adding_Visitor:public Visitor<int>
{
protected:
	bool IsDone_;
	int sum;
public:
	Adding_Visitor():	IsDone_(false), sum(0) {};
	void Visit(int &element);
	bool IsDone(){return IsDone_;}
	int Sum(){return sum;}
};

