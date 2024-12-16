#include <nanogui/nanogui.h>
#include <nanogui/tabwidget.h>
#include <custom/tabgenerator/tabgenerator.h>


int main(){
    nanogui::Vector2i screenSize = nanogui::Vector2i(700, 500);
    nanogui::init();
    {
    //glfwGetCurrentContext()
    nanogui::Screen *screen = new nanogui::Screen(screenSize, "Self-Manager");
    nanogui::TabWidget* tabWidget = screen->add<nanogui::TabWidget>();
    
    custom::TabGenerator::createTab(tabWidget, custom::TabGenerator::Tabs::Main);
    custom::TabGenerator::createTab(tabWidget, custom::TabGenerator::Tabs::About);
    custom::TabGenerator::createTab(tabWidget, custom::TabGenerator::Tabs::Routine);
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
