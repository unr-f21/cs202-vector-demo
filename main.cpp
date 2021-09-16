#include <iostream>
#include <utility>
#include <vector>

/**
 * Look through the code below for lines marked TODO. These
 * are lines of code that I would like you to investigate to
 * understand what they are doing. I would
 * suggest making notes on what you find so that you will be
 * ready to answer questions on a quiz or exam.
 *
 * Study the constructors and run the code as we did in class
 * to ensure that you understand why a constructor is called
 * in each case.
 */


class Cat {
    std::string name;
    int age{}; // TODO: What do the {} do here?
public:
    Cat(){
        std::cout << "Default ctor" << std::endl;
    }
    Cat(const Cat& rhs){
        std::cout << "Copy ctor for " << rhs.name << std::endl;
        name = rhs.name;
        age = rhs.age;
    }
    explicit Cat(std::string name):name(std::move(name)){ //TODO: What does std::move do here?
        std::cout << "In the parameterized ctor" << std::endl;
    }
    Cat(std::string name, int age):name(std::move(name)), age(age){
        std::cout << "In the parameterized ctor with both params" << std::endl;
    }
    std::string toString(){
        return "Name: " + name + ", Age: " + std::to_string(age); //TODO: what is std::to_string?

    }
};



void basicVector();

void vectorWithObjects();

int main() {
    //basicVector();
    vectorWithObjects();
}

void vectorWithObjects() {
    std::vector<Cat> cats(3);
    //cats.emplace_back(Cat());
    cats.emplace_back("Thomas",12);
    cats.emplace_back("Tom");
    for(Cat& cat: cats){
        std::cout << cat.toString() << std::endl;

    }
}

void basicVector() {
    std::vector<int> lilu;
    for(int n = 0; n < 10; n++){
        lilu.push_back(n);
    }

    std::vector<int> corbin {1,2,3,4,5}; // direct initialization
    //corbin.at(10) = 100; // no can do
    for(int n: corbin){
        std::cout << n << std::endl;
    }

    for(int n = 0; n < lilu.size(); n++){
        std::cout << lilu[n] << std::endl;
    }

    for(int n : lilu){
        std::cout << lilu.at(n); // alias for v[n] that does bounds checking
    }
    std::cout << std::endl;

    lilu.erase(lilu.begin() + 5); // erase the fifth element

    // now do a multi-pass on contents
    for(int n = 0; n < lilu.size(); n++ ){
        std::cout << lilu[n];
    }
    std::cout << std::endl;
    for(int n : lilu){
        std::cout << "index:" << n << " ";
        std::cout << "value: " << lilu[n] << " " << std::endl;
    }
}
