//
// Created by james on 9/29/2022.
//


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
    template <class T2>
    friend bool operator==(iterator a, iterator b);
    template <class T2>
    friend bool operator!=(iterator a, iterator b);
    iterator &operator++(){ return data++;}
    iterator &operator++(int){return ++data;}
    T &operator*(){return *data;}
    T const &operator*() const {return *data;}
    T *data;
};
template <class T>
bool operator==(iterator<T> a, iterator<T> b){return a.data == b.data;}
template <class T>
bool operator!=(iterator<T> a, iterator<T> b){return !(a == b);}


int main(){
    iterator_c<int> auto thing = iterator<int>{nullptr};
}