#include <iostream>
#include <catch2/catch_session.hpp>
#include "list.hpp"
#include "assignment.hpp"
#include "list_concepts.hpp"

template <class T>
concept name = requires(T t){
{T{}};
};

int main(int argc, char ** argv) {
    auto session = Catch::Session();

    name auto t = int{};

    jpm::list_c<double> auto t1 = jpm::list<double>();
//    jpm::list<int> list;
    t1.append(-0.3125);
    t1.append(0);
    t1.append(9.915);
    t1.append(7.75);
    t1.append(40);

//    if(!list.append(-5.3)) { std::exit(EXIT_FAILURE); }
//    if(!list.append(3.1)) { std::exit(EXIT_FAILURE); }
//
    std::cout << "Hello, World!" << std::endl;
    c4a2::display(t1);
    std::cout << std::endl;
    return session.run(argc, argv);

    std::cout << c4a2::evaluate(t1, 7.0) << '\n';
}
