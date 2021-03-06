#pragma once
#include "stdafx.hpp"
#include "../res/XRect.hpp"
#include "IXCanvas.hpp"
#include "IXRender.hpp"
#include "input/XInputs.hpp"

namespace XUI {
    class UIViewController;
    class XNavigationManager;
}
 

class SIMPLEDIRECTUI_API IXWindow
{
public:
    //fullScreen
    static std::shared_ptr<IXWindow> createWindow();
    
	virtual ~IXWindow(){};
    virtual void showInFront() = 0;
    virtual void setRootViewController(std::shared_ptr<XUI::UIViewController> rootViewController) = 0;
    virtual void setPresentingViewController(std::shared_ptr<XUI::UIViewController> presentingVC) = 0;
    virtual const XResource::XDisplaySize &size() = 0;
    virtual const XResource::XDisplayPoint &position() = 0;
	virtual void setSize(const XResource::XDisplaySize &size) = 0;
	virtual void setPositon(const XResource::XDisplayPoint &pos) = 0;
    void setNeedReDraw() {
        mNeedReDraw = true;
    }
    virtual const std::shared_ptr<XUI::XNavigationManager>& getNavigationManager() = 0;
    virtual void perparToShow(XUI::UIViewController *vc) = 0;
#ifdef _WINDOWS
	virtual HWND getHandler() = 0;
#endif // _WINDOWS


    //virtual std::shared_ptr<IXRender> render() = 0;
	//TODO::不应该有基于具体平台的
	//virtual HWND Hwnd() = 0;
	//virtual void NeedReDraw() = 0;
	//virtual HWND Create(HINSTANCE hInstance, int iCmdShow) = 0;
	//virtual void Drag(LPARAM lParam) = 0;
	//virtual const std::wstring& ID() = 0;
	//virtual void ID(const std::wstring& id) = 0;
    
    
	//virtual const XResource::XRect& Rect() const = 0;
	//virtual void Rect(const XResource::XRect& rect) = 0;
protected:
    std::shared_ptr<IXCanvas> _canvas;
    bool mNeedReDraw = true;
};

