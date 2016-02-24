//
//  XJPGDecoder.hpp
//  XImage
//
//  Created by ximiao on 16/2/24.
//  Copyright © 2016年 ximiao. All rights reserved.
//
#pragma once

#include <stdio.h>
#include "XImageDecoder.hpp"
#include "../jpg/jpeglib.h"


class XJPGDecoder : public XImageDecoder {
    friend XImageDecoder;
private:
    jpeg_decompress_struct _cinfo;
protected:
    virtual ~XJPGDecoder();
    static NULL_ABLE XImageDecoder *getInstance();
    //inherit from XImageDecoder
    virtual NULL_ABLE XImageDecoder *fork();
    virtual bool isThisFormart(XData *data);
    virtual bool initWithData(XData *data);
    virtual int width();
    virtual int height();
    virtual int count();
    virtual bool getImage(void *outBuf, int index);
};