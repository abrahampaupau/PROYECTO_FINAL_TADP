#pragma once

#include <iostream>
#include <stack> // Necesario para la funci�n PostOrderIterative
using namespace std;

#include <cmath> // Required for std::log

double log_base_n(double x, double base);


int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

template <typename T>
class BinarySearchTree
{
	template <typename T>
	class TreeNode
	{
	public:
		TreeNode()
		{
			parent = leftChild = rightChild = nullptr;
			data = {};
		}

		TreeNode(T data)
		{
			parent = leftChild = rightChild = nullptr;
			// this se refiere a exactamente el objeto que est� mandando a llamar la funci�n.
			this->data = data;
		}

		T data;
		// el padre de este nodo dentro del �rbol.
		// En otras palabras, this == parent.leftChild || this == parent.rightChild
		TreeNode<T>* parent;

		// vector<TreeNode*> children; // si quisi�ramos que tuviera la posibilidad de tener m�s de dos hijos cada nodo.
		TreeNode<T>* leftChild;
		TreeNode<T>* rightChild;
	};

public:
	BinarySearchTree()
	{
		root = nullptr;
		count = 0;
	}

	void AddWithAddRecursive(T value)
	{
		// primero checamos si root es nullptr.
		if (root == nullptr)
		{
			// si s� es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a
			// convertir en el nodo root.
			root = new TreeNode<T>(value);
			count++;
			return; // nos salimos de la funci�n.
		}

		TreeNode<T>* currentNode = root;

		AddRecursive(value, currentNode);
	}

	void InsertarNode(TreeNode<T>* currentNode, bool isLeftChild, T value)
	{
		TreeNode<T>* newNode = new TreeNode<T>(value);
		newNode->parent = currentNode;
		if (isLeftChild)
			currentNode->leftChild = newNode;
		else
			currentNode->rightChild = newNode;
		count++;

	}

	// AQUI ESTA LA CORRECCION AL ADD Y ADDRECURSIVE
	void AddRecursive(T value, TreeNode<T>* currentNode)
	{
		// Si el valor ya existe, salimos sin hacer nada.
		if (value == currentNode->data)
		{
			cout << "El valor " << value << " ya existe en el arbol. No se agregara." << endl;
			return;
		}

		// si value es mayor que el data de currentNode
		if (value > currentNode->data)
		{
			// entonces nos vamos a su derecha
			// checamos si ese hijo de la derecha es nullptr.
			if (currentNode->rightChild == nullptr)
			{
				// si s� es nullptr, entonces ahora value va a ser ese hijo.
				InsertarNode(currentNode, false, value);
				return;
			}
			else
			{
				// aqu� hacemos la recursi�n
				return AddRecursive(value, currentNode->rightChild);
			}
		}
		else if (value < currentNode->data)
		{
			// entonces nos vamos a su izquierda.
			// checamos si ese hijo de la izquierda es nullptr.
			if (currentNode->leftChild == nullptr)
			{
				// si s� es nullptr, entonces ahora value va a ser ese hijo.
				InsertarNode(currentNode, true, value);
				return;
			}
			else
			{
				// aqu� hacemos la recursi�n
				return AddRecursive(value, currentNode->leftChild);
			}
		}
	}

	// AQUI ESTA LA CORRECCION AL ADD Y ADDRECURSIVE
	void Add(T value)
	{
		// primero checamos si root es nullptr.
		if (root == nullptr)
		{
			// si s� es nullptr, quiere decir que value es el primer valor en entrar, y por tanto se va a
			// convertir en el nodo root.
			root = new TreeNode<T>(value);
			count++;
			return; // nos salimos de la funci�n.
		}

		TreeNode<T>* currentNode = root;

		// necesitamos un ciclo que dure hasta que lleguemos a un nodo nullptr
		while (currentNode != nullptr) // mientras que nuestro nodo actual siga siendo v�lido, continua el ciclo.
		{
			// Si el valor ya existe, salimos sin hacer nada.
			if (value == currentNode->data)
			{
				cout << "El valor " << value << " ya existe en el arbol. No se agregara." << endl;
				return;
			}

			// el ciclo consiste en el proceso de navegar a trav�s de hijos izquierdos y derechos

			// si value es mayor que el data de currentNode
			if (value > currentNode->data)
			{
				// entonces nos vamos a su derecha
				// checamos si ese hijo de la derecha es nullptr.
				if (currentNode->rightChild == nullptr)
				{
					// si s� es nullptr, entonces ahora value va a ser ese hijo.
					InsertarNode(currentNode, false, value);
					return;
				}
				else
				{
					currentNode = currentNode->rightChild;
				}
			}
			else if (value < currentNode->data)
			{
				// entonces nos vamos a su izquierda.
				// checamos si ese hijo de la izquierda es nullptr.
				if (currentNode->leftChild == nullptr)
				{
					// si s� es nullptr, entonces ahora value va a ser ese hijo.
					InsertarNode(currentNode, true, value);
					return;
				}
				else
				{
					currentNode = currentNode->leftChild;
				}
			}
		}
	}

	void InOrderWithRecursive()
	{
		InOrderRecursive(root);
	}


	int MinimaAltura()
	{
		// le dice que tiene N nodos, y que es un �rbol de base 2 (porque es binario en este caso).
		return MinimaAlturaDeArbol(count, 2);
	}



	// Es el nodo ra�z desde el cual el �rbol es capaz de llegar a cualquier otro nodo en el �rbol.
	TreeNode<T>* root;

	// cu�ntos nodos en total tiene el �rbol.
	int count;

	// cu�ntos niveles de profundidad tiene el �rbol.
	// int depth;

	bool SearchWithRecursive(T value)
	{
		TreeNode<T>* resultNode = SearchRecursive(root, value);
		if (resultNode == nullptr)
			return false;
		return true;
	}

	// NUEVA FUNCION: B�squeda de un valor de forma iterativa
	bool Search(T value)
	{
		// Ok, para buscar algo, primero tengo que empezar desde el principio del �rbol, la ra�z.
		TreeNode<T>* currentNode = root;

		// Ahora, voy a hacer un ciclo para recorrer el �rbol. Seguir� buscando mientras mi nodo actual no sea nulo.
		while (currentNode != nullptr)
		{
			// Si el valor del nodo en el que estoy es exactamente el que busco... �lo encontr�!
			if (currentNode->data == value)
			{
				cout << "�Encontr� el valor " << value << "!" << endl;
				return true;
			}
			// Si el valor que busco es m�s peque�o que el del nodo actual,
			// significa que tengo que irme hacia la izquierda.
			else if (value < currentNode->data)
			{
				currentNode = currentNode->leftChild;
			}
			// Si no es m�s peque�o, entonces debe ser m�s grande, as� que me voy a la derecha.
			else
			{
				currentNode = currentNode->rightChild;
			}
		}

		// Si sal� del ciclo y nunca lo encontr�, pues ya s� que ese valor no est� en mi �rbol.
		cout << "El valor " << value << " no se encontr� en el �rbol." << endl;
		return false;
	}


	// AQUI ESTA EL ERROR Y CORRECCION EN LA LOGICA DE RECONECTAR PUNTEROS
	void Delete(T value)
	{
		// Corroboramos que existe un nodo con el valor dado.
		TreeNode<T>* nodeToDelete = SearchRecursive(root, value);

		if (nodeToDelete == nullptr)
		{
			cout << "no existe el valor " << value << " en este �rbol." << endl;
			return;
		}

		// caso 1: el nodo no tiene hijos.
		if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild == nullptr)
		{
			// si el nodo que queremos borrar es la ra�z...
			if (nodeToDelete == root) {
				root = nullptr;
			}
			// si no, nos aseguramos de que su padre ya no apunte a �l.
			else if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
			{
				nodeToDelete->parent->leftChild = nullptr;
			}
			else
			{
				// si no, entonces somos el hijo derecho
				nodeToDelete->parent->rightChild = nullptr;
			}

			// y luego borramos este nodo
			count--;
			delete nodeToDelete;
			return;
		}

		// caso 2: tiene un solo hijo.
		// tiene hijo derecho pero no izquierdo
		if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild != nullptr)
		{
			// en este caso, el hijo derecho del nodo a borrar toma su lugar.

			// si el nodo a borrar es la ra�z...
			if (nodeToDelete == root) {
				root = nodeToDelete->rightChild;
				root->parent = nullptr;
			}
			// si no, conectamos al abuelo con el nieto.
			else if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
			{
				nodeToDelete->parent->leftChild = nodeToDelete->rightChild;
			}
			else
			{
				// si no, somos el hijo derecho
				nodeToDelete->parent->rightChild = nodeToDelete->rightChild;
			}

			// y el nieto, ahora su parent va a ser su abuelo.
			nodeToDelete->rightChild->parent = nodeToDelete->parent;
			count--;
			delete nodeToDelete;
			return;
		}
		// tiene hijo izquierdo pero no derecho
		else if (nodeToDelete->leftChild != nullptr && nodeToDelete->rightChild == nullptr)
		{
			// en este caso, el hijo izquierdo del nodo a borrar toma su lugar.

			// si el nodo a borrar es la ra�z...
			if (nodeToDelete == root) {
				root = nodeToDelete->leftChild;
				root->parent = nullptr;
			}
			// si no, conectamos al abuelo con el nieto.
			else if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
			{
				nodeToDelete->parent->leftChild = nodeToDelete->leftChild;
			}
			else
			{
				// si no, somos el hijo derecho
				nodeToDelete->parent->rightChild = nodeToDelete->leftChild;
			}

			// y el nieto, ahora su parent va a ser su abuelo.
			nodeToDelete->leftChild->parent = nodeToDelete->parent;
			count--;
			delete nodeToDelete;
			return;
		}


		// aqu� ya sabemos que tiene los dos hijos porque si no no habr�a llegado a esta l�nea de c�digo.
		// entonces es el caso 3:

		// encontramos al sucesor de nodeToDelete
		TreeNode<T>* successorNode = Successor(nodeToDelete);  // NOTA, nunca podr�a ser nulo, porque nodeToDelete tiene sus dos hijos
		// a donde nodeToDelete apuntaba con la izquierda, ahora el sucesor apunta con su izquierda y viceversa.
		successorNode->leftChild = nodeToDelete->leftChild;
		nodeToDelete->leftChild->parent = successorNode;

		// el hijo derecho del sucesor ahora es hijo del pap� del sucesor y viceversa.
		// pero necesitamos saber si successorNode es hijo izquierdo o derecho del abuelo.
		if (successorNode->parent->leftChild == successorNode) // soy tu hijo izquierdo?
		{
			successorNode->parent->leftChild = successorNode->rightChild;
		}
		else
		{
			// si no, entonces somos el hijo derecho
			successorNode->parent->rightChild = successorNode->rightChild;
		}
		// conectamos el hijo derecho del sucesor con su abuelo.
		if (successorNode->rightChild) {
			successorNode->rightChild->parent = successorNode->parent;
		}

		// a donde apuntaba nodeToDelete con la derecha, ahora el sucesor va a apuntar con su derecha y viceversa.
		successorNode->rightChild = nodeToDelete->rightChild;
		if (nodeToDelete->rightChild) {
			nodeToDelete->rightChild->parent = successorNode;
		}

		// nos falta que el sucesor sepa qui�n es su pap�, y viceversa
		successorNode->parent = nodeToDelete->parent;
		// si el nodo a borrar era la ra�z, el sucesor se vuelve la nueva ra�z.
		if (nodeToDelete == root) {
			root = successorNode;
		}
		// aqu� S� necesitamos saber si nodeToDelete es su hijo derecho o izquierdo
		else if (nodeToDelete->parent->leftChild == nodeToDelete) // soy tu hijo izquierdo?
		{
			nodeToDelete->parent->leftChild = successorNode;
		}
		else
		{
			// si no, entonces somos el hijo derecho
			nodeToDelete->parent->rightChild = successorNode;
		}

		count--;
		// y borramos el nodo.
		delete nodeToDelete;
	}

	// NUEVA FUNCION: Borrar todo el �rbol
	void DestruirArbol() {
		// Lo primero es asegurarme de que el �rbol no est� vac�o.
		if (root == nullptr) {
			cout << "Mi arbol ya esta vacio, no hay nada que destruir." << endl;
			return;
		}

		// Ok, ahora voy a llamar a mi funci�n privada que har� el trabajo de verdad.
		// Le digo que empiece a borrar desde la ra�z.
		DestruirArbolRecursivo(root);

		// Una vez que la magia de la recursi�n ha borrado todo...
		// Mi ra�z ya no debe apuntar a nada, porque no hay nodos.
		root = nullptr;
		// Y el conteo de nodos debe volver a cero.
		count = 0;

		cout << "�El arbol ha sido destruido por completo!" << endl;
	}

	// NUEVA FUNCION: Recorrido Post-order de forma iterativa
	void PostOrderIterative()
	{
		// Lo primero es ver si mi �rbol ya est� vac�o, si lo est�, no hay nada que hacer.
		if (root == nullptr)
		{
			return;
		}

		// Ok, ahora voy a usar dos pilas para que me ayuden a hacer esto.
		stack<TreeNode<T>*> stack1;
		stack<TreeNode<T>*> stack2;

		// Empezamos poniendo el primer nodo (la ra�z) en la primera pila.
		stack1.push(root);

		// Ahora, voy a hacer un ciclo que seguir� mientras la primera pila no est� vac�a.
		while (!stack1.empty())
		{
			// Saco el nodo que est� hasta arriba de la primera pila...
			TreeNode<T>* currentNode = stack1.top();
			stack1.pop();

			// ... y lo pongo en la segunda pila.
			stack2.push(currentNode);

			// Ahora, si este nodo tiene un hijo a la izquierda, lo pongo en la primera pila.
			if (currentNode->leftChild != nullptr)
			{
				stack1.push(currentNode->leftChild);
			}

			// Y si tiene un hijo a la derecha, tambi�n lo pongo en la primera pila.
			if (currentNode->rightChild != nullptr)
			{
				stack1.push(currentNode->rightChild);
			}
		}

		// Cuando mi primera pila se vac�a, la segunda pila ya tiene todos los nodos en el orden correcto
		// para el post-orden. Ahora solo tengo que sacarlos y mostrarlos.
		while (!stack2.empty())
		{
			// Saco el nodo de arriba de la segunda pila y muestro su valor.
			cout << stack2.top()->data << endl;
			stack2.pop();
		}
	}


private:
	TreeNode<T>* TreeMaximum()
	{
		// empezamos en la ra�z y le pedimos el m�ximo desde ah�.
		return Maximum(root);
	}

	// Nos da el m�ximo a partir de node como ra�z.
	TreeNode<T>* Maximum(TreeNode<T>* node)
	{
		// empezamos en node y
		TreeNode<T>* maximum = node;
		// nos vamos todo a la derecha hasta que el hijo derecha sea nullptr.
		while (maximum->rightChild != nullptr)
			maximum = maximum->rightChild;

		return maximum;
	}


	// el m�nimo valor T en todo el �rbol.
	TreeNode<T>* TreeMinimum()
	{
		// empezamos en la ra�z y le pedimos el m�nimo desde ah�
		return Minimum(root);
	}

	// Nos da el m�nimo a partir de node como ra�z.
	TreeNode<T>* Minimum(TreeNode<T>* node)
	{
		// empezamos en node y
		TreeNode<T>* minimum = node;
		// nos vamos todo a la izquierda hasta que el hijo izquierdo sea nullptr.
		while (minimum->leftChild != nullptr)
			minimum = minimum->leftChild;

		return minimum;
	}

	TreeNode<T>* MinimumWithRecursive()
	{
		// empezamos en la ra�z y hacemos recursi�n.
		return MinimumRecursive(root);
	}

	TreeNode<T>* MinimumRecursive(TreeNode<T>* currentNode)
	{
		if (currentNode->leftChild == nullptr)
			return currentNode;
		// else
		return MinimumRecursive(currentNode->leftChild);
	}

	TreeNode<T>* Successor(TreeNode<T>* node)
	{
		if (node->rightChild != nullptr)
			return Minimum(node->rightChild); // Minimum se debe mandar a llamar desde la derecha del node que se recibi� como par�metro.

		// si no, entonces
		// tomamos el padre de node, y lo guardamos en una variable
		TreeNode<T>* ancestor = node->parent;
		// Mientras que no llegue a null y siga siendo hijo derecho de alguien, entonces se seguir�
		// subiendo en los parents.
		while (ancestor != nullptr && node == ancestor->rightChild)
		{
			// node se vuelve su pap�
			node = ancestor;
			// y el pap� se vuelve su pap�
			ancestor = node->parent;
		}
		return ancestor;
	}

	// lo mismo que Successor, pero invertimos Right por Left, y Minimum por maximum.
	TreeNode<T>* Predecessor(TreeNode<T>* node)
	{
		if (node->leftChild != nullptr)
			return Maximum(node->leftChild); // Maximum se debe mandar a llamar desde la izquierda del node que se recibi� como par�metro.

		// si no, entonces
		// tomamos el padre de node, y lo guardamos en una variable
		TreeNode<T>* ancestor = node->parent;
		// Mientras que no llegue a null y siga siendo hijo izquierdo de alguien, entonces se seguir�
		// subiendo en los parents.
		while (ancestor != nullptr && node == ancestor->leftChild)
		{
			// node se vuelve su pap�
			node = ancestor;
			// y el pap� se vuelve su pap�
			ancestor = node->parent;
		}
		return ancestor;
	}


	TreeNode<T>* SearchRecursive(TreeNode<T>* currentNode, T value)
	{
		if (currentNode == nullptr)
			return nullptr;
		if (currentNode->data == value)
			return currentNode;
		// si el valor que est�s buscando (value) es menor que el de este nodo, vete al hijo izquierdo
		if (value < currentNode->data)
		{
			return SearchRecursive(currentNode->leftChild, value);
		}

		// else
		return SearchRecursive(currentNode->rightChild, value);
	}

	// Esta es la funci�n que borra cada nodo de forma recursiva con un recorrido post-orden.
	void DestruirArbolRecursivo(TreeNode<T>* node) {
		// Mi regla principal es: solo trabajo si el nodo en el que estoy no es nulo.
		if (node != nullptr) {
			// Paso 1: Primero me voy a la izquierda y borro todo lo que hay ah�.
			DestruirArbolRecursivo(node->leftChild);
			// Paso 2: Luego, me voy a la derecha y borro todo lo que encuentro.
			DestruirArbolRecursivo(node->rightChild);
			// Paso 3: Por �ltimo, cuando ya no hay nada en la izquierda ni en la derecha...
			// �Borro el nodo actual! Aqu� es donde libero la memoria.
			cout << "Borrando nodo con valor: " << node->data << endl;
			delete node;
		}
	}

	void InOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			// Mandamos recursivamente a izquierda
			InOrderRecursive(node->leftChild);
			// Luego se visita (en este caso, se imprime su valor)
			cout << node->data << endl;
			// Mandamos recursivamente a derecha
			InOrderRecursive(node->rightChild);
		}
	}

	void PreOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			// Luego se visita (en este caso, se imprime su valor)
			cout << node->data << endl;
			// Mandamos recursivamente a izquierda
			PreOrderRecursive(node->leftChild);
			// Mandamos recursivamente a derecha
			PreOrderRecursive(node->rightChild);
		}
	}

	void PostOrderRecursive(TreeNode<T>* node)
	{
		if (node != nullptr)
		{
			// Mandamos recursivamente a izquierda
			PostOrderRecursive(node->leftChild);
			// Mandamos recursivamente a derecha
			PostOrderRecursive(node->rightChild);
			// Luego se visita (en este caso, se imprime su valor)
			cout << node->data << endl;
		}
	}
};