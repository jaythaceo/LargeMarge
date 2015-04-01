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


double bonds duration(const vector<double>& cashflow times,
                      const vector<double>& cashflows,
                      const double& r);

double bonds yield to maturity(const vector<double>& cashflow times,
                               const vector<double>& cashflow amounts,
                               const double& bondprice);

double bonds duration macaulay(const vector<double>& cashflow times,
                               const vector<double>& cashflows,
                               const double& bond price);

double bonds convexity(const vector<double>& cashflow times,
                       const vector<double>& cashflow amounts,
                       const double& y );

/// term structure basics
double term structure yield from discount factor(const double& dfact, const double& t);

double term structure discount factor from yield(const double& r, const double& t);

double term structure forward rate from discount factors(const double& d t1, const double& d t2,
const double& time);

double term structure forward rate from yields(const double& r t1, const double& r t2,
const double& t1, const double& t2);

double term structure yield linearly interpolated(const double& time,
const vector<double>& obs times,

const vector<double>& obs yields);

// a term structure class
class term structure class {
public:
  virtual ˜term structure class();
  virtual double r(const double& t) const; // short rate, yield on zero coupon bond
  virtual double d(const double& t) const; // discount factor
  virtual double f(const double& t1, const double& t2) const; // forward rate
};

class term structure class flat : public term structure class {
private:
  double R ; // interest rate

  public:
    term structure class flat(const double& r);
    virtual ˜term structure class flat();
    virtual double r(const double& t) const;
    void set int rate(const double& r);
};

class term structure class interpolated : public term structure class {
private:
  vector<double> times ; // use to keep a list of yields
  vector<double> yields ;
  void clear();

public:
  term structure class interpolated();
  term structure class interpolated(const vector<double>& times, const vector<double>& yields);
  virtual ˜term structure class interpolated();
  term structure class interpolated(const term structure class interpolated&);
  term structure class interpolated operator= (const term structure class interpolated&);
  int no observations() const { return int(times .size()); };
  virtual double r(const double& T) const;
  void set interpolated observations(vector<double>& times, vector<double>& yields);
};

// using the term structure classes
double bonds price(const vector<double>& cashflow times,
const vector<double>& cashflows,
const term structure class& d);

double bonds duration(const vector<double>& cashflow times,
const vector<double>& cashflow amounts,
const term structure class& d);

double bonds convexity(const vector<double>& cashflow times,
const vector<double>& cashflow amounts,
const term structure class& d);

//// Futures pricing
double futures price(const double& S, const double& r, const double& time to maturity);

/// Binomial option pricing
// one periode binomial
double option price call european binomial single period( const double& S, const double& K, const double& r,
                                                         const double& u, const double& d);

// multiple periode binomial
double option price call european binomial multi period given ud( const double& S, const double& K,
                                                                 const double& r,
                                                                 const double& u, const double& d,
                                                                 const int& no periods);

// multiple periode binomial
vector< vector<double> ❃ binomial tree(const double& S0, const double& u,const double& d,
const int& no steps);

/// Black Scholes formula //////////////////////////////////////////
double option price call black scholes(const double& S, const double& K, const double& r,
                                       const double& sigma, const double& time) ;

double option price put black scholes (const double& S, const double& K, const double& r,
                                       const double& sigma, const double& time) ;

double option price implied volatility call black scholes newton( const double& S, const double& K,
                                                                 const double& r, const double& time,
                                                                 const double& option price);

double option price implied volatility put black scholes newton( const double& S, const double& K,
                                                                const double& r, const double& time,
                                                                const double& option price);

double option price implied volatility call black scholes bisections( const double& S, const double& K,
                                                                     const double& r, const double& time,
                                                                     const double& option price);

double option price implied volatility put black scholes bisections( const double& S, const double& K
                                                                    const double& r, const double& time,
                                                                    const double& option price);

double option price delta call black scholes(const double& S, const double& K, const double& r,
                                             const double& sigma, const double& time);

double option price delta put black scholes (const double& S, const double& K, const double& r,
                                             const double& sigma, const double& time);

void option price partials call black scholes(const double& S, const double& K, const double& r,
                                              const double& sigma, const double& time,
                                              double& Delta, double& Gamma, double& Theta,
                                              double& Vega, double& Rho);

void option price partials put black scholes(const double& S, const double& K, const double& r,
                                             const double& sigma, const double& time,
                                             double& Delta, double& Gamma, double& Theta,
                                             double& Vega, double& Rho);

/// warrant price
double warrant price adjusted black scholes(const double& S, const double& K,
                                            const double& r, const double& sigma,
                                            const double& time,
                                            const double& no warrants outstanding,
                                            const double& no shares outstanding);

double warrant price adjusted black scholes(const double& S, const double& K,
                                            const double& r, const double& q,
                                            const double& sigma, const double& time,
                                            const double& no warrants outstanding,

#endif // FIN_RECIPES_H