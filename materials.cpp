#include <iostream>

using namespace std;



class Material
{
public:
    // Принимает на вход величину деформации.
    // Возвращает величину напряжения, посчитанную с учётом реологии материала.
    virtual float getStress(float strain) = 0;
};

class ElasticMaterial: public Material{
    private:
        float elasticModulus;
    public:
        ElasticMaterial(float elasticModulus){
            this->elasticModulus = elasticModulus;
        }
        float getStress(float strain){
            return elasticModulus * strain;
        }

};

class PlasticMaterial: public Material{
    private:
        float elasticModulus;
        float strainLimit;
    public:
        PlasticMaterial(float elasticModulus, float strainLimit){
            this->elasticModulus = elasticModulus;
            this->strainLimit = strainLimit;
        }
        float getStress(float strain){
            if ((strain > 0) && (strain <= this->strainLimit)){
                return strain*elasticModulus;

            }
            else return strainLimit*elasticModulus;
        }
};

int main()
{
        Material* m;
    m = new ElasticMaterial(100);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    m = new PlasticMaterial(100, 0.01);
    cout << "Material stress is: " << m->getStress(0.1) << endl;
    delete m;
    return 0;
}

