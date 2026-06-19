#include "ModuleAndPluginCharacter.h"
#include "TestActor.h"
#include "../../Plugins/Temporary/Source/Temporary/Public/CharacterData.h"
#include "Engine/World.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/Controller.h"

AModuleAndPluginCharacter::AModuleAndPluginCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	// 카메라 붐 생성 (충돌 발생 시 플레이어 쪽으로 당겨짐)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	// 이 거리에서 카메라가 캐릭터를 따라감
	CameraBoom->TargetArmLength = 300.0f; 
	// 컨트롤러 회전에 따라 암(Arm) 회전
	CameraBoom->bUsePawnControlRotation = true; 

	// 팔로우 카메라 생성
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	// 카메라를 붐 끝에 부착하고, 붐이 컨트롤러 방향에 맞게 조정되도록 함
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); 
	// 카메라는 암과 상대적으로 회전하지 않음
	FollowCamera->bUsePawnControlRotation = false; 
}

void AModuleAndPluginCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AModuleAndPluginCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AModuleAndPluginCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}

void AModuleAndPluginCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AModuleAndPluginCharacter::MoveRight(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		AddMovementInput(Direction, Value);
	}
}

void AModuleAndPluginCharacter::BeginPlay()
{
	Super::BeginPlay();

	// 필수 기능 4: Test 모듈에서 TestActor 생성
	FVector SpawnLocation = GetActorLocation() + GetActorForwardVector() * 200.0f;
	GetWorld()->SpawnActor<ATestActor>(ATestActor::StaticClass(), SpawnLocation, FRotator::ZeroRotator);

	// 도전 기능: Temporary 플러그인에서 CharacterData 사용
	MyData = NewObject<UCharacterData>(this);
	if (MyData)
	{
		FString Message = FString::Printf(TEXT("Character Data - Name: %s, Level: %d"), *MyData->CharacterName, MyData->Level);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *Message);
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Cyan, Message);
		}
	}
}
