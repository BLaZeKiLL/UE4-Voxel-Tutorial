// Copyright 2016-2020 Chris Conway (Koderz). All Rights Reserved.

#include "Components/RuntimeMeshComponentStatic.h"
#include "Providers/RuntimeMeshProviderStatic.h"
#include "Providers/RuntimeMeshProviderModifiers.h"
#include "Modifiers/RuntimeMeshModifierNormals.h"
#include "Modifiers/RuntimeMeshModifierAdjacency.h"

URuntimeMeshComponentStatic::URuntimeMeshComponentStatic(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// We can create our static provider here as a default subobject
	StaticProvider = CreateDefaultSubobject<URuntimeMeshProviderStatic>("StaticProvider");
}

void URuntimeMeshComponentStatic::OnRegister()
{
	Super::OnRegister();

	if (RuntimeMesh)
	{
		StaticProvider = CastChecked<URuntimeMeshProviderStatic>(RuntimeMesh->GetProvider());
		SetRuntimeMesh(RuntimeMesh);
	}
	else
	{
		Initialize(StaticProvider);
	}	
}

void URuntimeMeshComponentStatic::CreateSection_Blueprint(int32 LODIndex, int32 SectionId, const FRuntimeMeshSectionProperties & SectionProperties, const FRuntimeMeshRenderableMeshData & SectionData)
{
	StaticProvider->CreateSection_Blueprint(LODIndex, SectionId, SectionProperties, SectionData);
}

void URuntimeMeshComponentStatic::CreateSectionFromComponents(int32 LODIndex, int32 SectionIndex, int32 MaterialSlot, 
	const TArray<FVector>& Vertices, const TArray<int32>& Triangles, const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FVector2D>& UV1, const TArray<FVector2D>& UV2, 
	const TArray<FVector2D>& UV3, const TArray<FLinearColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents, ERuntimeMeshUpdateFrequency UpdateFrequency, bool bCreateCollision)
{
	StaticProvider->CreateSectionFromComponents(LODIndex, SectionIndex, MaterialSlot,
		Vertices, Triangles, Normals, UV0, UV1, UV2, UV3, VertexColors, Tangents, UpdateFrequency, bCreateCollision);
}

void URuntimeMeshComponentStatic::CreateSectionFromComponents(int32 LODIndex, int32 SectionIndex, int32 MaterialSlot, const TArray<FVector>& Vertices, const TArray<int32>& Triangles,
	const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FVector2D>& UV1, const TArray<FVector2D>& UV2, const TArray<FVector2D>& UV3, const TArray<FColor>& VertexColors,
	const TArray<FRuntimeMeshTangent>& Tangents, ERuntimeMeshUpdateFrequency UpdateFrequency, bool bCreateCollision)
{
	StaticProvider->CreateSectionFromComponents(LODIndex, SectionIndex, MaterialSlot,
		Vertices, Triangles, Normals, UV0, UV1, UV2, UV3, VertexColors, Tangents, UpdateFrequency, bCreateCollision);
}

void URuntimeMeshComponentStatic::CreateSectionFromComponents(int32 LODIndex, int32 SectionIndex, int32 MaterialSlot, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, 
	const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FLinearColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents,
	ERuntimeMeshUpdateFrequency UpdateFrequency, bool bCreateCollision)
{
	StaticProvider->CreateSectionFromComponents(LODIndex, SectionIndex, MaterialSlot,
		Vertices, Triangles, Normals, UV0, VertexColors, Tangents, UpdateFrequency, bCreateCollision);
}

void URuntimeMeshComponentStatic::CreateSectionFromComponents(int32 LODIndex, int32 SectionIndex, int32 MaterialSlot, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, 
	const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents,
	ERuntimeMeshUpdateFrequency UpdateFrequency, bool bCreateCollision)
{
	StaticProvider->CreateSectionFromComponents(LODIndex, SectionIndex, MaterialSlot,
		Vertices, Triangles, Normals, UV0, VertexColors, Tangents, UpdateFrequency, bCreateCollision);
}

void URuntimeMeshComponentStatic::UpdateSection_Blueprint(int32 LODIndex, int32 SectionId, const FRuntimeMeshRenderableMeshData & SectionData)
{
	StaticProvider->UpdateSection_Blueprint(LODIndex, SectionId, SectionData);
}

void URuntimeMeshComponentStatic::UpdateSectionFromComponents(int32 LODIndex, int32 SectionIndex, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, 
	const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FVector2D>& UV1, const TArray<FVector2D>& UV2, const TArray<FVector2D>& UV3, 
	const TArray<FLinearColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents)
{
	StaticProvider->UpdateSectionFromComponents(LODIndex, SectionIndex,
		Vertices, Triangles, Normals, UV0, UV1, UV2, UV3, VertexColors, Tangents);
}

void URuntimeMeshComponentStatic::UpdateSectionFromComponents(int32 LODIndex, int32 SectionIndex, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, 
	const TArray<FVector>& Normals, const TArray<FVector2D>& UV0, const TArray<FVector2D>& UV1, const TArray<FVector2D>& UV2, const TArray<FVector2D>& UV3, 
	const TArray<FColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents)
{
	StaticProvider->UpdateSectionFromComponents(LODIndex, SectionIndex,
		Vertices, Triangles, Normals, UV0, UV1, UV2, UV3, VertexColors, Tangents);
}

void URuntimeMeshComponentStatic::UpdateSectionFromComponents(int32 LODIndex, int32 SectionIndex, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, const TArray<FVector>& Normals,
	const TArray<FVector2D>& UV0, const TArray<FLinearColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents)
{
	StaticProvider->UpdateSectionFromComponents(LODIndex, SectionIndex,
		Vertices, Triangles, Normals, UV0, VertexColors, Tangents);
}

void URuntimeMeshComponentStatic::UpdateSectionFromComponents(int32 LODIndex, int32 SectionIndex, const TArray<FVector>& Vertices, const TArray<int32>& Triangles, const TArray<FVector>& Normals,
	const TArray<FVector2D>& UV0, const TArray<FColor>& VertexColors, const TArray<FRuntimeMeshTangent>& Tangents)
{
	StaticProvider->UpdateSectionFromComponents(LODIndex, SectionIndex,
		Vertices, Triangles, Normals, UV0, VertexColors, Tangents);
}

void URuntimeMeshComponentStatic::ClearSection(int32 LODIndex, int32 SectionId)
{
	StaticProvider->ClearSection(LODIndex, SectionId);
}

void URuntimeMeshComponentStatic::SetCollisionSettings(const FRuntimeMeshCollisionSettings & NewCollisionSettings)
{
	StaticProvider->SetCollisionSettings(NewCollisionSettings);
}

void URuntimeMeshComponentStatic::SetCollisionMesh(const FRuntimeMeshCollisionData & NewCollisionMesh)
{
	StaticProvider->SetCollisionMesh(NewCollisionMesh);
}

void URuntimeMeshComponentStatic::SetRenderableLODForCollision(int32 LODIndex)
{
	StaticProvider->SetRenderableLODForCollision(LODIndex);
}

void URuntimeMeshComponentStatic::SetRenderableSectionAffectsCollision(int32 SectionId, bool bCollisionEnabled)
{
	StaticProvider->SetRenderableSectionAffectsCollision(SectionId, bCollisionEnabled);
}

int32 URuntimeMeshComponentStatic::GetLODForMeshCollision() const
{
	return StaticProvider->GetLODForMeshCollision();
}

TSet<int32> URuntimeMeshComponentStatic::GetSectionsForMeshCollision() const
{
	return StaticProvider->GetSectionsForMeshCollision();
}

FRuntimeMeshCollisionSettings URuntimeMeshComponentStatic::GetCollisionSettings() const
{
	return StaticProvider->GetCollisionSettingsStatic();
}

FRuntimeMeshCollisionData URuntimeMeshComponentStatic::GetCollisionMesh() const
{
	return StaticProvider->GetCollisionMeshStatic();
}





URuntimeMeshProviderStatic * URuntimeMeshComponentStatic::GetStaticProvider()
{
	return StaticProvider;
}

void URuntimeMeshComponentStatic::EnableNormalTangentGeneration()
{
	if (!NormalsModifier)
	{
		NormalsModifier = NewObject<URuntimeMeshModifierNormals>(this);
		StaticProvider->RegisterModifier(NormalsModifier);
	}
}

void URuntimeMeshComponentStatic::DisableNormalTangentGeneration()
{
	if (NormalsModifier)
	{
		StaticProvider->UnRegisterModifier(NormalsModifier);
		NormalsModifier = nullptr;
	}
}

bool URuntimeMeshComponentStatic::HasNormalTangentGenerationEnabled() const
{
	return NormalsModifier != nullptr;
}

void URuntimeMeshComponentStatic::EnabledTessellationTrianglesGeneration()
{
	if (!AdjacencyModifier)
	{
		AdjacencyModifier = NewObject<URuntimeMeshModifierAdjacency>(this);
		StaticProvider->RegisterModifier(AdjacencyModifier);
	}
}

void URuntimeMeshComponentStatic::DisableTessellationTrianglesGeneration()
{
	if (AdjacencyModifier)
	{
		StaticProvider->UnRegisterModifier(AdjacencyModifier);
		AdjacencyModifier = nullptr;
	}
}

bool URuntimeMeshComponentStatic::HasTessellationTriangleGenerationEnabled() const
{
	return AdjacencyModifier != nullptr;
}





