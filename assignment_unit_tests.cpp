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

TEST_CASE("c4a2::evaluate"){

    /*
     * x + 1.0 ................................ with x = 1.0
     * x^2 - 1.0 .............................. with x = 2.03
     * -3.0x^3 + 0.5x^2 - 2.0x ................ with x = 05.0
     * -0.3125x^4 - 9.915x^2 - 7.75x - 40.0 ... with x = 123.45
     */

    //test 0
    {
        // x + 1.0 .............................. with x = 1.0

        jpm::list<double> t1;
        t1.append(6);
        t1.append(0);
        t1.append(-5.3);
        t1.append(3.1);
        REQUIRE(c4a2::evaluate(t1, 7) == 2024);
    }
    //test 1
    {
        // x + 1.0 .............................. with x = 1.0

        jpm::list<double> t1;
        t1.append(1);
        REQUIRE(c4a2::evaluate(t1, 1) == 1);
    }

    //test 2
    {
        // x2 - 1.0 ............................. with x = 2.03
        jpm::list<double> t1;
        t1.append(0);
        t1.append(-1);
        t1.append(0);

        REQUIRE(c4a2::evaluate(t1, 2.03) == 3.1209);
        //
    }

    //test 2
    {
        jpm::list<double> t1;
        t1.append(0);
        t1.append(-1);
//        REQUIRE(c4a2::evaluate(t1, 2.03) == 3.1209);
        //
    }

}

