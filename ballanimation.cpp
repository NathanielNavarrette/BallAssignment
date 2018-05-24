#include "ballanimation.h"
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>

/*
 * Note: m_origin is the origin of the ball in the square
 * this->height and this->width are the size of the square
 * (really its the size of the widget)
 * */

BallAnimation::BallAnimation(QWidget *parent) :
    QWidget(parent),
    m_origin(QPoint(48,50))

{
    setFixedSize(m_size, m_size);
}

void BallAnimation::setOrigin(const QPoint &origin)
{
    m_origin = origin;
}

void BallAnimation::addToOrigin(const QPoint &point)
{

    m_origin += point;
    qDebug() << "pos X: " << m_origin.x() << " Pos Y: " << m_origin.y();
}


void BallAnimation::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawRect(QRect(0,0,width()-1,height()-1));
    painter.setBrush(Qt::blue);
    painter.setPen(Qt::red);
    painter.drawEllipse(m_origin,10,10);
}

int BallAnimation::collisionDetect()
{
    if(m_origin.y() <= 0)
        return 1;
    else if(m_origin.x() >= this->width())
        return 2;
    else if(m_origin.y() >= this->height())
        return 3;
    else if(m_origin.x() <= 0)
        return 4;
}

void BallAnimation::setMove(int mv_x, int mv_y)
{
    m_mvX = mv_x;
    m_mvY = mv_y;
    switch(collisionDetect())
    {
    case 1:
        setMove(m_mvX, m_mvY * -1);
        break;
    case 2:
        setMove(m_mvX * -1, m_mvY);
        break;
    case 3:
        setMove(m_mvX, m_mvY * -1);
        break;
    case 4:
        setMove(m_mvX * -1, m_mvY);
        break;
    }
    addToOrigin(QPoint(m_mvX, m_mvY));
}
