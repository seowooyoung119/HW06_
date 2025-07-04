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
	// ������
	UHW_GameInstance();

	// UGameInstance �������̵�
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
	 * ���� �ý��۵��� �ʱ�ȭ�մϴ�.
	 * Init() �ܰ迡�� ȣ��˴ϴ�.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "HW Game Instance")
	void InitializeGameSystems();

	/**
	 * ���� �ý��۵��� �����մϴ�.
	 * Shutdown() �� BeginDestroy() �ܰ迡�� ȣ��˴ϴ�.
	 */
	UFUNCTION(BlueprintImplementableEvent, Category = "HW Game Instance")
	void CleanupGameSystems();

	/**
	 * ���� �ý��۵��� �ʱ�ȭ�մϴ�. (C++ ����)
	 */
	virtual void InitializeGameSystems_Implementation();

	/**
	 * ���� �ý��۵��� �����մϴ�. (C++ ����)
	 */
	virtual void CleanupGameSystems_Implementation();

private:
	/**
	 * ���� �ν��Ͻ� �ʱ�ȭ �Ϸ� ����
	 */
	UPROPERTY()
	bool bIsInitialized;

	/**
	 * ���� �۾� ���� ���� (�ߺ� ������)
	 */
	UPROPERTY()
	bool bIsCleaningUp;

	// ����: Ŀ���� �Ŵ������� �����ϴ� �����͵�
	/*
	UPROPERTY()
	TObjectPtr<class UCustomManager> CustomManagerPtr;

	UPROPERTY()
	TArray<TObjectPtr<UObject>> ManagedObjects;

	// ��������Ʈ ����
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnGameInstanceReady);
	UPROPERTY(BlueprintAssignable, Category = "HW Game Instance")
	FOnGameInstanceReady OnGameInstanceReady;
	*/

public:
	// �������Ʈ���� ���� ������ �Լ���
	UFUNCTION(BlueprintCallable, Category = "HW Game Instance")
	bool IsGameInstanceInitialized() const { return bIsInitialized; }

	UFUNCTION(BlueprintCallable, Category = "HW Game Instance")
	bool IsGameInstanceCleaningUp() const { return bIsCleaningUp; }

	// ������ �Լ�
	UFUNCTION(BlueprintCallable, Category = "HW Game Instance|Debug")
	void LogGameInstanceState() const;
};