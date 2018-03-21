#pragma once
#include "ofMain.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class pmText {
    public:

        void setup();
        void update();
        void draw();

        pmText();

    private:

        float x;
        float y;
        ofTrueTypeFont myFont;
        std::string myString;
        std::string frameRateString;
        unsigned int lineCount;
        ofBuffer buf;
        float stringWidth;
        vector <string> lines;
        float elapsedTime;
        float fadeTime;
        float duration;
        float t0, t1, t2, t3;
        ofFloatColor white;
        ofFloatColor black;
        ofFloatColor textColor;

};
