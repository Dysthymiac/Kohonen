#ifndef SCALABLEGRAPHICSVIEW_H
#define SCALABLEGRAPHICSVIEW_H

#include <QObject>
#include <QWidget>
#include <QGraphicsView>
#include <QMouseEvent>

class ScalableGraphicsView : public QGraphicsView
{
    Q_OBJECT
signals:
    void mouseMove(QPoint pos, Qt::MouseButton button);
    void mousePress(QPoint pos, Qt::MouseButton button);

public:
    ScalableGraphicsView(QWidget *parent = 0);
    ScalableGraphicsView(QGraphicsScene * scene, QWidget *parent = 0);
    ScalableGraphicsView(QGraphicsViewPrivate & view, QWidget *parent = 0);

    bool getAutoScale() const;
    void setAutoScale(bool value);

private:
    bool autoScale;

protected:
    void resizeEvent(QResizeEvent * event);
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent * event);
};

#endif // SCALABLEGRAPHICSVIEW_H
