#include "TestActor.h"

ATestActor::ATestActor()
{
	// 액터가 매 프레임 업데이트되도록 설정
	PrimaryActorTick.bCanEverTick = true;
}

void ATestActor::BeginPlay()
{
	Super::BeginPlay();
	
	// 테스트 모듈에서 액터가 생성되었음을 로그로 출력
	UE_LOG(LogTemp, Warning, TEXT("TestActor from Test Module spawned!"));
	if (GEngine)
	{
		// 화면에 디버그 메시지 표시
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("TestActor from Test Module spawned!"));
	}
}
