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
    virtual int& pop_back() = 0;

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

class array_of_ints: public container_of_ints{

private:

    int *array;
    int m_size;

public:
    array_of_ints(int size) { //konstruktor
        array = new int[size];
        this->m_size = size;

    }
    int size(){
        return m_size;
    }

    int& at(int i){
        if (i < m_size)
            return array[i];
    }
    int& operator[](int i){
        return array[i];
    }
    void push_back(int new_element){
        int* t_arr = new int[m_size];
        m_size += 1;
        for (int i = 0; i < m_size-1; i++){
            t_arr[i] = array[i];
        }
        array = new int[m_size];
        for (int i = 0; i < m_size; i++){
            array[i] = t_arr[i];
        }
        array[m_size-1] = new_element;
    }
    int& pop_back(){
        int& temp = array[m_size - 1];
        int* t_arr = new int[m_size];
        for (int i = 0; i < m_size-1; i++){
            t_arr[i] = array[i];
        }
        m_size -= 1;
        array = new int[m_size];
        for (int i = 0; i < m_size; i++){
            array[i] = t_arr[i];
        }
        return temp;
    }
    void clear(){
        delete[] array;
    }
    void reverse(){
        int *temp = new int[m_size];
        for(int i=0;i<m_size-1;i++)
            if (i == 0)
                temp[i] = array[m_size-1];
            else
                temp[i] = array[m_size-(i+1)];
        for(int i=0;i<m_size;i++)
            array[i] = temp[i];
    }

};

int main() {
    using namespace std;
    int n = 5;
    array_of_ints arr(n);
    initialization_container_of_ints(&arr);

    show_container_of_ints(&arr);
    arr.push_back(5);
    show_container_of_ints(&arr);
    cout << arr.pop_back() << endl;
    show_container_of_ints(&arr);
    arr.reverse();
    show_container_of_ints(&arr);

    return 0;
}
