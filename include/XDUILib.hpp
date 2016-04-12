//
//  XDUILib.h
//  XDUILib
//
//  Created by ximiao on 16/3/17.
//  Copyright © 2016年 wudijimao. All rights reserved.
//
#pragma once
#include "core/stdafx.hpp"
#include "core/UIView.hpp"
#include "core/XApp.hpp"
#include "core/IXWindow.hpp"
#include "res/XImage/XImage.hpp"
#include "core/XResManager.hpp"


#ifdef TARGET_OS_IPHONE
    #include "ios/XDUILib_ios.hpp"
    #define XDUIMain int main(int argc, char * argv[])
    #define XDUIRUN int run(argc, argv)
#endif

#ifdef TARGET_OS_MAC
#endif


#ifdef TARGET_OS_MSWINDOWS
    #define XDUIMain int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow)
    #define XDUI_RUN_PARAMS hInstance, hPrevInstance, szCmdLine, iCmdShow
#endif

