//
//  GameObjStar.cpp
//  LuoLiRun
//
//  Created by iMac on 2014-05-13.
//
//

#include "GameObjStar.h"

void GameObjStar::set_visable(bool var){
    _visable = var;
    this->setVisible(var);
}

bool GameObjStar::get_visable(){
    return _visable;
}

GameObjStar::GameObjStar(){
    
}

GameObjStar::~GameObjStar(){
    
    
}
void GameObjStar::onEnter(){
    CCNode::onEnter();
    //星星初始化
    //this->setContentSize(Size(36.5,35.5));
    this->setContentSize(Size(73,71));
    Sprite* star = Sprite::create("star.png");
    //star->setScale(0.5);
    _visable = true;
    addChild(star,1);
}

void GameObjStar::onExit(){
    Node::onExit();
}