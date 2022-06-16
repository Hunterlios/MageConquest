#pragma once
#include "Enemy.h"
class Rat :
    public Enemy
{
private:
    RenderWindow* window;
    RectangleShape shape;
    
public:
    Rat(RenderWindow* window, ResourcesManager& resManager);
    ~Rat();
    

    // Odziedziczono za pośrednictwem elementu Enemy
    virtual void Update(float deltaTime) override;

    virtual void Render() override;

    virtual RectangleShape getShape() override;

};

