#include "stats.h"


#include "stats.h"

stats::stats(PNG & im){
/* Your code here!! */

    for(unsigned int h = 0; h < im.height(); h++){
        sumRed.push_back(vector<long>());
        sumGreen.push_back(vector<long>());
        sumBlue.push_back(vector<long>());
        sumsqRed.push_back(vector<long>());
        sumsqBlue.push_back(vector<long>());
        sumsqGreen.push_back(vector<long>());


        for(unsigned int w = 0; w < im.width(); w++){

            RGBAPixel *currPix = im.getPixel(w, h);
            unsigned char r = currPix->r;
            unsigned char g = currPix->g;
            unsigned char b = currPix->b;

            sumRed[h].push_back(r);
            sumBlue[h].push_back(b);
            sumGreen[h].push_back(g);
            sumsqRed[h].push_back(r*r);
            sumsqBlue[h].push_back(b*b);
            sumsqGreen[h].push_back(g*g);

            if(h > 0){
                sumRed[h][w] += sumRed[h-1][w];
                sumBlue[h][w] += sumBlue[h-1][w];
                sumGreen[h][w] += sumGreen[h-1][w];
                sumsqRed[h][w] += sumsqRed[h-1][w];
                sumsqGreen[h][w] += sumsqGreen[h-1][w];
                sumsqBlue[h][w] += sumsqBlue[h-1][w];
            }
            
            if(w > 0){
                sumRed[h][w] += sumRed[h][w-1];
                sumBlue[h][w] += sumBlue[h][w-1];
                sumGreen[h][w] += sumGreen[h][w-1];
                sumsqRed[h][w] += sumsqRed[h][w-1];
                sumsqGreen[h][w] += sumsqGreen[h][w-1];
                sumsqBlue[h][w] += sumsqBlue[h][w-1];
            }

            if(w > 0 && h > 0){
                sumRed[h][w] -= sumRed[h-1][w-1];
                sumBlue[h][w] -= sumBlue[h-1][w-1];
                sumGreen[h][w] -= sumGreen[h-1][w-1];
                sumsqRed[h][w] -= sumsqRed[h-1][w-1];
                sumsqGreen[h][w] -= sumsqGreen[h-1][w-1];
                sumsqBlue[h][w] -= sumsqBlue[h-1][w-1];
            }
        }
    }

    for(unsigned int h = 0; h < im.height(); h++){
        sumRed.push_back(vector<long>());
        sumGreen.push_back(vector<long>());
        sumBlue.push_back(vector<long>());
        sumsqRed.push_back(vector<long>());
        sumsqBlue.push_back(vector<long>());
        sumsqGreen.push_back(vector<long>());


        for(unsigned int w = 0; w < im.width(); w++){

            RGBAPixel *currPix = im.getPixel(w, h);
            unsigned char r = currPix->r;
            unsigned char g = currPix->g;
            unsigned char b = currPix->b;

            sumRed[h].push_back(r);
            sumGreen[h].push_back(g);
            sumBlue[h].push_back(b);
            sumsqRed[h].push_back(r*r);
            sumsqGreen[h].push_back(g*g);
            sumsqBlue[h].push_back(b*b);

            if(h > 0){
                sumRed[h][w] += sumRed[h-1][w];
                sumGreen[h][w] += sumGreen[h-1][w];
                sumBlue[h][w] += sumBlue[h-1][w];
                sumsqRed[h][w] += sumsqRed[h-1][w];
                sumsqGreen[h][w] += sumsqGreen[h-1][w];
                sumsqBlue[h][w] += sumsqBlue[h-1][w];
            }
            
            if(w > 0){
                sumRed[h][w] += sumRed[h][w-1];
                sumGreen[h][w] += sumGreen[h][w-1];
                sumBlue[h][w] += sumBlue[h][w-1];
                sumsqRed[h][w] += sumsqRed[h][w-1];
                sumsqGreen[h][w] += sumsqGreen[h][w-1];
                sumsqBlue[h][w] += sumsqBlue[h][w-1];
            }

            if(w > 0 && h > 0){
                sumRed[h][w] -= sumRed[h-1][w-1];
                sumGreen[h][w] -= sumGreen[h-1][w-1];
                sumBlue[h][w] -= sumBlue[h-1][w-1];
                sumsqRed[h][w] -= sumsqRed[h-1][w-1];
                sumsqGreen[h][w] -= sumsqGreen[h-1][w-1];
                sumsqBlue[h][w] -= sumsqBlue[h-1][w-1];
            }
        }
    }
}

long solveGeom(vector<vector<long>> &chan, pair<int,int> ul, int w, int h){
    long curSum = chan[ul.second + h - 1][ul.first + w - 1];
        if(ul.second > 0){
            curSum -= chan[ul.second - 1][ul.first + w - 1];
        }
        if(ul.first > 0){
            curSum -= chan[ul.second + h - 1][ul.first - 1];
        }
        if(ul.first > 0 && ul.second > 0){
            curSum += chan[ul.second - 1][ul.first - 1];
        }
    
    return curSum;
}
long solveGeom(vector<vector<long>> &chan, pair<int,int> ul, int w, int h){
    long curSum = chan[ul.second + h - 1][ul.first + w - 1];
        if(ul.second > 0){
            curSum -= chan[ul.second - 1][ul.first + w - 1];
        }
        if(ul.first > 0){
            curSum -= chan[ul.second + h - 1][ul.first - 1];
        }
        if(ul.first > 0 && ul.second > 0){
            curSum += chan[ul.second - 1][ul.first - 1];
        }
    
    return curSum;
}

long stats::getSum(char channel, pair<int,int> ul, int w, int h){
/* Your code here!! */
    if(channel == 'r'){
        return solveGeom(sumRed, ul, w, h);
    }
    else if(channel == 'g'){
        return solveGeom(sumGreen, ul, w, h);
    }
    else if(channel == 'b'){
        return solveGeom(sumBlue, ul, w, h);
    }
}

long stats::getSumSq(char channel, pair<int,int> ul, int w, int h){
/* Your code here!! */
    if(channel == 'r'){
        return solveGeom(sumsqRed, ul, w, h);
    }
    else if(channel == 'g'){
        return solveGeom(sumsqGreen, ul, w, h);
    }
    else if(channel == 'b'){
        return solveGeom(sumsqBlue, ul, w, h);
    }
    if(channel == 'r'){
        return solveGeom(sumsqRed, ul, w, h);
    }
    else if(channel == 'g'){
        return solveGeom(sumsqGreen, ul, w, h);
    }
    else if(channel == 'b'){
        return solveGeom(sumsqBlue, ul, w, h);
    }
}

// given a rectangle, compute its sum of squared deviations from mean, over all color channels.
// see written specification for a description of this function.
double stats::getVar(pair<int,int> ul, int w, int h){
/* Your code here!! */
    long xsq = getSumSq('r', ul, w, h) + getSumSq('g', ul, w, h) + getSumSq('b', ul, w, h);
    long x = getSum('r', ul, w, h) + getSum('g', ul, w, h) + getSum('b', ul, w, h);

}
		
RGBAPixel stats::getAvg(pair<int,int> ul, int w, int h){
/* Your code here!! */
    long ravg = getSum('r', ul, w, h)/(w*h);
    long gavg = getSum('g', ul, w, h)/(w*h);
    long bavg = getSum('b', ul, w, h)/(w*h);
    long ravg = getSum('r', ul, w, h)/(w*h);
    long gavg = getSum('g', ul, w, h)/(w*h);
    long bavg = getSum('b', ul, w, h)/(w*h);

    return RGBAPixel(ravg, gavg, bavg);
    return RGBAPixel(ravg, gavg, bavg);
}
