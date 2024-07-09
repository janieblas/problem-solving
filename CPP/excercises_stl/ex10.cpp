#include <iostream>
#include <map>
#include <string>
#include <algorithm>

class StoreInventory{

    public:

    ~StoreInventory(void){}

    void addProduct(const std::string& name, int quantity){
            products[name] = quantity;
    }

    bool removeProduct(const std::string& name){
        return products.erase(name) > 0;
    }

    bool updateProduct(const std::string name, int newQuantity){
        auto it = products.find(name);
        if (it != products.end())
        {
            it->second = newQuantity;
            return true;
        }
        return false;
    }

    void printProducts(void) const{
        for (const auto& product : products)
        {
            std::cout << "product:" << product.first << ", quantity: " << product.second << std::endl; 
        }
        
    }
    private:
    std::map<std::string, int> products;
};

int main(void){

    StoreInventory products;

    products.addProduct("cerial", 2);
    products.addProduct("leche", 1);
    products.addProduct("papel",8);

    products.printProducts();

    std::cout << std::endl;

    products.removeProduct("leche");
    products.updateProduct("cerial", 1);

    products.printProducts();

    return 0;
}