#include <iostream>
#include <vector>
#include <memory>

using namespace std;

// Clase base abstracta
class LibraryItem {
public:
    LibraryItem(const string& title, const string& author)
        : title(title), author(author) {}

    virtual ~LibraryItem() = default;

    virtual void displayInfo() const = 0;
    virtual double calculateLateFee(int daysLate) const = 0;

protected:
    string title;
    string author;
};

// Clase derivada que representa un libro
class Book : public LibraryItem {
public:
    Book(const string& title, const string& author, int pageCount)
        : LibraryItem(title, author), pageCount(pageCount) {}

    void displayInfo() const override {
        cout << "Book: " << title << " by " << author << ", " << pageCount << " pages" << endl;
    }

    double calculateLateFee(int daysLate) const override {
        return daysLate * 0.25; // 0.25 currency units per day late
    }

private:
    int pageCount;
};

// Clase derivada que representa una revista
class Magazine : public LibraryItem {
public:
    Magazine(const string& title, const string& author, int issueNumber)
        : LibraryItem(title, author), issueNumber(issueNumber) {}

    void displayInfo() const override {
        cout << "Magazine: " << title << " by " << author << ", Issue " << issueNumber << endl;
    }

    double calculateLateFee(int daysLate) const override {
        return daysLate * 0.10; // 0.10 currency units per day late
    }

private:
    int issueNumber;
};

// Clase que maneja una colección de LibraryItem
class Library {
public:
    void addItem(LibraryItem* item) {
        items.push_back(item);
    }

    void displayAllItems() const {
        for (const auto& item : items) {
            item->displayInfo();
        }
    }

    void displayLateFees(int daysLate) const {
        for (const auto& item : items) {
            cout << "Late fee for ";
            item->displayInfo();
            cout << ": " << item->calculateLateFee(daysLate) << " currency units" << endl;
        }
    }

    const vector<LibraryItem*>& getItems() const {
        return items;
    }

private:
    vector<LibraryItem*> items;
};

int main() {
    Library library;

    library.addItem(new Book("1984", "George Orwell", 328));
    library.addItem(new Magazine("National Geographic", "Various Authors", 130));

    cout << "Library items:" << endl;
    library.displayAllItems();

    cout << "\nLate fees for 5 days late:" << endl;
    library.displayLateFees(5);

    // Liberar memoria
    for (auto item : library.getItems()) {
        item->displayInfo();
    }

    return 0;
}
