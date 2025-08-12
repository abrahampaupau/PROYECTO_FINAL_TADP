#pragma once

#include <iostream>
#include <forward_list>
#include <string>
using namespace std;


template <typename T>
class HashTableChaining
{
	// un lugar donde almacenar los datos
	forward_list<T>* data;
	unsigned int arraySize;

public:

	HashTableChaining(unsigned int size)
	{
		// pedimos memoria para nuestras N listas.
		data = new forward_list<T>[size];
		arraySize = size;
	}

	// ¡Aquí agrego el destructor para liberar la memoria que pedí con 'new'!
	
	~HashTableChaining()
	{
		delete[] data;
	}

	// Función Hash
	int HashFunction(T key)
	{
		return key % arraySize;
	}

	// Metodos (con las correcciones)
	//  le agregué la palabra 'virtual' para que la herencia funcione bien.
	virtual void Add(T element)
	{
		int index = HashFunction(element);
		data[index].push_front(element);
	}

	// También hice 'virtual' esta función por si quiero cambiarla en el futuro.
	virtual void Remove(T element)
	{
		int index = HashFunction(element);
		forward_list<T>& listAtIndex = data[index];
		// La función de la lista hace la búsqueda y borra el elemento por mí.
		listAtIndex.remove(element);
	}

	// Y también hago 'virtual' la función de búsqueda.
	virtual bool Contains(T element)
	{
		int index = HashFunction(element);
		forward_list<T>& listAtIndex = data[index];
		for (auto i : listAtIndex)
		{
			if (i == element)
			{
				return true;
			}
		}
		return false;
	}

	void Print()
	{
		for (int i = 0; i < arraySize; i++)
		{
			cout << "lista del índice: " << std::to_string(i) << ": ";
			for (auto j : data[i])
				cout << j << ", ";
			cout << endl;
		}
	}
};


void HashTableChainingExample();