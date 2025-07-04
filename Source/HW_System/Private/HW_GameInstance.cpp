// Fill out your copyright notice in the Description page of Project Settings.

#include "HW_GameInstance.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

UHW_GameInstance::UHW_GameInstance()
    : bIsInitialized(false)
    , bIsCleaningUp(false)
{
    // 생성자에서 초기화
}

void UHW_GameInstance::Init()
{
    Super::Init();

    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::Init() called"));

    if (bIsInitialized)
    {
        UE_LOG(LogTemp, Warning, TEXT("HW_GameInstance already initialized"));
        return;
    }

    // 게임 인스턴스 초기화 로직
    InitializeGameSystems_Implementation();

    // 블루프린트 이벤트 호출
    InitializeGameSystems();

    bIsInitialized = true;

    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance initialization completed"));
}

void UHW_GameInstance::Shutdown()
{
    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::Shutdown() called"));

    if (!bIsCleaningUp)
    {
        bIsCleaningUp = true;

        // C++ 정리 작업
        CleanupGameSystems_Implementation();

        // 블루프린트 이벤트 호출
        CleanupGameSystems();
    }

    Super::Shutdown();
}

void UHW_GameInstance::BeginDestroy()
{
    UE_LOG(LogTemp, Warning, TEXT("HW_GameInstance::BeginDestroy() called - Name: %s"),
        *GetName());

    // 중복 호출 방지 및 유효성 검사
    if (HasAnyFlags(RF_BeginDestroyed))
    {
        UE_LOG(LogTemp, Warning, TEXT("HW_GameInstance::BeginDestroy() already called, skipping"));
        Super::BeginDestroy();
        return;
    }

    if (!IsValidLowLevel())
    {
        UE_LOG(LogTemp, Error, TEXT("HW_GameInstance::BeginDestroy() - Object is not valid"));
        Super::BeginDestroy();
        return;
    }

    // 안전한 정리 작업
    if (!bIsCleaningUp)
    {
        bIsCleaningUp = true;
        CleanupGameSystems_Implementation();
    }

    UE_LOG(LogTemp, Warning, TEXT("HW_GameInstance calling Super::BeginDestroy()"));

    // 반드시 부모 클래스의 BeginDestroy() 호출
    Super::BeginDestroy();
}

void UHW_GameInstance::OnStart()
{
    Super::OnStart();

    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::OnStart() called"));

    // 게임 시작 시 로직
}

void UHW_GameInstance::LoadComplete(const float LoadTime, const FString& MapName)
{
    Super::LoadComplete(LoadTime, MapName);

    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::LoadComplete() - Map: %s, Time: %f"),
        *MapName, LoadTime);
}

void UHW_GameInstance::InitializeGameSystems_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::InitializeGameSystems_Implementation() called"));

    // C++ 게임 시스템 초기화 로직
    // 예시:
    /*
    if (!CustomManagerPtr)
    {
        CustomManagerPtr = NewObject<UCustomManager>(this);
        if (CustomManagerPtr)
        {
            CustomManagerPtr->Initialize();
        }
    }
    */
}

void UHW_GameInstance::CleanupGameSystems_Implementation()
{
    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::CleanupGameSystems_Implementation() called"));

    // 모든 관리하는 객체들을 안전하게 정리
    /*
    if (CustomManagerPtr && IsValid(CustomManagerPtr))
    {
        CustomManagerPtr->Shutdown();
        CustomManagerPtr = nullptr;
    }

    // 배열 정리
    ManagedObjects.Empty();

    // 델리게이트 바인딩 해제
    if (OnGameInstanceReady.IsBound())
    {
        OnGameInstanceReady.Clear();
    }
    */

    bIsInitialized = false;
}

void UHW_GameInstance::LogGameInstanceState() const
{
    UE_LOG(LogTemp, Log, TEXT("=== HW_GameInstance State ==="));
    UE_LOG(LogTemp, Log, TEXT("Name: %s"), *GetName());
    UE_LOG(LogTemp, Log, TEXT("IsInitialized: %s"), bIsInitialized ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Log, TEXT("IsCleaningUp: %s"), bIsCleaningUp ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Log, TEXT("IsValid: %s"), IsValid(this) ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Log, TEXT("HasBeginDestroyed: %s"), HasAnyFlags(RF_BeginDestroyed) ? TEXT("true") : TEXT("false"));
    UE_LOG(LogTemp, Log, TEXT("=============================="));
}

#if WITH_EDITOR
void UHW_GameInstance::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
    Super::PostEditChangeProperty(PropertyChangedEvent);

    // 에디터에서 속성 변경 시 처리
    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance property changed in editor"));
}
#endif