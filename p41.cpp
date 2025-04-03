#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

class ATM {
private:
    double balance;

public:
    ATM(double initial_balance) {
        if (initial_balance < 0) {
            cout << "Ошибка: начальный баланс не может быть отрицательным. Установлен баланс 0 грн." << endl;
            balance = 0;
        }
        else {
            balance = initial_balance;
        }
    }

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма пополнения должна быть больше 0 грн." << endl;
            return;
        }
        if (amount > 1000000) {
            cout << "Ошибка: максимальная сумма пополнения — 1 000 000 грн." << endl;
            return;
        }
        balance += amount;
        cout << "Вы успешно пополнили счёт на " << fixed << setprecision(2) << amount << " грн." << endl;
        showBalance();
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Ошибка: сумма снятия должна быть больше 0 грн." << endl;
            return;
        }
        double commission = amount * 0.005;
        if (commission > 50) commission = 50;
        double totalAmount = amount + commission;

        if (totalAmount > balance) {
            cout << "Ошибка: недостаточно средств на счету." << endl;
            return;
        }

        balance -= totalAmount;
        cout << "Вы сняли " << fixed << setprecision(2) << amount << " грн с комиссией " << commission << " грн." << endl;
        showBalance();
    }

    void showBalance() const {
        cout << "\n======================================" << endl;
        cout << "Текущий баланс: " << fixed << setprecision(2) << balance << " грн." << endl;
        cout << "======================================\n" << endl;
    }
};

void showMenu() {
    cout << "\n======================================" << endl;
    cout << "         БАНКОМАТ          " << endl;
    cout << "======================================" << endl;
    cout << "1. Пополнить счёт" << endl;
    cout << "2. Снять деньги" << endl;
    cout << "3. Проверить баланс" << endl;
    cout << "0. Выйти" << endl;
    cout << "======================================" << endl;
    cout << "Ваш выбор: ";
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    double initial_balance;
    cout << "Введите начальный баланс: ";
    cin >> initial_balance;

    ATM atm(initial_balance);

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            double amount;
            cout << "Введите сумму пополнения: ";
            cin >> amount;
            atm.deposit(amount);
            break;
        }
        case 2: {
            double amount;
            cout << "Введите сумму снятия: ";
            cin >> amount;
            atm.withdraw(amount);
            break;
        }
        case 3:
            atm.showBalance();
            break;
        case 0:
            cout << "Выход..." << endl;
            break;
        default:
            cout << "Ошибка: некорректный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 0);

    return 0;
}