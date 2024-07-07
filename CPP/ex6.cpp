#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

class BankAccount{
    public:
    BankAccount(int ID_i, float balance_i): ID(ID_i),balance(balance_i) {}
    
    virtual ~BankAccount() = default;
    
    virtual double calculateInterest() const = 0;

    virtual void displayBalance() const{
        cout << "ID User: " << ID << endl;
        cout << "balance: " << balance << endl;
    }
    
    void deposit(float dp){
        balance += dp;
        cout << "deposit: " << balance << endl;
    }
    void withdrawlas(float wd){
        balance -= wd;
        cout << "withdrawlas: " << balance << endl;
    }


    protected:
    int ID;
    float balance;
};

class SavingsAccount: public BankAccount{
    public:
        SavingsAccount(int ID_i, float balance_i, float rate_i)
            :BankAccount(ID_i,  balance_i),interestRate(rate_i){}
    
    double calculateInterest() const override {
        return balance * interestRate;
    }

    void displayBalance(void) const override {
        BankAccount::displayBalance();
        cout << "Account Type: Savings, Interest: " << calculateInterest() << endl;
    }

    private:
    float interestRate;
};

class CheckingAccount: public BankAccount{

    public:

    CheckingAccount(int ID_i, float balance_i)
        : BankAccount(ID_i, balance_i){}

    double calculateInterest() const override {
        return 0.0;
    }

    void displayBalance() const override {
        BankAccount::displayBalance();
        cout << "Account Type: Checking, Interest: " << calculateInterest() << endl;
    }

};


int main(void){

        // Polimorfismo usando punteros inteligentes
    vector<unique_ptr<BankAccount>> accounts;
    accounts.push_back(std::make_unique<SavingsAccount>(1, 1000.0, 0.03));
    accounts.push_back(std::make_unique<CheckingAccount>(2, 2000.0));


    for (const auto& account : accounts) {
        account->displayBalance();
        std::cout << std::endl;
    }

    BankAccount* user = accounts[0].get();
    user->deposit(500);

    for (const auto& account : accounts) {
        account->displayBalance();
        std::cout << std::endl;
    }

    return 0;
}