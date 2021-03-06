#ifndef TREEITERATOR_H
#define TREEITERATOR_H

#include <stdio.h>
#include "less.h"
#include "treenode.h"

namespace mystl {
    template<typename T, typename O = Less<T> >
    class TreeIterator {
        typedef TreeNode<T,O> NODE;
        typedef Tree<T,O> TREE;

    private:
        NODE* m_node;        
        TREE* m_tree;

        NODE* wanderLeft(NODE* node) {
            if(node->m_left)
                return wanderLeft(node->m_left);

            return node;
        }

        NODE* wanderUp(NODE* node) {
            O op;

            if(op(node->m_up->m_value, node->m_value)){
                return wanderUp(node->m_up);
            }else{
                return node->m_up;
            }
        }

        NODE* recFindUp(NODE* last, NODE* up) {
            //fprintf(stderr, "up!\n" );

            if(!up) {
                //fprintf(stderr, "no up!\n");
                return NULL;
            }

            if(last == up->m_left) {
                //fprintf(stderr, "left! %i\n", up->value() );
                //Ich komme von links                
                return up;
            }

            //Ich komme von rechts
            return recFindUp(up, up->m_up);
        }

        NODE* recFindReverseUp(NODE* last, NODE* up) {
            fprintf(stderr, "findreverse\n");
            if(!up) {
                fprintf(stderr, "NO up\n");
                return NULL;
            }

            if(last == up->m_right) {
                fprintf(stderr, "up\n");
                //Ich komme von rechts
                return up;
            }

            return recFindReverseUp(up, up->m_up);
        }

    public:
        /*TreeIterator(TreeNode<T,O>* node) : m_node(node), m_tree(0) {
        }*/

        TreeIterator(TreeNode<T,O>* node, TREE* tree) : m_node(node), m_tree(tree) {
        }

        T& operator*() {
            if(!m_node) {
                //fprintf(stdout, "called *NULL!\n");
            }
            return m_node->value();
        }

        T* operator->() {
            return &(m_node->value());
        }

        TreeIterator<T,O> operator++() {                                    
            if(!m_node) {
                //fprintf(stderr, "No m_node.\n" );
                return *this;
            }
            //fprintf(stderr, "m_node! \n" );

            NODE* right = m_node->m_right;

            if(right) {
                //fprintf(stderr, "right!\n" );
                m_node = right->findFirst();
                return *this;
            }

            //Wenn ich beim hochsteigen auf den wurzelknoten stoße ist schluss
            m_node = recFindUp(m_node, m_node->m_up);
            return *this;
        }

        TreeIterator<T,O> operator++(int) {
            return ++(*this);
        }

        TreeIterator<T,O> operator--() {
            if(!m_node) {
                //fprintf(stderr, "No m_node.\n" );
                if(!m_tree) {
                    //fprintf(stderr, "No m_tree!.\n" );
                }
                else {
                    //fprintf(stderr, "yes m_tree!.\n" );
                }

                TreeIterator<T,O> ite = m_tree->last();
                this->m_node = ite.m_node;
                return *this;
            }
            //fprintf(stderr, "m_node! \n" );

            NODE* left = m_node->m_left;

            if(left) {
                //fprintf(stderr, "right!\n" );
                m_node = left->findLast();
                return *this;
            }

            //Wenn ich beim hochsteigen auf den wurzelknoten stoße ist schluss
            m_node = recFindReverseUp(m_node, m_node->m_up);
            return *this;
        }

        TreeIterator<T,O> operator--(int) {
            return --(*this);
        }

        bool operator==(const TreeIterator<T,O> &rhs) {
            return this->m_node == rhs.m_node;
        }

        bool operator!=(const TreeIterator<T,O> &rhs) {
            return this->m_node != rhs.m_node;
        }
    };
}

#endif // TREEITERATOR_H
