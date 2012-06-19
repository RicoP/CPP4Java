#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "less.h"
#include "treenode.h"

namespace mystl {
    template<typename T, typename O = Less<T> >
    class TreeIterator {
        typedef TreeNode<T,O> NODE;

    private:
        NODE* m_node;

        TreeIterator<T,O> wanderLeft(NODE* node) {
            if(node->m_left)
                return wanderLeft(node->m_left);

            return node;
        }

    public:
        TreeIterator(TreeNode<T,O>* node) : m_node(node) {
        }

        T& operator*() {
            return m_node->value();
        }

        T* operator->() {
            return &(m_node->value());
        }

        TreeIterator<T,O> operator++() {
            NODE* node = m_node->findFirst();
            return TreeIterator<T,O>(node);
        }

        //TreeIterator<T,O>& operator--()

        bool operator==(const TreeIterator<T,O> &rhs) {
            return this->m_node == rhs.m_node;
        }

        bool operator!=(const TreeIterator<T,O> &rhs) {
            return this->m_node != rhs.m_node;
        }
    };
}

#endif // TREEITERATOR_H
