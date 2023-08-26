#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;
};

template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    // Constructor y destructor

    // Agregar un elemento al final de la lista
    void push_back(const T& value);

    // Insertar un elemento en una posición específica
    void insert(int position, const T& value);

    // Eliminar un elemento de una posición específica
    void remove(int position);

    // Obtener el tamaño de la lista
    int size() const;

    // Obtener el valor en una posición específica
    T& at(int position);

    // Obtener el valor en una posición específica (versión constante)
    const T& at(int position) const;

    // Mover un nodo a una nueva posición
    void moveNodeToPosition(int fromPosition, int toPosition);

    // Obtener el nodo en una posición específica
    Node<T>* getNode(int position) const;
};

#endif // DOUBLY_LINKED_LIST_H