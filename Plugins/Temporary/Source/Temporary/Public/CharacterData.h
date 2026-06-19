#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterData.generated.h"

// 캐릭터 데이터 저장용 클래스
UCLASS(BlueprintType, Blueprintable)
class TEMPORARY_API UCharacterData : public UObject
{
	GENERATED_BODY()

public:
	UCharacterData();

	// 캐릭터 이름 저장용 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString CharacterName;

	// 캐릭터 레벨 저장용 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	int32 Level;
};
