// Mi archivo principal para probar todo el proyecto.
#include <iostream>
#include "BinarySearchTree.h" 
#include "HashTableChaining.h" 
#include "HashSet.h" 

using namespace std;

// Función para probar la parte del HashSet.
void ProbarHashSet() {
    cout << "===============================================" << endl;
    cout << "            PROBANDO MI CLASE HASHSET          " << endl;
    cout << "===============================================" << endl;

    // Voy a crear un HashSet con un tamaño inicial de 5.
    HashSet<int> miHashSet(5);

    cout << "Agregando elementos a mi HashSet:" << endl;
    miHashSet.Add(10);
    miHashSet.Add(20);
    miHashSet.Add(30);
    miHashSet.Add(15);
    cout << "El estado actual del HashSet es:" << endl;
    miHashSet.Print();
    cout << endl;

    // Ahora intento agregar un elemento que ya existe (el 20).
    cout << "Intentando agregar el elemento 20 de nuevo..." << endl;
    miHashSet.Add(20);
    cout << "El estado del HashSet despues de la operacion:" << endl;
    miHashSet.Print();
    cout << endl;

    // Intento agregar un elemento diferente para ver que sí funciona.
    cout << "Intentando agregar un nuevo elemento (45)..." << endl;
    miHashSet.Add(45);
    cout << "El estado del HashSet despues de la operacion:" << endl;
    miHashSet.Print();
    cout << endl;

    // Verifico si un elemento existe y luego lo borro.
    cout << "Verificando si el elemento 15 existe..." << endl;
    if (miHashSet.Contains(15)) {
        cout << "¡Si, el 15 esta! Ahora lo voy a borrar." << endl;
        miHashSet.Remove(15);
    }
    cout << "El estado del HashSet despues de borrar 15:" << endl;
    miHashSet.Print();
    cout << endl;

    cout << "Pruebas de HashSet terminadas con exito." << endl;
}

// Función para probar la parte del Binary Search Tree.
void ProbarBinarySearchTree() {
    cout << "===============================================" << endl;
    cout << "      PROBANDO MI CLASE BINARY SEARCH TREE     " << endl;
    cout << "===============================================" << endl << endl;

    // Creo una instancia de mi arbol para trabajar con numeros enteros.
    BinarySearchTree<int> miArbol;

    // Primero, voy a llenar mi arbol con algunos valores.
    cout << "Paso 1: Llenando el arbol con valores." << endl;
    miArbol.Add(50);
    miArbol.Add(30);
    miArbol.Add(70);
    miArbol.Add(20);
    miArbol.Add(40);
    miArbol.Add(60);
    miArbol.Add(80);
    miArbol.Add(10);
    miArbol.Add(25);
    cout << "Mi arbol ya tiene varios nodos. La raiz es 50." << endl << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "Paso 2: Probando la nueva funcion Search (iterativa)." << endl;
    // Voy a buscar un valor que si existe.
    cout << "Intentando buscar el valor 40..." << endl;
    if (miArbol.Search(40))
    {
        cout << "¡La busqueda iterativa funciono correctamente!" << endl;
    }
    // Y ahora uno que no existe.
    cout << "Intentando buscar el valor 99..." << endl;
    if (!miArbol.Search(99))
    {
        cout << "¡La busqueda iterativa tambien funciono para un valor que no existe!" << endl;
    }
    cout << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "Paso 3: Probando la nueva funcion de recorrido Post-order (iterativa)." << endl;
    cout << "Recorrido Post-order de mi arbol:" << endl;
    miArbol.PostOrderIterative();
    cout << "Si los numeros se imprimen en el orden: 10, 25, 20, 40, 30, 60, 80, 70, 50, ¡funciona!" << endl << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "Paso 4: Probando la funcion Delete corregida." << endl;

    // Caso 1: Borrar un nodo 'hoja' (sin hijos). Voy a borrar el 10.
    cout << "Borrando el nodo 10 (sin hijos)..." << endl;
    miArbol.Delete(10);
    cout << "Ahora el 10 ya no deberia estar en el arbol." << endl;
    miArbol.PostOrderIterative();

    // Caso 2: Borrar un nodo con un solo hijo. Voy a borrar el 20 (su hijo es el 25).
    cout << "\nBorrando el nodo 20 (con un solo hijo)..." << endl;
    miArbol.Delete(20);
    cout << "Ahora el 20 ya no deberia estar y su hijo 25 tomo su lugar." << endl;
    miArbol.PostOrderIterative();

    // Caso 3: Borrar un nodo con dos hijos. Voy a borrar el 30.
    cout << "\nBorrando el nodo 30 (con dos hijos)..." << endl;
    miArbol.Delete(30);
    cout << "Ahora el 30 ya no deberia estar. El sucesor (40) tomo su lugar." << endl;
    miArbol.PostOrderIterative();

    // Ahora vamos a borrar la raiz.
    cout << "\nBorrando la raiz (50)..." << endl;
    miArbol.Delete(50);
    cout << "La nueva raiz deberia ser el 60." << endl;
    miArbol.PostOrderIterative();

    cout << "---------------------------------------------------" << endl;
    cout << "Paso 5: Probando la funcion de destruccion del arbol." << endl;
    // Ahora que ya probamos todo, vamos a destruir el arbol.
    miArbol.DestruirArbol();

    // Intento buscar un valor despues de destruir el arbol.
    cout << "\nIntentando buscar el valor 60 despues de destruir el arbol..." << endl;
    miArbol.Search(60);

    cout << "\nPruebas finalizadas. Si todo se ve correcto, ¡mi codigo funciona bien!" << endl;
}

int main()
{
    ProbarHashSet();
    cout << endl << endl;
    ProbarBinarySearchTree();

    return 0;
}