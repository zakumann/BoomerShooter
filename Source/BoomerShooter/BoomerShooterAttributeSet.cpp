// Fill out your copyright notice in the Description page of Project Settings.


#include "BoomerShooterAttributeSet.h"
#include "BoomerShooterCharacter.h"

UBoomerShooterAttributeSet::UBoomerShooterAttributeSet()
{

}

void UBoomerShooterAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	ABoomerShooterCharacter* RetroChar = Cast<ABoomerShooterCharacter>(GetOwningActor());

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, RetroChar->MaxHealth);
	}
	else if (Attribute == GetArmorAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, RetroChar->MaxArmor);
	}
	else if (Attribute == GetBulletsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, RetroChar->MaxBullets);
	}
	else if (Attribute == GetRocketsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, RetroChar->MaxRockets);
	}
	else if (Attribute == GetShellsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, RetroChar->MaxShells);
	}
	else if (Attribute == GetHeavyBulletsAttribute())
	{
		NewValue = FMath::Clamp<float>(NewValue, 0, RetroChar->MaxHeavyBullets);
	}
}

bool UBoomerShooterAttributeSet::PreGameplayEffectExecute(struct FGameplayEffectModCallbackData& Data)
{
	float AbsoluteMagnitude = FMath::Abs(Data.EvaluatedData.Magnitude);

	ABoomerShooterCharacter* RetroChar = Cast<ABoomerShooterCharacter>(GetOwningActor());

	if (Data.EvaluatedData.Magnitude > 0)
	{
		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() + AbsoluteMagnitude >= RetroChar->MaxArmor)
		{
			SetArmor(RetroChar->MaxArmor);
			return false;
		}

		else if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() + AbsoluteMagnitude >= RetroChar->MaxHealth)
		{
			SetHealth(RetroChar->MaxHealth);
			return false;
		}

		else if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() + AbsoluteMagnitude >= RetroChar->MaxBullets)
		{
			SetBullets(RetroChar->MaxBullets);
			return false;

		}
		else if (Data.EvaluatedData.Attribute == GetRocketsAttribute() && GetRockets() + AbsoluteMagnitude >= RetroChar->MaxRockets)
		{
			SetRockets(RetroChar->MaxRockets);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetShellsAttribute() && GetShells() + AbsoluteMagnitude >= RetroChar->MaxShells)
		{
			SetShells(RetroChar->MaxShells);
			return false;
		}
		else if (Data.EvaluatedData.Attribute == GetHeavyBulletsAttribute() && GetHeavyBullets() + AbsoluteMagnitude >= RetroChar->MaxHeavyBullets)
		{
			SetHeavyBullets(RetroChar->MaxHeavyBullets);
			return false;
		}
	}
	else
	{

		if (Data.EvaluatedData.Attribute == GetArmorAttribute() && AbsoluteMagnitude > GetArmor())
		{
			Health.SetCurrentValue(Health.GetCurrentValue() - (AbsoluteMagnitude - GetArmor()));
		}
	}
	return true;
}

void UBoomerShooterAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	if (Data.EvaluatedData.Attribute == GetHealthAttribute() && GetHealth() < 0)
	{
		SetHealth(0);
	}
	else if (Data.EvaluatedData.Attribute == GetArmorAttribute() && GetArmor() < 0)
	{
		SetArmor(0);
	}
	else if (Data.EvaluatedData.Attribute == GetBulletsAttribute() && GetBullets() < 0)
	{
		SetBullets(0);
	}
	else if (Data.EvaluatedData.Attribute == GetRocketsAttribute() && GetRockets() < 0)
	{
		SetRockets(0);
	}
	else if (Data.EvaluatedData.Attribute == GetShellsAttribute() && GetShells() < 0)
	{
		SetShells(0);
	}
	else if (Data.EvaluatedData.Attribute == GetHeavyBulletsAttribute() && GetHeavyBullets() < 0)
	{
		SetHeavyBullets(0);
	}
}
