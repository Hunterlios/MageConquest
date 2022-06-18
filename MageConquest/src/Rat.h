#pragma once
#include "Enemy.h"
class Rat :
    public Enemy
{
    
public:
    Rat(RenderWindow* window, ResourcesManager& resManager);
    ~Rat();
    
    Vector2f generatePos();


    // Odziedziczono za poœrednictwem elementu Enemy
    virtual void Update(float deltaTime, Vector2f playerCenter) override;

    virtual void Render() override;

    virtual RectangleShape getShape() override;

    virtual Vector2f getVelocity() override;

    virtual void setPos(Vector2f pos) override;

};

