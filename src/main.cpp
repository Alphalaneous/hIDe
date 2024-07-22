#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include "EditLevelLayer.h"

using namespace geode::prelude;

bool isShiftHeld = false;

class $modify(MyCCKeyboardDispatcher, CCKeyboardDispatcher) {

    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool arr) {

		Loader::get()->queueInMainThread([key, down, arr]() {
			if(CCScene* currentScene = CCDirector::sharedDirector()->getRunningScene()) {
				if(currentScene->getChildrenCount() == 0) return;
				if(EditLevelLayer* layer = typeinfo_cast<EditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0))){
					MyEditLevelLayer* myLayer = static_cast<MyEditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0));
					if (down && (key == KEY_Shift)) {
						if(!isShiftHeld) {
							isShiftHeld = true;
							myLayer->setIDVisible(true);
						}
					}
					if (!down && (key == KEY_Shift)) {
						if(isShiftHeld){
							isShiftHeld = false;
							myLayer->setIDVisible(false);
						}
					}
				}
			}
		});
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, arr);
    }
};

