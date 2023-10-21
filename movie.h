#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Movie{
    private:
        string title;
        string year;
        string rated;
        string releaseDate;
        string runtime;
        string poster;
        vector<string> genres;
        vector<string> languages;
        
    public:
        //default constructor
        Movie(): title(""), year(""), rated(""), releaseDate(""), poster(""){}
        
        Movie(string title, string year, string rated, string releaseDate, string runtime, string poster, vector<string> genres, vector<string> languages){
            this->title = title;
            this->year = year;
            this->rated = rated;
            this->releaseDate = releaseDate;
            this->runtime = runtime;
            this->poster = poster;
            for(string str : genres)
                this->genres.push_back(str);
            for(string str : languages)
                this->languages.push_back(str);
        }

        //accessors
        string getTitle() const
            { return this->title; }
        string getYear() const
            { return this->year; }
        string getRated() const
            { return this->rated; }
        string getReleaseDate() const
            { return this->releaseDate; }
        string getRuntime() const
            { return this->runtime; }
        string getPoster() const
            { return this->poster; }
        vector<string> getGenres() const
            { return this->genres; }
        vector<string> getLanguages() const
            { return this->languages; }

        //mutators
        void setTitle(string title)
            { this->title = title; }
        void setYear(string year)
            { this->year = year; }
        void setRated(string rated)
            { this->rated = rated; }
        void setReleaseDate(string releaseDate)
            { this->releaseDate = releaseDate; }
        void setRuntime(string runtime)
            { this->runtime = runtime; }
        void setPoster(string poster)
            { this->poster = poster; }
        void setGenres(vector<string> genres)
            { for(string str : genres)
                this->genres.push_back(str); }
        void setLanguages(vector<string> languages)
            { for(string str : languages)
                this->languages.push_back(str); }
};