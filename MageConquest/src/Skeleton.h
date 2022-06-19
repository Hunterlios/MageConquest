#pragma once
#include "Enemy.h"
class Skeleton :
    public Enemy
{
public:
    Skeleton(RenderWindow* window, ResourcesManager& resManager);
    ~Skeleton();

    Vector2f generatePos();
    // Odziedziczono za poœrednictwem elementu Enemy
    virtual void setPos(Vector2f pos) override;
    virtual Vector2f getVelocity() override;
    virtual void Update(float deltaTime, Vector2f playerCenter) override;
    virtual void Render() override;
    virtual RectangleShape getShape() override;
};

