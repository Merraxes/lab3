// Kontenery
#include <vector>	// Tablica
#include <set>		// Zbiór
#include <map>		// Słownik

// Adaptery
#include <queue>	// Kolejka
#include <stack>	// Stos

#include <iostream>
#include <stdio.h>
#include <cstdlib>

#include "Slav.h"

#define REPORT_ADAPTERS showMeAdapterSizes(queueOfSlavs,stackOfSlavs)
#define REPORT_CONTAINERS showMeContainerSizes(vectorOfSlavs,setOfSlavs,mapOfSlavs)

using namespace std;

void showMeContainerSizes(vector <Slav *>, set <Slav *>, map <Slav *, Slav*>);
void showMeAdapterSizes(queue <Slav *>, stack <Slav *>);

void containers(Slav *, int);
void adapters(Slav *, int);

int main(int argc, char const *argv[])
{
	int n = 2 * atoi(argv[1]);
	Slav *slavs = new Slav[n];
	cout << "# Generated Slavs" << endl;
	for (int i = 0; i < n; ++i)
		cout << slavs[i].description() << endl;

	containers(slavs, n);
	adapters(slavs, n);

	delete [] slavs;
}

void containers(Slav * slavs, int n)
{
	vector <Slav *> vectorOfSlavs;
	set <Slav *> setOfSlavs;
	map <Slav *, Slav *> mapOfSlavs;

	printf("# Containers\n");
	REPORT_CONTAINERS;
	printf("## vector\n");

	vectorOfSlavs.push_back(NULL);
	for (int i=0; i<n; ++i)
	{
		int where=rand () % (vectorOfSlavs.size());
		vectorOfSlavs.insert(vectorOfSlavs.begin()+ where , (slavs+i));
	}
		vectorOfSlavs.pop_back();
	// Umieść Słowian w losowej kolejności w wektorze.


	for(vector<Slav *>::iterator it=vectorOfSlavs.begin(); it!=vectorOfSlavs.end(); ++it)
		cout << (**it).description() <<endl;
	// Wykorzystując iterator i funkcję description(), wyświetl wszystkich Słowian w wektorze

	REPORT_CONTAINERS;
	printf("## set\n");

	for (int i=0; i<n; ++i)
	{
		setOfSlavs.insert(vectorOfSlavs.back());
		vectorOfSlavs.pop_back();

	}
	// Przenieś wszystkich Słowian z wektoru do zbioru.

	REPORT_CONTAINERS;
	printf("## map\n");

	for(set<Slav *>::iterator it=setOfSlavs.begin(); it!=setOfSlavs.end(); ++it)
		mapOfSlavs[*it]=*(++it);
	setOfSlavs.clear();
	// Stwórz słownik tworzący pary Słowian, z tych znajdujących się w zbiorze, czyszcząc zbiór
	for(map<Slav *, Slav *>::iterator it_map=mapOfSlavs.begin(); it_map!=mapOfSlavs.end(); ++it_map)
		cout<<(*(*it_map).first).description()<<" "<<(it_map->second)->description()<<endl;

	// Wykorzystując iterator, wyświetl wszystkie pary Słowian

	REPORT_CONTAINERS;
}

void adapters(Slav * slavs, int n)
{
	queue <Slav *> queueOfSlavs;
	stack <Slav *> stackOfSlavs;

	printf("# Adapters\n");
	REPORT_ADAPTERS;
	printf("## queue\n");

	for (int i=0; i<n; ++i)
		queueOfSlavs.push(slavs+i);
	// Umieść Słowian w kolejce.

	REPORT_ADAPTERS;

	printf("## stack\n");

	for (int i=0; i<n; ++i)
	{
		stackOfSlavs.push(queueOfSlavs.front());
		queueOfSlavs.pop();
	}
	// Przenieś Słowian z kolejki do stosu.

	REPORT_ADAPTERS;

	for (int i=0; i<n; ++i)
	{
		cout<<(*(stackOfSlavs.top())).description()<< endl;
		stackOfSlavs.pop();
	}
	// Wyświetl Słowian zdejmowanych ze stosu.

	REPORT_ADAPTERS;
}

void showMeContainerSizes(vector <Slav *> vector, set <Slav *> set, map <Slav *, Slav*> map)
{
	printf("[vector_size = %u, set_size = %u, map_size = %u, existingSlavs = %i]\n",
		vector.size(),
		set.size(),
		map.size(),
		Slav::counter());
}

void showMeAdapterSizes(queue <Slav *> queue, stack <Slav *> stack)
{
	printf("[queue_size = %u, stack_size = %u, existingSlavs = %i]\n",
		queue.size(),
		stack.size(),
		Slav::counter());

}
