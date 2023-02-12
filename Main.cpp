#include <iostream>
#include <vector>
using namespace std;

int g_DefId = 1, g_CredId = 1, g_DepId = 1;

class Account {
public:
    Account() {
        this->id = 1;
        this->balance = 0.f;

        this->name = "Empty";
        this->type = "$";
        this->compName = "Bank #11";
        this->additionalAnalytic = "Empty";
    }

    void TopUpBalance() {
        cout << "Top up account: "; float tempBalance; cin >> tempBalance;
        if (tempBalance >= 0) {
            balance += tempBalance;
            cout << "Successful\n\n\n\n";
        }
        else {
            cout << "Balance cannot be negative\n\n\n\n";
        }
    }

    void WithdrawMoney() {
        cout << "Withdraw money: "; float tempBalance; cin >> tempBalance;
        if ((this->balance - tempBalance) >= 0) {
            this->balance -= tempBalance;
            cout << "Successful\n\n\n\n";
        }
        else {
            cout << "Balance cannot be negative\n\n\n\n";
        }
    }

    void CreateAccount() {
        cout << "Set name of account: ";  cin >> name;
        cout << "Currency type: ";  cin >> type;
        cout << "Top up account: ";  cin >> balance;

        this->id = g_DefId; g_DefId++;
        this->compName = "Bank #11";
        this->additionalAnalytic = "Empty";

        GetInfo();
    }

    void GetInfo() {
        cout << "\n";
        cout << "1. Id: " << id << "\n";
        cout << "2. Balance: " << balance << type << "\n";
        cout << "3. Name:" << name << "\n";
        cout << "4. Company name: " << compName << "\n";
        cout << "5. Additional Analytic: " << additionalAnalytic << "\n\n\n\n";
    }

protected:
    int id; // 123132412
    int balance; // balance
    string name; // name
    string type; // $
    string compName; // Bank #10
    string additionalAnalytic;
};

class Credit : public Account {
public:
    void WithdrawMoney() {
        float temp;
        cout << "Withdraw money: "; cin >> temp; this->balance -= temp;
        cout << "Successful\n\n\n\n";
        if (this->balance < 0) {
            additionalAnalytic = "30%";
        }
    }

    void CreateAccount() {
        cout << "Set name of account: ";  cin >> name;
        cout << "Currency type: ";  cin >> type;
        cout << "Top up account: ";  cin >> balance;

        this->id = g_CredId; g_CredId++;
        this->compName = "Bank #11";
        this->additionalAnalytic = "Empty";

        GetInfo();
    }
};

class Deposit : public Account {
public:
    void GetInfo() {
        cout << "\n";
        cout << "1. Id: " << id << "\n";
        cout << "2. Balance: " << balance << type << "\n";
        cout << "3. Name:" << name << "\n";
        cout << "4. Company name: " << compName << "\n";
        cout << "5. Additional Analytic: " << additionalAnalytic << "\n";
        cout << "6. Deposit expiry date: " << anotherInfo.day << "/" << anotherInfo.month << "/" << anotherInfo.year << "\n";
    }

    void CreateAccount() {
        cout << "Set name of account: ";  cin >> name;
        cout << "Currency type: ";  cin >> type;
        cout << "Top up account: ";  cin >> balance;

        this->id = g_DepId; g_DepId++;
        this->compName = "Bank #11";
        this->additionalAnalytic = "Empty";

        GetInfo();
    }
protected:
    struct Another {
        int day = 19;
        int month = 1;
        int year = 2038;
    }anotherInfo;
};

int main() {
    vector<Account> DefaultAccount; Account TempDefaultAccount;
    vector<Credit> CreditAccount; Credit TempCreditAccount;
    vector<Deposit> DepositAccount; Deposit TempDepositAccount;

    int line;
    while (true) {
        cout << "\n\n1. Create account\n";
        cout << "2. Withdraw\n";
        cout << "3. Top up\n";
        cout << "4. Show account\n";
        cout << "->"; cin >> line;

        switch (line) {
        case 1:
            cout << "Account type (Default - 1; Credit - 2; Deposit - 3):"; cin >> line;
            if (line == 1) {
                TempDefaultAccount.CreateAccount();
                DefaultAccount.push_back(TempDefaultAccount);
            }
            else if (line == 2) {
                TempCreditAccount.CreateAccount();
                CreditAccount.push_back(TempCreditAccount);
            }
            else if (line == 3) {
                TempDepositAccount.CreateAccount();
                DepositAccount.push_back(TempDepositAccount);
            }
            else {
                cout << "Unknown command, try again\n";
            }
            break;
        case 2:
            cout << "Account type (Default - 1; Credit - 2; Deposit - 3):"; cin >> line;
            if (line == 1) {
                cout << "Write id:"; cin >> line;
                DefaultAccount[line - 1].WithdrawMoney();
            }
            else if (line == 2) {
                cout << "Write id:"; cin >> line;
                CreditAccount[line - 1].WithdrawMoney();
            }
            else if (line == 3) {
                cout << "Write id:"; cin >> line;
                DepositAccount[line - 1].WithdrawMoney();
            }
            else {
                cout << "Unknown command, try again\n";
            }
            break;
        case 3:
            cout << "Account type (Default - 1; Credit - 2; Deposit - 3):"; cin >> line;
            if (line == 1) {
                cout << "Write id:"; cin >> line;
                DefaultAccount[line - 1].TopUpBalance();
            }
            else if (line == 2) {
                cout << "Write id:"; cin >> line;
                CreditAccount[line - 1].TopUpBalance();
            }
            else if (line == 3) {
                cout << "Write id:"; cin >> line;
                DepositAccount[line - 1].TopUpBalance();
            }
            else {
                cout << "Unknown command, try again\n";
            }
            break;
        case 4:
            cout << "Account type (Default - 1; Credit - 2; Deposit - 3):"; cin >> line;
            if (line == 1) {
                cout << "Write id:"; cin >> line;
                DefaultAccount[line - 1].GetInfo();
            }
            else if (line == 2) {
                cout << "Write id:"; cin >> line;
                CreditAccount[line - 1].GetInfo();
            }
            else if (line == 3) {
                cout << "Write id:"; cin >> line;
                DepositAccount[line - 1].GetInfo();
            }
            else {
                cout << "Unknown command, try again\n";
            }
            break;
        default:
            cout << "Unknown command, try again\n";
            break;
        }
    }

    return 0;
}

/*
Написати клас Рахунок, в якому мають бути передбачені наступні властивості:
1) ідентифікатор;
2) назва;
3) валюта;
4) установа, де рахунок відкритий;
5) додаткова аналітика;
6) залишок;
На основі попереднього класу створіть успадковані класи Кредитний і Депозитний. Особливістю класу
Кредитний має бути те, що залишок може бути від’ємний. В додатковій аналітиці має бути відсоток, який
нараховується на залишок. Має появитися нове поле “інше”, де має бути прогнозована дата закінчення депозита або
кредита.
*/
