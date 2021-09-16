#include <iostream>
#include <utility>
#include <vector>

class Cat {
    std::string name;
    int age{}; // what the heck does this do?
public:
    Cat():age(0){
        std::cout << "Default ctor" << std::endl;
    }
    Cat(const Cat& rhs){
        std::cout << "Copy ctor" << std::endl;
    }
    explicit Cat(std::string name):name(std::move(name)){ // What is all this?
        std::cout << "In the parameterized ctor" << std::endl;
    }
    Cat(std::string name, int age):name(std::move(name)), age(age){
        std::cout << "In the parameterized ctor with both params" << std::endl;
    }
    std::string toString(){
        return "Name: " + name + ", Age: " + std::to_string(age);

    }
};



void basicVector();

void vectorWithObjects();

int main() {
    basicVector();
    //vectorWithObjects();
}

void vectorWithObjects() {
    std::vector<Cat> cats;
    //cats.emplace_back(Cat());
    cats.emplace_back("Tom");
    cats.emplace_back("Thomas",12);
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
    corbin.at(10) = 100; // no can do
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
