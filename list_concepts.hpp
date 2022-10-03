//
// Created by james on 9/29/2022.
//

#ifndef C5_3_LIST_CONCEPTS_HPP
#define C5_3_LIST_CONCEPTS_HPP
#include <concepts>

namespace jpm {
    template<class C, class T>
    concept container_c = requires(C a, C b, C &&rv){
        { typename C::value_type{}} ->std::same_as<T>;
        typename C::size_type;
        typename C::iterator;
        typename C::const_iterator;
        typename C::difference_type;

        { C() } -> std::same_as<C>;
        { C(a) } -> std::same_as<C>;
        { C(rv) } -> std::same_as<C>;
        { a = b } -> std::same_as<C &>;
        { a = rv } -> std::same_as<C &>;
        { a.~C() } -> std::same_as<void>;
        { a.begin() } -> std::same_as<typename C::iterator>;
        { a.end() } -> std::same_as<typename C::iterator>;
        { a.cbegin() } -> std::same_as<typename C::const_iterator>;
        { a.cend() } -> std::same_as<typename C::const_iterator>;
        { const_cast<C &>(a).cbegin() } -> std::same_as<typename C::const_iterator>;
        { const_cast<C &>(a).cend() } -> std::same_as<typename C::const_iterator>;

        { a == b } -> std::convertible_to<bool>;
        { a != b } -> std::convertible_to<bool>;

        { a.swap(b) } -> std::same_as<void>;
        { swap(a, b) } -> std::same_as<void>;
        { a.size() } -> std::same_as<typename C::size_type>;
        { a.max_size() } -> std::same_as<typename C::size_type>;
        { a.empty() } -> std::convertible_to<bool>;
    };

    template<class List_T, class element_t>
    concept list_c = container_c<List_T, element_t> &&
                     requires(List_T list, element_t element){
                         { list.append(element) } -> std::convertible_to<bool>;
                     };

} // namespace jpm

#endif //C5_3_LIST_CONCEPTS_HPP
