#pragma once

#include <nanogui/theme.h>

namespace custom{
    class Config : public nanogui::Theme{
    public:
        Config(NVGcontext *ctx) : nanogui::Theme(ctx){
            mTabMinButtonWidth = 0;
        };
        nanogui::Vector2i mTabCloseButtonSize = nanogui::Vector2i(20, 20);
    };
}
