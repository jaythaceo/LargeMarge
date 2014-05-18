//
//  fin_recipes.h
//  rate_return
//
//  Created by JasonBrooks on 5/11/14.
//  Copyright (c) 2014 venom. All rights reserved.
//

#ifndef rate_return_fin_recipes_h
#define rate_return_fin_recipes_h

#include <vector>
#include <cmath>
using namespace std;

////Present value///
//discrete compounding
////discrete annual compounding

double cash_flow_pv_discrete(const vector<double>& cflow_times,
                             const vector<double> & cflow_amounts,
                             const double&r);

double cash_flow_irr_discrete(const vector<double> cflow_times,
                              const vector<double> cflow_amounts);

BOOL cash_flow_unique_irr(const vector<double> cflow_times,
                          const vector<double> cflow_amounts);

double bonds_price_discrete(const vector<double>& cashflow_times,
                            const vector<double>& cashflows,
                            const double& r):

double bonds_yield_to_maturity_discrete(const vector<double>& times,
                                        const vector<double>& amounts,
                                        const double& bondprice);

double bonds_duration_discrete(const vector<double>& times,
                               const vector<double>& cashflows,
                               const double& r):

double bonds_duration_macaulay_discrete(const vector<double>& cashflow_times,
                                        const vector<double>& cashflows,
                                        const double& bond_price);

double bonds_duration_modified_discrete(const vector<double>& times,
                                        const vector<double>& amounts,
                                        const double& bond_price);

double bonds_convexity_discrete(const vector<double>& cflow_times,
                                const vector<double>& cflow_amounts,
                                const double& r);
//////////////////////////
// continous compounding
double cash_flow_pv(const vector<double>& cflow_times,
                    const vector<double>& cflow_amounts,
                    const double& r);

double cash_flow_irr(const vector<double>& cflow_times,
                     const vector<double>& cflow_amounts);

double bonds_price(const vector<double>& cashflow_times,
                   const vector<double>& cashflows,
                   const double& r);

double bonds_price(const vector<double>& coupon_times,
                   const vector<double>& coupon_amounts,
                   const vector<double>& principal_times
                   const vector<double>& principal_amounts,
                   const double& r);

double bonds_duration(const vector<double>& cashflow_times,
                      const vector<double>& cashflows,
                      const double& r);

double bonds_yield_to_maturity(const vector<double>& cashflow_times,
                               const vector<double>& cashflow_amounts,
                               const double& bondprice);

double bonds_duration_macaulay(const vector<double>& cashflow_times,
                               const vector<double>& cashflows,
                               const double& bond_price);

double bonds_convexity(const vector<double>& cashflow_times,
                       const vector<double>& cashflow_amounts,
                       const double& y);

// term structure basics
double term_structure_yield_from_discount_factor(const double& dfact,
                                                 const double& t);

double term_structure_discount_factor_from_yield(const double& r,
                                                 const double& t);

double term_structure_forward_rate_from_discount_factors(const double& r_t1,
                                                         const double& r_t2,
                                                         const double& time);

double term_structure_forward_rate_from_yields(const double& r_t1,
                                               const double& r_t2,
                                               const double& t1,
                                               const double& t2);

double term_structur_yield_linearly_interplotated(const double& time,
                                                  const vector<double>& obs_times,
                                                  const vector<double>& obs_yields);
// A term structure class
class term_structure_class {
public:
    virtual ~term_structure_class();
    virtual double r(const double& t) const;
    virtual double d(const double& t) const;
    virtual double f(const double& t1, const double& t2) const;
};

class tern_structure_class_flat : public: term_structure_class {
private:
    double R_; // interest rate
public:
    term_structure_class_flat(const double& r);
    virtual ~term_structure_class_flat();
    virtual double r(const double& t) const;
    void set_int_rate(const double& r);
};

class term_structure_class_interpolated : public term_structure_class {
private:
    vector<double> times_;
    vector<double> yields_;
    void clear();
public:
    term_structure_class_interpolated();
    term_structure_class_interpolated(const vector<double>& times, const vector<double>& yields);
    virtual ~term_structure_class_interpolated();
    term_structure_class_interpolated(const term_structure_class_interpolated&);
    term_structure_class_interpolated operator= (const term_structure_class_interpolated&);


    int no_observations() const { return int(times_.size()); };
    virtual double r(const double& T) const;
    void set_interpolated_observations(vector<double>& times, vector<double>& yields);
};


// using term structure class

double bonds_price(const vector<double>& cashflow_times,
                   const vector<double>& cashflows,
                   const term_structure_class& d);

double bonds_duration(const vector<double>& cashflow_times,
                      const vector<double>& cashflow_amounts,
                      const term_structure_class& d);

double bonds_convexity(const vector<double>& cashflow_times,
                       const vector<double>& cashflow_amounts,
                       const term_structure_class& d);

//// Futures pricing
double futures_price(const double& S, const double& r, const double& time_to_maturity);

/// Binomial option pricing

  // one period binomial
double option_price_call_european_binomial_single_period(const double& S,
                                                         const double& K,
                                                         const double& r,
                                                         const double& u,
                                                         const double& d);
// Multiple period binomial
double option_price_call_european_binomial_multi_period_given_ud(const double& S,
                                                                 const double& K,
                                                                 const double& r,
                                                                 const double& u,
                                                                 const double& d,
                                                                 const int& no_periods);
vector<vector<double> > binomial_tree(const double& SO,
                                      const double& u,
                                      const double& d,
                                      const int& no_steps);

/// Black Scholes formula //////////////////
double option_price_call_black_scholes();
double option_price_put_black_scholes();
double option_price_implied_volatility_call_black_scholes_newton();
double option_price_implied_volatility_put_black_scholes_newton();
double option_price_implied_volatility_call_black_scholes_bisections();
double option_price_implied_volatility_put_black_scholes_bisections();





#endif
