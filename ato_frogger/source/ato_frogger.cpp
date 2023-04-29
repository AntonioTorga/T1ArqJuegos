#include "box_renderer.h"
#include <vector>
#include "sprite.h"
#include "vec2_functions.h"
#include <iostream>
#include <memory>

void add_to_sprite(std::shared_ptr <GameObject::Sprite> sprite, BoxRenderer::Vec2 pos,  BoxRenderer::Color color, BoxRenderer::Vec2 size, BoxRenderer::Canvas& canvas, float scale) 
{   
    BoxRenderer::BoxId boxId = canvas.addBox({pos*scale, color, size*scale}); 
    sprite->add_box(boxId, canvas);
}

void create_bus(std::shared_ptr <GameObject::Sprite> busName, BoxRenderer::Canvas& canvas, float busScale)
{
    add_to_sprite(busName, { 0.0, 0.0 }, BoxRenderer::Color::Yellow(), { 0.6, 0.15 }, canvas, busScale); //body
    add_to_sprite(busName, { 0.28, 0.07 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, busScale); //wheels 
    add_to_sprite(busName, { -0.28, 0.07 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, busScale); //wheels 
    add_to_sprite(busName, { 0.28, -0.07 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, busScale); //wheels 
    add_to_sprite(busName, { -0.28, -0.07 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, busScale); //wheels 


}
void create_car(std::shared_ptr <GameObject::Sprite> carName, BoxRenderer::Canvas& canvas, float carScale)
{
    add_to_sprite(carName, { 0.0, 0.0 }, BoxRenderer::Color::Red(), { 0.2, 0.15 }, canvas, carScale); //body
    add_to_sprite(carName, { 0.095, 0.075}, BoxRenderer::Color::Black(), {0.05, 0.025},canvas, carScale); //wheels 
    add_to_sprite(carName, { 0.095, -0.075 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, carScale); //wheels 
    add_to_sprite(carName, { -0.095, 0.075 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, carScale); //wheels 
    add_to_sprite(carName, { -0.095, -0.075 }, BoxRenderer::Color::Black(), { 0.05, 0.025 }, canvas, carScale); //wheels 
}
int main()
{
    constexpr unsigned int SCR_WIDTH = 600;
    constexpr unsigned int SCR_HEIGHT = 600;
    BoxRenderer::Canvas canvas( SCR_WIDTH , SCR_HEIGHT ,"Frogger! Ato");

    canvas.setBackgroundColor(BoxRenderer::Color::Gray());

    std::vector<bool> rp(10,false);
    std::vector<std::vector<bool>> grid(10,rp);

    std::vector<std::shared_ptr <GameObject::Sprite>> objects; //keeps the sprite objects from the game
    
// set objets
// Main character
    float scale = 0.2;
    std::shared_ptr <GameObject::Sprite> main(new  GameObject::Sprite({0.0,-0.9},{0.0,0.0},{1,1}));
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

//Cars
    float carScale = 1;
    std::shared_ptr <GameObject::Sprite> carRed6(new GameObject::Sprite({ -1.00 ,0.7 }, { 0.0006 ,0.0 }, { 1, 1 })); //1
    std::shared_ptr <GameObject::Sprite> carRed7(new GameObject::Sprite({ 0.5 ,0.7 }, { 0.0006 ,0.0 }, { 1, 1 })); //1
    std::shared_ptr <GameObject::Sprite> carRed2(new GameObject::Sprite({ 1.49 ,0.3 }, { -0.0005 ,0.0 }, { 1, 1})); //3
    std::shared_ptr <GameObject::Sprite> carRed5(new GameObject::Sprite({ 0.5 ,-0.1 }, { 0.0003 ,0.0 }, { 1, 1})); //5
    std::shared_ptr <GameObject::Sprite> carRed3(new GameObject::Sprite({ -1.49 ,-0.3 }, { 0.0005 ,0.0 }, { 1, 1})); //6
    std::shared_ptr <GameObject::Sprite> carRed(new GameObject::Sprite({ -1.49 ,-0.7 }, { 0.0005 ,0.0 }, { 1, 1})); //8
    std::shared_ptr <GameObject::Sprite> carRed4(new GameObject::Sprite({ 0.0 ,-0.7 }, { 0.0005 ,0.0 }, { 1, 1})); //8
    create_car(carRed, canvas, carScale);
    create_car(carRed2, canvas, carScale);
    create_car(carRed3, canvas, carScale);
    create_car(carRed4, canvas, carScale);
    create_car(carRed5, canvas, carScale);
    create_car(carRed6, canvas, carScale);
    create_car(carRed7, canvas, carScale);

//Buses
    float busScale = 1;
    std::shared_ptr <GameObject::Sprite> busYellow4(new GameObject::Sprite({ -1.49 , 0.7 }, { 0.0006 ,0.0 }, { 3, 1 })); //1
    std::shared_ptr <GameObject::Sprite> busYellow5(new GameObject::Sprite({ 1.49 , 0.5 }, { -0.0006 ,0.0 }, { 3, 1 })); //2
    std::shared_ptr <GameObject::Sprite> busYellow7(new GameObject::Sprite({ 0.3 , 0.5 }, { -0.0006 ,0.0 }, { 3, 1 })); //2
    std::shared_ptr <GameObject::Sprite> busYellow2(new GameObject::Sprite({ -1.49 ,-0.1 }, { 0.0003 ,0.0 }, { 3, 1 })); //5
    std::shared_ptr <GameObject::Sprite> busYellow3(new GameObject::Sprite({ 0.0 ,-0.1 }, { 0.0003 ,0.0 }, { 3, 1 })); //5
    std::shared_ptr <GameObject::Sprite> busYellow(new GameObject::Sprite({ 1.49 ,-0.5 }, { -0.0005 ,0.0 }, { 3, 1 })); //
    create_bus(busYellow,canvas,busScale);
    create_bus(busYellow2, canvas, busScale);
    create_bus(busYellow3, canvas, busScale);
    create_bus(busYellow4, canvas, busScale);
    create_bus(busYellow5, canvas, busScale);
    create_bus(busYellow7, canvas, busScale);
//añadir a las cosas que se actualizan
    objects.push_back(main);
    objects.push_back(carRed);
    objects.push_back(carRed2);
    objects.push_back(carRed3);
    objects.push_back(carRed4);
    objects.push_back(carRed5);
    objects.push_back(carRed6);
    objects.push_back(carRed7);
    objects.push_back(busYellow);
    objects.push_back(busYellow2);
    objects.push_back(busYellow3);
    objects.push_back(busYellow4);
    objects.push_back(busYellow5);
    objects.push_back(busYellow7);

    auto update = [&](float dt)
    {   
        //receive and execute events
        for(std::shared_ptr <GameObject::Sprite> object : objects){
            object->update(dt, canvas);
        }
    };
    
    Alice::Controller controller;
    controller.onKeyPress(Alice::Key::W, [&]() 
        { 
            main->get_pos().y = main->get_pos().y + 0.2;
            for(BoxRenderer::BoxId box : main->get_boxes() )
            {   
                BoxRenderer::Box& b = canvas.getBox(box);
                b.position().y = b.position().y + 0.2;
            }
        });
    controller.onKeyPress(Alice::Key::S, [&]() 
        { 
            main->get_pos().y = main->get_pos().y - 0.2;
            for (BoxRenderer::BoxId box : main->get_boxes())
            {
                BoxRenderer::Box& b = canvas.getBox(box);
                b.position().y = b.position().y - 0.2;
            }
        });
    controller.onKeyPress(Alice::Key::D, [&]()
        {
            main->get_pos().x = main->get_pos().x + 0.2;
            for (BoxRenderer::BoxId box : main->get_boxes())
            {
                BoxRenderer::Box& b = canvas.getBox(box);
                b.position().x = b.position().x + 0.2;
            }
        });
    controller.onKeyPress(Alice::Key::A, [&]()
        {
            main->get_pos().x = main->get_pos().x - 0.2;
            for (BoxRenderer::BoxId box : main->get_boxes())
            {
                BoxRenderer::Box& b = canvas.getBox(box);
                b.position().x = b.position().x - 0.2;
            }
        });
    //controller.onKeyPress(Alice::Key::S, [&]() { speed /= 2.0f; });
    //controller.onKeyPress(Alice::Key::ESCAPE, [&]() { canvas.close(); });
    canvas.drawScene(controller, update);
    //definimos las cajas para cada object y las añadimos a mBoxes
}