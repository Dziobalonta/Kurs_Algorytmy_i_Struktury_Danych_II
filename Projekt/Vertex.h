#ifndef VERTEX
#define VERTEX

#include <iostream>

class Vertex
{
  int number;
public:
  int weight;
  std::string label;
  Vertex(int n) {number = n;}
  int Number() const  {return number;}
  friend std::ostream& operator<<(std::ostream& os, const Vertex& v) {
    os << "Numer wierzcholka: " << v.Number() << ", Waga wierzcholka: " << v.weight;
    return os;
  }
};

#endif // VERTEX