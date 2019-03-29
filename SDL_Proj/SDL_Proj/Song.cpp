#include "stdafx.h"

SoundManager::SoundManager()
{
	SoundManager::cmdType = 0;
	SoundManager::currentSong = 0;
	SoundManager::songMaxIndex = 0;
	SoundManager::songList = new const char*;
}

void SoundManager::AddSong(const char * songDir)
{
	songList[songMaxIndex++] = songDir;
}

void SoundManager::SongStateSet()
{
	char result[128] = "";
	strcat_s(result, (char*)state[cmdType]);
	strcat_s(result, (char*)songList[currentSong]);
	mciSendString(result, NULL, 0, NULL);
}

void SoundManager::ChangeCurrentSong(int SongID)
{
	//ChangeCurrentState(1);
	currentSong = SongID;
	//SongStateSet();
}

void SoundManager::ChangeCurrentState(int StateID)
{
	cmdType = StateID;
}

int SoundManager::GetCurrentSongID() {
	return currentSong;
}

int SoundManager::GetCurrentMaxIndex() {
	return songMaxIndex - 1;
}

void SoundManager::Release()
{
	delete songList;
}

SoundManager::~SoundManager()
{
}
