#include <iostream>
#include <string>
#include <vector>

#define PI 3.1416

using namespace std;

class Shape{

    public:
    
    virtual void displayShape() const = 0;
    virtual float calculateShape() const = 0;

    virtual ~Shape(){};

};

class Circule: public Shape{

    public:
    Circule(float rd):radius(rd ){}

    float calculateShape() const override{
        return PI * radius  * radius;
    }
    void displayShape()const override{
        cout << "Circule area: " << calculateShape() << endl;
    }

    private:
    float radius ;

};

class Rectangle: public Shape{

    public:
    Rectangle(float wit, float het): width(wit), heigth(het){}

    float calculateShape() const override{
        return width * heigth;
    }

    void displayShape() const override{
        cout << "rectangle area: " << calculateShape() << endl;
    }

    private:
    float width;
    float heigth;
};
int  main(void){

    vector<Shape*> shapes;

    shapes.push_back(new Rectangle(5.0, 5.0));
    shapes.push_back(new Circule(5.0));

    for (const auto& shape: shapes)
    {
        shape->displayShape();
    }
    
    for(auto& shape : shapes){
        delete shape;
    }

    return 0;
}