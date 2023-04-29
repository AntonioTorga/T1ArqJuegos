#include "box_renderer.h"
#include <vector>
#include <iostream>

BoxRenderer::Vec2 operator+(const BoxRenderer::Vec2& lhs, const BoxRenderer::Vec2& rhs)
{
    return BoxRenderer::Vec2{lhs.x + rhs.x, lhs.y + rhs.y};
};

BoxRenderer::Vec2 operator-(const BoxRenderer::Vec2& lhs, const BoxRenderer::Vec2& rhs)
{
    return BoxRenderer::Vec2{lhs.x - rhs.x, lhs.y - rhs.y};
};

BoxRenderer::Vec2 operator*(const BoxRenderer::Vec2& lhs, float rhs)
{
    return BoxRenderer::Vec2{lhs.x * rhs, lhs.y * rhs};
};

namespace GameObject{

class Sprite
{
    public:
        Sprite(BoxRenderer::Vec2 position,BoxRenderer::Vec2 velocity,BoxRenderer::Vec2 size):
        mPosition(position), mVelocity(velocity), mSize(size)
        {}
        BoxRenderer::Vec2& get_pos() {return mPosition;};
        BoxRenderer::Vec2& get_vel() {return mVelocity;};
        BoxRenderer::Vec2& get_size() {return mSize;};
        void add_box(BoxRenderer::BoxId& box, BoxRenderer::Canvas& canvas);
        void update(float dt, BoxRenderer::Canvas& canvas, std::vector<bool> grid);
    private:
        BoxRenderer::Vec2 mPosition, mVelocity, mSize;
        std::vector<BoxRenderer::BoxId> mBoxes;
};

}

void GameObject::Sprite::update(float dt,  BoxRenderer::Canvas& canvas, std::vector<bool> grid)
{   
    //what grid spaces is using:
    BoxRenderer::Vec2 position = get_pos(), size = get_size();
    int center_x = 5 + floor(position.x/0.2) ,center_y = 5 + floor(position.y/0.2);
    //this is our center square on the grid
    //


    for(BoxRenderer::BoxId box : mBoxes)
    {   
        BoxRenderer::Box& b = canvas.getBox(box);
        b.position().x = (b.position().x + get_vel().x * dt);
        b.position().y = (b.position().y + get_vel().y * dt);
    }
}
void GameObject::Sprite::add_box(BoxRenderer::BoxId& box,  BoxRenderer::Canvas& canvas)
{
    mBoxes.push_back(box);
    BoxRenderer::Box& b = canvas.getBox(box);
    b.position() = b.position() + get_pos();
}

void add_to_sprite(GameObject::Sprite& sprite, BoxRenderer::Vec2 pos,  BoxRenderer::Color color, BoxRenderer::Vec2 size, BoxRenderer::Canvas& canvas, float scale) 
{   
    BoxRenderer::BoxId boxId = canvas.addBox({pos*scale, color, size*scale}); 
    sprite.add_box(boxId, canvas);
}

int main()
{
    constexpr unsigned int SCR_WIDTH = 600;
    constexpr unsigned int SCR_HEIGHT = 600;
    BoxRenderer::Canvas canvas( SCR_WIDTH , SCR_HEIGHT ,"Frogger! Ato");

    canvas.setBackgroundColor(BoxRenderer::Color::Gray());

    std::vector<bool> grid(100,false);

    std::vector<GameObject::Sprite> objects; //keeps the sprite objects from the game
    
    // set objets
    // Main character
    float scale = 0.2;
    GameObject::Sprite main({0.0,-0.9},{0.0,0.0},{1,1});
    add_to_sprite(main, { 0.0, 0.0 }, BoxRenderer::Color::Green(), { 0.3, 0.5 }, canvas, scale); //body
    add_to_sprite(main, { 0.2, -0.3 } , BoxRenderer::Color::Green(), {0.1, 0.2 }, canvas, scale); //rightleg
    add_to_sprite(main,  { 0.3, -0.35 }, BoxRenderer::Color::Green(), {0.1, 0.1 } , canvas, scale); 
    add_to_sprite(main, { -0.2, -0.3 }, BoxRenderer::Color::Green(), {0.1, 0.2 }, canvas, scale); //leftleg
    add_to_sprite(main, { -0.3, -0.35 }, BoxRenderer::Color::Green(), {0.1, 0.1 } , canvas, scale);
    add_to_sprite(main, { 0.2, 0.3 }, BoxRenderer::Color::Green(), {0.1, 0.3 }  , canvas, scale); //rightarm
    add_to_sprite(main, { -0.2, 0.3 }, BoxRenderer::Color::Green(), {0.1, 0.3 }  , canvas, scale); //leftarm
    add_to_sprite(main,  { 0.0, 0.40 }, BoxRenderer::Color::Green(), {0.25, 0.25 } , canvas, scale); //head
    add_to_sprite(main, { 0.05, 0.47 }, BoxRenderer::Color::White(), { 0.05, 0.05 }, canvas, scale);//eyes
    add_to_sprite(main, { -0.05, 0.47 }, BoxRenderer::Color::White(), { 0.05, 0.05 }, canvas, scale);
    add_to_sprite(main, { 0.05, 0.48 }, BoxRenderer::Color::Black(), { 0.025, 0.025 }, canvas, scale);
    add_to_sprite(main, { -0.05, 0.48 }, BoxRenderer::Color::Black(), { 0.025, 0.025 }, canvas, scale);



    //Car
    float carScale = 1;
    GameObject::Sprite carRed({ -1.0 ,-0.7 }, { 0.0005 ,0.0 }, { 3, 1});
    add_to_sprite(carRed, { 0.0, 0.0 }, BoxRenderer::Color::Red(), { 0.2, 0.15 }, canvas, carScale); //body
    add_to_sprite(carRed, { 0.01, 0.0075}, BoxRenderer::Color::Black(), {0.05, 0.025},canvas, carScale); //wheels 
    
    //Bus
    float busScale = 1;
    GameObject::Sprite busYellow({ 1.0 ,-0.5 }, { -0.0005 ,0.0 }, { 3, 1 });
    add_to_sprite(busYellow, { 0.0, 0.0 }, BoxRenderer::Color::Yellow(), { 0.6, 0.15 }, canvas, busScale); //body
    add_to_sprite(busYellow, { 0.01, 0.0075 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, busScale); //wheels 


    objects.push_back(main);
    objects.push_back(carRed);
    objects.push_back(busYellow);
    // add boxes to objects
    // 
    auto update = [&](float dt)
    {   
        //receive and execute events
        for(GameObject::Sprite object : objects){
            object.update(dt, canvas, grid);
        }
    };
    

    Alice::Controller controller;
    canvas.drawScene(controller, update);
    //definimos las cajas para cada object y las añadimos a mBoxes
}