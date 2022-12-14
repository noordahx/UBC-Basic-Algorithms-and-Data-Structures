#include "block.h"
#include <cmath>
#include <iostream>


int Block::width() const
{
/* YOUR CODE HERE */
    return data.size();
}
int Block::height() const
{
/* YOUR CODE HERE */
    return data[0].size();
}

void Block::render(PNG &im, int column, int row) const
{
/* YOUR CODE HERE */
    for (int x = 0; x < width(); x++) {
        for (int y = 0; y < height(); y++) {
            *im.getPixel(column+x,row+y) = data[x][y];
        }
    }

}

void Block::build(PNG &im, int column, int row, int width, int height)
{
/* YOUR CODE HERE */
    data.resize(width, vector<RGBAPixel>(height));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            data[x][y] = *im.getPixel(column+x,row+y);
        }
    }
    
} 

void Block::flipVert()
{
/* YOUR CODE HERE */
    for (int x = 0; x < width(); x++) {
        for (int y = 0; y < height()/2; y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[x][height()-1-y];
            data[x][height()-1-y] = temp;
        }
    }
}

void Block::flipHoriz()
{
/* YOUR CODE HERE */
    for (int x = 0; x < width()/2; x++) {
        for (int y = 0; y < height(); y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[width()-1-x][y];
            data[width()-1-x][y] = temp;
        }
    }
}

void Block::rotateRight()
{
    /* YOUR CODE HERE */
    for (int x = 0; x < width()/2; x++) {
        for (int y = x; y < height()-x-1; y++) {
            RGBAPixel temp = data[x][y];
            data[x][y] = data[y][width()-1-x];
            data[y][width()-1-x] = data[width()-1-x][width()-1-y];
            data[width()-1-x][width()-1-y] = data[width()-1-y][x];
            data[width()-1-y][x] = temp;
        }
    }
}