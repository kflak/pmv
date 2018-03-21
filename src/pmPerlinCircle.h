#pragma once
#include "ofMain.h"
#include <vector>

class pmPerlinCircle {
    public:

        void setup();
        void update();
        void draw();

        pmPerlinCircle();

    private:

        int N;
        int maxN;
        vector<float> r;
        float minR, maxR;
        vector<float> radius;
        vector<float> theta;
        vector<float> thetaSpeed;
        float minThetaSpeed, maxThetaSpeed;
        // vector<float> timeOffset;
        float noise;
        float noiseMul;
        vector<ofPoint> points;
        ofPoint center = ofPoint(0.0, 0.0);
        float x;
        float y;
        int height;
        int width;
        ofColor green = ofColor(198, 253, 242, 100);
        // ofColor yellow = ofColor(255, 255, 153, 255);
        ofColor blue = ofColor(129, 191, 245, 140);
        ofColor color;
        // ofFloatColor black = ofColor::black;
        // vector<ofFloatColor> circleColor;
        // vector<float> colorOffset;
        // vector<float> colorInc;
        float t0, t1;
        // float fadeTime = 10.0;
        ofFbo fbo;
        float history;
        float elapsedTime;
        float spawnRate;
        // float rotation;
        // float rotationRate;

};
