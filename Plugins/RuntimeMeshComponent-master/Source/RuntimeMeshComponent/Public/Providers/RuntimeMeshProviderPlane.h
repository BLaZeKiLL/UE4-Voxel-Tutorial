// Copyright 2016-2020 Chris Conway (Koderz). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeMeshProvider.h"
#include "RuntimeMeshProviderPlane.generated.h"

/*
A - - - - B		Supply with A, B and C, D will be computed
|        /|		
       /  |
|    /    |
   /      |
|/        |
C - - - - D
*/

UCLASS(HideCategories = Object, BlueprintType)
class RUNTIMEMESHCOMPONENT_API URuntimeMeshProviderPlane : public URuntimeMeshProviderPassthrough
{
	GENERATED_BODY()

private:
	mutable FCriticalSection PropertySyncRoot;

	int32 MaxLOD;


	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	FVector LocationA;

	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	FVector LocationB;
	
	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	FVector LocationC;
	
	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	TArray<int32> VertsAB;
	
	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	TArray<int32> VertsAC;
	
	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	TArray<float> ScreenSize;

	UPROPERTY(Category = "RuntimeMesh|Providers|Sphere", EditAnywhere)
	UMaterialInterface* Material;

public:
	URuntimeMeshProviderPlane();

// 	FVector GetLocationA() const;
// 	void SetLocationA(const FVector& InLocationA);
// 	FVector GetLocationB() const;
// 	void SetLocationB(const FVector& InLocationB);
// 	FVector GetLocationC() const;
// 	void SetLocationC(const FVector& InLocationC);



protected:	
	virtual void Initialize_Implementation() override;
	virtual bool GetSectionMeshForLOD_Implementation(int32 LODIndex, int32 SectionId, FRuntimeMeshRenderableMeshData& MeshData) override;
	virtual FRuntimeMeshCollisionSettings GetCollisionSettings_Implementation() override;
	virtual FBoxSphereBounds GetBounds_Implementation() override;
	virtual bool IsThreadSafe_Implementation() override;

private:

	int32 GetMaximumPossibleLOD();
};
