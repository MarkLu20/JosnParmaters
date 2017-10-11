// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
//#include "Runtime/XmlParser/Public/XmlParser.h"
#include "Json.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpRequest.h"
#include "Runtime/Online/HTTP/Private/HttpTests.h"
#include "Runtime/Online/HTTP/Public/HttpModule.h"
#include "Runtime/Online/HTTP/Public/Interfaces/IHttpResponse.h"
#include "Misc/Paths.h"
#include "JsonrComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JOSNPARMATERS_API UJsonrComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJsonrComponent();
	FString JsonStr;
	int32  dc;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = "Json")
		void JosnRead(FString JosnString ,FString &Name,FString &SkillId,FString SkillName,FString &SkillImage);
	UFUNCTION(BlueprintCallable, Category = "Josn")
		bool ReadJson(FString FileName);
};
