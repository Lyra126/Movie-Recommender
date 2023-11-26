#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;


class User{
    private:
        //users preferences
        string startYear;
        string endYear;
        string rating;
        string language;
        int runtime;
        vector<string> genres;
        
    public:
        //default constructor
        User(): startYear("1900"), endYear("2023"), rating("PG-13"), runtime(60), language("English"){}
        
        User(string startYear, string endYear, string rating, string runtimeStr, string language, string genreList){
            this->startYear = startYear;
            this->endYear = endYear;
            this->rating = rating;
            this->language = language;
            
            istringstream iss(runtimeStr);
            iss >> runtime;

            stringstream ss(genreList);
            // Temp variable to hold each word
            string genre;
            // Iterate through the stringstream, splitting on commas, and add to vector
            while (getline(ss, genre, ',')) {
                genre.erase(0, genre.find_first_not_of(" \t\r\n"));
                genre.erase(genre.find_last_not_of(" \t\r\n") + 1);
                genres.push_back(genre);
            }
        }

        //accessors
        int getStartYear() const
            { return stoi(this->startYear); }
        int getEndYear() const
            { return stoi(this->endYear); }
        string getRating() const
            { return this->rating; }
        string getLanguage() const
            { return this->language; }
        int getRuntime() const
            { return this->runtime; }
        vector<string> getGenres() const
            { return this->genres; }

        //mutators
        void setStartYear(string startYear)
            { this->startYear = startYear; }
        void setEndYear(string endYear)
            { this->endYear = endYear; }
        void setRating(string rating)
            { this->rating = rating; }
        void setLanguage(string language)
            { this->language = language; }
        void setRuntime(string runtimeStr){
            istringstream iss(runtimeStr);
            iss >> runtime;
        }
        void setGenres(string genreList){
            stringstream ss(genreList);
            // Temp variable to hold each word
            string genre;

            // Iterate through the stringstream, splitting on commas, and add to vector
            while (getline(ss, genre, ',')) {
                genre.erase(0, genre.find_first_not_of(" \t\r\n"));
                genre.erase(genre.find_last_not_of(" \t\r\n") + 1);
                genres.push_back(genre);
            }
        }

        
};