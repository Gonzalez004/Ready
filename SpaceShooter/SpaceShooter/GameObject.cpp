#include "GameObject.h"

GameObject::GameObject() {
	x = 0;
	y = 0;

	velX = 0;
	velY = 0;

	dirX = 0;
	dirY = 0;

	boundX = 0;
	boundY = 0;

	maxFrame = 0;
	currFrame = 0;
	frameCount = 0;
	frameDelay = 0;
	frameWidth = 0;
	frameHeight = 0;
	animationColumns = 0;
	animationDirection = 0;

	Image = NULL;

	alive = true;
	collidable = true;
}
void GameObject::Destroy() {
	if (Image != NULL)
		al_destroy_bitmap(Image);
}
void GameObject::Init(float x, float y, float velX, float velY, int dirX, int dirY, int boundX, int boundY) {
	GameObject::x = x;
	GameObject::y = y;
	GameObject::velX = velX;
	GameObject::velY = velY;
	GameObject::dirX = dirX;
	GameObject::dirY = dirY;
	GameObject::boundX = boundX;
	GameObject::boundY = boundY;
}
void GameObject::Update() {
	x += velX * dirX;
	y += velY * dirY;
}
void GameObject::Render() {  
}

bool GameObject::CheckCollision(GameObject *otherObject) {
	float oX = otherObject->GetX();
	float oY = otherObject->GetY();

	float obX = otherObject->GetBoundX();
	float obY = otherObject->GetBoundY();

	if (x + boundX > oX - obX &&
		x - boundX<oX + obX &&
		y + boundY>oY - obY &&
		y - boundY < oY + obY)
		return true;
	else
		return false;
}
void GameObject::Collided(int objectID) {

}

bool GameObject::Collidable() {
	return alive && collidable;
}














