#pragma once
#include "Enemy.h"
class Rat :
    public Enemy
{
private:
    RenderWindow* window;
    RectangleShape shape;
    Vector2f dir;
    Vector2f dirNorm;
    float x, y;
    
public:
    Rat(RenderWindow* window, ResourcesManager& resManager);
    ~Rat();
    
    Vector2f generatePos();

    // Odziedziczono za poœrednictwem elementu Enemy
    virtual void Update(float deltaTime, Vector2f playerCenter) override;

    virtual void Render() override;

    virtual RectangleShape getShape() override;

};

