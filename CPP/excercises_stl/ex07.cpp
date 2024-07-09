#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

class Library{

    public:
    void addBook(const std::string& title, const std::string& author){
       books.emplace_back(title, author);
       //books.push_back(make_pair(title, author));
    }

    void removeBook(const std::string& title){ 
        auto it = std::find_if(books.begin(), books.end(), [&title](const auto& book) {
            return book.first == title;
        });

        if (it != books.end())
        {
            books.erase(it);
        }
    }

    int getBookCount() const{
        return books.size();
    }
    void printBooks() const{
        for (const auto& book : books)
        {
            std::cout << "title: " << book.first << ", author: " << book.second << std::endl;
        }
        //std::cout << std::endl;
    }
    private:
    std::vector<std::pair<std::string, std::string>> books;
};

int main(void){
    Library books;

    books.addBook("The Great Gatsby","F. Scott Fitzgerald");
    books.addBook("1984","George Orwell");
    books.addBook("To Kill a Mockingbird","Harper Lee");

    books.printBooks();
    
    std::cout << std::endl;
    
    books.removeBook("To Kill a Mockingbird");

    books.printBooks();

    return 0;
}