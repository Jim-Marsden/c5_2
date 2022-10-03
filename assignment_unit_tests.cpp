//
// Created by james on 9/27/2022.
//

#include "assignment.hpp"
#include <catch2/catch_test_macros.hpp>

#include "list"
#include "list_concepts.hpp"

#include <sstream>
#include <iostream>
TEST_CASE("c4a2::display 6 0 -5.3 3.1"){
    std::ostringstream oss;
    auto p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    jpm::list_c<double> auto list = jpm::list<double>();

    if(!list.append(6.0)) { std::cout << "wat!?\n"; }
    if(!list.append(0.)) { std::cout << "wat!?\n"; }
    if(!list.append(-5.3)) { std::cout << "wat!?\n"; }
    if(!list.append(3.1)) { std::cout << "wat!?\n"; }

    c4a2::display(list);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss);
    REQUIRE(oss.str() == "6x^3 - 5.3x + 3.1");


}

TEST_CASE("c4a2::display 3 0 0.5 2 0"){
    std::ostringstream oss;
    auto p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    jpm::list_c<double> auto list = jpm::list<double>();

    // -3.0x3 + 0.5x2 - 2.0x
    if(!list.append(-3.0)) { std::cout << "wat!?\n"; }
    if(!list.append(0.5)) { std::cout << "wat!?\n"; }
    if(!list.append(-2)) { std::cout << "wat!?\n"; }
    if(!list.append(0)) { std::cout << "wat!?\n"; }
    c4a2::display(list);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss);
    REQUIRE(oss.str() == "-3x^3 + 0.5x^2 - 2x");

}