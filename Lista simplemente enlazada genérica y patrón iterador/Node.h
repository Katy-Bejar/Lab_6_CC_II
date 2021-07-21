#ifndef __NODE_H__
#define __NODE_H__

using namespace std;

template <typename T>
class Node{
    private: 
        T elem;
        Node<T>* next;
    public:
        // Constructores
        Node(T);
        Node();

        // Get
        T getElem()const;
        Node<T>* getNext()const;
  
        // Set
        void setElem(T);
        void setNext(Node<T>*);
};

// Constructores
template <typename T>
Node<T>::Node(T elem){
    this -> elem = elem;
    this -> next = nullptr;
}
template <typename T>
Node<T>::Node(){
    this -> elem = elem;
    this -> next = next;
}

// Get
template <typename T>
T Node<T>::getElem()const{
    return elem;
}
template <typename T>
Node<T>* Node<T>::getNext()const{
    return next;
}

// Set
template <typename T>
void Node<T>::setElem(T elem){
    this -> elem = elem;
}
template <typename T>
void Node<T>::setNext(Node* next){
    this -> next = next;
}

#endif