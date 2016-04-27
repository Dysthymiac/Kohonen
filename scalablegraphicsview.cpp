#include "scalablegraphicsview.h"

#include <qdebug.h>

ScalableGraphicsView::ScalableGraphicsView(QWidget* parent):QGraphicsView(parent), autoScale(false)
{

}

ScalableGraphicsView::ScalableGraphicsView(QGraphicsScene * scene, QWidget* parent):QGraphicsView(scene, parent), autoScale(false)
{

}

ScalableGraphicsView::ScalableGraphicsView(QGraphicsViewPrivate & view, QWidget *parent):QGraphicsView(view, parent), autoScale(false)
{

}

bool ScalableGraphicsView::getAutoScale() const
{
    return autoScale;
}

void ScalableGraphicsView::setAutoScale(bool value)
{
    autoScale = value;
    if(autoScale)
        fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}

void ScalableGraphicsView::resizeEvent(QResizeEvent *event)
{
    if(autoScale)
        fitInView(scene()->sceneRect(), Qt::KeepAspectRatio);
}

void ScalableGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
    QPointF posF = this->mapToScene(event->pos());
    QPoint pos;
    pos.setX((int)posF.x());
    pos.setY((int)posF.y());
    emit mouseMove(pos, event->button());
}


void ScalableGraphicsView::mousePressEvent(QMouseEvent *event)
{
    QPointF posF = this->mapToScene(event->pos());
    QPoint pos;
    pos.setX((int)posF.x());
    pos.setY((int)posF.y());

    emit mousePress(pos, event->button());
}
