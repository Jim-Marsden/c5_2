//
// Created by james on 9/27/2022.
//
#include "assignment.hpp"
#include <cmath>

bool c4a2::appendTerm(jpm::list<double> &Polynomial, double constant) {
    return Polynomial.append(constant);
}

void c4a2::display(jpm::list<double> const &Polynomial) {

    if(Polynomial.empty()){
        return ;
    }



    auto do_sign = [](double d) {

            return d < 0.0 ? '-' : '+';
    };

    auto const max_size{Polynomial.size() - 1};

    auto iterator = Polynomial.begin();
    for (long long my_exp {max_size}; my_exp > -1; --my_exp, ++iterator) {
        double d = std::abs(*iterator);

        // If x is 0 we don't need to display anything
        if(*iterator == 0) { continue; }
        if(my_exp == max_size){
            std::cout << *iterator << "x^" << my_exp << ' ';
        }
        else if(my_exp == 1){
            std::cout << do_sign(*iterator) << " " << d << "x";
            auto t = iterator;
            t++;
            if(*t != 0){ std::cout << ' try2';}

        }
        else if(my_exp == 0){
            std::cout << do_sign(*iterator) << " " << std::abs(*iterator);
        }
        else{
//////////////////
            std::cout << do_sign(*iterator) << " " << std::abs(*iterator) << "x^" << my_exp << ' ';
        }

    }

    return ;
}

double c4a2::evaluate(const jpm::list<double> &Polynomial, double x) {
    double product{0.0};
    auto exponent{Polynomial.size() - 1};
    for (auto element : Polynomial){
        if(element == 0) { continue;}
        else if(exponent == 2){
            --exponent;
            product += element * x;
        }
        else if(exponent == 1){product += element;}
        else {
            product += element * std::pow(x, (exponent--));
        }

    }

    return product;
}

