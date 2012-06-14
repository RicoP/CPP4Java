#ifndef PAIR_H
#define PAIR_H
#include <iostream>

namespace mystl {
    template<typename T1, typename T2>
    class Pair
    {
    private:
        T1 _first;
        T2 _second;

    public:
        Pair() : _first(), _second() {
        }

        Pair(T1 first, T2 second) : _first(first), _second(second) {
        }

        T1 first() const { return _first; }
        T1& first() { return _first; }

        T2 second() const { return _second; }
        T2& second() { return _second; }
    };

    template<typename T1, typename T2>
    std::ostream& operator<<(std::ostream &lhs, const Pair<T1,T2> &pair) {
        lhs << "<" << pair.first() << "," << pair.second() << ">";
        return lhs;
    }
}
#endif // PAIR_H
