#ifndef EDGE
#define EDGE

#include <iostream>
#include "Vertex.h"

class Edge
{
protected:
  Vertex* v0;
  Vertex* v1;
public:
  int weight;
  std::string label;
  Edge(Vertex *V0, Vertex* V1);
  Vertex* V0()  {return v0;};
  Vertex* V1()  {return v1;};
  Vertex* Mate(Vertex *v);
    friend std::ostream& operator<<(std::ostream& os, Edge& e) {
    os << "v0: " << e.V0()->Number() << ", v1: " << e.V1()->Number() << ", waga: " << e.weight;
    return os;
  }
};

#endif // EDGE