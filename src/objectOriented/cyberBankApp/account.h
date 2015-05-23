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