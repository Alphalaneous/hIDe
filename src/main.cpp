#include <Geode/Geode.hpp>
#include <Geode/modify/CCKeyboardDispatcher.hpp>
#include "EditLevelLayer.h"

using namespace geode::prelude;

class $modify(CCKeyboardDispatcher) {

	bool isShiftHeld = false;

    bool dispatchKeyboardMSG(enumKeyCodes key, bool down, bool arr) {
        if (down && (key == KEY_Shift)) {
            
			if(!isShiftHeld){
				isShiftHeld = true;

				CCScene* currentScene = CCDirector::sharedDirector()->getRunningScene();

				EditLevelLayer* layer = dynamic_cast<EditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0));

				if(layer){
					((AlphaEditLevelLayer*)layer)->setIDVisible(true);
				}
			}
            return true;
        }
		if (!down && (key == KEY_Shift)) {
            
			if(isShiftHeld){
				isShiftHeld = false;

				CCScene* currentScene = CCDirector::sharedDirector()->getRunningScene();

				EditLevelLayer* layer = dynamic_cast<EditLevelLayer*>(currentScene->getChildren()->objectAtIndex(0));

				if(layer){
					((AlphaEditLevelLayer*)layer)->setIDVisible(false);
				}
			}
            return true;
        }
        return CCKeyboardDispatcher::dispatchKeyboardMSG(key, down, arr);
    }
};

