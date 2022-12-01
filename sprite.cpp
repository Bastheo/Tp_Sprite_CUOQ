#include "sprite.h"

Sprite::Sprite(QObject *parent) :
 QObject(parent), QGraphicsItem()
{
 currentFrame = 0; // On initialise les coordonnées du sprite
 spriteImage = new QPixmap(":/sprite/Matthieu.png"); // On charge l'image dans un QPixmap
 spriteImage2 = new QPixmap(":/sprite/Mino_M2.png");
 timer = new QTimer(); // Creation d'un timer pour l'animation du sprite
 connect(timer, &QTimer::timeout, this, &Sprite::nextFrame); //Un slot permettra d'afficher l'image suivante quand le chrono sera fini
 timer->start(25); // On lance le timer pour un décompte de 25 ms
}

QRectF Sprite::boundingRect() const
{
 return QRectF(0,0,630,73); //On crée une zone rectangulaire
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget
*widget)
{
 /* Dans la zone graphique on dessine un sprite
 * Les 2 permiers arguments - l'abscisse X et l'ordonnée Y où on place l'image
QPixmap
 * Le 3eme argument - un pointeur vers le QPixmap
 * 4e et 5e arguments - Les coordonnées de l'image du sprite à afficher issues de
QPixmap (qui contient l'image composée des différentes position du personnage
 * en mettant currentFrame dans X on déplace la vue au bon endroit
 * Les 2 derniers arguments - la largeur et la hauteur de l'image (frame) affichée
 * */
 painter->drawPixmap(position,0, *spriteImage, currentFrame, 0, 63,73);
 painter->drawPixmap(position+80,0, *spriteImage2, currentFrame, 0, 63,73);
 Q_UNUSED(option);
 Q_UNUSED(widget);
}

void Sprite::nextFrame()
{
 /* Quand le SIGNAL du slot est actif, on décale la vue du nombre de pixel necessaire à obtenir le frame suivant
 * si on arrive en fin d'image on retourne à 0 et on update
 * */
 position+=vitesse;
 if (position>566){position=0;}
 currentFrame += 64;
 if (currentFrame >= 573 ) currentFrame = 0;
 this->update(0,0,630,73);
}


Minotaure::Minotaure(QObject *parent)
{
 currentFrame = 0; // On initialise les coordonnées du sprite
 spriteImage = new QPixmap(":/sprite/Mino_M2.png"); // On charge l'image dans un QPixmap
 timer = new QTimer(); // Creation d'un timer pour l'animation du sprite
 connect(timer, &QTimer::timeout, this, &Minotaure::nextFrame); //Un slot permettra d'afficher l'image suivante quand le chrono sera fini
 timer->start(25); // On lance le timer pour un décompte de 25 ms
}

QRectF Minotaure::boundingRect() const
{
 return QRectF(0,0,630,73);
}

void Minotaure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget
*widget)
{
 painter->drawPixmap(position,0, *spriteImage, currentFrame, 0, 63,73);
 Q_UNUSED(option);
 Q_UNUSED(widget);
}

void Minotaure::nextFrame()
{
 position+=vitesse;
 if (position>566){position=0;}
 currentFrame += 64;
 if (currentFrame >= 573 ) currentFrame = 0;
 this->update(0,0,630,73);
}

Demon::Demon(QObject *parent)
{
 currentFrame = 0; // On initialise les coordonnées du sprite
 spriteImage = new QPixmap(":/sprite/Matthieu.png"); // On charge l'image dans un QPixmap
 timer = new QTimer(); // Creation d'un timer pour l'animation du sprite
 connect(timer, &QTimer::timeout, this, &Demon::nextFrame); //Un slot permettra d'afficher l'image suivante quand le chrono sera fini
 timer->start(25); // On lance le timer pour un décompte de 25 ms
}

QRectF Demon::boundingRect() const
{
 return QRectF(0,0,630,73);
}

void Demon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget
*widget)
{
 painter->drawPixmap(position,0, *spriteImage, currentFrame, 0, 63,73);
 Q_UNUSED(option);
 Q_UNUSED(widget);
}

void Demon::nextFrame()
{
 position+=vitesse;
 if (position>566){position=0;}
 currentFrame += 64;
 if (currentFrame >= 573 ) currentFrame = 0;
 this->update(0,0,630,73);
}
