#include <nanogui/nanogui.h>
#include <iostream>

int main(){
    bool bvar = false;
    std::string strval = "something";
    std::cout << "Hey!\n";
    nanogui::init();
    {
    nanogui::Screen *screen = new nanogui::Screen(nanogui::Vector2i(500, 700), "Test");
    nanogui::FormHelper *gui = new nanogui::FormHelper(screen);
    nanogui::ref<nanogui::Window> window = gui->addWindow(Eigen::Vector2i(10, 10), "Form helper example");
    gui->addGroup("Basic types");
    gui->addVariable("bool", bvar);
    gui->addVariable("string", strval);
    screen->setVisible(true);
    screen->performLayout();
    window->center();
    nanogui::mainloop();
    }
    nanogui::shutdown();
    return 0;
}
