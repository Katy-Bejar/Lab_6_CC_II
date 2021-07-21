#ifndef __ITERATOR__H__
#define __ITERATOR__H__
#include <iostream>

using namespace std;

template <typename T, typename U>
class Iterator {
    private:
        Node<T>* Iterador;
        U* m_Container;

    public:
        Iterator(U* container) :m_Container(container){
            Iterador = m_Container->CreateIterator();
        }

        //Sobrecarga del operador de puntero
        T operator *(){
            Node<T>* temp = this->Iterador;
            return temp->getElem();
        }

        //Antes de la sobrecarga del operador ++
        Node<T>* & operator++(){
            this->Iterador = this->Iterador->getNext();
            return this->Iterador;
        }

        //Después de la sobrecarga del operador ++
        const Node<T>* operator++ (int){
            Node<T>* temp = this->Iterador;
            this->Iterador = this->Iterador->getNext();
            return temp;
        }

        //Sobrecarga del operador de asignación
        Iterator<T, U>& operator= (Node<T>* node){
            this->Iterador = node;
            return *this;
        }

        //Sobrecarga de operadores de desigualdad
        bool operator!= (const Node<T>* node){
            if (this->Iterador == node){
                return false;
            }
            return true;  
        }
    };

#endif