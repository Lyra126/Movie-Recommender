#include <iostream>
#include "movie.h"
#include "user.h"
#include "map.h"
#include "priorityQueue.h"

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

    //implement OMDb Web API and get 1,000 data points (movies), store in map
    map movieData;

    //rank movies according to preferences and store rankings in priority queue
    priorityQueue pq;
    rankMovies(user, movieData, pq);

    //output json files and put them in a database so the web UI and get them and display them
    storeRankings(pq);
}

void rankMovies(User& user, map& movieData, priorityQueue& pq){
    //implement algorithm to rank movies
    string movie;
    pq.insert(movie);
}

void storeRankings(priorityQueue& pq){
    //create json files based on rankings and send them to a database
}