#include <iostream>
#include <string>
#include "MusicDB.h"
#include "Song.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>
#include <array>
#include <vector>
using namespace MusicDatabase;
using namespace std;
string getCommandFromUser();

Genre convertStringToGenre(string genre_string)
{
	Genre genre;


	//transform(genre.begin(), genre.end(), genre.begin(),
		//[](unsigned char c) {return tolower(c); });

	//convert here
	if (genre_string == "blues") {

		genre = Genre::Blues;  
	}
	else if (genre_string == "country") {
		genre = Genre::Country;
	}
	else if (genre_string == "electronic") {
		genre = Genre::Electronic;
	}
	else if (genre_string == "folk") {
		genre = Genre::Folk;
	}
	else if (genre_string == "HipHop") {
		genre = Genre::HipHop;
	}
	else if (genre_string == "Jazz") {
		genre = Genre::Jazz;
	}
	else if (genre_string == "Latin") {
		genre = Genre::Latin;
	}
	else if (genre_string == "Pop") {
		genre = Genre::Pop;
	}
	if (genre_string == "Rock") {
		genre = Genre::Rock;
	}



	return genre;

}



string convertGenreToString(Genre genre)

{
	string return_value;
	//switch statment start point
	switch (genre) {
	case Blues:
		return_value = "Blues";
		return return_value;
		break;
	case Country:
		return_value = "Country";
		return return_value;
		break;
	case Electronic:
		return_value = "Electronic";
		return return_value;
		break;
	case Folk:
		return_value = "Folk";
		break;
	case HipHop:
		return_value = "HipHop";
		return return_value;
		break;
	case Jazz:
		return_value = "Jazz";
		return return_value;
		break;
	case Latin:
		return_value = "Latin";
		return return_value;
		break;
	case Pop:
		return_value = "Pop";
		return return_value;
		break;
	case Rock:
		return_value = "Rock";
		return return_value;
		break;
	}
	//switch statment end brackets 
}
	int main()
{
	//Song songs[8];
	cout << "add: Add a new song to database." << endl;
	cout << "list: List song(s) currently in database." << endl;
	cout << "save: Save the music database." << endl;
	cout << "help: Display this menu." << endl;
	cout << "exit: Exit the database." << endl;




	string user_input;

	while (user_input != "exit")
	{
		cin >> user_input;
		if (user_input == "add")
		{
			addToDatabase();
		}
		else if (user_input == "help")
		{
			helpMenu();
		}
		else if (user_input == "list")
		{
			listDatabase();

		}
		/*else if (user_input == "save")
		{
			saveSong(Song songs);
		}
		else if (user_input == "get")
		{
			getTotalNumberOfSongs();
		}*/
	}
}
		
	
	//string getCommandFromUser()
	//{

	//}
	


		