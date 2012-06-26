#ifndef TREE_H
#define TREE_H

#include "less.h"
#include "treenode.h"
#include "treeiterator.h"

namespace mystl {
    template<typename T, typename O = Less<T> >
    class Tree {
    public:
        typedef TreeIterator<T,O> iterator;
        typedef TreeNode<T,O> node;

    private:
        TreeNode<T,O>* m_root;

        iterator recInsert(node* current, const T& value, O op) {
            if(op(value, current->m_value)) {
                if(!current->m_left) {
                    current->m_left = new node(value, current);
                    return iterator(current->m_left, this);
                }
                return recInsert(current->m_left, value, op);
            }
            if(op(current->m_value, value)) {
                if(!current->m_right) {
                    current->m_right = new node(value, current);
                    return iterator(current->m_right, this);
                }
                return recInsert(current->m_right, value, op);
            }

            current->m_value = value;
            return iterator(current, this);
        }

        void recClear(node* n) {
            if(n->m_left) recClear(n->m_left);
            if(n->m_right) recClear(n->m_right);

            delete n;
        }
    public:
        Tree() : m_root(NULL) {
        }

        iterator insert(const T& value) {
            if(!m_root) {
                m_root = new node(value, NULL);
                return iterator(m_root, this);
            }
            else {
                O op;
                return recInsert(m_root, value, op);
            }
        }

        void clear() {
            if(m_root) {
                recClear(m_root);
            }

            m_root = NULL;
        }

        iterator begin() {
            if(m_root) {
                return iterator(m_root->findFirst(), this);
            }

            return end();
        }

        iterator end() {
            return iterator(NULL, this);
        }

        iterator first() {
            return begin();
        }

        iterator last() {
            if(!m_root) {
                return end();
            }

            return iterator(m_root->findLast(), this);
        }

        iterator find(const T& value) {
            if(!m_root) {
                return end();
            }

            node* n = m_root->find(value);
            return iterator(n);
        }
    };
}


#endif // TREE_H
