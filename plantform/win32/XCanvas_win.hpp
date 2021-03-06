#include "core\stdafx.hpp"
#include <gdiplus.h>
#include "core\GLCanvas.hpp"
#include "GDIRender.hpp"

class SIMPLEDIRECTUI_API_DEBUG GLCanvas_ios : public GLCanvas
{
public:
	~GLCanvas_ios() {
		if (mBkgGraphics != nullptr)
		{
			delete mBkgGraphics;
		}
		::ReleaseDC(mHWND, mHDC);
	}
	HWND mHWND = nullptr;
	HDC mHDC = nullptr;
	bool init(HWND hWnd, const XResource::XSize &size) {
		RECT rct;
		GetWindowRect(mHWND, &rct);
		//setSize(XResource::XSize(rct.right - rct.left, rct.bottom - rct.top), 1.0);
		setSize(size, 1.0);
		mHWND = hWnd;
		mHDC = ::GetDC(hWnd);
		initMemDC();
		CreateDIB();
		initOpengl(mHDC);
		return true;
	}
	virtual bool Present() {
		this->GLCanvas::Present();
		//test Opengl
		//glClearColor(1, 1, 1, 1);
		//glClear(GL_COLOR_BUFFER_BIT);

		//glBegin(GL_TRIANGLES);                              // Drawing Using Triangles
		//glColor3f(0, 1, 1);
		//glVertex3f(0.0f, 1.0f, 0.1f);                  // Top
		//glColor3f(0.0f, 1.0f, 0.0f);                      // Set The Color To Green
		//glVertex3f(-1.0f, -1.0f, 0.1f);                  // Bottom Left
		//glColor3f(0.0f, 0.0f, 1.0f);                      // Set The Color To Blue
		//glVertex3f(1.0f, -1.0f, 0.1f);                  // Bottom Right
		//glEnd();
		//glFlush();
		//TODO::drawtowin by gdi+
		//XResource::XColor *piexls = new XResource::XColor[_size.Width() * _size.Height()];
		//SwapBuffers(mHDC);
		
		//glReadBuffer(GL_BACK);
		//glPixelStorei(GL_PACK_ALIGNMENT, 1);
		glReadPixels(0, 0, _size.Width(), _size.Height(), GL_BGRA, GL_UNSIGNED_BYTE, bmp_cnt);

		/*unsigned char *c = bmp_cnt;
		for (int i = 0; i < 50000; ++i, c += 4)
		{
			c[0] = 9;
			c[1] = 0;
			c[2] = 255;
			c[3] = 254;
		}*/

		RECT rct;
		GetWindowRect(mHWND, &rct);
		POINT ptWinPos = { rct.left, rct.top };
		POINT    ptSrc = { 0, 0 };
		SIZE    sizeWindow = { _size.Width(), _size.Height() };

		BLENDFUNCTION    m_Blend;
		m_Blend.BlendOp = AC_SRC_OVER; //theonlyBlendOpdefinedinWindows2000
		m_Blend.BlendFlags = 0; //nothingelseisspecial...
		m_Blend.AlphaFormat = AC_SRC_ALPHA; //...
		m_Blend.SourceConstantAlpha = 255;//AC_SRC_ALPHA 
		UpdateLayeredWindow(mHWND, mHDC, &ptWinPos, &sizeWindow, mDIB_DC, &ptSrc, 0, &m_Blend, ULW_ALPHA);
		return true;
	}
private:
	HBITMAP mBitMap = nullptr;
	HDC mMemDC = nullptr;
	HDC mDIB_DC = nullptr;
	HBITMAP mDIBBitMap;
	unsigned char *bmp_cnt = nullptr;
	Gdiplus::Graphics *mBkgGraphics;

	bool initOpengl(HDC hdc) {
		int bits = 32;
		static	PIXELFORMATDESCRIPTOR pfd =				// pfd Tells Windows How We Want Things To Be
		{
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW |						// Format Must Support Window
			//PFD_DRAW_TO_BITMAP |
			PFD_SUPPORT_OPENGL,				// Format Must Support OpenGL
			//PFD_DOUBLEBUFFER,							// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			bits,										// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			0,											// No Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			24,											// 16Bit Z-Buffer (Depth Buffer)  
			8,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
		};
		int piexelFormat = ChoosePixelFormat(mHDC, &pfd);
		if (!SetPixelFormat(mHDC, piexelFormat, &pfd)) {
			return false;
		}

		_context = wglCreateContext(mHDC);

		if (!wglMakeCurrent(mHDC, _context)) {
			return false;
		}

		GLenum err = glewInit();
		if (GLEW_OK != err)
		{
			return false;
		}

		//::ReleaseDC(hWnd, mHDC);//һ��Ҫ�ͷž��
		if (!this->InitGLProgram()) {
			return false;
		}
		if (!this->InitFrameBuffer()) {
			return false;
		}
        this->enableGLSettings();
		return true;
	}
	void CreateDIB()
	{
		BITMAPINFOHEADER BIH;
		int iSize = sizeof(BITMAPINFOHEADER);
		memset(&BIH, 0, iSize);
		BIH.biSize = iSize;
		BIH.biWidth = _size.Width();
		BIH.biHeight = _size.Height();
		BIH.biPlanes = 1;
		BIH.biBitCount = 32;
		BIH.biCompression = BI_RGB;

		if (mDIB_DC)
			DeleteDC(mDIB_DC);
		if (mDIBBitMap)
			DeleteObject(mDIBBitMap);
		mDIB_DC = CreateCompatibleDC(NULL);
		
		
		mDIBBitMap = CreateDIBSection(
			mDIB_DC,
			(BITMAPINFO*)&BIH,
			DIB_RGB_COLORS,
			(void**)&bmp_cnt,
			NULL,
			0);
		if (mDIBBitMap) {
			SelectObject(mDIB_DC, mDIBBitMap);
		}
	}
	bool initMemDC();
public:
	HGLRC _context;
};