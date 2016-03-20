#pragma once
#include "stdafx.hpp"
#include "../res/XRect.hpp"

#ifdef TARGET_OS_MSWINDOWS
struct MouseStatusStruct
{
	int X, Y;
	int LastX, LastY;
	void inline SetMouseStatus(WPARAM wParam, LPARAM lParam)
	{
		LastX = X;
		LastY = Y;
		X = (int)(short)LOWORD(lParam);
		Y = (int)(short)HIWORD(lParam);
		mWParam = wParam;
	}
	bool IsLButtonDown() const
	{
		return (mWParam & WM_LBUTTONDOWN) != 0;
	}
	bool IsRButtonDown() const
	{
		return (mWParam & WM_RBUTTONDOWN) != 0;
	}
	bool IsXButton1Down() const
	{
		return (mWParam & WM_XBUTTONDOWN) != 0;
	}
	bool IsXButton2Down() const
	{
		return (mWParam & WM_XBUTTONDOWN) != 0;
	}
	bool IsShiftDown() const
	{
		return (mWParam & MK_SHIFT) != 0;
	}
	bool IsContrlDown() const
	{
		return (mWParam & MK_CONTROL) != 0;
	}
	WPARAM mWParam;
};
#endif // TARGET_OS_MSWINDOWS

class SIMPLEDIRECTUI_API IXWindow
{
public:
	virtual ~IXWindow(){};
    virtual void showInFront() = 0;
	//TODO::不应该有基于具体平台的
	//virtual HWND Hwnd() = 0;
	//virtual void NeedReDraw() = 0;
	//virtual HWND Create(HINSTANCE hInstance, int iCmdShow) = 0;
	//virtual void Drag(LPARAM lParam) = 0;
	virtual const MouseStatusStruct& MouseStauts() = 0;
	//virtual const std::wstring& ID() = 0;
	//virtual void ID(const std::wstring& id) = 0;
    
    
	//virtual const XResource::XRect& Rect() const = 0;
	//virtual void Rect(const XResource::XRect& rect) = 0;
};

