#include <iostream>
#include <cpr/cpr.h>
#include <vector>
#include <json/json.h>
#include <map>
#include <fstream>
#include "user.h"
#include "movie.h"
#include "userInput.h"
using namespace std;

// Function to calculate the movie rank based on user preferences
int calculateMovieRank(const User user, const Movie movie) {
    int rank = 0;

    // Year preference (penalize movies that are not in the user's preferred years)
    int yearDiffStart = abs(movie.getReleaseYear() - user.getStartYear());
    int yearDiffEnd = abs(movie.getReleaseYear() - user.getEndYear());

    if (yearDiffStart == 0 || yearDiffEnd == 0)
        rank += 30;  // Very high rank for movies released in the exact year of the user's start or end year
    else if ((yearDiffStart <= 2 && yearDiffEnd > 0) || (yearDiffStart > 0 && yearDiffEnd <= 2))
        rank += 25;  // Very high rank for movies released within 2 years from the start or end year
    else if ((yearDiffStart <= 5 && yearDiffEnd > 2) || (yearDiffStart > 2 && yearDiffEnd <= 5))
        rank += 20;  // High rank for movies released between 2 and 5 years from the start or end year
    else if ((yearDiffStart <= 10 && yearDiffEnd > 5) || (yearDiffStart > 5 && yearDiffEnd <= 10))
        rank += 15;  // Moderate rank for movies released between 5 and 10 years from the start or end year
    else if ((yearDiffStart <= 15 && yearDiffEnd > 10) || (yearDiffStart > 10 && yearDiffEnd <= 15))
        rank += 10;  // Lower rank for movies released between 10 and 15 years from the start or end year
    else 
        rank -= 30;  // Penalize movies released more than 15 years away from the start or end year

    // Rating preference
    if (user.getRating() == movie.getRated())
        rank += 25;

    // Runtime preference (penalize movies with significantly different runtimes)
    int runtimeDiff = abs(movie.getRuntime() - user.getRuntime());

    if (runtimeDiff <= 2)
        rank += 30;  // Very high rank for movies with runtimes within 2 minutes of the user's preference
    else if (runtimeDiff <= 5)
        rank += 25;  // Very high rank for movies with runtimes between 2 and 5 minutes from the user's preference
    else if (runtimeDiff <= 10)
        rank += 20;  // High rank for movies with runtimes between 5 and 10 minutes from the user's preference
    else if (runtimeDiff <= 15)
        rank += 15;  // Moderate rank for movies with runtimes between 10 and 15 minutes from the user's preference
    else
        rank -= 25;  // Penalize movies with runtimes more than 15 minutes away from the user's preference

    // Language preference
    (user.getLanguage() == movie.getLanguage()) ? rank += 25 : rank -= 25;

    //Genre preference
    for (const string& userGenre : user.getGenres()) 
        for (const string& movieGenre : movie.getGenres()) 
            if (userGenre == movieGenre) 
                rank += 30; // Increase rank for each matching genre

    return rank;
}


//implement algorithm to rank movies
void rankMovies(User user, map<string, Movie> movies, priorityQueue& pq){
    //iterate through list of movies to process, storing only movie title and rank in priority queue
    for(const auto& movie : movies)
        pq.insert(movie.second.getTitle(), calculateMovieRank(user, movie.second));
}

//create json files based on rankings and send them to a database
void storeRankings(priorityQueue& pq) {
    std::ofstream file("movieRecs.json");

    // Loop through the movies in the priority queue
    while (!pq.isEmpty()) {
        movieNode movie = pq.deleteMax();
        // Write JSON object for each movie on a new line
        file << "{ \"movieTitle\":\"" << movie.getMovie() << "\", \"rank\":" << movie.getRank() << "}" << std::endl;
    }

    file.close();
}

int main() {
    string apiKey = "5a925008";
    string apiUrl = "http://www.omdbapi.com/";

    // Number of movies to fetch
    int numMovies = 100;

    // Data structure to store movie information
    map<string, Movie> movies; //the vector of maps will be a temporary placeholder while i coode up the map data structure

    // Fetch information for each movie
    for (int i = 0; i < numMovies; ++i) {
        // Generate a random IMDb ID (you might want to change this logic)
        string imdbId = "tt" + to_string(rand() % 1000000 + 1000000);

        // Construct the API request URL
        string requestUrl = apiUrl + "?i=%20" + imdbId + "&apikey=" + apiKey;

        // Make the HTTP request
        auto response = cpr::Get(cpr::Url{requestUrl});
    
        // Parse the JSON response
        Json::Value jsonData;
        Json::CharReaderBuilder jsonReader;
        std::istringstream jsonStream(response.text);
        Json::parseFromStream(jsonReader, jsonStream, &jsonData, nullptr);

        // Check if the request was successful
        if (jsonData["Response"].asString() == "True")
            movies[jsonData["Title"].asString()] = Movie(jsonData["Title"].asString(), jsonData["Year"].asString(), jsonData["Rated"].asString(),jsonData["Released"].asString(), jsonData["Poster"].asString(), jsonData["Language"].asString(), jsonData["Runtime"].asString(), jsonData["Genre"].asString() );
        else 
            cout << "Error fetching movie with IMDb ID " << imdbId << " - " << jsonData["Error"].asString() << std::endl;
    }
    //checking if the code above actually stored anything
    //for (const auto& pair : movies)
     //   pair.second.toString();


    //make user object and use Web UI to get user preferences and storing those in a map
    //user preferences are assigned numbers then translated into strings
    string startYear; //earliest year they would like movie from
    string endYear; //end year they would like movie from, default if not chosen is current time
    string rating; //movie rating (i.e PG13)
    string language; //what language do they speak/prefer
    string runtime; //avg time they would like movie to be
    string genreList; // list of genres they would like to see
    //User user(startYear, endYear, rating, runtime, language, genreList);
    User user = User("2000", "2023", "PG-13", "English", "60 mins", "Action, Comedy, Romance");

    //rank movies according to preferences and store rankings in priority queue
    priorityQueue pq;
    rankMovies(user, movies, pq);

    //output json files and put them in a database so the web UI and get them and display them
    storeRankings(pq);
    return 0;
}

