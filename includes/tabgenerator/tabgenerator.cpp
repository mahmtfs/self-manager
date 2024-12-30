#include <tabgenerator/tabgenerator.h>
#include <nanogui/widget.h>
#include <nanogui/layout.h>
#include <nanogui/label.h>

namespace custom {

const char* TabGenerator::tabNames[3] = {"Main", "About", "Routine"};

void TabGenerator::createTab(nanogui::TabWidget *tabWidget, Tabs tabType){
    nanogui::Widget* layer = tabWidget->createTab(tabNames[tabType]);
    layer->setLayout(new nanogui::GroupLayout());
    fillTabContent(layer, tabType);
}

void TabGenerator::fillTabContent(nanogui::Widget *tabLayer, Tabs tabType){
    switch (tabType){
        case Tabs::Main:
            tabLayer->add<nanogui::Label>("Main Tab", "sans-bold");
            break;
        case Tabs::About:
            tabLayer->add<nanogui::Label>("About Tab", "sans-bold");
            break;
        case Tabs::Routine:
            tabLayer->add<nanogui::Label>("Routine Tab", "sans-bold");
            break;
    };
}

}