#pragma once

#include <custom/tabwidget/tabwidget.h>
#include <custom/tabheader/tabheader.h>

namespace custom {

class TabManager {
public:
    TabManager() = delete;
    static void sendRemoveRequest(int tabid);
    static int getActiveTab();
    static TabWidget* receiver;
    static TabHeader* sender;
};

}