#include <nanogui/nanogui.h>
#include <custom/tabwidget/tabwidget.h>
#include <string>

int main(){
    nanogui::Vector2i screenSize = nanogui::Vector2i(700, 500);
    nanogui::init();
    {
    nanogui::Screen *screen = new nanogui::Screen(screenSize, "Self-Manager");
    custom::TabWidget* tabWidget = screen->add<custom::TabWidget>();

    nanogui::Widget* layer = tabWidget->createTab("Main");
    layer->setLayout(new nanogui::GroupLayout());
    layer->add<nanogui::Label>("Main Tab", "sans-bold");

    layer = tabWidget->createTab("Routine");
    layer->setLayout(new nanogui::GroupLayout());
    layer->add<nanogui::Label>("Routine Tab", "sans-bold");

    layer = tabWidget->createTab("About");
    layer->setLayout(new nanogui::GroupLayout());
    layer->add<nanogui::Label>("About Tab", "sans-bold");

    layer = tabWidget->createTab("Placeholder1");
    layer->setLayout(new nanogui::GroupLayout());
    layer->add<nanogui::Label>("Placeholder1 Tab", "sans-bold");

    tabWidget->createTab("Placeholder2");
    tabWidget->createTab("Placeholder3");
    tabWidget->createTab("Placeholder4");
    tabWidget->createTab("Placeholder5");
    tabWidget->createTab("Placeholder6");
    tabWidget->createTab("Placeholder7");
    tabWidget->createTab("Placeholder8");
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
