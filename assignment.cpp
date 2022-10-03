//
// Created by james on 9/27/2022.
//
#include "assignment.hpp"
#include <cmath>

bool c4a2::appendTerm(jpm::list<double> &Polynomial, double constant) {
    // not checking for failure for the sake of unit-tests.
    // A simple example would be if(!p.append(constant) std::exit(EXIT_FAILURE);
    return Polynomial.append(constant);
}

void c4a2::display(jpm::list<double> const &Polynomial) {
    // Nothing to do if empty
    if(Polynomial.empty()){
        return ;
    }

    // returns the proper sign based on if the value was positive or negitive.
    auto do_sign = [](double d) {
            return d < 0.0 ? '-' : '+';
    };

    auto const max_size{Polynomial.size() - 1};

    auto iterator = Polynomial.begin();
    for (long long my_exp {max_size}; my_exp > -1; --my_exp, ++iterator) {
        double d = std::abs(*iterator);

        // If x is 0 we don't need to display anything
        if(*iterator == 0) { continue; }


        if(my_exp == max_size){ // avoid doing leading sign
            std::cout << *iterator << "x^" << my_exp << ' ';
        }
        else if(my_exp == 1){
            std::cout << do_sign(*iterator) << " " << d << "x";
            auto t = iterator;
            t++;
            if(*t != 0){ std::cout << " ";}

        }
        else if(my_exp == 0){ // don't display the variable (x)
            std::cout << do_sign(*iterator) << " " << std::abs(*iterator);
        }
        else{ // display everything
            std::cout << do_sign(*iterator) << " " << std::abs(*iterator)
            << "x^" << my_exp << ' ';
        }

    }
}

double c4a2::evaluate(const jpm::list<double> &Polynomial, double x) {

    // the value we'll return
    double product{0.0};



    auto exponent{Polynomial.size() - 1};

    // iterate over every element and apply the result of the term to exponent
    for (auto element : Polynomial){

        if(element == 0) { continue;}
        else if(exponent == 2){
            --exponent;
            if(element > 0)
                product += element * x;
            else
                product -= std::abs(element) * x;
        }
        else if(exponent == 1){product += element;}
        else {
            if(element > 0)
                product += element * std::pow(x, (exponent--));
            else
                product -= element * std::pow(x, (exponent--));
        }

    }

    return product;
}

