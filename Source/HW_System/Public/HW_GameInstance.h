// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "HW_GameInstance.generated.h"

/**
 * Custom Game Instance class for HW System
 * Handles game-wide initialization, cleanup, and system management
 */
UCLASS(BlueprintType, Blueprintable)
class HW_SYSTEM_API UHW_GameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// 생성자
	UHW_GameInstance();

	// UGameInstance 오버라이드
	virtual void Init() override;
	virtual void Shutdown() override;
	virtual void BeginDestroy() override;
	virtual void OnStart() override;
	virtual void LoadComplete(const float LoadTime, const FString& MapName) override;

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif

protected:
	/**
	 * 게임 시스템들을 초기화합니다.
	 * Init() 단계에서 호출됩니다.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "HW Game Instance")
	void InitializeGameSystems();

	/**
	 * 게임 시스템들을 정리합니다.
	 * Shutdown() 및 BeginDestroy() 단계에서 호출됩니다.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "HW Game Instance")
	void CleanupGameSystems();

	/**
	 * 게임 시스템들을 초기화합니다. (C++ 구현)
	 */
	virtual void InitializeGameSystems_Implementation();

	/**
	 * 게임 시스템들을 정리합니다. (C++ 구현)
	 */
	virtual void CleanupGameSystems_Implementation();

private:
	/**
	 * 게임 인스턴스 초기화 완료 여부
	 */
	UPROPERTY()
	bool bIsInitialized;

	/**
	 * 정리 작업 진행 여부 (중복 방지용)
	 */
	UPROPERTY()
	bool bIsCleaningUp;

	// 예시: 커스텀 매니저들을 관리하는 포인터들
	/*
	UPROPERTY()
	TObjectPtr<class UCustomManager> CustomManagerPtr;

	UPROPERTY()
	TArray<TObjectPtr<UObject>> ManagedObjects;

	// 델리게이트 예시
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameInstanceReady);
	UPROPERTY(BlueprintAssignable, Category = "HW Game Instance")
	FOnGameInstanceReady OnGameInstanceReady;
	*/

public:
	// 블루프린트에서 접근 가능한 함수들
	UFUNCTION(BlueprintCallable, Category = "HW Game Instance")
	bool IsGameInstanceInitialized() const { return bIsInitialized; }

	UFUNCTION(BlueprintCallable, Category = "HW Game Instance")
	bool IsGameInstanceCleaningUp() const { return bIsCleaningUp; }

	// 디버깅용 함수
	UFUNCTION(BlueprintCallable, Category = "HW Game Instance|Debug")
	void LogGameInstanceState() const;
};