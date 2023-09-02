// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "FPCPicture.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct PICTURECAMERA_API FPCPicture
{
 GENERATED_BODY()

 UPROPERTY(EditAnywhere,BlueprintReadOnly)
 TObjectPtr<UTextureRenderTarget2D> Texture;

 UPROPERTY(EditAnywhere,BlueprintReadOnly)
 FDateTime DateTime;

 UPROPERTY(EditAnywhere,BlueprintReadOnly)
 FTransform Transform;
 
};
