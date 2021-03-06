//
//  TestViewController.cpp
//  TestUI
//
//  Created by ximiao on 16/6/24.
//  Copyright © 2016年 wudijimao. All rights reserved.
//


#include "TestViewController.hpp"
#include "LoginViewController.hpp"

#pragma execution_character_set("utf-8")

//class TestData : public XResponseData {
//public:
//    std::string name;
//    virtual void parse(const rapidjson::Document &json) override {
//        name = json["data"]["cityname"].GetStringSafe();
//    }
//};
//
//class TestRequest : public XHTTPRequestT<TestData> {
//public:
//    TestRequest(){
//        url = "http://movie.weibo.com/movieapp/rank/weibohot";
//        //url = "http://www.baidu.com/";
//        this->method = XHTTPRequestMethod::XHTTPRequestMethod_Post;
//        this->_params.addParam("uid", "5633119670");
//        this->_params.addParam("token", "2.00B5msBDcX6kGD82b79248caxjF5WD");
//        this->_params.addParam("你好", "测试中文");
//        //this->_params.setParams("uid=5633119670&lfid=&lon=&count=2147483647&os_v=4.3&wm=44994_0001&luicode=&from=8610705010&os_n=Android&cityid=&ip=10.0.3.15&d_id=D0BE2BB07273F93&v=1.0.7&num=1&page=1&token=2.00B5msBDcX6kGD82b79248caxjF5WD&a_n=MovieSDK&d_n=Google+Nexus+4+-+4.3+-+API+18+-+768x1280&lat=&");
//        std::string str = this->_params.getStr();
//
//        int a = 0;
//    }
//};


    using namespace XResource;
    ViewController::~ViewController() {
    }
    void ViewController::viewDidLoad() {
        XUI::UIViewController::viewDidLoad();

//        auto jpgImg = XResource::XImage::imageNamed("test.jpg");



        auto scrollView = std::make_shared<XUI::ScrollView>();
        scrollView->setBkgColor(XResource::XUIColor::pinkColor());
        scrollView->setRect(XResource::XRectPro(20, 100, 100, 200));
        this->view()->addSubView(scrollView);

        auto textView = std::make_shared<XUI::UITextView>();
        auto attrStr = XResource::XAttributedString::attrStr("红字蓝字大字小字大蓝字");
        auto redAttr = XResource::XStringAttrColor::colorWithColor(XUIColor::redColor());
        attrStr->addAttr(redAttr, XRange(0, 2));
        auto blueAttr = XResource::XStringAttrColor::colorWithColor(XUIColor::blueColor());
        attrStr->addAttr(blueAttr, XRange(2, 2));
        auto bigFont = XResource::XFont::systemFont(30);
        auto smallFont = XResource::XFont::systemFont(10);
        attrStr->addAttr(bigFont, XRange(4, 2));
        attrStr->addAttr(smallFont, XRange(6, 2));
        attrStr->addAttr(bigFont, XRange(8, 3));
        attrStr->addAttr(blueAttr, XRange(8, 3));
        textView->setText(attrStr);
        textView->setTextColor(XResource::XUIColor::blueColor());
        textView->setFont(XResource::XFont::systemFont(16));
        auto color = XResource::XUIColor::pinkColor()->copy();
        color->_color.a = 200;
        textView->setBkgColor(color);
        textView->setRect(XResource::XRectPro(0, 0, 550, 650));
        auto img = XResource::XImage::imageNamed("test.png");
        textView->setBkgImg(img);
        scrollView->setContentView(textView);

//        auto btn = std::make_shared<XUI::XButton>();
//        btn->setTitle("LoginPage");
//        btn->setBackgroundColor(XResource::XUIColor::blueColor(), XUI::ButtonStates::DOWN);
//        btn->setRect(XResource::XRectPro(100, 120, 180, 420));
//        btn->setTransformCenter(XResource::XDisplayPoint(90, 60));
//        this->view()->addSubView(btn);
//        
//        
//        auto imgView = std::make_shared<XUI::XUIImageView>();
//        imgView->setImage(XResource::XImage::imageNamed("test.png"));
//        imgView->setRect(XResource::XRect(10, 10, 140, 100));
//        imgView->setScaleType(XUI::XUIImageScaleType::AspectFill);
//        imgView->setBkgColor(XResource::XUIColor::blueColor());
//        btn->addSubView(imgView);
//        
//        
//        view()->setBkgColor(XResource::XUIColor::lightGrayColor());
//        
//        btn->onClick = [this, btn](XUI::XButton&){
////            _testSubView = std::make_shared<XUI::XView>();
////            _testSubView->setBkgColor(XResource::XUIColor::redColor());
////            _testSubView->setRect(XResource::XRectPro(20, 20, 320, 120));
////            _testSubView->setBkgImg(XResource::XImage::imageNamed("test.jpg"));
////            this->view()->addSubView(_testSubView);
//            //this->presentViewController(std::make_shared<LoginViewController>(), XUI::PresentAnimation::Present);
//            auto ani = XUI::ValueAnimation<float>::createAni(0, 360, [this, btn](float v){
//                GLTransform3D tr;
////                tr.setPosition(0, v*50 - 50);
////                tr.setScale(v, v);
//                tr.setRotationY(v);
//                btn->setTransform3D(tr);
//                //btn->subViews()[1]->setNeedLayout();
//                //btn->subViews()[1]->setNeedReDraw();
//            });
//            ani->setDurationMS(3000);
//            this->addAnimation(ani);
//            ani->play();
//        };


//        auto request = std::make_shared<TestRequest>();
//        request->onFinish = [&](TestRequest::ResponseTypePtr response) {
//            auto header = response->header();
//            std::string str = header->getStr();
//            auto image = XResource::XImage::imageFromData(response->contentData());
        //_testSubView->setBkgImg(image);
        //this->view()->addSubView(_testSubView);
//        };
//        IXHTTPClient::getSharedInstanc()->sendRequest(request);


//        rapidjson::Document doc;
//        std::string str = "aaa";
//        if(!doc.Parse("{\"a\":\"1\", \"b\":\"2\", \"c\":\"3\"}").HasParseError()) {
//            str = doc["a"].GetString();
//            textView->setText(str.c_str());
//            int a = 0;
//        }

//        auto imgView = std::make_shared<XUI::XUIImageView>();
//        imgView->setRect(XResource::XRectPro(100, 300, 200, 200));
//        imgView->setImage(jpgImg);
//        this->view()->addSubView(imgView);
//        imgView->setScaleType(XUI::XUIImageScaleType::AspectFill);
//        imgView->setBkgColor(XResource::XUIColor::grayColor());


        //auto vc = std::make_shared<LoginViewController>();
        //this->presentViewController(vc);
        //        clock_t t1 = clock();
        //        for (int i = 0; i < 4; ++i) {
        //            XDispatch::dispatchAsnyc(XDispatch::getGlobleQueue(XDispatch::XTaskPriority::XTaskPriority_Default), [this, i, t1](){
        //                for (int j = 0; j < 100000; ++j) {
        //                    XDispatch::dispatchAfter(XDispatch::getMainQueue(), [this, i, j, t1](){
        //                        ++mNum;
        //                        XLog::sharedInstance().log(XLogLevel::Debug, "%d:%d___%d\r\n", i, j, mNum);
        //                        if (mNum == 400000) {
        //                            clock_t t2 = clock();
        //                            std::cout << "count:" << mNum << "   time:" << (t2 - t1) / (CLOCKS_PER_SEC / 1000.0) << "ms" << std::endl;
        //                        }
        //                    }, 100);
        //                }
        //            });
        //        }

        //        for (int i = 0; i < 400000; ++i) {
        //            ++mNum;
        //            XLog::sharedInstance().log(XLogLevel::Debug, "%d:%d___%d\r\n", i, i, mNum);
        //            if (mNum == 400000) {
        //                clock_t t2 = clock();
        //                std::cout << "count:" << mNum << "   time:" << (t2 - t1) / (CLOCKS_PER_SEC / 1000.0) << "ms" << std::endl;
        //            }
        //        }

        //        __block ViewController *bThis = this;
        //        for (int i = 0; i < 4; ++i) {
        //            dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        //                for (int j = 0; j < 100000; ++j) {
        //                    //XLog::sharedInstance().log(XLogLevel::Debug, "%d:%d\r\n", i, j);
        //                    void(bl)(void) = ^{
        //                        ++bThis->mNum;
        //                        //XLog::sharedInstance().log(XLogLevel::Debug, "%d:%d___%d\r\n", i, j, bThis->mNum);
        //                        if (bThis->mNum == 400000) {
        //                            clock_t t2 = clock();
        //                            std::cout << "count:" << mNum << "   time:" << (t2 - t1) / (CLOCKS_PER_SEC / 1000.0) << "ms" << std::endl;
        //                        }
        //                    }
        //                    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, (int64_t)(100 * NSEC_PER_MSEC)), dispatch_get_main_queue(), );
        //                }
        //            });
        //        }


        auto editView = std::make_shared<XUI::UIEditView>();
        editView->setRect(XResource::XRectPro(150, 100, 200, 30));
        editView->setBkgColor(XResource::XUIColor::lightGrayColor());
        editView->setText("");
        view()->addSubView(editView);
    }
    void ViewController::onTouch(const std::vector<std::shared_ptr<XTouch>> &touch) {
        //(*touch.begin())->_belongView->setBkgColor(XResource::XUIColor::greenColor());
    }
    void ViewController::onMouseEvent(const std::vector<std::shared_ptr<XMouse>> &mouseEvents) {
        auto event = (*mouseEvents.begin());
        if (event->eventType == MouseEventType::Up)
        {
            if (event->eventButton == MouseEventButton::Left) {
                event->_belongView->setBkgColor(XResource::XUIColor::grayColor());
            } else {
                event->_belongView->setBkgColor(XResource::XUIColor::redColor());
            }
        }
    }
