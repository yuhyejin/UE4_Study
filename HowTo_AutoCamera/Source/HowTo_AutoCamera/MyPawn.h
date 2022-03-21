// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyPawn.generated.h"

UCLASS()
class HOWTO_AUTOCAMERA_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	AMyPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// ������Ʈ�� ��� ������ ����
	UPROPERTY(EditAnywhere)
	USceneComponent* OurVisibleComponent;

	// �Է� �Լ�
	void Move_XAxis(float AxisValue);
	void Move_YAxis(float AxisValue);
	void StartGrowing();
	void StopGrowing();

	// �Է� �Լ�
	FVector CurrentVelocity;
	bool bGrowing;

	float InputTime;
};
