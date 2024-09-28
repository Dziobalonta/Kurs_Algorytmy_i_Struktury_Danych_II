#include <iostream>
#include "Labyrinth.h"
#include "GraphAsMatrix.h"
#include "Edge.h"

Labyrinth::Labyrinth(int x, int y): x(x), y(y)
{
  graph = new GraphAsMatrix(x*y ,false);

  generateEdges();
  labyrinthEdges = graph->KruskalModified();

  for (auto &edge: labyrinthEdges)
  {
    std::cout << *edge << std::endl;
    graph->DeleteEdge(edge->V0()->Number(), edge->V1()->Number());
  }
}

void Labyrinth::generateEdges()
{
  for (int i = 0; i < y; i++) // Przechodzimy przez wszystkie rzędy
  {
    for (int j = 0; j < x; j++) // Przechodzimy przez wszystkie kolumny
    {
      int actual_iter = i*x + j; // Obliczamy aktualny indeks

      // Nad nim
      if (i > 0)
        graph->AddEdge(actual_iter, actual_iter-x);
      // Pod nim
      if (i < y-1)
        graph->AddEdge(actual_iter, actual_iter+x);
      // Na lewo
      if (j > 0)
        graph->AddEdge(actual_iter, actual_iter-1);
      // Na prawo
      if (j < x-1)
        graph->AddEdge(actual_iter, actual_iter+1);
    }
  }
}

void Labyrinth::Print()
{
  // Printowanie macierzy sasiedztwa
  // graph->PrintAdjMat(x*y);

  int rows = 2*y-1;
  int cols = 2*x-1;
  int vertCount = -1, vertCount2 = -1;
  // Tworzymy macierz, która będzie przechowywać labirynt
  std::vector<std::vector<std::string>> maze(rows, std::vector<std::string>(cols, "   "));

  // Ustawiamy ściany labiryntu
  for (int i = 0; i < rows; i++)
  {
    for (int j = 0; j < cols; j++)
    {
      if (i % 2 == 0 && j % 2 == 0) 
      {
        vertCount++;
        maze[i][j] = "+";
      }else
      if (i % 2 == 0)
      {
        if (!graph->IsEdge(vertCount, vertCount+1) && !graph->IsEdge(vertCount+1, vertCount))
        {
          maze[i][j] = "---";
        }
      } else if (j % 2 == 0)
      {
        vertCount2++;
        if (!graph->IsEdge(vertCount2, vertCount2 + x) && !graph->IsEdge(vertCount2 + x, vertCount2))
        {
          maze[i][j] = "|";
        } else maze[i][j] = " ";
      }
    }
  }
  // Wypisujemy labirynt
  for (const auto &row : maze)
  {
    for (const auto &cell : row)
    {
      std::cout << cell;
    }
    std::cout << std::endl;
  }
}

Labyrinth::~Labyrinth()
{
  delete graph;
}