#include <iostream>
#include <fstream>

#include "Header.h"

using namespace std;

int main()
{
	int numberOfPeople, numberOfBikes, numberOfPeaks, i;
	numberOfPeaks;
	scanf_s("%d", &numberOfPeople);
	scanf_s("%d", &numberOfBikes);
	numberOfPeaks = numberOfPeople + numberOfBikes;


	//Additional index_queueueue
	queue *index_queue = new queue();

	// type of [i] edge. True - person, False - bike
	bool *isBike = (bool*)malloc(sizeof(bool)* numberOfPeaks);

	//index = specific edge, value - number of matched edge
	int *matched = (int*)malloc(sizeof(int)* numberOfPeaks);

	//additional table
	int *extend = (int*)malloc(sizeof(int)* numberOfPeaks);

	//array which checking that peak was visited
	bool *isVisited = (bool*)malloc(sizeof(bool)* numberOfPeaks);
	
	//main representatnion of graph
	stack **graph = new stack*[numberOfPeaks];
	
	for (i = 0; i < numberOfPeaks; i++) graph[i] = new stack();

	int numberOfBikesForOnePerson;
	int bikeIndex;
	stack *buffer = new stack();
	int j, s, y;
	for (i = 0; i < numberOfPeople; i++)
	{
		//get number of preffered bikes for 'i' person
		scanf_s("%d", &numberOfBikesForOnePerson);

		for (j = 0; j < numberOfBikesForOnePerson; j++)
		{
			//creating edges
			scanf_s("%d", &bikeIndex);
			//bike offset
			bikeIndex += numberOfPeople - 1;
			graph[i]->push(bikeIndex);				
			isBike[i] = false;     
			graph[bikeIndex]->push(i);		   
			isBike[bikeIndex] = true;            
		}
	}


	for (i = 0; i < numberOfPeaks; i++)
		matched[i] = -1;           
	for (i = 0; i < numberOfPeaks; i++)
		isVisited[i] = false;
	
	int current_queue_item;
	int matchedPeople = 0;
	stack *visible_peaks = new stack();
	int numberOfVisiblePeaks;
	for (int v = 0; v < numberOfPeople; v++)
	{
		if (matched[v] == -1)
		{
			numberOfVisiblePeaks = visible_peaks->size();

			for (i = 0; i < numberOfVisiblePeaks; i++)
			{				
				isVisited[visible_peaks->at(i)] = false;
			}
			visible_peaks->setSize(0);			
			index_queue->refresh();
			isVisited[v] = true;
			visible_peaks->push(v);
			extend[v] = -1;
			index_queue->push(v);
			while (!index_queue->empty())
			{
				current_queue_item = index_queue->front();
				index_queue->pop();
				if (!isBike[current_queue_item])
				{
					int count = graph[current_queue_item]->size();
					
					for (s = 0; s < count; s++)
					{
						y = graph[current_queue_item]->at(s);
						//if not, that mean we have to find other bike
						if (!isVisited[y])
						{
							//Creating all posibble connection with person
							isVisited[y] = true;
							visible_peaks->push(y);
							extend[y] = current_queue_item;
							index_queue->push(y);
						}
					}
				}
				//condition for bikes
				else
				{
					//if bike is matched by other person (force to change connection in other person by isVisible)
					if (matched[current_queue_item] != -1)
					{
						extend[matched[current_queue_item]] = current_queue_item;
						isVisited[matched[current_queue_item]] = true;
						visible_peaks->push(matched[current_queue_item]);
						index_queue->push(matched[current_queue_item]);
					}
					//if free bike (after adding items to queue)
					else
					{
						while (extend[current_queue_item] > -1)
						{
							if (isBike[current_queue_item])
							{
								//matching
								matched[current_queue_item] = extend[current_queue_item];
								matched[extend[current_queue_item]] = current_queue_item;
							}
							current_queue_item = extend[current_queue_item];
						}
						break;
					}

				}

			}
		}
		if (matched[v] != -1)
			matchedPeople++;
	}

	free(isBike);
	free(matched);
	free(extend);
	free(isVisited);
	delete [] graph;
	delete visible_peaks;
	delete index_queue;

	cout << matchedPeople;


	return 0;
}