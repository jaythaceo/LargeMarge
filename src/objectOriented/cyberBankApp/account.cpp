

bool Account::withdraw(double amt) {
  // Ensure there is a enough money in account to make withdrawal
  if (balance < amt)
  {
    return false;
  } else {
    balance -= amt;
    numOfTrans++;

    if (numOfTrans == maxTrans)
    {
      if (!resizeTransLedger())
      {
        cerr << "Out of memory" << endl;
        exit(-1);
      }
    }
    // Add withdrawal to transaction log
    allTransactions[numOfTrans-1].setTransID(numOfTrans);
    allTransactions[numOfTrans-1].setTransType(0);
    allTransactions[numOfTrans-1].setTransAmt(amt);

    return true;
  }
}

