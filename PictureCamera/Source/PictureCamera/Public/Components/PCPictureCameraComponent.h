// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UPCPicturesDataAsset.h"
#include "Components/ActorComponent.h"
#include "Structs/FPCPicture.h"
#include "PCPictureCameraComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class PICTURECAMERA_API UPCPictureCameraComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPCPictureCameraComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	TObjectPtr<UUPCPicturesDataAsset> AlbumDataAsset;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta=(ClampMin=0), Category="Picture Resolution")
	int32 PictureWidth = 1920;

	UPROPERTY(EditAnywhere,BlueprintReadWrite, meta=(ClampMin=0), Category="Picture Resolution")
	int32 PictureHeight = 1080;

	UFUNCTION(BlueprintCallable)
	bool ShotAndStore(USceneCaptureComponent2D* PictureCameraCaptureComponent2D);

	UFUNCTION(BlueprintCallable)
	FPCPicture Shot(USceneCaptureComponent2D* PictureCameraCaptureComponent2D);
	
	UFUNCTION(BlueprintCallable)
	bool Store(FPCPicture& Picture,UUPCPicturesDataAsset* DataAsset);

	
};
