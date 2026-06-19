#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ModuleAndPluginCharacter.generated.h"

UCLASS()
class MODULEANDPLUGIN_API AModuleAndPluginCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AModuleAndPluginCharacter();

protected:
	virtual void BeginPlay() override;

	// 앞뒤 이동 입력 처리
	void MoveForward(float Value);

	// 좌우 이동 입력 처리
	void MoveRight(float Value);

	// 지정된 속도로 회전 입력 처리
	void TurnAtRate(float Rate);

	// 지정된 속도로 위아래 보기 입력 처리
	void LookUpAtRate(float Rate);

protected:
	// APawn 인터페이스
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// APawn 인터페이스 끝

public:
	// 카메라 붐 (캐릭터 뒤에 카메라 위치)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	// 팔로우 카메라
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY()
	class UCharacterData* MyData;
};
