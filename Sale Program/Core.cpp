#include "Core.h"

bool IdValidation(Menu menu, string id)
{
    if (menu.item == nullptr) {
        return true;
    }
    Item* ptr = menu.SearchItem(id);
    if (ptr == nullptr) {
        return true;
    }
    else {
        return false;
    }
}
