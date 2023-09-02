// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/PCPictureCameraComponent.h"


#include "Components/SceneCaptureComponent2D.h"
#include "Kismet/KismetRenderingLibrary.h"


// Sets default values for this component's properties
UPCPictureCameraComponent::UPCPictureCameraComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;


	
}


// Called when the game starts
void UPCPictureCameraComponent::BeginPlay()
{
	Super::BeginPlay();
		
}

bool UPCPictureCameraComponent::ShotAndStore(USceneCaptureComponent2D* PictureCameraCaptureComponent2D)
{
	auto Picture = Shot(PictureCameraCaptureComponent2D);
	return Store(Picture,AlbumDataAsset);
}

FPCPicture UPCPictureCameraComponent::Shot(USceneCaptureComponent2D* PictureCameraCaptureComponent2D)
{

	PictureCameraCaptureComponent2D->bCaptureEveryFrame = false;
	PictureCameraCaptureComponent2D->bCaptureOnMovement = false;
	
	UTextureRenderTarget2D* TextureRender = UKismetRenderingLibrary::CreateRenderTarget2D(GetWorld(),PictureWidth,PictureHeight);
	PictureCameraCaptureComponent2D->TextureTarget = TextureRender;

	PictureCameraCaptureComponent2D->CaptureScene();

	FPCPicture Picture;
	Picture.Texture = TextureRender;
	Picture.DateTime = FDateTime::Now();
	Picture.Transform = PictureCameraCaptureComponent2D->GetComponentTransform();

	return Picture;
}

bool UPCPictureCameraComponent::Store(FPCPicture& Picture, UUPCPicturesDataAsset* DataAsset)
{
	return(DataAsset->Pictures.Add(Picture)!=0);
}


