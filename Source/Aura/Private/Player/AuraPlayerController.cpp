// Fill out your copyright notice in the Description page of Project Settings.

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/PlayerController.h"
#include "Player/AuraPlayerController.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
	//
}

//만약 멀티플레이 게임이라면 자기 자신의 플레이어 컨트롤러에서만 플레이어 틱이 호출된다는 것이다.
void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
}


void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);

	UEnhancedInputLocalPlayerSubsystem* subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(subsystem);
	subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;

	//FInputModeGameAndUI : 입력 모드도 설정할 수 있습니다.
	/*이제 입력 모드 게임과 UI 구조체는 입력 모드 구조체이며, 이 입력 모드를 사용한다면
	키보드와 마우스의 입력을 사용할 수 있으며 입력을 사용하여 위젯과 같은 UI에 영향을 줄 수 있습니다.*/

	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& Value)
{
	const FVector2D InputAxisVector = Value.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0, Rotation.Yaw, 0);

	const FVector forwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector rightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControllerPawn = GetPawn<APawn>())
	{
		ControllerPawn->AddMovementInput(forwardDirection, InputAxisVector.Y);
		ControllerPawn->AddMovementInput(rightDirection, InputAxisVector.X);
	}

}

void AAuraPlayerController::CursorTrace()
{
}
