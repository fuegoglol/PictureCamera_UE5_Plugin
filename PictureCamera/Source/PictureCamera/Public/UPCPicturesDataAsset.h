// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Structs/FPCPicture.h"
#include "UPCPicturesDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PICTURECAMERA_API UUPCPicturesDataAsset : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	TArray<FPCPicture> Pictures;
};
