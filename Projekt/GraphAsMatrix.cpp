#include <iostream>
#include <vector>
#include <algorithm> // std::shuffle
#include <random> // std::default_random_engine
#include <chrono> // std::chrono::system_clock
#include "GraphAsMatrix.h"

GraphAsMatrix::GraphAsMatrix(int n, bool b): numberOfVertices(n), isDirected(b), vertices(n)
{
  for (int i = 0; i < n; i++)
  {
    vertices[i] = new Vertex(i);
  }

  adjacencyMatrix.resize(n, std::vector<Edge *>(n, nullptr));
}

bool GraphAsMatrix::IsEdge(int u, int v)
{
  return (u >= 0 && u < numberOfVertices && v >= 0 && v < numberOfVertices && adjacencyMatrix[u][v] != nullptr);
}

void GraphAsMatrix::MakeNull() 
{
  //Krawedzie
  for(auto &row : adjacencyMatrix) 
  {
    for(auto &edge : row) 
    {
      delete edge;
      edge = nullptr; // dla pewnosci
    }
  }
  numberOfEdges = 0;

  //Wierzcholki
  for (auto &vertex: vertices)
  {
    delete vertex;
    vertex = nullptr; // dla pewnosci
  }
}

void GraphAsMatrix::AddEdge(int u, int v)
{
  if(u >= 0 && u < numberOfVertices && v >= 0 && v < numberOfVertices)
  {
    Edge* krawedz = new Edge(vertices[u],vertices[v]);
    if (adjacencyMatrix[u][v] == nullptr)
    {
      adjacencyMatrix[u][v] = krawedz;
      numberOfEdges++;
    }

    // Przypadek gdy jest nieskierowany - "duplikujemy wartosc" po drugiej stronie macierzy
 if (!isDirected && adjacencyMatrix[v][u] == nullptr)
    {
      adjacencyMatrix[v][u] = krawedz;
    }
  }
}

void GraphAsMatrix::DeleteEdge(int u, int v)
{
  if(u >= 0 && u < numberOfVertices && v >= 0 && v < numberOfVertices)
  {
    if(adjacencyMatrix[u][v] != nullptr)
    {
      delete adjacencyMatrix[u][v];
      adjacencyMatrix[u][v] = nullptr;
      numberOfEdges--;
    }

    // Przypadek gdy jest nieskierowany - "usuń wartość" po drugiej stronie macierzy
    if (!isDirected && adjacencyMatrix[v][u] != nullptr)
    {
      adjacencyMatrix[v][u] = nullptr;
    }
  }
}

Edge* GraphAsMatrix::SelectEdge(int u, int v)
{
    if(u >= 0 && u < numberOfVertices && v >= 0 && v < numberOfVertices) 
      return adjacencyMatrix[u][v];
    else 
      return nullptr;
}

Vertex* GraphAsMatrix::SelectVertex(int v)
{
  if(v >= 0 && v < numberOfVertices) return vertices[v];
  else throw std::out_of_range("Vertex index is out of range");
}

void GraphAsMatrix::PrintAdjMat(int size)
{
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      if (adjacencyMatrix[i][j] != nullptr) std::cout << "1" << " ";
       else std::cout << adjacencyMatrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

std::vector<Edge*> GraphAsMatrix::KruskalModified()
{
  // Tworzymy wektor wszystkich krawędzi
  std::vector<Edge*> allEdges;
  for(auto &row : adjacencyMatrix) 
  {
    for(auto &edge : row) 
    {
      if (edge != nullptr)
      {
        allEdges.push_back(edge);
      }
    }
  }

  // Losowo tasujemy krawedzie -  zamiast po wadze
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(allEdges.begin(), allEdges.end(), std::default_random_engine(seed));

  // Tworzymy strukture zbiorow rozlacznych - kazdy wierzcholek to osobny zbior
  std::vector<int> parent(numberOfVertices);
  for (int i = 0; i < numberOfVertices; i++) 
  { 
    parent[i] = i;
  }

  // Tworzymy drzewo rozpinajace
  std::vector<Edge*> spanningTree;
  for (auto &edge : allEdges)
  {
    int u = edge->V0()->Number();
    int v = edge->V1()->Number();

    // Szukanie poddrzewa kazdego z wierzcholkow
    int set_u = FindSet(u, parent);
    int set_v = FindSet(v, parent);

    if (set_u != set_v)
    {
      spanningTree.push_back(edge);
      Union(set_u, set_v, parent);
    }
  }
  return spanningTree;
}

int GraphAsMatrix::FindSet(int i, const std::vector<int> &parent)
{
  if (i == parent[i])
  {
    return i;
  }
  else
  {
    return FindSet(parent[i], parent);
  }
}

void GraphAsMatrix::Union(int u, int v, std::vector<int> &parent)
{
  int set_u = FindSet(u, parent);
  int set_v = FindSet(v, parent);

  if (set_u != set_v)
  {
    parent[set_v] = set_u;
  }
}
