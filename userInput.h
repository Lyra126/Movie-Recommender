#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class userInput {

private:

public:
    //users preferences
    string yearReleased;
    string gender;
    string rating;
    string length;
    string season;
    vector<string> genres;

    //default constructor
    userInput(): yearReleased(""), gender(""), rating(""), length(""), season(""){}

    userInput(string prefYear, string prefGender, string prefRating, string prefLength, string prefSeason, vector<string> prefGenres){
        this->yearReleased = prefYear;
        this->gender = prefGender;
        this->rating = prefRating;
        this->length = prefLength;
        this->season = prefSeason;
        for(string str : prefGenres)
            this->genres.push_back(str);
    }

    //accessors
    string getYear() const
    { return this->yearReleased; }
    string getGender() const
    { return this->gender; }
    string getRating() const
    { return this->rating; }
    string getLength() const
    { return this->length; }
    string getSeason() const
    { return this->season; }
    vector<string> getGenres() const
    { return this->genres; }


    //mutators
    void setYear(string year)
    { this->yearReleased = year; }
    void setGender(string gen)
    { this->gender = gen; }
    void setRating(string rate)
    { this->rating = rate; }
    void setLength(string runtime)
    { this->length = runtime; }
    void setSeason(string seas)
    { this->season = seas; }
    void setGenres(vector<string> gen)
    { for(string str : gen)
            this->genres.push_back(str); }

    //getRank
    string whichYear(int var) {
        string temp;
        if(var == 1) {
            temp = "Less than 1 year";
        }
        else if(var == 2) {
            temp = "1-5 years";
        }
        else if(var == 3) {
            temp = "5-10 years";
        }
        else if(var == 4) {
            temp = "10-15 years";
        }
        else if(var == 5) {
            temp = "15+ years";
        }
        return temp;
    }
    string whichGender(int var) {
        string temp;
        if(var == 1) {
            temp = "Male";
        }
        else if(var == 2) {
            temp = "Female";
        }
        return temp;
    }
    string whichRating(int var) {
        string temp;
        if(var == 1) {
            temp = "G";
        }
        else if(var == 2) {
            temp = "PG";
        }
        else if(var == 3) {
            temp = "PG-13";
        }
        else if(var == 4) {
            temp = "R";
        }
        return temp;
    }
    string whichSeason(int var) {
        string temp;
        if(var == 1) {
            temp = "Fall";
        }
        else if(var == 2) {
            temp = "Winter";
        }
        else if(var == 3) {
            temp = "Spring";
        }
        else if(var == 4) {
            temp = "Summer";
        }
        return temp;
    }

    string whichLength(int var) {
        string temp;
        if(var == 1) {
            temp = "Less than 90 minutes";
        }
        else if(var == 2) {
            temp = "90 min. - 180 min.";
        }
        else if(var == 3) {
            temp = "180 min. - 270 min.";
        }
        else if(var == 4) {
            temp = "270+ minutes";
        }
        return temp;
    }

    vector<string> whichGenre(vector<int> var) {
        string temp;
        vector<string> returner;
        for(int i = 0; i < var.size(); i++) {
            if (var[i] == 1) {
                temp = "Romance";
                returner.push_back(temp);
            } else if (var[i] == 2) {
                temp = "Action";
                returner.push_back(temp);
            } else if (var[i] == 3) {
                temp = "Drama";
                returner.push_back(temp);
            } else if (var[i] == 4) {
                temp = "History";
                returner.push_back(temp);
            } else if (var[i] == 5) {
                temp = "Comedy";
                returner.push_back(temp);
            } else if (var[i] == 6) {
                temp = "Adventure";
                returner.push_back(temp);
            } else if (var[i] == 7) {
                temp = "Animation";
                returner.push_back(temp);
            } else if (var[i] == 8) {
                temp = "Sci-Fi";
                returner.push_back(temp);
            }
        }
        return returner;
    }

    int yearRate(string var) {
        int temp;
        if(var == "Less than 1 year") {
            temp = 1;
        }
        else if(var == "1-5 years") {
            temp = 2;
        }
        else if(var == "5-10 years") {
            temp = 3;
        }
        else if(var == "10-15 years") {
            temp = 4;
        }
        else if(var == "15+ years") {
            temp = 5;
        }
        return temp;
    }
    int genderRate(string var) {
        int temp;
        if(var == "Male") {
            temp = 0;
        }
        else if(var == "Female") {
            temp = 500;
        }
        return temp;
    }
    int ratingRate(string var) {
        int temp;
        if(var == "G") {
            temp = 10;
        }
        else if(var == "PG") {
            temp = 20;
        }
        else if(var == "PG-13") {
            temp = 30;
        }
        else if(var == "R") {
            temp = 40;
        }
        return temp;
    }
    int seasonRate(string var) {
        int temp;
        if(var == "Fall") {
            temp = 5;
        }
        else if(var == "Winter") {
            temp = 15;
        }
        else if(var == "Spring") {
            temp = 25;
        }
        else if(var == "Summer") {
            temp = 35;
        }
        return temp;
    }

    int lengthRate(string var) {
        int temp;
        if(var == "Less than 90 minutes") {
            temp = 2;
        }
        else if(var == "90 min. - 180 min.") {
            temp = 4;
        }
        else if(var == "180 min. - 270 min.") {
            temp = 6;
        }
        else if(var == "270+ minutes") {
            temp = 8;
        }
        return temp;
    }

    vector<int> genreRate(vector<string> var) {
        int temp;
        vector<int> returner;
        for(int i = 0; i < var.size(); i++) {
            if (var[i] == "Romance") {
                temp = 2;
                returner.push_back(temp);
            } else if (var[i] == "Action") {
                temp = 4;
                returner.push_back(temp);
            } else if (var[i] == "Drama") {
                temp = 6;
                returner.push_back(temp);
            } else if (var[i] == "History") {
                temp = 8;
                returner.push_back(temp);
            } else if (var[i] == "Comedy") {
                temp = 10;
                returner.push_back(temp);
            } else if (var[i] == "Adventure") {
                temp = 12;
                returner.push_back(temp);
            } else if (var[i] == "Animation") {
                temp = 14;
                returner.push_back(temp);
            } else if (var[i] == "Sci-Fi") {
                temp = 16;
                returner.push_back(temp);
            }
        }
        return returner;
    }

};