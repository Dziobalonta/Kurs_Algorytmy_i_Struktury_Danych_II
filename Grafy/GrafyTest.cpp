#include <iostream>
#include "Edge.h"
#include "Vertex.h"
#include "GraphAsMatrix.h"

using std::cout;
using std::endl;

int main()
{
  cout << "\033[1;32m ---------- GRAFY ---------- \033[0m" << endl << endl;
  cout << "\033[1;33m A) DLA GRAFU SKIEROWANEGO \033[0m" << endl << endl;
  // Utworz Graf skierowany zlozony z 10 wierzcholkow
  // Wypisz, ile jest wierzcholkow
  // Wypisz, ile jest krawedzi 
  GraphAsMatrix Graf1(10,true);
  cout << "Liczba wierzcholkow: " << Graf1.NumberOfVertices() << endl;
  cout << "Liczba krawedzi: " << Graf1.NumberOfEdges() << endl;
  cout << endl;

  Vertex* v1 = Graf1.SelectVertex(2);
  // Wypisz unikalny Numer v
  // Nadaj v wagę unikalnyNumer*UniklanyNumer;
  // Wypisz wage v
  cout << "Unikalny Numer v: " << v1->Number() << endl;
  v1->weight = 7 * 7;
  cout << "Unikalna waga v: " << v1->weight << endl;
  cout << endl;

  Graf1.AddEdge(1,2);
  Graf1.AddEdge(1,2);
  Graf1.AddEdge(2,3);
  Graf1.AddEdge(3,4);
  Graf1.AddEdge(9,9);

  // Wypisz, ile jest wierzcholkow
  // Wypisz, ile jest krawedzi
  // Wypisz, czy istnieje krawedz (1,1)
  // Wypisz, czy istnieje krawedz (1,2)
  // Wypisz, czy istnieje krawedz (2,1)

  cout << "Liczba wierzcholkow: " << Graf1.NumberOfVertices() << endl;
  cout << "Liczba krawedzi: " << Graf1.NumberOfEdges() << endl;
  cout << "Czy istnieje krawedz (1,1): " << (Graf1.IsEdge(1,1) ? "Tak" : "Nie") << endl;
  cout << "Czy istnieje krawedz (1,2): " << (Graf1.IsEdge(1,2) ? "Tak" : "Nie") << endl;
  cout << "Czy istnieje krawedz (2,1): " << (Graf1.IsEdge(2,1) ? "Tak" : "Nie") << endl;
  cout << endl;

  cout << "Krawedz (1,2)" << endl;
  Edge* e1 = Graf1.SelectEdge(1,2);
  // Wypisz V0 dla e
  // Wypisz V1 dla e
  cout << "v0 dla e: " << e1->V0()->Number() << endl;
  cout << "v1 dla e: " << e1->V1()->Number() << endl;

  // Wypisz sasiada (V0) dla e - test metody Mate
  // Wypisz sasiada (V1) dla e - test metody Mate
  cout << "Sasiad (v0) dla e: " << e1->Mate(e1->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e1->Mate(e1->V1())->Number() << endl;

  // Nadaj krawedzi e wagę V0+V1
  // Wypisz wage krawedzi e
  e1->weight = e1->V0()->Number() + e1->V1()->Number();
  cout << "Waga krawedzi e: " << e1->weight << endl;
  cout << endl;

  // Dla kolejnych krawedzi Grafu powtorz ostatnie 7 krokow (e=SelectEdge(2,3),…)
  cout << "Krawedz (2,3)" << endl;
  Edge* e2 = Graf1.SelectEdge(2,3);

  cout << "v0 dla e: " << e2->V0()->Number() << endl;
  cout << "v1 dla e: " << e2->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e2->Mate(e2->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e2->Mate(e2->V1())->Number() << endl;

  e2->weight = e2->V0()->Number() + e2->V1()->Number();
  cout << "Waga krawedzi e: " << e2->weight << endl;
  cout << endl;

  // Krawedz (3,4)
  cout << "Krawedz (3,4)" << endl;
  Edge* e3 = Graf1.SelectEdge(3,4);

  cout << "v0 dla e: " << e3->V0()->Number() << endl;
  cout << "v1 dla e: " << e3->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e3->Mate(e3->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e3->Mate(e3->V1())->Number() << endl;

  e3->weight = e3->V0()->Number() + e3->V1()->Number();
  cout << "Waga krawedzi e: " << e3->weight << endl;
  cout << endl;

  // Krawedz (9,9)
  cout << "Krawedz (9,9)" << endl;
  Edge* e4 = Graf1.SelectEdge(9,9);

  cout << "v0 dla e: " << e4->V0()->Number() << endl;
  cout << "v1 dla e: " << e4->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e4->Mate(e4->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e4->Mate(e4->V1())->Number() << endl;

  e4->weight = e4->V0()->Number() + e4->V1()->Number();
  cout << "Waga krawedzi e: " << e4->weight << endl;
  cout << endl;

  // ITERATORY
  cout << "\033[1;36m ---------- ITERATORY ---------- \033[0m" << endl << endl;
  //Wypisz wszystkie wierzcholki korzystajac z iteratora po wierzcholkach (ich unikalny numer i wage)
  cout << "Wszystkie wierzcholki grafu:" << endl;
  Iterator<Vertex>& iter1_w = Graf1.VerticesIter();
  while(!iter1_w.IsDone())
  {
    cout << *iter1_w << endl;
    ++iter1_w;
  } 
  cout << endl;

  // Dodaj krawedzie: AddEdge(3,5), AddEdge(8,3), AddEdge(5,2)
  Graf1.AddEdge(3,5);
  Graf1.AddEdge(8,3);
  Graf1.AddEdge(5,2);

  // Wypisz wszystkie krawedzie korzystajac z odpowiedniego iteratora 
  // (to znaczy, wypisz pierwszy i drugi wierzcholek krawedzi - v0 i v1)
  Iterator<Edge>& iter1_k = Graf1.EdgesIter();
  while(!iter1_k.IsDone())
  {
    cout << *iter1_k << endl;
    ++iter1_k;
  }
  cout << endl;

  // Wypisz wszystkie krawedzie wychodzace z wierzcholka o numerze 3, korzystajac z odpowiedniego iteratora
  // (to znaczy, wypisz pierwszy i drugi wierzcholek krawedzi - v0 i v1)
  cout << "Wychodzace krawedzie z wierzcholka 3: " << endl;
  Iterator<Edge>& iter1_wych = Graf1.EmanatingEdgesIter(3);
  while(!iter1_wych.IsDone())
  {
    cout << *iter1_wych << endl;
    ++iter1_wych;
  }
  cout << endl;

  // Wypisz wszystkie krawedzie dochodzace do wierzcholka o numerze 2, korzystajac z odpowiedniego iteratora
  // (to znaczy, wypisz pierwszy i drugi wierzcholek krawedzi - v0 i v1)
  cout << "Wchodzace krawedzie do wierzcholka 2: " << endl;
  Iterator<Edge>& iter1_wcho = Graf1.IncidentEdgesIter(2);
  while(!iter1_wcho.IsDone())
  {
    cout << *iter1_wcho << endl;
    ++iter1_wcho;
  }
  cout << endl;

  // Testy prosze powtorzyc tworzac Graf nieskierowany 

  cout << "\033[1;33m B) DLA GRAFU NIESKIEROWANEGO \033[0m" << endl << endl;
  GraphAsMatrix Graf2(10,false);
  cout << "Liczba wierzcholkow: " << Graf2.NumberOfVertices() << endl;
  cout << "Liczba krawedzi: " << Graf2.NumberOfEdges() << endl;
  cout << endl;

  Vertex* v2 = Graf2.SelectVertex(2);

  cout << "Unikalny Numer v: " << v2->Number() << endl;
  v2->weight = 7 * 7;
  cout << "Unikalna waga v: " << v2->weight << endl;
  cout << endl;

  Graf2.AddEdge(1,2);
  Graf2.AddEdge(1,2);
  Graf2.AddEdge(2,3);
  Graf2.AddEdge(3,4);
  Graf2.AddEdge(9,9);

  cout << "Liczba wierzcholkow: " << Graf2.NumberOfVertices() << endl;
  cout << "Liczba krawedzi: " << Graf2.NumberOfEdges() << endl;
  cout << "Czy istnieje krawedz (1,1): " << (Graf2.IsEdge(1,1) ? "Tak" : "Nie") << endl;
  cout << "Czy istnieje krawedz (1,2): " << (Graf2.IsEdge(1,2) ? "Tak" : "Nie") << endl;
  cout << "Czy istnieje krawedz (2,1): " << (Graf2.IsEdge(2,1) ? "Tak" : "Nie") << endl;
  cout << endl;

  cout << "Krawedz (1,2)" << endl;
  Edge* e11 = Graf2.SelectEdge(1,2);

  cout << "v0 dla e: " << e11->V0()->Number() << endl;
  cout << "v1 dla e: " << e11->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e11->Mate(e11->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e11->Mate(e11->V1())->Number() << endl;

  e11->weight = e11->V0()->Number() + e11->V1()->Number();
  cout << "Waga krawedzi e: " << e11->weight << endl;
  cout << endl;

  // Krawedz (2,3)
  cout << "Krawedz (2,3)" << endl;
  Edge* e22 = Graf2.SelectEdge(2,3);

  cout << "v0 dla e: " << e22->V0()->Number() << endl;
  cout << "v1 dla e: " << e22->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e22->Mate(e22->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e22->Mate(e22->V1())->Number() << endl;

  e22->weight = e22->V0()->Number() + e22->V1()->Number();
  cout << "Waga krawedzi e: " << e22->weight << endl;
  cout << endl;

  // Krawedz (3,4)
  cout << "Krawedz (3,4)" << endl;
  Edge* e33 = Graf2.SelectEdge(3,4);

  cout << "v0 dla e: " << e33->V0()->Number() << endl;
  cout << "v1 dla e: " << e33->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e33->Mate(e33->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e33->Mate(e33->V1())->Number() << endl;

  e33->weight = e33->V0()->Number() + e33->V1()->Number();
  cout << "Waga krawedzi e: " << e3->weight << endl;
  cout << endl;

  // Krawedz (9,9)
  cout << "Krawedz (9,9)" << endl;
  Edge* e44 = Graf2.SelectEdge(9,9);

  cout << "v0 dla e: " << e44->V0()->Number() << endl;
  cout << "v1 dla e: " << e44->V1()->Number() << endl;

  cout << "Sasiad (v0) dla e: " << e44->Mate(e44->V0())->Number() << endl;
  cout << "Sasiad (v1) dla e: " << e44->Mate(e44->V1())->Number() << endl;

  e44->weight = e44->V0()->Number() + e44->V1()->Number();
  cout << "Waga krawedzi e: " << e44->weight << endl;
  cout << endl;

  // ITERATORY
  cout << "\033[1;36m ---------- ITERATORY ---------- \033[0m" << endl << endl;

  cout << "Wszystkie wierzcholki grafu:" << endl;
  Iterator<Vertex>& iter2_w = Graf2.VerticesIter();
  while(!iter2_w.IsDone())
  {
    cout << *iter2_w << endl;
    ++iter2_w;
  } 
  cout << endl;

  Graf2.AddEdge(3,5);
  Graf2.AddEdge(8,3);
  Graf2.AddEdge(5,2);

  Iterator<Edge>& iter2_k = Graf2.EdgesIter();
  while(!iter2_k.IsDone())
  {
    cout << *iter2_k << endl;
    ++iter2_k;
  }
  cout << endl;

  // Wychodzace z wierzcholka 3
  cout << "Wychodzace krawedzie z wierzcholka 3: " << endl;
  Iterator<Edge>& iter2_wych = Graf2.EmanatingEdgesIter(3);
  while(!iter2_wych.IsDone())
  {
    cout << *iter2_wych << endl;
    ++iter2_wych;
  }
  cout << endl;

  // Wchodzace z wierzcholka 2
  cout << "Wchodzace krawedzie do wierzcholka 2: " << endl;
  Iterator<Edge>& iter2_wcho = Graf2.IncidentEdgesIter(2);
  while(!iter2_wcho.IsDone())
  {
    cout << *iter2_wcho << endl;
    ++iter2_wcho;
  }
  cout << endl;


  // DFS
  cout << "\033[1;32m ---------- DFS ---------- \033[0m" << endl << endl;

  // Zwykle testy
  cout << "\033[1;33m A) DLA GRAFU NIESKIEROWANEGO \033[0m" << endl << endl;
  GraphAsMatrix* graph1 = new GraphAsMatrix(10,false);
  graph1->AddEdge(0,1);
  graph1->AddEdge(1,2);
  graph1->AddEdge(2,3);
  graph1->AddEdge(3,4);
  graph1->AddEdge(3,7); 
  graph1->AddEdge(4,5);
  graph1->AddEdge(5,9);
  graph1->AddEdge(9,9);
  graph1->AddEdge(6,8);
  graph1->AddEdge(8,6);
  graph1->AddEdge(0,8);
  graph1->AddEdge(5,7);
  graph1->DFS(graph1->SelectVertex(0));
  cout << endl;
  
  // Wizytator testy
  cout << "\033[1;33m B) DLA GRAFU SKIEROWANEGO + WIZYTATOR \033[0m" << endl << endl;
  GraphAsMatrix* graph2 = new GraphAsMatrix(10,true);
  CountingVisitor wizytator_graph2;
  graph2->AddEdge(0,1);
  graph2->AddEdge(1,2);
  graph2->AddEdge(2,3);
  graph2->AddEdge(3,4);
  graph2->AddEdge(3,7); 
  graph2->AddEdge(4,5);
  graph2->AddEdge(5,9);
  graph2->AddEdge(9,9);
  graph2->AddEdge(6,8);
  graph2->AddEdge(8,6);
  graph2->AddEdge(0,8);
  graph2->DFS_visitor(&wizytator_graph2, graph2->SelectVertex(0),true);
  cout << endl;

  cout << "\033[1;32m ---------- SPOJNOSC ---------- \033[0m" << endl << endl;
  cout << "\033[1;33m A) DLA GRAFU NIESKIEROWANEGO \033[0m" << endl << endl;
  GraphAsMatrix * graph3 = new GraphAsMatrix(10,false);
  graph3->AddEdge(0,1);
  graph3->AddEdge(1,2);
  graph3->AddEdge(2,3);
  graph3->AddEdge(3,4);
  graph3->AddEdge(3,7);
  graph3->AddEdge(4,5);
  graph3->AddEdge(5,9);
  graph3->AddEdge(9,9);
  graph3->AddEdge(6,8);
  graph3->AddEdge(8,6);

  bool isConn3 = graph3->IsConnected(false);
  cout << "Czy graf jest spojny: " << (isConn3 ? "Tak" : "Nie") << endl;
  
  graph3->AddEdge(0,8);
  isConn3 = graph3->IsConnected(false);
  cout << "Czy graf jest spojny: " << (isConn3 ? "Tak" : "Nie") << endl;
  cout << endl;

  cout << "\033[1;33m B) DLA GRAFU SKIEROWANEGO \033[0m" << endl << endl;
  GraphAsMatrix * graph4 = new GraphAsMatrix(10,true);
  graph4->AddEdge(0,1);
  graph4->AddEdge(1,2);
  graph4->AddEdge(2,3);
  graph4->AddEdge(3,4);
  graph4->AddEdge(3,7);
  graph4->AddEdge(4,5);
  graph4->AddEdge(5,9);
  graph4->AddEdge(9,9);
  graph4->AddEdge(6,8);
  graph4->AddEdge(8,6);
  graph4->AddEdge(0,8);
  graph4->AddEdge(6,0);
  graph4->AddEdge(9,0);

  bool isConn4 = graph4->IsConnected(false);
  cout << "Czy graf jest spojny: " << (isConn4 ? "Tak" : "Nie") << endl;
  
  graph4->AddEdge(7,0);
  isConn4 = graph4->IsConnected(false);
  cout << "CZy graf jest spojny: " << (isConn4 ? "Tak" : "Nie") << endl << endl;


  cout << "\033[1;32m ---------- DRZEWA ROZPINAJACE ---------- \033[0m" << endl << endl;
  cout << "\033[1;33m A) DLA GRAFU NIESKIEROWANEGO \033[0m" << endl << endl;

  GraphAsMatrix* graph5 = new GraphAsMatrix(10,false);
  graph5->AddEdge(0,1);
  graph5->AddEdge(1,2);
  graph5->AddEdge(2,3);
  graph5->AddEdge(3,4);
  graph5->AddEdge(3,7);
  graph5->AddEdge(4,5);
  graph5->AddEdge(5,9);
  graph5->AddEdge(9,9);
  graph5->AddEdge(6,8);
  graph5->AddEdge(8,6);
  graph5->AddEdge(0,8);
  cout << "\033[1m Dla oryginalnego drzewa: \033[0m" << endl;
  graph5->DFS_Spanning_Tree(graph5->SelectVertex(0));
  cout << endl;

  graph5->AddEdge(3,9);
  graph5->AddEdge(5,7);
  graph5->AddEdge(9,8);
  cout << "\033[1m Dla zmodyfikowanego drzewa: \033[0m" << endl;
  graph5->DFS_Spanning_Tree(graph5->SelectVertex(0));
  cout << endl;

  return 0;
}