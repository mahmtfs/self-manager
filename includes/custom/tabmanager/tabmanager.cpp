#include <custom/tabmanager/tabmanager.h>

namespace custom {

TabWidget* TabManager::receiver = nullptr;
TabHeader* TabManager::sender = nullptr;

void TabManager::sendRemoveRequest(int tabid){
    receiver->removeTab(tabid);
}

int TabManager::getActiveTab(){
    return receiver->activeTab();
}

}