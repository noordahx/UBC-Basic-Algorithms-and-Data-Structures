#include "treasureMap.h"
#include "queue.h"
using namespace std;

treasureMap::treasureMap(const PNG & baseim, const PNG & mazeim, pair<int,int> s)
{

/* YOUR CODE HERE */
    base = PNG(baseim);
    maze = PNG(mazeim);
    start.first = s.first;
    start.second = s.second;
}

void treasureMap::setGrey(PNG & im, pair<int,int> loc){

/* YOUR CODE HERE */

}

void treasureMap::setLOB(PNG & im, pair<int,int> loc, int d){

/* YOUR CODE HERE */

}

PNG treasureMap::renderMap(){

/* YOUR CODE HERE */

}


PNG treasureMap::renderMaze(){

/* YOUR CODE HERE */

}

bool treasureMap::good(vector<vector<bool>> & v, pair<int,int> curr, pair<int,int> next){

/* YOUR CODE HERE */

}

vector<pair<int,int>> treasureMap::neighbors(pair<int,int> curr) {

/* YOUR CODE HERE */
    vector<pair<int,int>> result;
    result.push_back(make_pair(curr.first, curr.second - 1));
    result.push_back(make_pair(curr.first - 1, curr.second));
    result.push_back(make_pair(curr.first, curr.second + 1));
    result.push_back(make_pair(curr.first + 1, curr.second));
    return result;
}

