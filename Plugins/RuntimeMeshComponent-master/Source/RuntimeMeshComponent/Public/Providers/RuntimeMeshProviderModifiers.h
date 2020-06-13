// Copyright 2016-2020 Chris Conway (Koderz). All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "RuntimeMeshProvider.h"
#include "RuntimeMeshModifier.h"
#include "RuntimeMeshProviderModifiers.generated.h"


UCLASS(HideCategories = Object, BlueprintType)
class RUNTIMEMESHCOMPONENT_API URuntimeMeshProviderModifiers : public URuntimeMeshProviderPassthrough
{
	GENERATED_BODY()
private:
	UPROPERTY()
	TArray<URuntimeMeshModifier*> Modifiers;

public:

	UFUNCTION(Category = "RuntimeMesh|Providers|Modifiers", BlueprintCallable)
	void AddModifier(URuntimeMeshModifier* NewModifier);

	UFUNCTION(Category = "RuntimeMesh|Providers|Modifiers", BlueprintCallable)
	void RemoveModifier(URuntimeMeshModifier* ModifierToRemove);


protected:
	bool GetSectionMeshForLOD_Implementation(int32 LODIndex, int32 SectionId, FRuntimeMeshRenderableMeshData& MeshData) override;
	bool GetAllSectionsMeshForLOD_Implementation(int32 LODIndex, TMap<int32, FRuntimeMeshSectionData>& MeshDatas) override;
	bool GetCollisionMesh_Implementation(FRuntimeMeshCollisionData& CollisionData) override;

private:
	void ApplyModifiers(FRuntimeMeshRenderableMeshData& MeshData);
	void ApplyModifiers(FRuntimeMeshCollisionData& CollisionData);

};