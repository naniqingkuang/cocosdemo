//
//  zhuzhuLayer.cpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#include "zhuzhuLayer.hpp"




bool zhuzhuLayer::init() {

    TableView *table = TableView::create(this, Size(480, 320));
    this->addChild(table);
    
    // 属性设置
    table->setBounceable(false);
    table->setDirection(ScrollView::Direction::VERTICAL);
    table->setDelegate(this);
    table->reloadData();
    
    
    
    return true;
}



Size zhuzhuLayer::cellSizeForTable(TableView* table) {
    return Size(100, 150);
}
TableViewCell* zhuzhuLayer::tableCellAtIndex(TableView *table, ssize_t idx) {
    TableViewCell *cell = table->dequeueCell();
    if (!cell) {
        cell = TableViewCell::create();
        
        Sprite *sprite = Sprite::create();
        sprite->setPosition(0, 0);
        sprite->setAnchorPoint(Vec2(0, 0.5));
        sprite->setContentSize(Size(100,100));
        cell->addChild(sprite);
        sprite->setTag(10);
        
        Label *label = Label::createWithTTF("", "./fonts/arial.ttf", 32);
        label->setPosition(100, 0);
        label->setContentSize(Size(50, 100));
        cell->addChild(label);
        label->setTag(11);
    }
    Sprite *sprite = (Sprite*)cell->getChildByTag(10);
    sprite->setTexture("Icon_gray.png");
    
    
    Label *label = (Label *) cell->getChildByTag(11);
    char buf[20];
    sprintf(buf, "%ld", idx);
    label->setString(buf);
    return cell;
    
}


ssize_t zhuzhuLayer::numberOfCellsInTableView(TableView *table){
    return 20;
}

 void zhuzhuLayer:: tableCellTouched(TableView* table, TableViewCell* cell)  {
     CCLOG("%ld",cell->getIdx());
}



