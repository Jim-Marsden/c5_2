////
//// Created by james on 9/27/2022.
////
//
//#ifndef C5_3_ITERATOR_IMPL_HPP
//#define C5_3_ITERATOR_IMPL_HPP
//
//#include "iterator.hpp"
//
////template<jpm::node_c node_t>
////bool jpm::iterator_t<node_t>::operator!=(const iterator_t &other) const {
////    return (this->current_node != other.current_node);
////}
////
////template<jpm::node_c node_t>
////bool jpm::iterator_t<node_t>::operator==(const iterator_t &other) const {
////    return this->current_node == other.current_node;
////}
//
//template<jpm::node_c node_t>
//auto &jpm::iterator_t<node_t>::operator*() { return current_node->data; }
//
//template<jpm::node_c node_t>
//const jpm::iterator_t<node_t> jpm::iterator_t<node_t>::operator++(int) {
//    auto out = current_node;
//    current_node = current_node->next;
//    return iterator_t{out};
//}
//
//template<jpm::node_c node_t>
//jpm::iterator_t<node_t> jpm::iterator_t<node_t>::operator++() {
//    current_node = current_node->next;
//    return iterator_t{current_node};
//}
//
//
//template<jpm::node_c node_t>
//jpm::iterator_t<node_t>::iterator_t(node_t * node): current_node{node} {}
//
//template <class T>
//bool operator==(jpm::iterator_t<T> const & a, jpm::iterator_t<T> const & b){
//    return a.current_node == b.current_node;
//}
//
//template <class T>
//bool operator!=(jpm::iterator_t<T> const & a, jpm::iterator_t<T> const & b){
//    return !(a == b);
//}
//
//#endif //C5_3_ITERATOR_IMPL_HPP
