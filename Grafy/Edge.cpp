#include <stdexcept> // Naglowek dla std::invalid_argument
#include "Edge.h"

Edge::Edge(Vertex* V0, Vertex* V1): v0(V0), v1(V1) {}

Vertex* Edge::Mate(Vertex *v)
{
  if(v->Number() == v0->Number()) return v1;
  else if(v->Number() == v1->Number()) return v0;
  else throw std::invalid_argument("Input vertex is not part of the edge");
}