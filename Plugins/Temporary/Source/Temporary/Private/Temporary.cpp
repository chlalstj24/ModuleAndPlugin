#include "Temporary.h"

#define LOCTEXT_NAMESPACE "FTemporaryModule"

void FTemporaryModule::StartupModule()
{
	// 플러그인 모듈 시작 시 로그 출력
	UE_LOG(LogTemp, Warning, TEXT("Temporary Plugin Module Started!"));
}

void FTemporaryModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FTemporaryModule, Temporary)
