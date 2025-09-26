#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class Movie
{
    private:
        string title;
        int yearReleased;
        string screenwriter;

    public:
        // constructor.
        Movie(string t, int year, string s)
        {
            title = t;
            yearReleased = year;
            screenwriter = s;
        }

        // setters & getters
        void setTitle(string t)
        {
            title = t;
        }

        void setYear(int year) 
        {
            yearReleased = year;
        }

        void setScreenwriter(string s) 
        {
            screenwriter = s;
        }

        // getters
        string getTitle() const
        {
            return title;
        }
        
        int getYear() const
        {
            return yearReleased;
        }

        string getScreenwriter() const
        {
            return screenwriter;
        }

        void print()
        {
            cout << "Movie: " << title << endl;
            cout << "\tYear Released: " << yearReleased << endl;
            cout << "\tScreenwriter: " << screenwriter << endl;
            cout << endl;
        }

};

int main()
{
    ifstream inFile("input.txt");
    if (!inFile)
    {
        cout << "Error." << endl;
        return 0;
    }

    vector<Movie> movies;
    string title, screenwriter;
    int year;


    while (getline(inFile, title) && inFile >> year && inFile.ignore() && getline(inFile, screenwriter))
    {
        Movie mov(title, year, screenwriter);
        movies.push_back(mov);
    }

    inFile.close();

    for (int i = 0; i < movies.size(); i++){
        movies[i].print();
    }


}