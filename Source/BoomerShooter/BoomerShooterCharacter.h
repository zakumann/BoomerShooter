// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GamePlayTagContainer.h"
#include "GameplayEffectTypes.h"
#include "AbilitySystemInterface.h"
#include "BoomerShooterCharacter.generated.h"

UCLASS()
class BOOMERSHOOTER_API ABoomerShooterCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Abilities, meta = (AllowPrivateAccess = "true"))
	class UAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	class UBoomerShooterAttributeSet* Attributes;

public:
	// Sets default values for this character's properties
	ABoomerShooterCharacter();

	// Ovberride from IAbilitySystemInterface.
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxHealth = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxArmor = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxBullets = 200;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxRockets = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	int MaxShells = 50;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
/*	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;*/

	// Effect that initializes our default attributes
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RetroFPS")
	TSubclassOf<class UGameplayEffect> DefaultAttributeEffect;

	// Array of starting abilities
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "RetroFPS")
	TArray<TSubclassOf<class UGameplayAbility>> DefaultAbilities;
};
