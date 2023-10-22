#include <iostream>
#include <map>
#include <set>
#include "movie.h"
#include "user.h"

using namespace std;

int main(){
    //parse json files from OMDb API and make user object
    //Using the Web UI to get user preferences and storing those in a map?
    string startYear;
    string endYear;
    string rating;
    string runtime;
    vector<string> genres;
    vector<string> languages;
    User user(startYear, endYear, rating, runtime, genres, languages);

    //implement OMDb Web API and get 1,000 data points (movies)

    //store movie data in sets

    //rank movies according to preferences and store rankings in priority queue

    //output json files and put them in a database so the web UI and get them and display them

}