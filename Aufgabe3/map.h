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
        ValueT defautltV;

    public:
        Map() : m_tree(tree()), defautltV(ValueT())  {
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

            return defautltV;
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
        //iterator first();
        //iterator last();
        //const KeyT& min();
        //const KeyT& max();
        //void clear();

    };
}

#endif // MAP_H
