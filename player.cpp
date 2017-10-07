#include "player.hpp"
#include "bullet.hpp"
#include <cmath>
#include <QDebug>
#include <QGraphicsScene>

Player::Player(double x, double y, double w, double h,
               double vx, QObject *parent):
    Entity(x,y,w,h,vx,0.f,parent)
{}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Left:
        mVelocity.setX(-fabs(mVelocity.x()));
        if(left() >= fabs(mVelocity.x()))
            move();
        break;
    case Qt::Key_Right:
        mVelocity.setX(+fabs(mVelocity.x()));
        if(right() <= this->scene()->width() - fabs(mVelocity.x()))
            move();
        break;
    case Qt::Key_Space:
        fireBullet();
        break;
    default:
        break;
    }
}

void Player::fireBullet()
{
    Bullet *bullet = new Bullet(x() + (this->width() - BULLET_WIDTH) / 2,
                                y() - BULLET_HEIGHT, BULLET_WIDTH,
                                BULLET_HEIGHT, 0.f, BULLET_VELOCITY);
    bullet->setPos(x() + (this->width() - BULLET_WIDTH) / 2,y() - BULLET_HEIGHT - 1);
    scene()->addItem(bullet);
}
