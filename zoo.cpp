#include <iostream>

using namespace std;

class Animal {

public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

class Monkey: public Animal{

protected:
    string type;
public:
    string getType(){
    return type;
    }
    bool isDangerous(){
        return false;
    }

};

class Lion: public Animal{
    protected:
    string type;

    string getType(){
        return type;
    }
    bool isDangerous(){
        return true;
    }

};



class ZooKeeper {

private:
     int counter = 0;
public:

    ZooKeeper() {

    }

    // Смотрителя попросили обработать очередного зверя.
    // Если зверь был опасный, смотритель фиксирует у себя этот факт.
    void handleAnimal(Animal* a){
        if (a->isDangerous())
            counter ++;
    }

    // Возвращает, сколько опасных зверей было обработано на данный момент.
    int getDangerousCount(){
        return counter ;
    }
};

int main()
{

    ZooKeeper z;
    Monkey *m = new Monkey();
    z.handleAnimal(m);
    delete m;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion *l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;

    return 0;
}
