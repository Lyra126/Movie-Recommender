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
        string poster;
        string language;
        int runtime;
        vector<string> genres;
        
    public:
        //default constructor
        Movie(): title(""), year(""), rated(""), releaseDate(""), poster(""){}
        
        Movie(string title, string year, string rated, string releaseDate, string poster, string language,string runtimeStr, string genresStr){
            this->title = title;
            this->year = year;
            this->rated = rated;
            this->releaseDate = releaseDate;
            this->poster = poster;
            this->language = language;
            
            istringstream iss(runtimeStr);
            iss >> runtime;
        
            //parsing the genres string according to the commas
            istringstream ss(genresStr);
            string genre;
            while (getline(ss, genre, ',')) {
                size_t start = genre.find_first_not_of(" \t\n");
                size_t end = genre.find_last_not_of(" \t\n");
                if (start != std::string::npos && end != std::string::npos)
                    genres.push_back(genre.substr(start, end - start + 1));
            }
            
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
        int getReleaseYear() const{ 
            istringstream dateStr(releaseDate);
            int day, year;
            string month;
            dateStr >> day >> month >> year;
            return year;
        }
        string getPoster() const
            { return this->poster; }
        string getLanguage() const
            { return this->language; }
        int getRuntime() const
            { return this->runtime; }
        vector<string> getGenres() const
            { return this->genres; }
        

        //mutators
        void setTitle(string title)
            { this->title = title; }
        void setYear(string year)
            { this->year = year; }
        void setRated(string rated)
            { this->rated = rated; }
        void setReleaseDate(string releaseDate)
            { this->releaseDate = releaseDate; }
        void setPoster(string poster)
            { this->poster = poster; }
        void setLanguage(string language)
            { this->language = language; }
        void setRuntime(string runtimeStr){
            istringstream iss(runtimeStr);
            iss >> runtime;
        }   
        void setGenres(string genresStr){
            istringstream ss(genresStr);
            string genre;
            while (getline(ss, genre, ',')) {
                size_t start = genre.find_first_not_of(" \t\n");
                size_t end = genre.find_last_not_of(" \t\n");
                if (start != std::string::npos && end != std::string::npos)
                    genres.push_back(genre.substr(start, end - start + 1));
            }
        }

        void toString() const {
            cout << "Title: " + title + 
            "\nYear: " + year + 
            "\nRated: " + rated + 
            "\nRelease Date: " + releaseDate + 
            "\nRuntime: " + to_string(runtime) + " mins"
            "\nPoster: " + poster + 
            "\nGenres: ";
            for (const auto& genre : genres)
                cout << genre + ", ";
            cout << "\nLanguage: " + language + "\n\n";
        }
};