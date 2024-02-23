#pragma once

#ifndef ALPHA_EDITLEVELLAYER_H
#define ALPHA_EDITLEVELLAYER_H

#include <Geode/Geode.hpp>
#include <Geode/modify/EditLevelLayer.hpp>

using namespace geode::prelude;

class $modify(AlphaEditLevelLayer, EditLevelLayer){

    CCLabelBMFont* label;
    CCLabelBMFont* replacementLabel;
    bool shouldSetVisibility = true;

    bool init(GJGameLevel* p0){

        if(!EditLevelLayer::init(p0)){
            return false;
        }

        this->m_fields->label = dynamic_cast<CCLabelBMFont*>(this->getChildByID("level-id-label"));
        this->m_fields->replacementLabel = CCLabelBMFont::create("ID: Hidden (shift)", "goldFont.fnt");

        if(strcmp(this->m_fields->label->getString(), "ID: na") == 0){
            this->m_fields->shouldSetVisibility = false;
            return true;
        }
        else {

            if(Loader::get()->isModLoaded("cvolton.betterinfo") && this->getChildByID("cvolton.betterinfo/level-id-menu")){
                
                CCMenu* menu = dynamic_cast<CCMenu*>(this->getChildByID("cvolton.betterinfo/level-id-menu"));

                CCMenuItemSpriteExtra* sprite = dynamic_cast<CCMenuItemSpriteExtra*>(menu->getChildren()->objectAtIndex(0));

                this->m_fields->label = dynamic_cast<CCLabelBMFont*>(sprite->getChildren()->objectAtIndex(0));

                this->m_fields->replacementLabel->setPosition(this->m_fields->label->getPosition());
                this->m_fields->replacementLabel->setScale(this->m_fields->label->getScale());
                this->m_fields->replacementLabel->setAnchorPoint(this->m_fields->label->getAnchorPoint());

                sprite->addChild(this->m_fields->replacementLabel);

            }
            else{

                this->m_fields->replacementLabel->setPosition(this->m_fields->label->getPosition());
                this->m_fields->replacementLabel->setScale(this->m_fields->label->getScale());
                this->m_fields->replacementLabel->setAnchorPoint(this->m_fields->label->getAnchorPoint());

                this->addChild(this->m_fields->replacementLabel);
            }

            this->m_fields->label->setVisible(false);
        }
        return true;
    }
    void setIDVisible(bool visible){
        if(this->m_fields->shouldSetVisibility){
            this->m_fields->label->setVisible(visible);
            this->m_fields->replacementLabel->setVisible(!visible);
        }

    }
    static void onModify(auto& self) {
        self.setHookPriority("EditLevelLayer::init", -10000);
    }
};

#endif