#include "dialog.h"
#include "ui_dialog.h"
#include "triangle.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    mouseDown(false)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::paintEvent(QPaintEvent * p) {
    QPainter painter(this);

    painter.drawLine(mouseXLast, mouseYLast, mouseX, mouseY);
}

void Dialog::mousePressEvent(QMouseEvent *) {
    mouseDown = true;
    update();
    showMouseInfo();
}

void Dialog::mouseReleaseEvent(QMouseEvent *) {
    mouseDown = false;
    update();
    showMouseInfo();
}

void Dialog::mouseMoveEvent(QMouseEvent * m) {
    mouseXLast = mouseX;
    mouseYLast = mouseY;
    mouseX = m->x();
    mouseY = m->y();
    update();
    showMouseInfo();
}

void Dialog::showMouseInfo() {
    static int i = 0;
    char buff[1024];
    sprintf(buff, "%i\tpos(%i,%i), Left:%i", i++, mouseX, mouseY, mouseDown);
    qDebug(buff);
}
