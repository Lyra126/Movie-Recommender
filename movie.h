#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
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
        string language;
        
    public:
        //default constructor
        Movie(): title(""), year(""), rated(""), releaseDate(""), poster(""){}
        
        Movie(string title, string year, string rated, string releaseDate, string runtime, string poster, string genresStr, string language){
            this->title = title;
            this->year = year;
            this->rated = rated;
            this->releaseDate = releaseDate;
            this->runtime = runtime;
            this->poster = poster;
            //parsing the genres string according to the commas
            istringstream ss(genresStr);
            string genre;
            while (getline(ss, genre, ',')) {
                size_t start = genre.find_first_not_of(" \t\n");
                size_t end = genre.find_last_not_of(" \t\n");
                if (start != std::string::npos && end != std::string::npos)
                    genres.push_back(genre.substr(start, end - start + 1));
            }
            this->language = language;
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
        string getLanguage() const
            { return this->language; }

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
        void setLanguage(string language)
            { this->language = language; }

        void toString() const {
            cout << "Title: " + title + 
            "\nYear: " + year + 
            "\nRated: " + rated + 
            "\nRelease Date: " + releaseDate + 
            "\nRuntime: " + runtime + 
            "\nPoster: " + poster + 
            "\nGenres: ";
            for (const auto& genre : genres)
                cout << genre + ", ";
            cout << "\nLanguage: " + language + "\n\n";
        }
};