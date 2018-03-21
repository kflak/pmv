#include "pmFlare.h"


pmFlare::pmFlare(){
}

void pmFlare::setup(){
    nPoints = 100;
    height = ofGetHeight();
    width = ofGetWidth();
    fbo.allocate(width, height, GL_RGB32F_ARB);
    fbo.begin();
    ofBackground(0);
    fbo.end();
    history = 0.95;
    maxR = height * 0.4;
    minR = height * 0.01;
    maxT = 0.9;
    minT = 0.01;
    maxRSpeed = 0.2;
    minRSpeed = 0.05;
    maxTSpeed = 0.01;
    minTSpeed = -0.01;
    maxCSpeed = 0.001;
    minCSpeed = 0.0001;
    font.load("Inconsolata-Regular.tff", 20);
    theta.push_back(0.0);
    for(int i=0; i<nPoints; i++) {
        r.push_back(minR);
        rSpeed.push_back(ofRandom(minRSpeed, maxRSpeed));
        if(i != 0) theta.push_back(theta[i-1] + ofRandom(2.0, PI));
        thetaSpeed.push_back(ofRandom(minTSpeed, maxTSpeed));
        x = r[i] * cos(theta[i]);
        y = r[i] * sin(theta[i]);
        verts.push_back(ofPoint(x, y));
    }
    elapsedTime = ofGetElapsedTimef();
    t0 = elapsedTime;
    t1 = t0 + fadeTime;
}

void pmFlare::update(){
    elapsedTime = ofGetElapsedTimef();
    float fade1 = ofMap(elapsedTime, t0, t1, 0.0, 1.0);

    for(int i=0; i<nPoints; i++) {
        x = r[i] * cos(theta[i]);
        y = r[i] * sin(theta[i]);
        verts[i] = ofPoint(x, y);
        if (r[i] > maxR || r[i] < minR) rSpeed[i] *= -1;
        r[i] += rSpeed[i];
        theta[i] += thetaSpeed[i];
    }

    if (colorInterp > 0.5) colorInterp = ofRandom(-maxCSpeed, -minCSpeed);
    if (colorInterp < 0.2) colorInterp = ofRandom(maxCSpeed, minCSpeed);
    if (elapsedTime >= t0 && elapsedTime < t1){
        flareColor = black.getLerped(red, fade1);
    } else {
        flareColor = red.getLerped(yellow, colorInterp);
    }
    colorInterp += colorSpeed;
}

void pmFlare::draw(){
    // std::string frameRateString;
    ofBackground(0);
    fbo.begin();
    ofEnableAlphaBlending();
    float alpha = (1-history) * 255;
    ofSetColor(0, 0, 0, alpha);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(flareColor);
    ofSetLineWidth(1);
    ofNoFill();
    ofPushMatrix();
    ofTranslate(width/2, height/2);
    ofBeginShape();
    ofCurveVertices(verts);
    ofEndShape();
    ofPopMatrix();
    ofDisableAlphaBlending();
    fbo.end();
    ofSetColor(255);
    fbo.draw(0, 0);
    // frameRateString = ofToString(ofGetFrameRate());
    // font.drawString(frameRateString, 100, 100);
}
