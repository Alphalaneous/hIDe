#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include "EditLevelLayer.h"

using namespace geode::prelude;

bool isShiftHeld = false;

class $modify(MyCCKeyboardDispatcher, CCKeyboardDispatcher) {

    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool arr) {
		CCScene* currentScene = CCDirector::sharedDirector()->getRunningScene();
		MyEditLevelLayer* layer = static_cast<MyEditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0));
		if(layer){
			if (down && (key == KEY_Shift)) {
				if(!isShiftHeld) {
					isShiftHeld = true;
					layer->setIDVisible(true);
				}
				return true;
			}
			if (!down && (key == KEY_Shift)) {
				if(isShiftHeld){
					isShiftHeld = false;
					layer->setIDVisible(false);
				}
				return true;
			}
		}
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, arr);
    }
};

