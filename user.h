#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class User{
    private:
        //users preferences
        string startYear;
        string endYear;
        string rating;
        string runtime;
        vector<string> genres;
        vector<string> languages;
        
    public:
        //default constructor
        User(): startYear(""), endYear(""), rating(""){}
        
        User(string startYear, string endYear, string rating, string runtime, vector<string> genres, vector<string> languages){
            this->startYear = startYear;
            this->endYear = endYear;
            this->rating = rating;
            this->runtime = runtime;
            for(string str : genres)
                this->genres.push_back(str);
            for(string str : languages)
                this->languages.push_back(str);
        }

        //accessors
        string getStartYear() const
            { return this->startYear; }
        string getEndYear() const
            { return this->endYear; }
        string getRating() const
            { return this->rating; }
        string getRuntime() const
            { return this->runtime; }
        vector<string> getGenres() const
            { return this->genres; }
        vector<string> getLanguages() const
            { return this->languages; }

        //mutators
        void setStartYear(string startYear)
            { this->startYear = startYear; }
        void setEndYear(string endYear)
            { this->endYear = endYear; }
        void setRating(string rating)
            { this->rating = rating; }
        void setRuntime(string runtime)
            { this->runtime = runtime; }
        void setGenres(vector<string> genres)
            { for(string str : genres)
                this->genres.push_back(str); }
        void setLanguages(vector<string> languages)
            { for(string str : languages)
                this->languages.push_back(str); }
};