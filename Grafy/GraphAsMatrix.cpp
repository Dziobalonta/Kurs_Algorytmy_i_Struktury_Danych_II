#include <iostream>
#include <vector>
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

bool GraphAsMatrix::IsConnected(bool showProcess)
{
  if (!IsDirected())
  {
    CountingVisitor visitor;
    DFS_visitor(&visitor,SelectVertex(0),showProcess);
    return visitor.getCount() == numberOfVertices;
  } 
  else
  {
    for (int i = 0; i < numberOfVertices; i++)
    {
      CountingVisitor visitor;
      DFS_visitor(&visitor,SelectVertex(i),showProcess);
      if (visitor.getCount() != numberOfVertices)
      {
        return false;
      }
    }
    return true;
  }
}

void GraphAsMatrix::DFS(Vertex *v)
{
  std::vector<bool> visited(numberOfVertices, false);

  //DFS1(vertices[v->Number()],visited);
  
  for(Edge* e: adjacencyMatrix[v->Number()])
  {
    if (e != nullptr && !visited[e->V0()->Number()])
    {
      DFS1(vertices[e->V0()->Number()],visited);
    } 
  }

  // for(int i = 0; i < numberOfVertices; i++)
  // {
  //   if (!visited[i])
  //   {
  //     DFS1(vertices[i],visited);
  //   } 
  // }
}

void GraphAsMatrix::DFS_visitor(CountingVisitor *visitor, Vertex *v, bool showProcess)
{
  std::vector<bool> visited(numberOfVertices, false);

  //DFS1(vertices[v->Number()],visited);

  for(Edge* e: adjacencyMatrix[v->Number()])
  {
    if (e != nullptr && !visited[e->V0()->Number()])
    {
      DFS1_visitor(visitor,vertices[e->V0()->Number()], visited, showProcess);
    } 
  }

  for(int i = 0; i < numberOfVertices; i++)
  {
    if (!visited[i])
    {
      DFS1(vertices[i],visited);
    } 
  }
}

void GraphAsMatrix::DFS1(Vertex *v, std::vector<bool> &visited)
{
  std::cout << *v << " — Zostal odwiedzony!" << std::endl;
  visited[v->Number()] = true;

  for (int i = 0; i < numberOfVertices; i++)
  {
    if (adjacencyMatrix[v->Number()][i] != nullptr && !visited[i])
    {
      DFS1(vertices[i],visited);
    } 
  }
}

void GraphAsMatrix::DFS1_visitor(CountingVisitor *visitor, Vertex *v, std::vector<bool> &visited, bool showProcess)
{
  visitor->Visit(*v);
  if (showProcess == true)
    {std::cout << *v << " — Zostal odwiedzony! " << "Licznik:  " << visitor->getCount() << std::endl;}
  visited[v->Number()] = true;

  for (int i = 0; i < numberOfVertices; i++)
  {
    if (adjacencyMatrix[v->Number()][i] != nullptr && !visited[i])
    {
      DFS1_visitor(visitor, vertices[i], visited, showProcess);
    } 
  }
}

void GraphAsMatrix::DFS_Spanning_Tree(Vertex *v)
{
  if (this->IsConnected(false))
  {
    std::vector<bool> visited(numberOfVertices,false);
    std::vector<int> parent(numberOfVertices,0);
    parent[v->Number()] = -1; // brak rodzica

    for(Edge* e: adjacencyMatrix[v->Number()])
    {
      if (e != nullptr && !visited[e->V0()->Number()])
      {
        DFS_Spanning_Tree_1(vertices[e->V0()->Number()], visited, parent);
      } 
    }
  } else std::cout << "Graf nie jest spojny! Nie mozna utworzyc drzewa rozpinajacego!" << std::endl;
  
}

void GraphAsMatrix::DFS_Spanning_Tree_1(Vertex *v, std::vector<bool> &visited, std::vector<int> &parent)
{
  std::cout << "Odwiedzono wierzchołek: " << v->Number() << ", Parent: "<< parent[v->Number()]<< std::endl;
  visited[v->Number()] = true;
  for (int i = 0; i < numberOfVertices; i++)
  {
    if (adjacencyMatrix[v->Number()][i] != nullptr && !visited[i])
    {
      parent[i] = v->Number();
      DFS_Spanning_Tree_1(vertices[i],visited,parent);
    } 
  }
}
