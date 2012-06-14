#ifndef GREATER_H
#define GREATER_H
#include "less.h"

namespace mystl {
    template<typename T>
    class Greater {
      public:
       bool operator()(const T& lhs, const T& rhs) {
           Less<T> less;
           return lhs != rhs && less(rhs, lhs);
       }
    };
}
#endif // GREATER_H
