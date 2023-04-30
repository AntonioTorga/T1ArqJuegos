#include "sprite.h"
#include "vec2_functions.h"
#include <cmath>
#include <iostream>
#include <memory>

void GameObject::Sprite::update(float dt,  BoxRenderer::Canvas& canvas)
{   
    if (abs(mPosition.x)>1.5)
    {
        mPosition.x = std::copysign(1.49, -mPosition.x);
        for(BoxRenderer::BoxId box : mBoxes)
        {   
            BoxRenderer::Box& b = canvas.getBox(box);
            b.position().x = -b.position().x;
            b.position().y = (b.position().y + get_vel().y * dt);
        }
    }
    else
    {    
        mPosition.x = mPosition.x + get_vel().x * dt;
        for(BoxRenderer::BoxId box : mBoxes)
        {   
            BoxRenderer::Box& b = canvas.getBox(box);
            b.position().x = (b.position().x + get_vel().x * dt);
            b.position().y = (b.position().y + get_vel().y * dt);
        }
    }
}
void GameObject::Sprite::add_box(BoxRenderer::BoxId& box,  BoxRenderer::Canvas& canvas)
{
    mBoxes.push_back(box);
    BoxRenderer::Box& b = canvas.getBox(box);
    b.position() = b.position() + get_pos();
}

BoxRenderer::Vec2 GameObject::gridPosition(const BoxRenderer::Vec2& position) {
    BoxRenderer::Vec2 new_Gp = position + BoxRenderer::Vec2{1,-1};
    new_Gp.x = floor(new_Gp.x / 0.2);
    new_Gp.y = floor(new_Gp.y / -0.2);
    return new_Gp;
}

