//
// Created by james on 9/27/2022.
//
#include "assignment.hpp"
//#include <fmt/format.h>
#include <cmath>

bool c4a2::appendTerm(jpm::list<double> &Polynomial, double constant) {
    // not checking for failure for the sake of unit-tests.
    // A simple example would be if(!p.append(constant) std::exit(EXIT_FAILURE);
    return Polynomial.append(constant);
}

void c4a2::display(jpm::list<double> const &Polynomial) {
    // Nothing to do if empty
    if (Polynomial.empty()) {
        return;
    }

    // returns the proper sign based on if the value was positive or negitive.
    auto do_sign = [](double d) {
        return d < 0.0 ? '-' : '+';
    };

    auto print = [has_printed{false}, expo{Polynomial.size() - 1}](double d)mutable {
        auto print_x_exp = [](unsigned long expo, double d){
            if(expo == 1){
                std::cout << "x";
            }
            else if(expo != 0){
                std::cout << "x^" << expo;
            }
        };
        auto do_sign = [](double d) {
            return d < 0.0 ? '-' : '+';
        };
        if(!has_printed){
            if(d == 1){
                print_x_exp(expo, d);
                has_printed = true;
            }
            else if(d != 0){
                has_printed = true;
                std::cout << d;
                print_x_exp(expo, d);

            }
        }
        else{
            if(d != 0){
                has_printed = true;
                std::cout << ' ' << do_sign(d) << ' ' << std::abs(d);
                print_x_exp(expo, d);
            }
        }
        --expo;
    };
    for(auto r : Polynomial){
        print(r);
    }
}

double c4a2::evaluate(const jpm::list<double> &Polynomial, double x) {

//    jpm::list<double> products;
    // the value we'll return
    double product{0.0};

    auto exponent{Polynomial.size() - 1};

    // iterate over every element and apply the result of the term to exponent
    for (auto element: Polynomial) {


            product += element * std::pow(x, (exponent--));
    }
        return product;
}