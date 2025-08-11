#pragma once


#include "HashTableChaining.h"

// La clase HashSet hereda p�blicamente de HashTableChaining
template <typename T>
class HashSet : public HashTableChaining<T>
{
public:
    // El constructor de HashSet simplemente llama al constructor de la clase base.
    HashSet(unsigned int size) : HashTableChaining<T>(size) {}

    // Sobrescribimos el m�todo Add para que no permita duplicados.
    void Add(T element)
    {
        // Antes de agregar, verificamos si el elemento ya existe en el set.
        if (!this->Contains(element))
        {
            // Si no existe, llamamos al m�todo Add de la clase base (HashTableChaining)
            // para que realice la inserci�n.
            HashTableChaining<T>::Add(element);
        }
        else
        {
            // Si el elemento ya existe, simplemente mostramos un mensaje y no hacemos nada.
            cout << "El elemento " << element << " ya existe en el HashSet. No se agregar�." << endl;
        }
    }
};

