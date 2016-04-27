#ifndef PICTUREBOX_H
#define PICTUREBOX_H

#include "scalablegraphicsview.h"
#include <QObject>
#include <QWidget>
#include <QImage>
#include <QPixmap>
#include <QGraphicsScene>

class PictureBox : public ScalableGraphicsView
{
    Q_OBJECT
    QPixmap image;
    QImage  *imageObject;
public:
    PictureBox(QWidget *parent = 0);
    PictureBox(QGraphicsScene * scene, QWidget *parent = 0);
    PictureBox(QGraphicsViewPrivate & view, QWidget *parent = 0);

    QPixmap getImage() const;
    QImage *getImageObject() const;
    void setImageObject(QImage *value);
};

#endif // PICTUREBOX_H
