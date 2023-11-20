#include <iostream>
#include "movie.h"
#include "user.h"
#include "map.h"
#include "priorityQueue.h"
#include "userInput.h"

using namespace std;
int eachPrefRank(userInput& user) {
    int a = 0;
    a += user.yearRate(user.yearReleased);
    a += user.genderRate(user.gender);
    a += user.lengthRate(user.length);
    a += user.ratingRate(user.rating);
    a += user.seasonRate(user.season);
    vector<int> var = user.genreRate(user.genres);
    for(int i = 0; i < var.size(); i++) {
        a += var[i];
    }
    return a;
}

void rankIt(userInput& user, map& movieData, priorityQueue& pq) {
    string movie;
    int theRank;
    theRank = eachPrefRank(user);
    pq.insert(movie, theRank);
}

void rankMovies(User& user, map& movieData, priorityQueue& pq){
    //implement algorithm to rank movies
    string movie;
    pq.insert(movie, 0);
}

void storeRankings(priorityQueue& pq){
    //create json files based on rankings and send them to a database
}

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

    //userInput
    //user chooses their preference, which are assigned numbers then translated into strings
    string year, mf, rate, size, seasons;
    vector<string> someGenres;
    userInput userInput(year, mf, rate, size, seasons, someGenres);

    //implement OMDb Web API and get 1,000 data points (movies), store in map
    map movieData;

    //rank movies according to preferences and store rankings in priority queue
    priorityQueue pq;
    rankMovies(user, movieData, pq);
    rankIt(userInput, movieData, pq);

    //output json files and put them in a database so the web UI and get them and display them
    storeRankings(pq);
}