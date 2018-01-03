//
//  zhuzhuLayer.hpp
//  MyCppGame-mobile
//
//  Created by 猪猪 on 2017/12/21.
//

#ifndef zhuzhuLayer_hpp
#define zhuzhuLayer_hpp
#include "cocos-ext.h"
#include "cocos2d.h"
using namespace cocos2d;

using namespace cocos2d::extension;
#include <stdio.h>

class zhuzhuLayer : public cocos2d::Layer, EditBoxDelegate  {
public:
    virtual bool init();
    /**
     * This method is called when an edit box gains focus after keyboard is shown.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxEditingDidBegin(EditBox* editBox);
    
    
    /**
     * This method is called when an edit box loses focus after keyboard is hidden.
     * @param editBox The edit box object that generated the event.
     * @deprecated Use editBoxEditingDidEndWithAction() instead to receive reason for end
     */
    CC_DEPRECATED_ATTRIBUTE virtual void editBoxEditingDidEnd(EditBox* editBox);
    
    /**
     * This method is called when the edit box text was changed.
     * @param editBox The edit box object that generated the event.
     * @param text The new text.
     */
    virtual void editBoxTextChanged(EditBox* editBox, const std::string& text);
    
    /**
     * This method is called when the return button was pressed or the outside area of keyboard was touched.
     * @param editBox The edit box object that generated the event.
     */
    virtual void editBoxReturn(EditBox* editBox);
    

    CREATE_FUNC(zhuzhuLayer);

};

#endif /* zhuzhuLayer_hpp */
