#include <QtGui/QApplication>
#include "dialog.h"
#include "triangle.h"

void callback (void* obj, Triangle* tri);

int main(int argc, char *argv[])
{
    Triangle fov;
    checkInsection(&fov, NULL, 0, callback, NULL);

    //---
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    
    return a.exec();
}

void callback (void* obj, Triangle* tri) {
    qDebug("Hallo");
}
