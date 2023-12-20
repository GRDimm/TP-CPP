#include "3.1.h"

List::List() {
    head = nullptr;
    n = 0;
}

int List::NumElements(){
    return n;
}

List::Element* List::Head(){
    return head;
}

void List::Remove(Element* element){
    if (element == nullptr || head == nullptr) {
        return;
    }

    if (element->prev != nullptr) {
        element->prev->next = element->next;
    } else {
        head = element->next;
    }

    if (element->next != nullptr) {
        element->next->prev = element->prev;
    }else{
        tail = element->prev;
    }

    delete element; 
    n--;
}

List::Element* List::InsertNewElementAfter(double value, Element* position){
    Element* newElement = new Element;
    newElement->value = value;

    if (position == nullptr) {
        newElement->next = head;
        if (head != nullptr) {
            head->prev = newElement;
        }
        head = newElement;
    } else {
        newElement->next = position->next;
        if (position->next != nullptr) {
            position->next->prev = newElement;
        }else{
            tail = newElement;
        }
        newElement->prev = position;
        position->next = newElement;
    }

    n++;
    return newElement;
}

List::Element* List::Find(double d){
    Element* current = head;
    while (current != nullptr) {
        if (current->value == d) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void List::InsertListAfter(const List* other, Element* position){
    if (other == nullptr || other->head == nullptr) {
            return;
        }

        if (position == nullptr) {
            if (head != nullptr) {
                other->tail->next = head;
                head->prev = other->tail;
                head = other->head;
            } else {
                head = other->head;
                tail = other->tail;
            }
        } else {
            Element* nextElement = position->next;
            if (nextElement != nullptr) {
                other->tail->next = nextElement;
                nextElement->prev = other->tail;
            } else {
                other->tail->next = nullptr;
                tail = other->tail;
            }
            position->next = other->head;
            other->head->prev = position;
        }

        n += other->n;
}

