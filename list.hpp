//
// Created by james on 9/27/2022.
//

#ifndef C5_3_LIST_HPP
#define C5_3_LIST_HPP

#include <stdexcept>
#include <iostream>
#include <iterator>

#include "iterator.hpp"




namespace jpm {
    template<class T, node_c node_c_t = node<T>>
    class list{
    public:
        using value_type = T;
        using size_type = unsigned long;
        using iterator = iterator_t<node_c_t>;
        using const_iterator = const iterator;
        using difference_type = size_type;

        using node_ptr = node_c_t *;

        list() = default;
        list(list const &) = default;
        list(list &&) noexcept = default;
        list &operator=(list const &) = default;
        list &operator=(list &&) noexcept = default;

        ~list() = default;

        iterator begin()  noexcept { return iterator{head};}
        iterator end()  noexcept{ return iterator{nullptr};}

        const_iterator begin() const noexcept{ return const_iterator{head};}
        const_iterator end() const noexcept{ return const_iterator{nullptr};}

        const_iterator cbegin() const noexcept{ return const_iterator{head};}
        const_iterator cend() const noexcept{ return const_iterator{nullptr};}

        bool operator==(list const & a) const noexcept{
            return false;
        }
        bool operator!=(list const & a){
            return false;
        }
        template <class V>
        friend void swap(list & a, list & b);
        void swap(list & other){
            auto temp_head = other.head;
            auto temp_tail = other.tail;

            other.head = head;
            other.tail = tail;

            head = temp_head;
            tail = temp_tail;
        }

        [[nodiscard]] size_type size() const noexcept{return size_val;}
        [[nodiscard]] size_type max_size() const noexcept{return size_val;};
        [[nodiscard]] bool empty() const noexcept{return size() == 0;};

        bool append(T const & t){
            try {
                auto temp = new node_c_t(t);
                if(head == nullptr){
                    head = temp;
                    tail = temp;
                }
                else{
                    tail->next = temp;
                    tail = temp;
                }
                ++size_val;
                return true;
            }
            catch (std::bad_alloc & e) {
                std::cout << e.what() << '\n';
                return false;
            }
            return false;
        }
    private:
        node_ptr head{nullptr};
        node_ptr tail{nullptr};
        size_type size_val{};
    };

    template<class T, jpm::node_c node_c_t>
    void swap(jpm::list<T, node_c_t> &a, jpm::list<T, node_c_t> &b);
}

//#include "list_impl.hpp"

#endif //C5_3_LIST_HPP
