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

	// �Aqu� agrego el destructor para liberar la memoria que ped� con 'new'!
	
	~HashTableChaining()
	{
		delete[] data;
	}

	// Funci�n Hash
	int HashFunction(T key)
	{
		return key % arraySize;
	}

	// Metodos (con las correcciones)
	//  le agregu� la palabra 'virtual' para que la herencia funcione bien.
	virtual void Add(T element)
	{
		int index = HashFunction(element);
		data[index].push_front(element);
	}

	// Tambi�n hice 'virtual' esta funci�n por si quiero cambiarla en el futuro.
	virtual void Remove(T element)
	{
		int index = HashFunction(element);
		forward_list<T>& listAtIndex = data[index];
		// La funci�n de la lista hace la b�squeda y borra el elemento por m�.
		listAtIndex.remove(element);
	}

	// Y tambi�n hago 'virtual' la funci�n de b�squeda.
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
			cout << "lista del �ndice: " << std::to_string(i) << ": ";
			for (auto j : data[i])
				cout << j << ", ";
			cout << endl;
		}
	}
};


void HashTableChainingExample();