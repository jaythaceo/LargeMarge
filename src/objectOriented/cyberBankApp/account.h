##ifndef ACCOUNT_H
#define ACCOUNT_H

#include "transaction.h"
#include <iostream>
#include <string>

using namespace std;

class account {
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
public:
  account(const std::string& name="", int acct=0, double bal=0)
  
};





#endif