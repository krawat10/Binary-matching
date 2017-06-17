﻿//// Kojarzenie małżeństw
//// Data: 23.12.2013
//// (C)2013 mgr Jerzy Wałaszek
////----------------------------------------
//
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <queue>
//
//using namespace std;
//
//// Typy dla dynamicznej tablicy list sąsiedztwa i kolejki
//
//struct slistEl
//{
//	slistEl * next;
//	int v;
//};
//
//
//int main()
//{
//	int n, m, i, v, x, y, *matching, *augment;
//	slistEl * p, *r, ** graf;
//	bool * visited, *color;
//	queue<int> Q;
//	ifstream in("in.txt");
//	streambuf *cinbuf = std::cin.rdbuf();
//	cin.rdbuf(in.rdbuf());
//	cin >> n >> m;                // Czytamy liczbę wierzchołków i krawędzi
//
//								  // Tworzymy zmienne dynamiczne
//
//	color = new bool[n];       // Kawalerowie (true), panny (false)
//	matching = new int[n];        // Skojarzenia
//	augment = new int[n];        // Ścieżka rozszerzająca
//	visited = new bool[n];       // Odwiedziny
//	graf = new slistEl *[n]; // Tworzymy tablicę list sąsiedztwa
//
//							 // Tablicę wypełniamy pustymi listami
//
//	for (i = 0; i < n; i++) graf[i] = NULL;
//
//	// Odczytujemy kolejne definicje krawędzi
//	int numberOfBikesForOnePerson;
//	int bikeIndex;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> numberOfBikesForOnePerson;
//
//
//		for (int j = 0; j < numberOfBikesForOnePerson; j++)
//		{
//			cin >> bikeIndex;
//			bikeIndex += n;
//			p = new slistEl;            // Tworzymy nowy element
//			p->v = bikeIndex;                   // Numerujemy go jako kawaler
//			p->next = graf[i];          // Dodajemy go na początek listy panny
//			graf[i] = p;
//			p = new slistEl;            // Tworzymy nowy element
//			p->v = i;                   // Numerujemy go jako pannę
//			p->next = graf[bikeIndex];          // Dodajemy go na początek listy kawalera
//			graf[bikeIndex] = p;
//			color[i] = false;           // Panna
//			color[bikeIndex] = true;            // Kawaler
//		}
//	}
//
//	cout << endl;
//
//	// Algorytm znajdowania maksymalnego skojarzenia
//
//	for (i = 0; i < n; i++)        // Elementy tablicy matching ustawiamy na -1
//		matching[i] = -1;           // Co oznacza brak skojarzenia
//
//	for (v = 0; v < n; v++)        // Przechodzimy przez kolejne wierzchołki
//		if ((matching[v] == -1) && !color[v])
//		{
//			for (i = 0; i < n; i++)
//				visited[i] = false;     // Zerujemy tablicę odwiedzin
//
//			while (!Q.empty()) Q.pop();// Zerujemy kolejkę
//
//			visited[v] = true;        // Oznaczamy v jako wierzchołek odwiedzony
//			augment[v] = -1;          // Poprzednikiem v jest korzeń drzewa rozpinającego
//			Q.push(v);                // Umieszczamy v w kolejce
//
//			while (!Q.empty())         // Uruchamiamy BFS
//			{
//				x = Q.front();          // Pobieramy x z kolejki
//				Q.pop();                // Pobrany wierzchołek usuwamy z kolejki
//
//				if (color[x])
//				{                       // Kawalerowie
//					if (matching[x] == -1)
//					{                     // Kawaler wolny
//						while (augment[x] > -1)
//						{
//							if (color[x])
//							{                 // Zamieniamy krawędzie skojarzone z nieskojarzonymi
//								matching[x] = augment[x];
//								matching[augment[x]] = x;
//							}
//							x = augment[x];   // Cofamy się po ścieżce rozszerzającej
//						}
//						break;              // Wracamy do pętli głównej
//					}
//					else
//					{                     // Kawaler skojarzony
//						augment[matching[x]] = x;
//						visited[matching[x]] = true;
//						Q.push(matching[x]);// W kolejce umieszczamy skojarzoną pannę
//					}
//				}
//				else
//				{                       // Panny
//					p = graf[x];          // Przeglądamy kawalerów
//					while (p)
//					{
//						y = p->v;           // Numer kawalera
//						if (!visited[y])     // Tylko kawalerowie nieskojarzeni
//						{                   // są umieszczani w kolejce
//							visited[y] = true;
//							augment[y] = x;   // Tworzymy ścieżkę rozszerzającą
//							Q.push(y);
//						}
//						p = p->next;
//					}
//				}
//			}
//		}
//
//	// Wyświetlamy skojarzenia panna --- kawaler
//
//	for (i = 0; i < n; i++)
//		if (!color[i]) cout << i << " --- " << matching[i] << endl;
//
//	// Usuwamy dynamiczne struktury danych
//
//	delete[] color;
//	delete[] matching;
//	delete[] augment;
//	delete[] visited;
//
//	for (i = 0; i < n; i++)
//	{
//		p = graf[i];
//		while (p)
//		{
//			r = p;
//			p = p->next;
//			delete r;
//		}
//	}
//
//	delete[] graf;
//
//	return 0;
//}