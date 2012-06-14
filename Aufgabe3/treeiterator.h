#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include "treenode.h"
#include "tree.h"

namespace mystl {
    template<typename T, typename O = Less<T> >
    class TreeIterator {
    private:
        TreeNode<T,O>* m_current;
        Tree<T,O>* m_tree;

        TreeIterator<T,O> getEnd() {
            return TreeIterator<T,O>(T(), NULL);
        }

    public:
        TreeIterator(TreeNode<T,O>* node, Tree<T,O>* tree) : m_current(node), m_tree(tree) {
        }

        T& operator*() {
            return m_current->m_value;
        }

        T* operator->() {
            return &(m_current->m_value);
        }

        TreeIterator<T,O> operator++() {
            O op;
            TreeNode<T,O>* left = m_current->m_left;
            TreeNode<T,O>* right = m_current->m_right;

            if(!left && !right) {
                return getEnd();
            }

            if(left && !right) {
                if(op(left->m_value, m_current->m_value)) {
                    return TreeIterator<T,O>(left, m_tree);
                }
                else {
                    return getEnd();
                }
            }

            if(!left && right) {
                if(op(right->m_value, m_current->m_value)) {
                    return TreeIterator<T,O>(right, m_tree);
                }
                else {
                    return getEnd();
                }
            }

            return TreeIterator<T,O>(m_current, m_tree);
        }

        TreeIterator<T,O> operator--() {
            if(m_current->m_up) {
                return TreeIterator<T,O>(m_current->m_up, m_tree);
            }
            return getEnd();
        }

        bool operator==(const TreeIterator<T,O> &rhs) {
            return this->m_current == rhs.m_current && this->m_tree == rhs.m_tree;
        }

        bool operator!=(const TreeIterator<T,O> &rhs) {
            return this->m_current != rhs.m_current || this->m_tree != rhs.m_tree;
        }
    };
}

#endif // TREEITERATOR_H
