// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonrComponent.h"
#include "Engine.h"


// Sets default values for this component's properties
UJsonrComponent::UJsonrComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	

	// ...
}


// Called when the game starts
void UJsonrComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UJsonrComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UJsonrComponent::ReadJson(FString FileName)
{
	return FFileHelper::LoadFileToString(JsonStr, *(FPaths::GameDir() + FileName));
}

void UJsonrComponent::JosnRead(FString JosnString, FString & Name, FString & SkillId, FString SkillName, FString & SkillImage)
{
	TArray<TSharedPtr<FJsonValue>> JsonParsed;

	//∂¡»°Json
	TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonStr);
	if (FJsonSerializer::Deserialize(JsonReader, JsonParsed))

	{

		for (int32 i = 0; i < JsonParsed.Num(); i++)
		{
			FString NameArray[100], FStringSkillIdArray[100], FStringSkillNameArray[100], FstrinngSkillImageArray[100];
			FString Name = JsonParsed[i]->AsObject()->GetStringField("Name");
			NameArray[i] = Name;
			FString FStringSkillId = JsonParsed[i]->AsObject()->GetStringField("SkillId");
			FStringSkillIdArray[i] = FStringSkillId;
			FString FStringSkillName = JsonParsed[i]->AsObject()->GetStringField("SkillName");
			FStringSkillNameArray[i] = FStringSkillName;
			FString FstrinngSkillImage = JsonParsed[i]->AsObject()->GetStringField("SkillImage");
			FstrinngSkillImageArray[i] = FstrinngSkillImage;
			FString tempString = "Name= " + Name + " ,SkillId = " + FStringSkillId + ",SkillName=" + FStringSkillName + ",SkillImage" + FstrinngSkillImage;
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, tempString);


		}

	}

}
	



