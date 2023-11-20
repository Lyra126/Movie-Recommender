#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <json/json.h>
#include <map> //remove this later!!!
#include "mapGraph.h"
#include "user.h"
#include "movie.h"
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

void rankIt(userInput& user, vector<map<string, string> >  movieData, priorityQueue& pq) {
    string movie;
    int theRank;
    theRank = eachPrefRank(user);
    pq.insert(movie, theRank);
}
void rankMovies(User& user, vector<map<string, string> > movies, priorityQueue& pq){
    //implement algorithm to rank movies
    string movie;
    pq.insert(movie, 0);
}

void storeRankings(priorityQueue& pq){
    //create json files based on rankings and send them to a database
}

int main() {
    string apiKey = "5a925008";
    string apiUrl = "http://www.omdbapi.com/";

    // Number of movies to fetch
    int numMovies = 100;

    // Data structure to store movie information
    vector<map<string, string>> movies; //the vector of maps will be a temporary placeholder while i coode up the map data structure

    // Fetch information for each movie
    for (int i = 0; i < numMovies; ++i) {
        // Generate a random IMDb ID (you might want to change this logic)
        string imdbId = "tt" + to_string(rand() % 1000000 + 1000000);

        // Construct the API request URL
        string requestUrl = apiUrl + "?i=%20" + imdbId + "&apikey=" + apiKey;
        cout << requestUrl << endl;

        // Make the HTTP request
        auto response = cpr::Get(cpr::Url{requestUrl});
    
        // Parse the JSON response
        Json::Value jsonData;
        Json::CharReaderBuilder jsonReader;
        std::istringstream jsonStream(response.text);
        Json::parseFromStream(jsonReader, jsonStream, &jsonData, nullptr);

        // Check if the request was successful
        if (jsonData["Response"].asString() == "True") {
            // Store movie information in your data structure
            movies.push_back({
                {"Title", jsonData["Title"].asString()},
                {"Year", jsonData["Year"].asString()},
                {"Genre", jsonData["Genre"].asString()},
                // Add other fields you need
            });
        } else {
            std::cout << "Error fetching movie with IMDb ID " << imdbId << " - " << jsonData["Error"].asString() << std::endl;
        }
    }
    //checking if the code above actually stored anything
    for (const auto& movie : movies)
        std::cout << "Title: " << movie.at("Title") << std::endl;

    //make user object and use Web UI to get user preferences and storing those in a map
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

    //rank movies according to preferences and store rankings in priority queue
    priorityQueue pq;
    rankMovies(user, movies, pq);
    rankIt(userInput, movies, pq);

    //output json files and put them in a database so the web UI and get them and display them
    storeRankings(pq);
    return 0;
}

