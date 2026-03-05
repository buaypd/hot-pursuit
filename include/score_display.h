#ifndef SCORE_DISPLAY_H
#define SCORE_DISPLAY_H

#include <bn_sprite_ptr.h>
#include <bn_vector.h>
#include <bn_sprite_text_generator.h>

class ScoreDisplay
{
public:
    ScoreDisplay();
    void update();
    void show_number(int x, int y, int number);
    void resetScore();

    int score;
    int high_score;
    bn::vector<bn::sprite_ptr, 22> score_sprites;
    bn::sprite_text_generator text_generator;
};
#endif