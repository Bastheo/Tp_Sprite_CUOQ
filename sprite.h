#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>

class Sprite : public QObject, public QGraphicsItem
{
 Q_OBJECT
public:
 explicit Sprite(QObject *parent = 0);

private slots:
 void nextFrame(); // Slot for turning images into QPixmap

private:
 void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
 QRectF boundingRect() const;
 int position = 0;
 const int vitesse = 5;

private:
 QTimer *timer; // Timer for turning images into QPixmap
 QPixmap *spriteImage2;
 QPixmap *spriteImage;// In this QPixmap object will be placed sprite
 int currentFrame; // Coordinates X, which starts the next frame of the sprite

};

class Minotaure : public Sprite
{
    Q_OBJECT
   public:
    explicit Minotaure(QObject *parent = 0);

   private slots:
    void nextFrame();

   private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    int position = 0;
    const int vitesse = 10;

   private:
    QTimer *timer;
    QPixmap *spriteImage;
    int currentFrame;
};

class Demon : public Sprite
{
    Q_OBJECT
   public:
    explicit Demon(QObject *parent = 0);

   private slots:
    void nextFrame();

   private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
    int position = 0;
    const int vitesse = 5;

   private:
    QTimer *timer;
    QPixmap *spriteImage;
    int currentFrame;
};

#endif // SPRITE_H


