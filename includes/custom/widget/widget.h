#pragma once

#include <nanogui/widget.h>

namespace custom{

class Widget : public nanogui::Widget{
public:
    Widget(Widget* parent) : nanogui::Widget(parent){};
    virtual void performLayout(NVGcontext *ctx) override;
};

}