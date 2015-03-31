// fin_recipes.h
// Created by: Jason "Jaythaceo" Brooks
// Email: jaythaceo@gmail.com

##ifndef FIN_RECIPES_H
#define FIN_RECIPES_H

#include <vector>
#include <math>
using namespace std;

/*
  Present value
  discrete compounding interest
  discrete annual interest
*/

double cash_flow_pv_discrete(const vector<double>& cflow times,
                             const vector<double>& cflow amounts,
                             const double& r);

double cash flow irr discrete(const vector<double>& cflow times,
                              const vector<double>& cflow amounts);

bool cash flow unique irr(const vector<double>& cflow times,
                          const vector<double>& cflow amounts);

double bonds price discrete(const vector<double>& cashflow times,
                            const vector<double>& cashflows,
                            const double& r);

double bonds yield to maturity discrete(const vector<double>& times,
                                        const vector<double>& amounts,
                                        const double& bondprice);

double bonds duration discrete(const vector<double>& times,
                               const vector<double>& cashflows,
                               const double& r);

double bonds duration macaulay discrete(const vector<double>& cashflow times,
                                        const vector<double>& cashflows,
                                        const double& bond price);

double bonds duration modified discrete (const vector<double>& times,
                                         const vector<double>& amounts,
                                         const double& bond price);

double bonds convexity discrete(const vector<double>& cflow times,
                                const vector<double>& cflow amounts,
                                const double& r);

/////////////////////////////////
// continous compounding.
double cash flow pv(const vector<double>& cflow times,
                    const vector<double>& cflow amounts,
                    const double& r);

double cash flow irr(const vector<double>& cflow times,
                     const vector<double>& cflow amounts);

double bonds price(const vector<double>& cashflow times,
                   const vector<double>& cashflows, const double& r);

double bonds price(const vector<double>& coupon times,
                   const vector<double>& coupon amounts,

const vector<double>& principal times,const vector<double>
                                & principal amounts,const double& r);



#endif // FIN_RECIPES_H
