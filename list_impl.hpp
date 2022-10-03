////
//// Created by james on 9/27/2022.
////
//
//#ifndef C5_3_LIST_IMPL_HPP
//#define C5_3_LIST_IMPL_HPP
//
//#include "list.hpp"
//
//template<class T, jpm::node_c node_c_t>
//bool jpm::list<T, node_c_t>::append(const T &t) {
//    try {
//        auto temp = new node_c_t(t);
//        if(head == nullptr){
//            head = temp;
//            tail = temp;
//        }
//        else{
//            tail->next = temp;
//            tail = temp;
//        }
//        ++size_val;
//        return true;
//    }
//    catch (std::bad_alloc & e) {
//        std::cout << e.what() << '\n';
//        return false;
//    }
//}
//
//template<class T, jpm::node_c node_c_t>
//bool jpm::list<T, node_c_t>::empty() const noexcept {
//    return head == nullptr;
//}
////
////template<class T, jpm::node_c node_c_t>
////typename jpm::list<T, node_c_t>::const_iterator jpm::list<T, node_c_t>::begin() const noexcept {return cbegin();}
////
////
////template<class T, jpm::node_c node_c_t>
////typename jpm::list<T, node_c_t>::const_iterator jpm::list<T, node_c_t>::end() const noexcept {return cend();}
////
////template<class T, jpm::node_c node_c_t>
////typename jpm::list<T, node_c_t>::const_iterator jpm::list<T, node_c_t>::cbegin() const noexcept {return const_iterator{head};}
////
////
////template<class T, jpm::node_c node_c_t>
////typename jpm::list<T, node_c_t>::const_iterator jpm::list<T, node_c_t>::cend() const noexcept {return const_iterator{nullptr};}
////
////template<class T, jpm::node_c node_c_t>
////typename jpm::list<T, node_c_t>::iterator jpm::list<T, node_c_t>::begin() noexcept {return iterator{head};}
////
//
//template<class T, jpm::node_c node_c_t>
//typename jpm::list<T, node_c_t>::iterator jpm::list<T, node_c_t>::end() noexcept {return iterator {nullptr};}
//
//template<class T, jpm::node_c node_c_t>
//bool operator==(const jpm::list<T, node_c_t> &a, const jpm::list<T, node_c_t> &b) {
//    return false;
//}
//
//template<class T, jpm::node_c node_c_t>
//bool operator!=(const jpm::list<T, node_c_t> &a, const jpm::list<T, node_c_t> &b) {
//    return !(a == b);
//}
//
//template<class T, jpm::node_c node_c_t>
//void jpm::list<T, node_c_t>::swap(jpm::list<T, node_c_t> &other) {
//
//}
//
//template<class T, jpm::node_c node_c_t>
//void jpm::swap(jpm::list<T, node_c_t> &a, jpm::list<T, node_c_t> &b) {
//    a.swap(b);
//}
//
//template<class T, jpm::node_c node_c_t>
//typename jpm::list<T, node_c_t>::size_type jpm::list<T, node_c_t>::max_size() const noexcept {
//    return 0;
//}
//
//#endif //C5_3_LIST_IMPL_HPP
