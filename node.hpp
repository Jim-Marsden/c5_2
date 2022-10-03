//
// Created by james on 9/27/2022.
//

#ifndef C5_3_NODE_HPP
#define C5_3_NODE_HPP

namespace jpm {

    template<class T> concept node_c = requires(T t){
        { t.next };
        { t.data };
    };

    template<class T>
    class node {
    public:
        T data{};
        node *next{nullptr};

        node() = default;

        node(node const &) = default;

        node(node &&) noexcept = default;

        ~node() = default;

        node &operator=(node const &) = default;

        explicit node(T const &data, node *next = nullptr) : data{data},
                                                             next{next} {}
    };
}
#endif //C5_3_NODE_HPP
