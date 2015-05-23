##ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

class Account {
public:
  Account(const std::string& name="", int acct=0, double bal=0) {
    accountHolder = name;
    accountNumber = acct;
    balance = bal;
    numOfTrans = 0;
    maxTrans = 10;
    allTransactions = new Transaction[maxTrans];
  }

  ~Account() {
    delete[] allTransactions;
  }

  // Getters
  double getNumOfTrans() const {
    return numOfTrans;
  }

  double getBalance() const {
    return balance;
  }

  string getName() const {
    return accountHolder;
  }

  int getAccountNum() const {
    return accountNumber;
  }

  // Setters
  void setAcctHolder(const string& name) {
    accountHolder = name;
  }

  // Account interface
  bool withdraw(double amount);

  bool deposit(double amount);

  // Transaction interface
  Transction getTransactionByNum(int i) const;

  // Security
  bool validateLogin(int acctNum, const string& pass) const;

private:
  string accountHolder;
  int accountNumber;
  string accountPasseword;
  double balance;
  int numOfTrans;
  int maxTrans;
  Transaction* allTransactions;

  // Increases the size of the ledger when needed
  bool resizeTransLedger();
};

#endif