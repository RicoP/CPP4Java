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
        NODE* m_left;
        NODE* m_right;
        NODE* m_up;

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
            NODE* right = current->m_right;

            if(!left && right) {
                if(op(current->m_value, right->m_value)) {
                    recFindFirst(right, op);
                }
            }

            if(left &&!right) {
                if(op(left->m_value, current->m_value)) {
                    recFindFirst(left, op);
                }
            }

            if(left && right) {
                if(op(left->m_value, right->m_value)) {
                    recFindFirst(left, op);
                }
                else {
                    recFindFirst(right, op);
                }
            }

            return current;
        }

        NODE* recFindLast(NODE* current, const O& op) {
            NODE* left = current->m_left;
            NODE* right = current->m_right;

            if(!left && right) {
                if(op(current, right)) {
                    recFindFirst(current, op);
                }
            }

            if(left &&!right) {
                if(op(left, current)) {
                    recFindFirst(current, op);
                }
            }

            if(left && right) {
                if(op(left, right)) {
                    recFindFirst(right, op);
                }
                else {
                    recFindFirst(left, op);
                }
            }

            return current;
        }

    public:
        TreeNode(T value) : m_value(value), m_left(NULL), m_right(NULL), m_up(NULL) {
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


