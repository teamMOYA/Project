#include <allegro.h>
#include "Drawable.h"
#include <cmath>
#include <iostream>
#include "Weapon.h"

using namespace std;

Drawable::Drawable()
{
    x = 10;
    y = 10;
}

Drawable::Drawable(BITMAP ***animations, int x, int y, int height, int width)
{

    this->animations = animations;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;

    genWalkCollision();
    this->collisionRadius = (width/3)*2;

    this->collisionType = 1;
}

/**
Constructor para instanciar el contenido del Ambiente del mapa
*/
Drawable::Drawable(BITMAP *bitmapAmbient, int x, int y, int height, int width)
{
    this->bitmapAmbient = bitmapAmbient;
    this->x = x;
    this->y = y;
    this->height = height;
    this->width = width;
    genWalkCollision();
    this->collisionRadius = (width/3)*2;

}

void Drawable::draw(BITMAP *buffer){
        //BITMAP bitmapAnimation = this->animations[this->activeBitmap[0]][this->activeBitmap[1]];
        BITMAP* bitmapAnimation = this->animations[0][0];
        //BITMAP *bitmapPointer = &bitmapAnimation;
        masked_blit(bitmapAnimation, buffer, 0, 0, x, y, width, height);
}

//TODO cambiar a character
bool Drawable::attackCollision(Drawable *drawable, Weapon *weapon) {


    float polarradius = distance(drawable);

    float angle = atan2(this->y - drawable->y, this->x - drawable->x) *180/3.14 ;
    float percent = 90;
    float endAngle;
    float startAngle = 0;
    //switch (this->activeBitmap[0]) {

    switch (2) {
        case 0:
            startAngle = 45;
            break;
        case 1:
            startAngle = 135;
            break;
        case 2:
            startAngle = -135;
            break;
        case 3:
            startAngle = -45;
            break;
        default:;
    }
    endAngle = percent + startAngle;
    //if (angle >= startAngle && angle <= endAngle && polarradius < weapon->getAttackDistance()) {
    cout << angle << " angle\n";
    cout << percent<< " percent\n";
    cout << endAngle<< " endAngle\n";
    cout << startAngle<< " startAngle\n";
    cout << endAngle<< " endAngle\n";
    cout << (angle >= startAngle) << " angle >= startAngle\n";
    cout << (angle <= endAngle) << " angle <= endAngle\n";
    cout << (polarradius) << " polarradius\n";


    if (angle >= startAngle && angle <= endAngle && polarradius < 100) {
        cout << "HIT\n";
        cout << "HIT\n";
        cout << "HIT\n";

        return true;
    }else{
        return false;
    }



}
bool Drawable::collision(Drawable *drawable){
    switch(this->collisionType) {
        case 1:
            if (distance(drawable) < (this->collisionRadius + drawable->collisionRadius)) {
                return true;
            }
            break;
        case 2:
            break;

        default:;
    }
    return false;

}

int Drawable::distance(Drawable *drawable){
    return sqrt(
            ((drawable->x + drawable->walkCollision[0]) - (this->x + this->walkCollision[0]))
            *
            ((drawable->x + drawable->walkCollision[0]) - (this->x + this->walkCollision[0]))
            +
            ((drawable->y + drawable->walkCollision[1]) - (this->y + this->walkCollision[1]))
            *
            ((drawable->y + drawable->walkCollision[1]) - (this->y + this->walkCollision[1])));

}


void Drawable::genWalkCollision(){
    this->walkCollision[0] = this->width/2;
    this->walkCollision[1] = (this->height/6)*5;
}



void Drawable::setHeight(int height)
{
    this->height = height;
}

void Drawable::setWidth(int width)
{
    this->width = width;
}

void Drawable::setX(int x)
{
    this->x = x;
}

void Drawable::setY(int y)
{
    this->y = y;
}


int Drawable::getX()
{
    return x;
}

int Drawable::getY()
{
    return y;
}

int Drawable::getHeight()
{
    return 0;
}

int Drawable::getWidth()
{
    return 0;
}

void Drawable::genAtackCollision() {

}

BITMAP *Drawable::getBitmapAmbient()
{
    return this->bitmapAmbient;
}



