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
        list(list const & other) {
            if(&other == this) return;
            for(auto const &e: other){
                append(e);
            }
        }
        list(list && other) noexcept {
            head = other.head;
            tail = other.tail;
            size_val = other.size_val;
            other.head = nullptr;
            other.tail = nullptr;
            other.size_val = 0;

        };
        list &operator=(list const &) = default;
        list &operator=(list &&) noexcept = default;

        ~list() {
            while(head != nullptr) {
                auto temp = head;
                head = head->next;
                delete temp;
            }
        }

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
            auto &&temp = std::move(other);
            other = std::move(*this);
            *this = std::move(temp);
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
    void swap(jpm::list<T, node_c_t> &a, jpm::list<T, node_c_t> &b){
        a.swap(b);
    }
}

//#include "list_impl.hpp"

#endif //C5_3_LIST_HPP
