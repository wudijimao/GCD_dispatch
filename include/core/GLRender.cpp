#include "GLRender.hpp"
//#include "GLHelper.hpp"
#include <vector>
#include <time.h>
#include <iterator>
#include "GL/GLRenderData.hpp"
#include "GL/GLRenderNineGridData.hpp"
#include "../res/XResource.hpp"

GLRender::GLRender(const IXRenderDataPovider *renderDataPovider) {
    mRenderDataPovider = renderDataPovider;
}

void GLRender::Submit() {
    IXCanvas::gCurrentCanvas->pushRenderData(&mCachedRenderData[0], mCachedRenderData.size());
}

void GLRender::clear() {
    for (auto data : mCachedRenderData)
    {
        delete data;
    }
    mCachedRenderData.clear();
}

const IXRenderDataPovider& GLRender::getRenderDataPovider() const {
    return *mRenderDataPovider;
}

void GLRender::DrawBackGround(const XResource::XColor &color, const XResource::XRect &xRect, bool isClipsChildren) {
    static std::shared_ptr<XResource::XImage> emptyImg;
    DrawBackGround(color, emptyImg, xRect, isClipsChildren);
}

void GLRender::DrawImage(const std::shared_ptr<XResource::IXImage> &image, const XResource::XRect &rect) {
    DrawBackGround(XResource::XUIColor::clearColor()->_color, image, rect, false);
}

void GLRender::DrawImage(const std::shared_ptr<XResource::XStretchableImage> &image, const XResource::XRect &rect) {
    XDUILib::GLRenderNineGridData *data = new XDUILib::GLRenderNineGridData(this);
    data->initWithRect(rect, image);
    mCachedRenderData.push_back(data);
}

void GLRender::DrawBackGround(const XResource::XColor &color, const std::shared_ptr<XResource::IXImage> &image, const XResource::XRect &xRect, bool isClipsChildren) {
    XDUILib::GLRenderSquareData *data = new XDUILib::GLRenderSquareData(this);
    data->initWithRect(xRect, color, image);
    data->setMaskImage(mClipsImage);
    if (isClipsChildren) {
        data->setClips(true);
    }
    mCachedRenderData.push_back(data);
}
void GLRender::DrawString(const XResource::XAttributedString &attrStr, const XResource::XRect &xRect) {
    auto frame = attrStr.createFrame(xRect.size());
    //this->DrawBackGround(XResource::XUIColor::redColor()->_color, xRect);
    for (auto l : frame->mLines) {
        for (auto g : l->mGroups) {
            for (auto c : g->mChars) {
                this->DrawBackGround(c->mFrontColor->_color, c->mGlyph->mImage, XResource::XRect(c->mRect).moveX(xRect.X()).moveY(xRect.Y()));
            }
        }
    }
}

void GLRender::setMask(const std::shared_ptr<XResource::IXImage> &image) {
    mClipsImage = image;
}

//void GLRender::DrawLine(int x1, int y1, int x2, int y2) {
//
//}
////需要绘制的矩形区域
//void GLRender::DrawImage(XResource::XImage &img, const XResource::XRect &rect) {
//
//}
////文本相关要单独处理？？ 如何与普通图形分开 又不过多多谢代码（分开的理由是OpenGl应该也会使用其渲染文本， 或者使用其他文字渲染引擎，比如FreeType/DirectWrite）
//void GLRender::DrawString(const std::wstring &text, const XResource::XRect &xRect) {
//
//}
//void GLRender::DrawString(const std::wstring &text, const XResource::XRect &xRect, Gdiplus::StringAlignment align) {
//
//}
//void GLRender::DrawString(const XResource::XText &text, const XResource::XRect &xRect) {
//
//}
//XResource::XRect GLRender::MeasureString(const XResource::XText &text, const XResource::XRect &xRect) {
//	return xRect;
//}
//XResource::XRect GLRender::MeasureString(const std::wstring &text) {
//	return XResource::XRect(0, 0, 0, 0);
//}