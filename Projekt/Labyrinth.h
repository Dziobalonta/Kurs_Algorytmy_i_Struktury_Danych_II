#ifndef LABYRINTH
#define LABYRINTH
#include "GraphAsMatrix.h"

class Labyrinth
{
private:
  int x;
  int y;
  GraphAsMatrix* graph;
  std::vector<Edge*> labyrinthEdges;

  void generateEdges();
public:
  Labyrinth(int x, int y);
  ~Labyrinth();

  void Print();
};

#endif // LABYRINTH