#include "MusicDB.h"
#include "Song.h"
#include <iostream>
#include <string>
#include <fstream>
#include <array>
#include <vector>
#include <stdexcept>

using namespace MusicDatabase;
using namespace std;
//Song songs[8];
int totalSongs = 0;
string genre;
string user_input;
vector <Song> songDatabase; 
void addToDatabase()
	{
	Song new_song; 
		cout << "Enter Song Title: " << endl;
		cin.getline(new_song.title, 64);//totalSongs[songs].title, 64;
		cout << "Enter Arist Name: " << endl;
		cin.getline(new_song.artist, 32); //>> totalSongs[songs].artist, 32;
		cout << "Enter Album Name: " << endl;
		cin.getline(new_song.albumName, 64);// totalSongs[songs].albumName, 64;
		cout << "Enter Track Number: " << endl;
		cin >> new_song.trackNum;
		cout << "Enter Release Year: " << endl;
		cin >> new_song.releaseYear;
		string genre;
		cout << "Enter genre: " << endl;
		std::getline(cin, genre);

		//new_song.genre = string convertStringToGenre(genre);
		MusicDatabase::addSongToDatabase(new_song);
	}


void listDatabase()
{
	int total_songs = MusicDatabase::getTotalSongsInDatabase();
	for (int idx = 0; idx < total_songs; idx++)
		Song song = MusicDatabase::getSongAtIndex(idx);
		cout << "The songs currently in the database are: /n" << total_songs << endl;
}

void helpMenu()
	{
		cout << "add: Add a new song to database." << endl;
		cout << "list: List song(s) currently in database." << endl;
		cout << "save: Save the music database." << endl;
		cout << "help: Display this menu." << endl;
		cout << "exit: Exit the database." << endl;
	}



namespace MusicDatabase
{
	vector<Song> songDatabase;
	const string DatabaseFilename = "Music.db";

	// Function to add a song to the MusicDatabase
	void addSongToDatabase(Song song)
	{
		songDatabase.push_back(song);
	}

	// Function to ask how many songs are in the MusicDatabase
	int getTotalSongsInDatabase()
	{
		return songDatabase.size();
	}

	// Function to get a song at a specific location in the MusicDatabase
	Song getSongAtIndex(int index)
	{
		if (index < getTotalSongsInDatabase())
		{
			return songDatabase[index];
		}
		else
		{
			throw new out_of_range("Invalid index into MusicDatabase");
		}
	}
	// Function to load the database from file
	void loadDatabase()
	{
		ifstream file(DatabaseFilename, ios_base::binary);

		int count = 0;
		file >> count;

		for (int x = 0; x < count; x++)
		{
			Song song;
			file.read((char*)& song, sizeof(Song));
			songDatabase.push_back(song);
		}

		file.close();
	}
	// Function to save the database to file
	void saveDatabase()
	{
		ofstream file(DatabaseFilename, ios_base::trunc | ios_base::binary);
		file << getTotalSongsInDatabase();

		auto itr = songDatabase.begin();
		while (itr != songDatabase.end())
		{
			Song song = *itr;
			/*
			file << song.title;
			file << song.artist;
			file << song.album;
			file << song.track;
			file << song.year;
			file << song.genre;
			*/
			file.write((const char*)& song, sizeof(Song));
			itr++;
		}

		file.close();
	}
}