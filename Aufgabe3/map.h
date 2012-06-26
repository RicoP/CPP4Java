#ifndef MAP_H
#define MAP_H


#include "less.h"
#include "tree.h"
#include "treeiterator.h"
#include "pair.h"

namespace mystl {
    template<typename KeyT, typename ValueT, typename OrderT = MapToFirst<KeyT,ValueT,Less<KeyT> > >
    class Map {

    public:
        typedef TreeIterator< Pair<KeyT, ValueT> > iterator;
        typedef Tree< Pair<KeyT, ValueT> > tree;

    private:
        Tree< Pair<KeyT, ValueT> > m_tree;
        ValueT defaultV;

    public:
        Map() : m_tree(tree()), defaultV(ValueT())  {
        }

        ValueT operator[](const KeyT& key) const {
            for(iterator ite = m_tree.begin();
                ite != m_tree.end();
                ite++) {
                if((*ite).value().first() == key) {
                    return (*ite).second();
                }
            }

            return ValueT();
        }

        ValueT& operator[](const KeyT& key) {
            for(iterator ite = m_tree.begin();
                ite != m_tree.end();
                ++ite) {
                if((*ite).first() == key) {
                    return (*ite).second();
                }
            }
            //Index out of range. Insert:

            Pair<KeyT, ValueT> p(key, defaultV);
            m_tree.insert( p );
            return defaultV;
        }


        iterator insert(const Pair<KeyT,ValueT>& value) {
            return m_tree.insert(value);
        }

        iterator find(const KeyT& key) {
            for(iterator ite = m_tree.begin();
                ite != m_tree.end();
                ite++) {
                if((*ite).value().first() == key) {
                    return ite;
                }
            }

            return m_tree.end();
        }

        iterator begin() {
            return m_tree.begin();
        }

        iterator end() {
            return m_tree.end();
        }
        iterator first() {
            return m_tree.first();
        }

        iterator last() {
            return m_tree.last();
        }

        const KeyT& min() {
            return (*(m_tree.first())).first();
        }

        const KeyT& max() {
            return (*(m_tree.last())).first();
        }

        void clear() {
            m_tree.clear();
        }
    };
}

#endif // MAP_H
