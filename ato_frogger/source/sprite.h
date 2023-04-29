#include "box_renderer.h"
#include <vector>

namespace GameObject{

BoxRenderer::Vec2 gridPosition(const BoxRenderer::Vec2& position);

class Sprite
{
    public:
        Sprite(BoxRenderer::Vec2 position,BoxRenderer::Vec2 velocity,BoxRenderer::Vec2 size):
        mPosition(position), mVelocity(velocity), mSize(size)
        {   
            mGrid_Pos = GameObject::gridPosition(position);
        }
        BoxRenderer::Vec2& get_pos() {return mPosition;};
        BoxRenderer::Vec2& get_vel() {return mVelocity;};
        BoxRenderer::Vec2& get_size() {return mSize;};
        std::vector<BoxRenderer::BoxId>& get_boxes() {return mBoxes;};
        void add_box(BoxRenderer::BoxId& box, BoxRenderer::Canvas& canvas);
        void update(float dt, BoxRenderer::Canvas& canvas);
    private:
        BoxRenderer::Vec2 mPosition, mVelocity, mSize;
        BoxRenderer::Vec2 mGrid_Pos;
        std::vector<BoxRenderer::BoxId> mBoxes;
};

}