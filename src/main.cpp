#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include "EditLevelLayer.h"

using namespace geode::prelude;

bool isShiftHeld = false;

class $modify(MyCCKeyboardDispatcher, CCKeyboardDispatcher) {

    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool arr) {
		CCScene* currentScene = CCDirector::sharedDirector()->getRunningScene();
		EditLevelLayer* layer = typeinfo_cast<EditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0));
		if(layer){
			MyEditLevelLayer* myLayer = static_cast<MyEditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0));
			if (down && (key == KEY_Shift)) {
				if(!isShiftHeld) {
					isShiftHeld = true;
					myLayer->setIDVisible(true);
				}
				return true;
			}
			if (!down && (key == KEY_Shift)) {
				if(isShiftHeld){
					isShiftHeld = false;
					myLayer->setIDVisible(false);
				}
				return true;
			}
		}
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, arr);
    }
};

