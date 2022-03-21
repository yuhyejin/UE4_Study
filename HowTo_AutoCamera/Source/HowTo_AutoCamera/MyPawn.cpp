// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <Engine/Classes/Camera/CameraComponent.h>

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// �� ���� ��ȣ�� 0���� �÷��̾ �����ϵ��� �����Ѵ�.
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// ���𰡸� ���� ���� ��Ʈ ������Ʈ�� �����.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// ī�޶�� ���̴� ������Ʈ�� �����.
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	// ��Ʈ ������Ʈ�� ī�޶�� ���̴� ������Ʈ�� ���δ�. ī�޶� �̰� �� ȸ����Ų��.
	OurCamera->SetupAttachment(RootComponent);
	OurCamera->SetRelativeLocation(FVector(-250.f, 0.0f, 250.0f));
	OurCamera->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	OurVisibleComponent->SetupAttachment(RootComponent);
}

void AMyPawn::BeginPlay()
{
	Super::BeginPlay();

}

void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	{
		float CurrentScale = OurVisibleComponent->GetComponentScale().X;
		if (bGrowing)
		{
			if(InputTime > 0.0f && InputTime <= 0.5f)
			{
				CurrentScale = 2.0f;
			}
			else
			{
				// 1�ʿ� ���� �ι� ũ��� Ű���.
				CurrentScale += DeltaTime;
			}
		}
		else
		{
			// Ű�� �ӵ���� �������� ���δ�.
			CurrentScale -= (DeltaTime * 0.5f);
		}
		// ���� ũ�� �Ʒ��� ���̰ų� �� �� �̻����� Ű���� �ʵ��� �Ѵ�.
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
	}

	// "MoveX" �� "MoveY" �࿡ ���� �̵��� ó���Ѵ�.
	{
		if (!CurrentVelocity.IsZero()) 
		{
			InputTime += DeltaTime;
			float a = InputTime * 5.0f;
			FVector NewLocation = GetActorLocation() + (CurrentVelocity * DeltaTime * a);
			SetActorLocation(NewLocation);
		}
		else
		{
			InputTime = 0.0f;
		}
	}
}

void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// "Grow" Ű�� �����ų� �� �� �����Ѵ�.
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	// "MoveX" �� "MoveY" �� �̵� ���� ���� �� ������ �����Ѵ�.
	InputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);
}

void AMyPawn::Move_XAxis(float AxisValue) 
{
	// �ʴ� 100 ������ �� �Ǵ� �ڷ� �����δ�.
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::Move_YAxis(float AxisValue)
{
	// �ʴ� 100 ������ ������ �Ǵ� �������� �����δ�.
	CurrentVelocity.Y  = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::StartGrowing()
{
	bGrowing = true;
}

void AMyPawn::StopGrowing()
{
	bGrowing = false;
}