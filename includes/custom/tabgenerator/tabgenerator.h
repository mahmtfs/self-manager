#pragma once

#include <nanogui/tabwidget.h>
#include <nanogui/tabheader.h>

namespace custom {

class TabGenerator{
public:
    enum Tabs {
        Main    = 0,
        About   = 1,
        Routine = 2
    };
    TabGenerator() = delete;
    static void createTab(nanogui::TabWidget *tabWidget, Tabs tabType);
private:
    static const char* tabNames[3];
    static void fillTabContent(nanogui::Widget *tabLayer, Tabs tabType);
};

}