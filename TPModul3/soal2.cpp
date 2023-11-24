#include<iostream>

using namespace std;

class shape{
private:
    float area;
    float keliling;
public:
    virtual float calculatedArea(){return 0;}
    virtual float calculatedKeliling(){return 0;} // bisa jika make virtual di awal
};

class rectangle : public shape{
private:
    float width;
    float length;
public:
    rectangle(float width,float length){
        this->width = width;
        this->length = length;
    }
    float calculatedArea(){
        return (width*length);
    }
    float calculatedKeliling(){
        return (2*(width+length));
    }
};

int main()
{
   rectangle rect(5.0,4.0);
   shape* shape1=&rect;
   
   cout<<shape1->calculatedArea()<<endl;
   cout<<shape1->calculatedKeliling()<<endl;


    return 0;
}