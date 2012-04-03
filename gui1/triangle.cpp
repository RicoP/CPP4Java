#include "triangle.h"
#include <QtCore>

void checkInsection(Triangle* fov,
                    Triangle* triangles,
                    int ctriangles,
                    void (*callback)(void* obj, Triangle* triangle),
                    void* obj) {
    callback(NULL, NULL);
}
