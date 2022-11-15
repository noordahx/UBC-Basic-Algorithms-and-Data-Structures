#include "treasureMap.h"
#include "queue.h"
using namespace std;

treasureMap::treasureMap(const PNG &baseim, const PNG &mazeim, pair<int, int> s)
{

    /* YOUR CODE HERE */
    base = PNG(baseim);
    maze = PNG(mazeim);
    start.first = s.first;
    start.second = s.second;
}

void treasureMap::setGrey(PNG &im, pair<int, int> loc)
{
    /* YOUR CODE HERE */
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
    pixel->r = 2*(pixel->r / 4);
    pixel->g = 2*(pixel->g / 4);
    pixel->b = 2*(pixel->b / 4);
}

void treasureMap::setLOB(PNG &im, pair<int, int> loc, int d)
{

    /* YOUR CODE HERE */
    RGBAPixel* pixel = im.getPixel(loc.first, loc.second);
    pixel->r = ((pixel->r >> 2) << 2) + ((d / 16) % 4);
    pixel->g = (pixel->g & 0xFC) + ((d / 4) % 4);
    pixel->b = (pixel->b & 0xFC) + (d % 4);
    // int newR = (d & 48) >> 4;
    // int newG = (d & 12) >> 2;
    // int newB = (d & 3);
    
    // int lastTwo = 252;
    // pixel->r = (pixel->r & lastTwo) | newR;
    // pixel->g = (pixel->g & lastTwo) | newG;
    // pixel->b = (pixel->b & lastTwo) | newB;
}

PNG treasureMap::renderMap()
{

    /* YOUR CODE HERE */
    // 0.
    PNG copy = PNG(base);

    // 1.a
    vector<vector<bool>> isVisited;
    isVisited.resize(copy.width(), vector<bool>(copy.height()));

    // 1.b
    vector<vector<int>> pathLength;
    pathLength.resize(copy.width(), vector<int>(copy.height()));

    // 2.
    Queue<pair<int, int>> myQueue;

    // 3.a
    isVisited[start.first][start.second] = true;

    // 3.b
    pathLength[start.first][start.second] = 0;

    // 3.c
    setLOB(copy, start, 0);

    // 3.d
    myQueue.enqueue(start);
    // for (auto neighbor : neighbors(start)) {
    //     myQueue.enqueue(neighbor);
    // }

    // 4.a
    pair<int, int> curr;
    while (!myQueue.isEmpty())
    {
        curr = myQueue.dequeue();
        for (auto neighbor : neighbors(curr)) {
            if (good(isVisited, curr, neighbor))
            {
                isVisited[neighbor.first][neighbor.second] = true;
                
                pathLength[neighbor.first][neighbor.second] =
                    pathLength[curr.first][curr.second] + 1;
                
                setLOB(copy, neighbor,
                       pathLength[neighbor.first][neighbor.second]);
                myQueue.enqueue(neighbor);
            }
        }
    }

    return copy;
}

PNG treasureMap::renderMaze()
{

    /* YOUR CODE HERE */
    PNG copy = PNG(base);
    vector<vector<bool>> isVisited;
    isVisited.resize(copy.width(), vector<bool>(copy.height()));

    Queue<pair<int, int>> myQueue;
    isVisited[start.first][start.second] = true;
    
    myQueue.enqueue(start);

    
    pair<int,int> curr;
    while (!myQueue.isEmpty())
    {
        curr = myQueue.dequeue();
        
        for (auto neighbor : neighbors(curr)) {
            if (good(isVisited, curr, neighbor))
            {
                setGrey(copy, neighbor);
                isVisited[neighbor.first][neighbor.second] = true;
                myQueue.enqueue(neighbor);
            }
        }
    }

    // draw square
    for (int i = start.first - 3; i <= start.first + 3; i++) {
        for (int j = start.second - 3; j <= start.second + 3; j++) {
            if (i >= 0 && i < (int)copy.width() && j >= 0 && j < (int)copy.height()) {
                RGBAPixel* pixel = copy.getPixel(i , j);
                pixel->r = 255;
                pixel->b = 0;
                pixel->g = 0;
            
            }
        }
    }
    return copy;
}

bool treasureMap::good(vector<vector<bool>> &v, pair<int, int> curr, pair<int, int> next)
{

    /* YOUR CODE HERE */
    if (next.first >= 0 && next.first < (int)base.width() && next.second >= 0 && next.second < (int)base.height())
    {
        if (v[next.first][next.second] == false)
        {
            if (*maze.getPixel(curr.first, curr.second) == *maze.getPixel(next.first, next.second))
            {
                return true;
            }
        }
    }
    return false;
}

vector<pair<int, int>> treasureMap::neighbors(pair<int, int> curr)
{

    /* YOUR CODE HERE */
    vector<pair<int, int>> result;
    result.push_back(make_pair(curr.first, curr.second - 1));
    result.push_back(make_pair(curr.first - 1, curr.second));
    result.push_back(make_pair(curr.first, curr.second + 1));
    result.push_back(make_pair(curr.first + 1, curr.second));
    return result;
}
