#ifndef BOOST_BAR_H
#define BOOST_BAR_H

#include <bn_sprite_ptr.h>
#include <bn_vector.h>

class BoostBar
{
public:
    BoostBar();
    void update();
    void draw(int boost_timer);

private:
    bn::vector<bn::sprite_ptr, 10> bar_sprites;
    bool visible;
};

#endif