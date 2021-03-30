#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Object{

public:
    virtual void whoAmI()= 0;
    virtual std::string toString()=0;
    virtual Object* clone()=0;
    virtual ~Object(){}
};

class StringObject: public Object{

private:
    char* value;
    size_t size;
    
public:
    StringObject(char* value, size_t size) {    
        this->value=value;
        this->size=size;    }
    
    char* get()const {  return value;   }
    void whoAmI() override {    std::cout<<"STRING"<<get()<<endl;   }
    std::string toString() {    return "StringObject";   }
    Object* clone() override {  return new StringObject(*this);}

};

class IntObject: public Object{

private:
    int value;
public:
    IntObject(int value) {  this->value=value;}
    int get()const {  return value; }
    void whoAmI() override {    std::cout<<"INT "<<get()<<endl;   }
    std::string toString(){  return "IntObject";  }
    Object* clone() override {  return new IntObject(*this);}
};

class DoubleObject: public Object{

private:
    double value;

public:
    DoubleObject(double value) {  this->value=value;    }
    double get()const {  return value; }
    void whoAmI() override {    std::cout<<"DOUBLE "<<get()<<endl;   }
    std::string toString(){  return "DoubleObject";  }
    Object* clone() override {  return new DoubleObject(*this); }   
};




void func(std::vector<Object*> objects){
    
    for(int i=0; i<objects.size(); ++i){
        double sum;
        if(objects[i]->toString() == "DoubleObject")
        {
            objects[i]->whoAmI();
        }
        
    }

}

int main(){
    char tab1[10]= "asdasdas";
    DoubleObject d1(321.234523);
    std::vector<Object*> objects {new StringObject(tab1,10), new IntObject(15), new DoubleObject(20.531), new IntObject(16), new DoubleObject(423.312)};
    func(objects);

}