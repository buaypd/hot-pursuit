#include <bn_core.h>
#include <bn_display.h>
#include <bn_keypad.h>
#include <bn_string.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_text_generator.h>

#include "common_fixed_8x16_font.h"

// Width and height of the the player bounding box
static constexpr bn::size PLAYER_SIZE = {8, 8};

static constexpr int MIN_Y = -bn::display::height() / 2;
static constexpr int MAX_Y = bn::display::height() / 2;
static constexpr int MIN_X = -bn::display::width() / 2;
static constexpr int MAX_X = bn::display::width() / 2;

// Number of characters required to show two of the longest numer possible in an int (-2147483647)
static constexpr int MAX_SCORE_CHARS = 22;

// Score location
static constexpr int SCORE_X = 70;
static constexpr int SCORE_Y = -70;

// High score location
static constexpr int HIGH_SCORE_X = -70;
static constexpr int HIGH_SCORE_Y = -70;

class ScoreDisplay {
    public:
        ScoreDisplay() :
            score(0),
            high_score(0),
            score_sprites(bn::vector<bn::sprite_ptr, MAX_SCORE_CHARS>()),
            text_generator(bn::sprite_text_generator(common::fixed_8x16_sprite_font))
        {}

        void update() {
            score++;
            if(score > high_score) {
                high_score = score;
            }
            score_sprites.clear();
            show_number(SCORE_X, SCORE_Y, score);
            show_number(HIGH_SCORE_X, HIGH_SCORE_Y, high_score);
        }

        void show_number(int x, int y, int number) {
            bn::string<MAX_SCORE_CHARS> number_string = bn::to_string<MAX_SCORE_CHARS>(number);
            text_generator.generate(x, y, number_string, score_sprites);
        }

        void resetScore() {
            score = 0;
        }

        int score;
        int high_score;
        bn::vector<bn::sprite_ptr, MAX_SCORE_CHARS> score_sprites;
        bn::sprite_text_generator text_generator;
};

int main() {
    bn::core::init();

    ScoreDisplay scoreDisplay = ScoreDisplay();

    while(true) {
        if(bn::keypad::a_pressed()) {
            scoreDisplay.resetScore();
        }
        scoreDisplay.update();

        bn::core::update();
    }
}