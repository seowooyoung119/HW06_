// Fill out your copyright notice in the Description page of Project Settings.

#include "HW_GameInstance.h"
#include "Engine/Engine.h"
#include "Engine/World.h"

UHW_GameInstance::UHW_GameInstance()
    : bIsInitialized(false)
    , bIsCleaningUp(false)
{
    // �����ڿ��� �ʱ�ȭ
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

    // ���� �ν��Ͻ� �ʱ�ȭ ����
    InitializeGameSystems_Implementation();

    // �������Ʈ �̺�Ʈ ȣ��
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

        // C++ ���� �۾�
        CleanupGameSystems_Implementation();

        // �������Ʈ �̺�Ʈ ȣ��
        CleanupGameSystems();
    }

    Super::Shutdown();
}

void UHW_GameInstance::BeginDestroy()
{
    UE_LOG(LogTemp, Warning, TEXT("HW_GameInstance::BeginDestroy() called - Name: %s"),
        *GetName());

    // �ߺ� ȣ�� ���� �� ��ȿ�� �˻�
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

    // ������ ���� �۾�
    if (!bIsCleaningUp)
    {
        bIsCleaningUp = true;
        CleanupGameSystems_Implementation();
    }

    UE_LOG(LogTemp, Warning, TEXT("HW_GameInstance calling Super::BeginDestroy()"));

    // �ݵ�� �θ� Ŭ������ BeginDestroy() ȣ��
    Super::BeginDestroy();
}

void UHW_GameInstance::OnStart()
{
    Super::OnStart();

    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance::OnStart() called"));

    // ���� ���� �� ����
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

    // C++ ���� �ý��� �ʱ�ȭ ����
    // ����:
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

    // ��� �����ϴ� ��ü���� �����ϰ� ����
    /*
    if (CustomManagerPtr && IsValid(CustomManagerPtr))
    {
        CustomManagerPtr->Shutdown();
        CustomManagerPtr = nullptr;
    }

    // �迭 ����
    ManagedObjects.Empty();

    // ��������Ʈ ���ε� ����
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

    // �����Ϳ��� �Ӽ� ���� �� ó��
    UE_LOG(LogTemp, Log, TEXT("HW_GameInstance property changed in editor"));
}
#endif