#include <iostream>
#include "Labyrinth.h"
#include "GraphAsMatrix.h"

using std::cout;
using std::endl;

int main(int argc, char *argv[])
{
  cout << "\033[1;32m ---------- ZMODYFIKOWANY ALGORYTM KRUSKALA ---------- \033[0m" << endl << endl;
  cout << "\033[1;33m A) KRAWĘDZIE JAKO DROGI W LABIRYNCIE \033[0m" << endl << endl;
  int x = std::atoi(argv[1]);
  int y = std::atoi(argv[2]);
  Labyrinth* Labirynt = new Labyrinth(x,y);
  cout << endl;
  
  cout << "\033[1;33m B) WIZUALIZACJA \033[0m" << endl << endl;
  Labirynt->Print();
  
  return 0;
}