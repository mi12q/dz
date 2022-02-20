#include <iostream>


// јбстрактный класс
class container_of_ints {
public:
    // ¬иртуальные методы:
    /*¬озвращает число элементов в текущем экземпл¤ре контейнера*/
    virtual int size() = 0;

    /*”добна¤ возможность обращени¤ к i-ому элементу в контейнере
    ѕ–ќ¬≈–я≈“  ќ––≈ “Ќќ—“№ (ѕ–ќ¬≈–я≈“ есть ли вообще в контейнере i-й элемент)*/
    virtual int& at(int i) = 0;

    /*”добна¤ возможность обращени¤ к i-ому элементу в контейнере
    Ќ≈ ѕ–ќ¬≈–я≈“  ќ––≈ “Ќќ—“№ (Ќ≈ ѕ–ќ¬≈–я≈“ есть ли вообще в контейнере i-й элемент)*/
    virtual int& operator[](int i) = 0;

    /*ƒобавл¤ет новый элемент new_element в конец контейнера*/
    virtual void push_back(int new_element) = 0;

    /*»звлекает последний элемент из контейнера:
    “о есть удал¤ет последний элемент из контейнера
    » возвращает его тому, кто вызвал метод push_back()
    */
    virtual int pop_back() = 0;

    /*ќсвобождает пам¤ть, выделенную под вектор
    ѕосле этого считаем, что в текущем контейнере Ќ≈“ Ёлементов*/
    virtual void clear() = 0;

    /*ѕосле вызова этого метода
    ¬—≈ данные внутри контейнера должны быть расположены в обратном пор¤дке
    P.S. “акой метод не совсем стандартный дл¤ контейнеров —++, но дл¤ тренировки норм*/
    virtual void reverse() = 0;
};


void initialization_container_of_ints(container_of_ints* obj) {
    for (int i = 0; i < obj->size(); i++) {
        obj->at(i) = i;
    }
}

void show_container_of_ints(container_of_ints* obj) {
    for (int i = 0; i < obj->size(); i++) {
        std::cout << obj->at(i) << ' ';
    }
    std::cout << std::endl;
}

void double_each_element (container_of_ints& obj) {
    for (int i = 0; i < obj.size(); i++) {
        //obj.at(i) *= 2;
        obj[i] *= 2;
    }
}


class list_of_ints: public container_of_ints{

private:
    struct node{
        int data;
        node* next;
    };

    node* head;

public:
    list_of_ints(int size) { //konstruktor
       if (size == 0) {
            head = nullptr;
            return;
        }
        node* curr = new node;
        head = curr;
        size--;
        while (size > 0)
        {
            curr->next = new node;
            curr = curr->next;
            size--;
        }

        curr->next = nullptr;
    }

    int size(){
        if(head == nullptr){
            return 0;
        }
        node* curr = head;
        int size = 0;

        while(curr->next != nullptr){

            size++;
            curr = curr->next;
        }
        return size;

    }
    int& at(int i){
       node* curr = head;
        for(int j = 0; j < i; j++){
            curr = curr->next;
        }
        if (curr != nullptr)
            return curr->data;
    }

    int& operator[](int i){
        node* curr = head;
        for(int j = 0; j < i; j++){
            curr = curr->next;
        }
        return curr->data;
    }

    void push_back(int new_element){
        node* element = new node;
        element->data = new_element;
        element->next = nullptr;
        if (head == nullptr){
            head = element;
        }
        else
        {
        node* curr = head;
        while(curr->next != nullptr){
            curr = curr->next;
        }
        curr->next = element;

        }


    }

    int pop_back(){
        if(head != nullptr){
            head = nullptr;
        }
        else{
        node* curr = head;
        while(curr->next->next != nullptr){
            curr = curr->next;
        }
        node* last_node = curr->next;
        int element = last_node->data;
        curr->next = nullptr;
        free(last_node);
        return element;
        }
        }



    void clear(){
        if (head == nullptr) {
            return;
        }
        node* curr = head;

        while (curr->next != nullptr) {
            node* tmp = curr->next;
            delete curr;
            curr = tmp;
        }
        delete curr;
    }
    void reverse()
     {
        node* curr = head;
        node *prev = nullptr;
        node *next = nullptr;

        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        head = prev;
     }

};


int main() {
    using namespace std;
    int n = 5;
    list_of_ints lst(n);
    initialization_container_of_ints(&lst);
    show_container_of_ints(&lst);
    lst.reverse();
    show_container_of_ints(&lst);

    return 0;
}
