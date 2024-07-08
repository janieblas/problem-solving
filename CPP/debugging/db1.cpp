#include <iostream>
#include <vector>
#include <string>

class Transaction {
public:
    Transaction(std::string desc, double amt) : description(desc), amount(amt) {}
    void print() const {
        std::cout << description << ": " << amount << std::endl;
    }
private:
    std::string description;
    double amount;
};

class Account {
public:
    Account(std::string accName, double initialBalance) : name(accName), balance(initialBalance) {}
    
    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount));
    }

    void withdraw(double amount) {
        if (balance < amount) {
            // add amount to Cout 
            std::cout << "Insufficient funds for withdrawal!" << amount << std::endl;
            return;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdraw", amount));
    }

    void printStatement() const {
        std::cout << "Account: " << name << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        for (const auto& t : transactions) {
            t.print();
        }
    }

private:
    std::string name;
    double balance;
    std::vector<Transaction> transactions;
};

int main() {
    Account myAccount("My Savings", 1000.0);

    myAccount.deposit(200.0);
    myAccount.withdraw(500.0);
    myAccount.withdraw(800.0);
    myAccount.printStatement();

    return 0;
}
