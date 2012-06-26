#ifndef TREENODE_H
#define TREENODE_H

#include "less.h"

namespace mystl {
    // Vorab-Deklaration
    template<typename T, typename O>
    class TreeIterator;

    // Vorab-Deklaration
    template<typename T, typename O>
    class Tree;

    template<typename T, typename O = Less<T> >
    class TreeNode {
        typedef TreeNode<T,O> NODE;

    protected:
        T m_value;
        NODE* m_up;
        NODE* m_left;
        NODE* m_right;

    private:
        NODE* recFind(NODE* current, const T& value) {
            if(!current) return NULL;

            if(current->m_value == value) {
                return current;
            }

            return recFind(current->m_left, value)
                    || recFind(current->m_right, value);
        }

        NODE* recFindFirst(NODE* current, O& op) {
            NODE* left = current->m_left;            

            if(!left) {
                return current;
            }

            return recFindFirst(left, op);
        }

        NODE* recFindLast(NODE* current, const O& op) {
            NODE* right = current->m_right;

            if(!right) {
                return current;
            }

            return recFindLast(right, op);
        }

    public:
        TreeNode(T value, TreeNode<T,O>* up) : m_value(value), m_up(up), m_left(NULL), m_right(NULL) {
        }

        T& value() {
            return m_value;
        }

        TreeNode<T,O>* find(const T& value) {
            return recFind(this, value);
        }

        TreeNode<T,O>* findFirst() {
            O op;
            return recFindFirst(this, op);
        }

        TreeNode<T,O>* findLast() {
            O op;
            return recFindLast(this, op);
        }

        friend class Tree<T,O>;
        friend class TreeIterator<T,O>;
    };
}

#endif // TREENODE_H


