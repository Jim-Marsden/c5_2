//
// Created by james on 9/27/2022.
//

#ifndef C5_3_ITERATOR_HPP
#define C5_3_ITERATOR_HPP

#include "node.hpp"

namespace jpm{

    template<class iterator_t, class element_t>
    concept iterator_c = requires(iterator_t i, iterator_t j){
        i != j;
        i == j;
        *i;
        ++i;
        i++;
    };

    template<class T>
    class iterator{
    public:
        friend bool operator==(T a, T b){return a.data == b.data;}
        friend bool operator!=(T a, T b){return !(a == b);}
        iterator &operator++(){ return data++;}
        iterator const &operator++(int){return ++data;}
        T &operator*(){return *data;}
        T const &operator*() const {return *data;}
    private:
        T *data;
    };


    template<jpm::node_c node_t>
    class iterator_t{
    public:
        bool operator==(iterator_t const & a){return a.data == data;}
        bool operator!=(iterator_t const & a){return !(a == *this);};;
        iterator_t operator++(){ {data = data->next;}; return *this;}
        iterator_t operator++(int){
            auto current = *(this);
            data = data->next;
            return current;
        }
        auto &operator*(){return data->data;}
        auto const &operator*() const {return *data;}
        node_t *data{nullptr};
    };


} // namespace jpm

#include "iterator_impl.hpp"

#endif //C5_3_ITERATOR_HPP
