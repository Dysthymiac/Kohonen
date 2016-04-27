#include "picturebox.h"

PictureBox::PictureBox(QWidget *parent):ScalableGraphicsView(parent),imageObject(0)
{
    setScene(new QGraphicsScene());
    this->setAutoScale(true);
}

PictureBox::PictureBox(QGraphicsScene *scene, QWidget *parent):ScalableGraphicsView(scene, parent),imageObject(0)
{
    setScene(new QGraphicsScene());
    this->setAutoScale(true);
}

PictureBox::PictureBox(QGraphicsViewPrivate &view, QWidget *parent):ScalableGraphicsView(view, parent),imageObject(0)
{
    setScene(new QGraphicsScene());
    this->setAutoScale(true);
}

QPixmap PictureBox::getImage() const
{
    return image;
}

QImage *PictureBox::getImageObject() const
{
    return imageObject;
}

void PictureBox::setImageObject(QImage *value)
{
    //if(imageObject)
    //    delete imageObject;
    imageObject = value;
    image = QPixmap::fromImage(*imageObject);
    scene()->clear();
    scene()->addPixmap(image);
    setSceneRect(image.rect());
    this->setAutoScale(this->getAutoScale());
}



