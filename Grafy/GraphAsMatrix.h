#ifndef GRAPH_AS_MATRIX
#define GRAPH_AS_MATRIX

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "Iterator.h"
#include "Visitor.h"

class CountingVisitor: public Visitor<Vertex>
{
private:
  int count;
public:
  CountingVisitor() : count(0) {}
  void Visit(Vertex& v) {count++;}
  int getCount() const {return count;}
  void resetCount(){count = 0;}
};

class GraphAsMatrix
{
 std::vector<Vertex*> vertices;
 std::vector< std::vector<Edge*> > adjacencyMatrix;
 bool isDirected;
 int numberOfVertices;
 int numberOfEdges = 0;

 class AllVerticesIter: public Iterator<Vertex>
  {
    GraphAsMatrix & owner;
    int current;

  public:
    AllVerticesIter(GraphAsMatrix &owner) :owner(owner), current(0) {}
    bool IsDone()
    {
      return (current >= owner.numberOfVertices);
    }
    Vertex & operator*()
    {
      return *(owner.vertices[current]);
    }
    void operator++() {current++;}
  };

  class AllEdgesIter: public Iterator<Edge>
  {
    GraphAsMatrix & owner;
    int row;
    int col;

  public:
    AllEdgesIter(GraphAsMatrix &owner):owner(owner),row(0), col(-1) {next();}

    void next()
    {
      do
      {
        if (++col>= owner.numberOfVertices)
        {
          col = 0;
          if (++row >= owner.numberOfVertices) return;
        }
      } while(owner.adjacencyMatrix[row][col] == nullptr);
    }

    bool IsDone()
    {
      return (row >= owner.numberOfVertices);
    }

    Edge & operator*()
    {
      return *(owner.adjacencyMatrix[row][col]);
    }

    void operator++() {next();}
  };

  class EmanEdgesIter: public Iterator<Edge> // wychodzace z wierzcholka
  {
    GraphAsMatrix & owner;
    int row;
    int col;
  public:
    EmanEdgesIter(GraphAsMatrix &owner,int v):owner(owner),row(v), col(-1) {next();}
    
    void next()
    {
      do
      {
        if (++col >= owner.numberOfVertices) return;
      } while(owner.adjacencyMatrix[row][col] == nullptr);
    }
    
    bool IsDone() {return (col >= owner.numberOfVertices);}

    Edge & operator*()
    {
      return *(owner.adjacencyMatrix[row][col]);
    }
    void operator++(){next();}

  };
  class InciEdgesIter: public Iterator<Edge> // wchodzace z wierzcholka
  {
    GraphAsMatrix & owner;
    int row;
    int col;

  public:
    InciEdgesIter(GraphAsMatrix &owner,int v):owner(owner),row(-1), col(v) {next();}

    void next()
    {
      do
      {
        if (++row >= owner.numberOfVertices) return;
      } while(owner.adjacencyMatrix[row][col] == nullptr);
    }

    bool IsDone(){return (row >= owner.numberOfVertices);}

    Edge & operator*()
    {
      return *(owner.adjacencyMatrix[row][col]);
    }

    void operator++(){next();}
  };

public:
  GraphAsMatrix(int n, bool b);
  int NumberOfVertices()  {return numberOfVertices;}
  bool IsDirected()  {return isDirected;}
  int NumberOfEdges()  {return numberOfEdges;}
  bool IsEdge(int u, int v);
  void MakeNull();
  void AddEdge (int u, int v);
  Edge* SelectEdge (int u, int v);
  Vertex* SelectVertex(int v);
  bool IsConnected(bool showProcess);


  Iterator<Vertex>& VerticesIter() {return *(new AllVerticesIter(*this));}
  Iterator<Edge>& EdgesIter()  {return *(new AllEdgesIter(*this));}
  Iterator<Edge>& EmanatingEdgesIter(int v) {return *(new EmanEdgesIter(*this,v));}
  Iterator<Edge>& IncidentEdgesIter(int v) {return *(new InciEdgesIter(*this,v));}

  void DFS(Vertex* v);
  void DFS1(Vertex *v, std::vector<bool> & visited);
  void DFS_visitor(CountingVisitor *visitor, Vertex *v, bool showProcess);
  void DFS1_visitor(CountingVisitor * visitor, Vertex *v, std::vector<bool> & visited, bool showProcess);

  void DFS_Spanning_Tree(Vertex * v);
  void DFS_Spanning_Tree_1(Vertex *v, std::vector<bool> & visited,
std::vector<int> & parent);

};

#endif // GRAPH_AS_MATRIX