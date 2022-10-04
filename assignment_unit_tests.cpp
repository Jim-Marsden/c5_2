//
// Created by james on 9/27/2022.
//

#include "assignment.hpp"
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "list"
#include "list_concepts.hpp"

#include <sstream>
#include <iostream>

TEST_CASE("c4a2::display 6 0 -5.3 3.1") {
    std::ostringstream oss;
    auto p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    jpm::list_c<double> auto list = jpm::list<double>();

    if (!list.append(6.0)) { std::cout << "wat!?\n"; }
    if (!list.append(0.)) { std::cout << "wat!?\n"; }
    if (!list.append(-5.3)) { std::cout << "wat!?\n"; }
    if (!list.append(3.1)) { std::cout << "wat!?\n"; }

    c4a2::display(list);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss);
    REQUIRE(oss.str() == "6x^3 - 5.3x + 3.1");


}

TEST_CASE("c4a2::display 3 0 0.5 2 0") {
    std::ostringstream oss;
    auto p_cout_streambuf = std::cout.rdbuf();
    std::cout.rdbuf(oss.rdbuf());
    jpm::list_c<double> auto list = jpm::list<double>();

    // -3.0x3 + 0.5x2 - 2.0x
    if (!list.append(-3.0)) { std::cout << "wat!?\n"; }
    if (!list.append(0.5)) { std::cout << "wat!?\n"; }
    if (!list.append(-2)) { std::cout << "wat!?\n"; }
    if (!list.append(0)) { std::cout << "wat!?\n"; }
    c4a2::display(list);

    std::cout.rdbuf(p_cout_streambuf); // restore

    // test your oss content...
    REQUIRE(oss);
    REQUIRE(oss.str() == "-3x^3 + 0.5x^2 - 2x");

}

TEST_CASE("c4a2::display all") {
    class os_safe{
    public:
        os_safe(){
            p_cout_streambuf = std::cout.rdbuf();
            std::cout.rdbuf(oss.rdbuf());
            REQUIRE(oss);
        }
        ~os_safe(){
            std::cout.rdbuf(p_cout_streambuf); // restore
        }
        std::string get(){return oss.str();}
    private:
        std::ostringstream oss;
        std::basic_streambuf<char>*p_cout_streambuf;
    };
    //test 1
    {
        // x + 1.0 .............................. with x = 1.0

        os_safe s;
        jpm::list<double> t1;
        t1.append(0);
        t1.append(1);
        t1.append(1);
        c4a2::display(t1);
        REQUIRE(s.get() == "x + 1");
    }

    //test 2

    {
        // x2 - 1.0 ............................. with x = 2.03

        os_safe s;

        jpm::list<double> t1;
        t1.append(1);
        t1.append(0);
        t1.append(-1);
        c4a2::display(t1);

        REQUIRE(s.get() == "x^2 - 1");
    }



    //test 3
    {
        //         -3.0x^3 + 0.5x^2 - 2.0x ................ with x = 05.0
        os_safe s;
        jpm::list<double> t1;
        t1.append(-3);
        t1.append(.5);
        t1.append(-2);
        t1.append(.0);
        c4a2::display(t1);

        REQUIRE(s.get() == "-3x^3 + 0.5x^2 - 2x");
        //
    }
    //test 4
    {
        //-0.3125x^4 - 9.915x^2 - 7.75x - 40.0
        jpm::list<double> t1;
        t1.append(-0.3125);
        t1.append(0);
        t1.append(-9.915);
        t1.append(-7.75);
        t1.append(-40);
        os_safe s;
        c4a2::display(t1);
        REQUIRE(s.get() == "-0.3125x^4 - 9.915x^2 - 7.75x - 40");

    }
}

TEST_CASE("c4a2::evaluate") {

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
        t1.append(1);
        t1.append(1);

        // floating point strageness it passes.
        auto const r{c4a2::evaluate(t1, 2.03)};
        auto const target{3.03};
        REQUIRE(r == Catch::Approx(target));
        //
    }



    //test 3
    {
//         -3.0x^3 + 0.5x^2 - 2.0x ................ with x = 05.0
        jpm::list<double> t1;
        t1.append(-3);
        t1.append(.5);
        t1.append(-2);
        t1.append(.0);
        REQUIRE(c4a2::evaluate(t1, 5) == Catch::Approx(-372.5));
        //
    }
    //test 4
    {
//        * -0.3125x^4 - 9.915x^2 - 7.75x - 40.0 ... with x = 123.45
        jpm::list<double> t1;
        t1.append(-0.3125);
        t1.append(0);
        t1.append(-9.915);
        t1.append(-7.75);
        t1.append(-40);
        REQUIRE(c4a2::evaluate(t1, 123.45) == Catch::Approx(-72731671.686));
    }

}

