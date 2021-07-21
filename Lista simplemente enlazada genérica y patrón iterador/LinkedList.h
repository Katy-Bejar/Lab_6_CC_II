#ifndef __LINKEDLIST__H__
#define __LINKEDLIST__H__
#include <iostream>

using namespace std;

template <typename T>
class LinkedList{
    private: // variables miembro
        int size;
        Node<T>* head;
        Node<T>* CreateIterator();
    public:
        // constructor
        LinkedList(T);

        // constructor por defecto
        LinkedList();
        
        // constructor copia
        LinkedList(const LinkedList<T> &o);

        //Operador de asignación copia
        LinkedList& operator= (const LinkedList<T> &o);

        //constructor de movimiento
        LinkedList(LinkedList<T> &&o);

        //Operador de asignación de movimiento
        LinkedList& operator= (LinkedList&& o);

        // destructor
        ~LinkedList();

        // get  
        int getSize()const;
        Node<T>* getHead()const;

        // set
        void setSize(int);
        void setHead(Node<T>*);

        //insert
        void push_front(T);
        void push_back(T);
        void insertByPosition(T, int);

        //remove
        void pop_front();
        void pop_back();
        void removeByPosition(int);

        //LinkedList(Node<T>* begin, Node<T>* end);
        Node<T>* begin(){
            return this -> head;
        }
        Node<T>* end(){
            return nullptr;
        }

        // sobrecarga del operador de salida
        friend std::ostream& operator << (std::ostream& ouput, const LinkedList<T> &o){
            // int cont=0;
            Node<T>* current = o.head;
            while(current){
                ouput << current->getElem() << "  ";
                current = current->getNext();
                //cont++;
            }
            ouput << endl;
            ouput <<"Size: "<< o.size << endl;
            return ouput;
        }
};

// constructor
template <typename T>
LinkedList<T>::LinkedList (){
    this -> size = 0;
    this -> head = nullptr;
}

//constructor parametrizado
template <typename T>
LinkedList<T>::LinkedList (T elem){
    this -> size = 1;
    this -> head = new Node<T>(elem);
}

//constructor copia
template <typename T>
LinkedList<T>::LinkedList (const LinkedList<T> &o){
    this -> size = o.size;
    Node<T>* nuevo = o.head;
    while (nuevo -> getNext() != nullptr){
        push_back (nuevo -> getElem());
        nuevo = nuevo -> getNext();
    }
}

//constructor de movimiento
template <typename T>
LinkedList<T>::LinkedList (LinkedList<T> &&o){
    cout << "Constructor movimiento" << endl;
    this -> size = o.size;
    Node<T>* nuevo = o.head;
    while (nuevo -> getNext() != nullptr){
        push_back (nuevo -> getElem());
        nuevo = nuevo -> getNext();
    }
}

//destructor
template <typename T>
LinkedList<T>::~LinkedList(){
    Node<T> *p = head;
    while (p){
        p = head -> getNext();
        delete head;
        head = p;
    }
}

// get
template <typename T>
int LinkedList<T>::getSize()const{
    return size;
}
template <typename T>
Node<T> *LinkedList<T>::getHead()const{
    return head;
}

// set
template <typename T>
void LinkedList<T>::setSize(int size){
    this -> size = size;
}
template <typename T>
void LinkedList<T>::setHead(Node<T> *head){
    this -> head = head;
}

//Metodo insertar al inicio
template <typename T>
void LinkedList<T>::push_front(T elem){
	Node<T>* nuevo = new Node<T> (elem);
    Node<T>* aux = head;
    if (!head) {
        head = nuevo;
    }
    else{
        nuevo -> setNext(this->head);
        this -> head = nuevo;      
        while (aux) {
            aux = aux -> getNext();
        }
    } 
    size++;
}

// Metodo insertar al final
template <typename T>
void LinkedList<T>::push_back(T elem){
	Node<T>* nuevo = new Node<T> (elem);
    Node<T>* aux = head;
    if (!head) {
        head = nuevo;
    }
    else{
        while (aux->getNext() != nullptr) {
            aux = aux -> getNext();
        }
        aux -> setNext(nuevo);
    }  
    size++;
}

//Metodo insert por posicion
template <typename T>
void LinkedList<T>::insertByPosition(T elem, int pos){
    Node<T>* nuevo = new Node<T> (elem);
    Node<T>* aux = head;
    Node<T>* aux1 = aux -> getNext();
    if (pos < 1 || pos > getSize() ) {
        cout << "Fuera de rango" << endl;
    } 
    else if (pos == 1) {
        head = head -> getNext();
        aux++;
    } 
    else{
        for (int i = 2; i <= pos; i++) {
            if (i == pos){
                Node<T>* insertar = aux1 ;
                aux -> setNext(aux1 -> getNext());
                insertar++;
            }
            aux = aux -> getNext();
            aux1 = aux1 -> getNext();
        }
    }
    size++;
}

//eliminar al inicio de la lista
template <typename T>
void LinkedList<T>::pop_front(){
    Node<T>* current = this->head ;
    this->head = this->head->getNext();
    current->setNext(NULL);
    delete current;
    this->size--;
}

//eliminar al final de la lista
template <typename T>
void LinkedList<T>::pop_back(){
    if(this->head){
        Node<T>*current = this->head;   
        Node<T>*prev = NULL;
        while(current->getNext()){
            prev = current;
            current = current->getNext();
        }
        if(current == this->head){
            this->head = this->head->getNext();
            delete current;
            this->size--;
        }else{
            prev->setNext(NULL);
            delete current;
            this->size--;
        }
    }
}

// Metodo remove por posicion
template <typename T>
void LinkedList<T>::removeByPosition (int pos){ 
    if (this -> head != nullptr){ 
        Node<T>* aux = head;
        Node<T>* aux1 = aux -> getNext();
        if (pos < 1 || pos > getSize()) {
            cout << "Fuera de rango" << endl;
        } 
        else if (pos == 1) {
            head = head -> getNext();
            delete aux;
        } 
        else{
            for (int i = 2; i <= pos; i++) {
                if (i == pos){
                    Node<T>* eliminar = aux1 ;
                    aux -> setNext(aux1 -> getNext());
                    delete eliminar;
                }
                aux = aux -> getNext();
                aux1 = aux1 -> getNext();
		    }
        }
        size--;
    }
    else{
        cout<<"No hay nodos "<<endl;;
    }
}

#endif