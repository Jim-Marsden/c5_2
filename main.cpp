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

    jpm::list_c<double> auto list = jpm::list<double>();
//    jpm::list<int> list;
    if(!list.append(6.0)) { std::cout << "wat!?\n"; }
    if(!list.append(0.)) { std::cout << "wat!?\n"; }
    if(!list.append(-5.3)) { std::cout << "wat!?\n"; }
    if(!list.append(3.1)) { std::cout << "wat!?\n"; }

    for(auto  & i : const_cast<const jpm::list<double>&>(list)){
        std::cout << i << '\n';
    }
    std::cout << "Hello, World!" << std::endl;
    return session.run(argc, argv);
    c4a2::display(list);
    std::cout << c4a2::evaluate(list, 7.0) << '\n';
}
