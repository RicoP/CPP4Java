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
    public:
        T m_value;

        TreeNode<T,O>* m_left;
        TreeNode<T,O>* m_right;
        TreeNode<T,O>* m_up;

    private:
        // Vorab-Deklaration
        template<typename T1, typename Op>
        class TreeIterator;

        // Vorab-Deklaration
        template<typename T1, typename Op>
        class Tree;

        typedef TreeNode<T,O> node;

        bool recFind(T& value, node** returnNode) {
            if(m_value == value) {
                *returnNode = this;
                return true;
            }

            if(m_left) {
                node* found = m_left->find(value);
                if(found) {
                    *returnNode = found;
                    return true;
                }
            }

            if(m_right) {
                node* found = m_right->find(value);
                if(found) {
                    *returnNode = found;
                    return true;
                }
            }

            return false;
        }

    public:
        TreeNode(T& value, TreeNode<T,O>* parent, TreeNode<T,O>* left, TreeNode<T,O>* right)
            : m_value(value), m_up(parent), m_left(left), m_right(right) {
        }

        node* find(const T& value) {
            node* node = NULL;
            bool found = recFind(value, &node);
            if(found) {
                return node;
            }
            return NULL;
        }

        node* findFirst() {
            if(!m_left && !m_right) {
                return this;
            }

            O op;

            if(m_left && !m_right) {
                node* left = m_left->findFirst();
                if(op(m_value, left->m_value))
                    return this;
                else
                    return left;
            }

            if(!m_left && m_right) {
                node* right = m_right->findFirst();
                if(op(m_value, right->m_value))
                    return this;
                else
                    return right;
            }

            //if(m_left && m_right)
            node* left = m_left->findFirst();
            node* right = m_right->findFirst();

            if(op(left->m_value, right->m_value))
                return left;
            else
                return right;
        }

        node* findLast() {
            if(!m_left && !m_right) {
                return this;
            }

            if(m_left && !m_right) {
                O op;
                node* left = m_left->findLast();
                if(op(m_value, left->m_value))
                    return left;
                else
                    return this;
            }

            if(!m_left && m_right) {
                O op;
                node* right = m_right->findLast();
                if(op(m_value, right->m_value))
                    return right;
                else
                    return this;
            }

            //if(m_left && m_right)
            O op;
            node* left = m_left->findLast();
            node* right = m_right->findLast();

            if(op(left->m_value, right->m_value))
                return right;
            else
                return left;
        }

        friend class Tree<T,O>;
        friend class TreeIterator<T,O>;
    };
}

#endif // TREENODE_H
