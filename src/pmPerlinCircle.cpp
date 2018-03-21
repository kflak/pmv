#include "pmPerlinCircle.h"

pmPerlinCircle::pmPerlinCircle(){
}

void pmPerlinCircle::setup(){
    N = 1;
    maxN = 100;
    elapsedTime = ofGetElapsedTimef();
    height = ofGetHeight();
    width = ofGetWidth();
    // noiseMul = height * 0.1;
    noiseMul = 100;
    fbo.allocate(width, height, GL_RGB32F_ARB);
    fbo.begin();
    ofBackground(0);
    fbo.end();
    history = 0.97;
    minThetaSpeed = -0.01;
    // minThetaSpeed = 0.0001;
    maxThetaSpeed = 0.03;
    // minR = height * 0.01;
    minR = 0.0;
    maxR = height * 0.5 - noiseMul;
    spawnRate = 0.1;
    // rotationRate = 1;
    // rotation = 0.0;
    for (int i = 0; i < N; i++) {
        theta.push_back(ofRandom(0, TWO_PI));
        thetaSpeed.push_back(ofRandom(minThetaSpeed, maxThetaSpeed));
        noise = ofSignedNoise(elapsedTime + i) * noiseMul;
        float expRand = pow(ofRandom(0.0, 1.0), 3) * maxR + minR;
        r.push_back(expRand);
        radius.push_back(r[i] + noise);
        x = radius[i] * cos(theta[i]);
        y = radius[i] * sin(theta[i]);
        points.push_back(ofPoint(x, y));
        // colorOffset.push_back(ofRandom(0.0, 1.0));
        // circleColor.push_back(blue.getLerped(green, colorOffset[i])); 
        // circleColor[i].a = 128;
        // colorInc.push_back(0.01);
        // colorOffset[i] += colorInc[i];
    };
    // t0 = elapsedTime;
    // t1 = t0 + fadeTime;
}

void pmPerlinCircle::update(){
    elapsedTime = ofGetElapsedTimef();
    // float fade1 = ofMap(elapsedTime, t0, t1, 0.0, 1.0);
    if ((fmod(elapsedTime, spawnRate) < spawnRate) && (N <= maxN)){
        theta.push_back(ofRandom(0, TWO_PI));
        thetaSpeed.push_back(ofRandom(minThetaSpeed, maxThetaSpeed));
        r.push_back(ofRandom(minR, maxR));
        radius.push_back(0.0);
        points.push_back(center);
        // colorOffset.push_back(ofRandom(0.0, 1.0));
        // circleColor.push_back(blue.getLerped(green, ofRandom(0.0, 0.1))); 
        // colorInc.push_back(0.01);
        N++;
        // N %= maxN;
    };
    
    for (int i = 0; i < N; i++) {
        noise = ofSignedNoise(elapsedTime + i * 0.1) * noiseMul;
        radius[i] = r[i] + noise;
        points[i].x = radius[i] * cos(theta[i]);
        points[i].y = radius[i] * sin(theta[i]);
        theta[i] += thetaSpeed[i];
        // circleColor[i] = blue.getLerped(green, colorOffset[i]);
        // circleColor[i].a = 50;
        // if (colorOffset[i] > 1.0 || colorOffset[i] < 0.0){
        //     colorInc[i] = -colorInc[i];
        // }
        // colorOffset[i] += colorInc[i];
    }

    color = green.getLerped(blue, sin(elapsedTime * 0.1)/2 + 0.5);
}

void pmPerlinCircle::draw(){
    ofBackground(0);
    fbo.begin();
    ofEnableAlphaBlending();
    float alpha = (1-history) * 255;
    ofSetColor(0, 0, 0, alpha);
    ofFill();
    ofDrawRectangle(0, 0, ofGetWidth(), ofGetHeight());
    ofPushMatrix();
    ofTranslate(width/2, height/2);
    ofSetColor(color);
    ofNoFill();
    ofBeginShape();
    ofCurveVertices(points);
    ofEndShape();
    for(int i = 0; i < N; i++){
        ofDrawCircle(points[i], radius[i] * 0.01);
        ofSetLineWidth(1);
        ofDrawLine(points[i], center);
    }
    // for (int i = 10; i > 0; i--) {
    //     ofSetColor(0, 0, 0, i * 10);
    //     ofDrawCircle(center.x, center.y, i);  
    // }
    ofPopMatrix();
    ofSetColor(0, 0, 0, 128);
    fbo.end();
    ofSetColor(255);
    fbo.draw(0, 0);
}
