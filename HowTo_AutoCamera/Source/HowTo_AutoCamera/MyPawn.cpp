// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPawn.h"
#include <Engine/Classes/Camera/CameraComponent.h>

AMyPawn::AMyPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	// 이 폰을 번호가 0번인 플레이어가 조종하도록 설정한다.
	AutoPossessPlayer = EAutoReceiveInput::Player0;

	// 무언가를 붙일 더미 루트 컴포넌트를 만든다.
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

	// 카메라와 보이는 오브젝트를 만든다.
	UCameraComponent* OurCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("OurCamera"));
	OurVisibleComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OurVisibleComponent"));

	// 루트 컴포넌트에 카메라와 보이는 오브젝트를 붙인다. 카메라를 이격 및 회전시킨다.
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
				// 1초에 걸쳐 두배 크기로 키운다.
				CurrentScale += DeltaTime;
			}
		}
		else
		{
			// 키운 속도대로 절반으로 줄인다.
			CurrentScale -= (DeltaTime * 0.5f);
		}
		// 시작 크기 아래로 줄이거나 두 배 이상으로 키우지 않도록 한다.
		CurrentScale = FMath::Clamp(CurrentScale, 1.0f, 2.0f);
		OurVisibleComponent->SetWorldScale3D(FVector(CurrentScale));
	}

	// "MoveX" 와 "MoveY" 축에 따라 이동을 처리한다.
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

	// "Grow" 키를 누르거나 뗄 때 반응한다.
	InputComponent->BindAction("Grow", IE_Pressed, this, &AMyPawn::StartGrowing);
	InputComponent->BindAction("Grow", IE_Released, this, &AMyPawn::StopGrowing);

	// "MoveX" 와 "MoveY" 두 이동 층의 값에 매 프레임 반응한다.
	InputComponent->BindAxis("MoveX", this, &AMyPawn::Move_XAxis);
	InputComponent->BindAxis("MoveY", this, &AMyPawn::Move_YAxis);
}

void AMyPawn::Move_XAxis(float AxisValue) 
{
	// 초당 100 유닛을 앞 또는 뒤로 움직인다.
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.0f, 1.0f) * 100.0f;
}

void AMyPawn::Move_YAxis(float AxisValue)
{
	// 초당 100 유닛을 오른쪽 또는 왼쪽으로 움직인다.
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