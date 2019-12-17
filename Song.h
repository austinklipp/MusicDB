#pragma once
enum Genre

{
	Blues = 0,//0
	Country,//1
	Electronic,//2
	Folk,//3
	HipHop,//4
	Jazz, //5
	Latin,//6
	Pop,//7
	Rock,//8
};

//const int MAX_CHARS_PER_TITLE = 64; 

struct Song
{
	char title[64];
	char artist[32];
	char albumName[64];
	int trackNum;
	int releaseYear;
	Genre genre;


}; 
