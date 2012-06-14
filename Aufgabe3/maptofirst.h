#ifndef MAPTOFIRST_H
#define MAPTOFIRST_H

#include "pair.h"
#include "less.h"

namespace mystl {
    template<typename T1, typename T2, typename Op = Less<T1> >
    class MapToFirst {
        public:
         bool operator()(const Pair<T1,T2>& a, const Pair<T1,T2>& b) {
             Op op;
             return op(a.first(), b.first());
         }
    };
}

#endif // MAPTOFIRST_H
