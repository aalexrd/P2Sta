#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

int main()
{
	Stack<int> intStack;
	cout << "Cargando bateria...\n";
	for (int i = 0; i < 100; i++) // Charge battery
		intStack.push(i);
	cout << "La bateria tiene un nivel de: " << intStack.size();
	cin.get();
	while (!intStack.empty())
		cout << "Nivel de Bateria: " << intStack.top()->getData() << endl;
	cin.get();
	return 0;
}
