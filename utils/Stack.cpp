#include <stdexcept>
#include "Stack.h"

template <class T> Stack<T>::~Stack() {
    delete this->head;
}

template <class T> void Stack<T>::push(T t) {
    this->head = new Node(t, this->head);
    this->sizeOf++;
}

template <class T> T Stack<T>::pop() {
    if (this->sizeOf > 0) {
        T result = this->head->value;
        this->head = this->head->next;
        this->sizeOf--;
        return result;
    } else {
        throw std::out_of_range("Cannot call pop on empty stack");
    }
}