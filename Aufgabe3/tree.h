#ifndef TREE_H
#define TREE_H

#include "less.h"
#include "treenode.h"
#include "treeiterator.h"

namespace mystl {
    template <typename T, typename O = Less<T> >
    class _Tree {
    private:
        TreeNode<T,O>* m_root;
        TreeNode<T,O>* m_terminate;

    public:
        typedef TreeIterator<T,O> iterator;
        typedef TreeNode<T,O> node;

        Tree() : m_root(NULL), m_terminate(NULL) {
        }

        ~Tree() {
            clear();
        }

        TreeNode<T,O>* insertValue(TreeNode<T,O>* currentNode, T& value) {
            O op;

            T currentValue = currentNode->m_value;

            if(op(value, currentValue)) {
                if(!currentNode->m_left) {
                    currentNode->m_left = new TreeNode<T,O>(value, currentNode);
                    return currentNode->m_left;
                }
                return insertValue(currentNode->m_left, value);
            }

            if(op(currentValue, value)) {
                if(!currentNode->m_right) {
                    currentNode->m_right = new TreeNode<T,O>(value, currentNode);
                    return currentNode->m_right;
                }
                return insertValue(currentNode->m_right, value);
            }

            return currentNode;
        }

        TreeIterator<T,O> insert(const T& value) {
            T t = value;

            if(!m_root) {
                m_root = new TreeNode<T,O>(t, NULL);
            }

            TreeNode<T,O>* node = insertValue(m_root, t);

            return TreeIterator<T,O>(node, this);
        }

        void clear() {
            if(m_root) {
                delete m_root;
            }
        }

        TreeIterator<T,O> end() {
            return TreeIterator<T,O>( m_terminate, this );
            //return TreeIterator<T,O>(NULL, *this);
        }

        TreeIterator<T,O> begin() {
            if(!m_root)
                return end();

            return first();
        }

        TreeIterator<T,O> first() {
            if(!m_root)
                return end();

            return TreeIterator<T,O>(m_root->findFirst(), this);
        }


        TreeIterator<T,O> last() {
            if(!m_root)
                return end();

            return TreeIterator<T,O>(m_root->findLast(), *this);
        }

        TreeIterator<T,O> find(const T& value) {
            if(m_root) {
                TreeNode<T,O>* node = m_root->find(value);
                if(node) {
                    return TreeIterator<T,O>(node, *this);
                }
            }

            return end();
        }
    };
}

#endif // TREE_H
