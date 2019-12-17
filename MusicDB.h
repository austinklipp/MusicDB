#pragma once 
#include "song.h"
#include <vector>


void addToDatabase(); //function to add song to database 
void listDatabase(); //function to list songs in database
//void saveSong (Song songs[]); //function to save a song to database 
void helpMenu();  //function to display command menu when prompted by user 
//int getTotalNumberOfSongs ();//function to display total number of songs in database
//void getSongInfo(int a);//get song info from index position?*/
 Song getSongatIndex(int index);


namespace MusicDatabase
{
	// Function to add a song to the MusicDatabase
	void addSongToDatabase(Song song);

	// Function to ask how many songs are in the MusicDatabase
	int getTotalSongsInDatabase();

	// Function to get a song at a specific location in the MusicDatabase
	Song getSongAtIndex(int index);

	// Function to load the database from file
	void loadDatabase();

	// Function to save the database to file
	void saveDatabase();
}