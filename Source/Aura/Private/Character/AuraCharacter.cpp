 // Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"		//GetCharacterMovement 사용하려면 선언
#include "Character/AuraCharacter.h"
#include "Player/AuraPlayerState.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 400.0f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

//c
void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
}

void AAuraCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}
 
void AAuraCharacter::InitAbilityActorInfo()
{
	/*AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);

	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	//state를 가져와서 체크하고 초기화 하는데 사용
	//state가AbilityActor의 owner이기때문에 
	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	AttributeSet = AuraPlayerState->GetAttributeSet();*/
}
