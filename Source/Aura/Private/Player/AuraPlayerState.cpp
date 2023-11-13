// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	NetUpdateFrequency = 100.0f;
	//how often the server will try to update clients.
	//So as changes occur on the server for the player state, then the server will be sending updates out to all clients so that they can sync up with the server version.
	//
}
