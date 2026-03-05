#include "boost_bar.h"
#include <bn_keypad.h>
#include "bn_sprite_items_bar.h"

BoostBar::BoostBar() :
    bar_sprites(bn::vector<bn::sprite_ptr, 10>()),
    visible(false)
{
}

void BoostBar::update()
{
    // visibility with X button
    if (bn::keypad::b_pressed())
    {
        visible = !visible;
        
    }
}

void BoostBar::draw(int boost_timer)
{
    bar_sprites.clear();

    if (!visible)
        return;

    // Calculate how many segments to fill (0 to 3)
    int filled_speed_bar = static_cast<int>((boost_timer / 180.0) * 3);
    
    if (filled_speed_bar > 3) 
        filled_speed_bar = 3;

    // Draw each bar segment
    for (int i = 0; i < 3; i++)
    {
        int segment_x = 50 + (i * 12);
        
        auto segment = bn::sprite_items::bar.create_sprite(segment_x, 50); 
        
        if (i < filled_speed_bar)
        {
            segment.set_scale(0.75);  
        }
        else
        {
            segment.set_scale(0.5);   
        }
        
        bar_sprites.push_back(segment);
    }
}