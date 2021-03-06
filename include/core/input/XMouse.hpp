//
//  XTouch.hpp
//  XDUILib
//
//  Created by ximiao on 16/3/30.
//  Copyright © 2016年 wudijimao. All rights reserved.
//
#pragma once

#include "XInput.hpp"
#include "../../res/XResource.hpp"


enum class MouseEventType {
	UnSet,
	Down,
	Up,
	Move,
	Wheel
};

enum class MouseEventButton {
	None,
	Left,
	Right,
	Wheel,
	X1,
	X2,
};

class MourceStatus {

};

class SIMPLEDIRECTUI_API XMouse : public XInputWithPostion {
public:
	static MourceStatus sMouseStatus;
	MouseEventType eventType;
	MouseEventButton eventButton = MouseEventButton::None;
    unsigned int clickCount;
    virtual XInputType type() {
        return XInputType::Mouse;
    }
};
enum class KeyEventType {
	UnSet,
	Down,
	Up
};
enum class KeyEventButton {
	None,
	BackForward,
};
class SIMPLEDIRECTUI_API XKeyInput : public XInput {
public:
	KeyEventType eventType;
	KeyEventButton eventButton = KeyEventButton::None;
	virtual XInputType type() {
		return XInputType::Key;
	}
};

