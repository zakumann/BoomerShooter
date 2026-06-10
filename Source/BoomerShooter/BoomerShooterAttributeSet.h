// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "BoomerShooterAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)\
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class BOOMERSHOOTER_API UBoomerShooterAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UBoomerShooterAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBoomerShooterAttributeSet, Health);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Armor;
	ATTRIBUTE_ACCESSORS(UBoomerShooterAttributeSet, Armor);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Bullets;
	ATTRIBUTE_ACCESSORS(UBoomerShooterAttributeSet, Bullets);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Rockets;
	ATTRIBUTE_ACCESSORS(UBoomerShooterAttributeSet, Rockets);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	FGameplayAttributeData Shells;
	ATTRIBUTE_ACCESSORS(UBoomerShooterAttributeSet, Shells);

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual bool PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
};
