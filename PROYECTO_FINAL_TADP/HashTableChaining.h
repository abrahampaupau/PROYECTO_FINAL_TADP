#pragma once

#include <iostream>
#include <forward_list> 
#include <string>
#include <vector> // Agregamos el vector para que la clase funcione correctamente
using namespace std;


template <typename T>
class HashTableChaining
{
public:
    // Constructor
    HashTableChaining(unsigned int size)
    {
        data.resize(size);
        this->size = size;
    }

    // Hacemos que la funcion Add sea virtual, como lo pidió tu profesor.
     // AQUI ESTA LA CORRECCION IMPORTANTE PARA EL OVERRIDE
    virtual void Add(T element)
    {
        int index = HashFunction(element);
        data[index].push_front(element);
    }
    
    // AQUI ESTA LA CORRECCION IMPORTANTE PARA EL OVERRIDE
    // Hacemos que la funcion Remove sea virtual.
    virtual void Remove(T element)
    {
        int index = HashFunction(element);
        forward_list<T>& listAtIndex = data[index];
        listAtIndex.remove(element);
    }

    // Hacemos que la funcion Contains sea virtual.
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
        for (size_t i = 0; i < data.size(); i++)
        {
            cout << "lista del indice: " << i << ": ";
            for (auto element : data[i])
            {
                cout << element << ", ";
            }
            cout << endl;
        }
    }

protected:
    // Hash function
    int HashFunction(T element)
    {
        hash<T> hasher;
        return hasher(element) % size;
    }

    vector<forward_list<T>> data;
    unsigned int size;
};