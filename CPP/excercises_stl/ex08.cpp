#include <iostream>
#include <vector>

#include <string>
#include <algorithm>

class Inventary{
    public:
    ~Inventary(void){}

    void addProduct(std::string name, int quantity){
        products.emplace_back(name, quantity);
    }

    bool removeProduct(std::string name){
        auto it = std::find_if(products.begin(), products.end(),[&name](const auto& product){
            return product.first == name;
        });

        if (it != products.end())
        {
            products.erase(it);
            return true;
        }
        return false;
    }

    bool updateProductQuantity(const std::string& name, int newQuantity){
        auto it = std::find_if(products.begin(), products.end(), [&name](const auto& product) {
            return product.first == name;
        });

        if (it != products.end()) {
            it->second = newQuantity;
            return true;
        }
        return false;        

    }
    void printProducts(void){
        for (const auto& product : products)
        {
            std::cout << product.first << ":\t" << product.second << std::endl;
        }
        
    }
    private:
    std::vector<std::pair<std::string, int>> products;
};

int main(void){
    Inventary products;

    products.addProduct("sal", 5);
    products.addProduct("galletas", 3);
    products.addProduct("soda", 10);

    products.printProducts();
    
    std::cout << std::endl;

    products.removeProduct("galletas");
    products.updateProductQuantity("soda", 11);

    products.printProducts();


    return 0;
}