#pragma once
#include "ofMain.h"
#include <string>
#include <vector>

class pmFlare {
    public:

        void setup();
        void update();
        void draw();

        pmFlare();

    private:

        vector<float> r;
        vector<float> rSpeed;
        vector<float> theta;
        vector<float> thetaSpeed;
        float maxR, minR, maxRSpeed, minRSpeed, maxT, minT, maxTSpeed, minTSpeed;
        float x;
        float y;
        int nPoints;
        vector<ofPoint> verts;
        int height;
        int width;
        ofTrueTypeFont font;
        ofFloatColor red = ofColor::red;
        ofFloatColor yellow = ofColor::yellow;
        ofFloatColor black = ofColor::black;
        ofFloatColor flareColor;
        float colorInterp = 0.0;
        float colorSpeed = 0.1;
        float minCSpeed, maxCSpeed;
        float t0, t1;
        float fadeTime = 10.0;
        ofFbo fbo;
        float history;
        float elapsedTime;

};
