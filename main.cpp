#include <nanogui/nanogui.h>
#include <custom/tabwidget/tabwidget.h>
#include <iostream>
#include <string>

int main(){
    nanogui::Vector2i screenSize = nanogui::Vector2i(500, 500);
    nanogui::init();
    {
    nanogui::Screen *screen = new nanogui::Screen(screenSize, "Self-Manager");
    custom::TabWidget* tabWidget = screen->add<custom::TabWidget>();

    nanogui::Widget* layer = tabWidget->createTab("Routine");
    layer->setLayout(new nanogui::GroupLayout());
    layer->add<nanogui::Label>("Routine Tab", "sans-bold");

    layer = tabWidget->createTab("About");
    layer->setLayout(new nanogui::GroupLayout());
    layer->add<nanogui::Label>("About Tab", "sans-bold");

    tabWidget->createTab("Placeholder");
    tabWidget->createTab("+");
    tabWidget->setActiveTab(0);

    screen->setResizeCallback(
        [screen](nanogui::Vector2i size){
            screen->setSize(size);
            for (nanogui::Widget *child : screen->children()){
                child->setSize(size);
                child->performLayout(screen->nvgContext());
            }
        }
    );
    screen->setVisible(true);
    screen->performLayout();
    tabWidget->setSize(screenSize);
    tabWidget->performLayout(screen->nvgContext());

    nanogui::mainloop();
    }
    nanogui::shutdown();
    return 0;
}
