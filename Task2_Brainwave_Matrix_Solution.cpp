#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
    string Account_Holder_Name;
    long long Account_Number;
    string type;
    float Balance;

public:
    Bank()
    {
        Account_Holder_Name = "";
        Account_Number = 0;
        type = "";
        Balance = 0;
    }

    void Open_Account();
    void Deposit_Money();
    void Withdraw_Money();
    void Transfer_Money(Bank &Account2);
    void Display_Account_Details() const;
    long long Get_Account_Number() const { return Account_Number; }
};

// Function to open a new account
void Bank::Open_Account()
{
    cout << "Enter your Name: ";
    cin >> Account_Holder_Name;
    cout << "Enter your Account Number: ";
    cin >> Account_Number;
    cout << "Enter your type of Account: ";
    cin >> type;
    cout << "Account Created for " << Account_Holder_Name << " successfully.\n\n";
}

// Function to Deposit Money
void Bank::Deposit_Money()
{
    cout << "Amount to Deposit: ";
    int deposit;
    cin >> deposit;
    Balance += deposit;
    cout << "Deposit Successful.\n\n";
}

// Function to Withdraw Money
void Bank::Withdraw_Money()
{
    cout << "Amount to Withdraw: ";
    int withdraw;
    cin >> withdraw;
    if (withdraw > Balance)
    {
        cout << "Transaction Declined. Insufficient Balance.\n\n";
    }
    else
    {
        Balance -= withdraw;
        cout << "Withdrawal Successful.\n\n";
    }
}

// Function to Transfer money from one account to another
void Bank::Transfer_Money(Bank &Account2)
{
    cout << "Amount to Transfer: ";
    int Money_Transfer;
    cin >> Money_Transfer;
    if (Money_Transfer <= Balance)
    {
        Balance -= Money_Transfer;
        Account2.Balance += Money_Transfer;
        cout << "Transfer Successful.\n\n";
    }
    else
    {
        cout << "Transaction Declined. Insufficient Balance.\n\n";
    }
}

// Function to display account details
void Bank::Display_Account_Details() const
{
    cout << "Account Holder Name: " << Account_Holder_Name << "\n";
    cout << "Your Account Number: " << Account_Number << "\n";
    cout << "Type of Account: " << type << "\n";
    cout << "Available Balance: " << Balance << "\n\n";
}

int main()
{
    map<long long, Bank> accounts;
    int choice;
    while (1)
    {
        cout << "Enter Your Choice\n";
        cout << "\t1. Create Account\n";
        cout << "\t2. Deposit Money\n";
        cout << "\t3. Withdraw Money\n";
        cout << "\t4. Transfer Money\n";
        cout << "\t5. Display Account Details\n";
        cout << "\t6. Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Bank new_account;
            new_account.Open_Account();
            accounts[new_account.Get_Account_Number()] = new_account;
            break;
        }
        case 2:
        {
            cout << "Enter your Account Number: ";
            long long acc_num;
            cin >> acc_num;
            if (accounts.find(acc_num) != accounts.end())
            {
                accounts[acc_num].Deposit_Money();
            }
            else
            {
                cout << "Account not found.\n\n";
            }
            break;
        }
        case 3:
        {
            cout << "Enter your Account Number: ";
            long long acc_num;
            cin >> acc_num;
            if (accounts.find(acc_num) != accounts.end())
            {
                accounts[acc_num].Withdraw_Money();
            }
            else
            {
                cout << "Account not found.\n\n";
            }
            break;
        }
        case 4:
        {
            cout << "Enter your Account Number: ";
            long long acc_num;
            cin >> acc_num;
            if (accounts.find(acc_num) != accounts.end())
            {
                cout << "Enter the Account Number to transfer to: ";
                long long target_acc_num;
                cin >> target_acc_num;
                if (accounts.find(target_acc_num) != accounts.end())
                {
                    accounts[acc_num].Transfer_Money(accounts[target_acc_num]);
                }
                else
                {
                    cout << "Target account not found.\n\n";
                }
            }
            else
            {
                cout << "Account not found.\n\n";
            }
            break;
        }
        case 5:
        {
            cout << "Enter your Account Number: ";
            long long acc_num;
            cin >> acc_num;
            if (accounts.find(acc_num) != accounts.end())
            {
                accounts[acc_num].Display_Account_Details();
            }
            else
            {
                cout << "Account not found.\n\n";
            }
            break;
        }
        case 6:
            cout << "Transaction Ended\n\n\n";
            return 0;
        default:
            cout << "Invalid Choice. Try Again.\n\n";
        }
    }
}
