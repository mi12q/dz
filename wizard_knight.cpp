#include <iostream>

using namespace std;

class Item {
    string title;
    int weight;
    int level;
    bool magical;
public:
    // Так можно создать предмет, указав его название, вес, уровень и магичность
    Item(string title, int weight, int level, bool magical){

    }
    // Получить вес предмета
    int getWeight(){
        return weight;
    }
    // Получить уровень предмета
    int getLevel(){
        return level;
    }
    // Получить, является ли предмет магичным
    int isMagical(){
        return magical;
    }
};

class Player {
protected:
    // Сила и уровень героя
    int strength;
    int level;
public:
    // Создать героя, все подробности будут указаны позже
    Player() { }
    // Удалить героя, ничего умного эта процедура пока что не требует
    virtual ~Player() { }

    // Базовые методы, пока что очень простые.
    // На данном этапе можно считать, что для всех героев они ведут себя одинаково,
    // так что пусть будут в базовом классе.

    // Задать силу
    void setStrength(int strength) {
        this->strength = strength;
    }
    // Задать уровень
    void setLevel(int level) {
        this->level = level;
    }

    // Получить силу
    int getStrength() {
        return this->strength;
    }
    // Получить уровень
    int getLevel() {
        return this->level;
    }

    // Проверка, может ли игрок использовать предмет
    virtual bool canUse(Item* item) = 0;
};



class Knight: public Player{
    bool canUse(Item* item){
        if(item->isMagical() == true){
            return false;
        }
        else{
            if(((item->getWeight() <= this->strength)) and (item->getLevel() <= this->level)){
                return true;
            }
            else return false;
        }
    }
};

class Wizard: public Player{
    bool canUse(Item* item){
        if(((item->getWeight() <= this->strength)) and (item->getLevel() <= this->level)){
            return true;
        }
        else return false;
    }
};


int main()
{
    Item* items[3];
    items[0] = new Item("Small sword", 1, 1, false);
    items[1] = new Item("Big sword", 5, 3, false);
    items[2] = new Item("Ward", 1, 3, true);

    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
        }
    }
    return 0;
}
