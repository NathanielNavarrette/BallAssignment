#ifndef BALLANIMATION_H
#define BALLANIMATION_H

#include <QWidget>
//#include <QGraphicsObject>

class BallAnimation : public QWidget
{
    Q_OBJECT
public:
    explicit BallAnimation(QWidget *parent = nullptr);
    void setOrigin(const QPoint &origin);
    void setMove(int x, int y);
    void addToOrigin(const QPoint &origin);


signals:

public slots:
    void paintEvent(QPaintEvent* event);
private:
    int collisionDetect();
    int m_size = 100;
    QPoint m_origin;
    int m_mvY;
    int m_mvX;
};

#endif // BALLANIMATION_H
