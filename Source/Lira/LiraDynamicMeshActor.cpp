// Fill out your copyright notice in the Description page of Project Settings.


#include "LiraDynamicMeshActor.h"

#include "GeometryScript/MeshBooleanFunctions.h"
#include "GeometryScript/MeshModelingFunctions.h"
#include "GeometryScript/MeshPrimitiveFunctions.h"


void ALiraDynamicMeshActor::DestroyWall(FVector Position, float SphereRadius)
{
	if (DynamicMeshComponent)
	{
		if (UDynamicMesh* DynamicMesh = DynamicMeshComponent->GetDynamicMesh())
		{
			if (UDynamicMesh* SphereMesh = AllocateComputeMesh())
			{
				FGeometryScriptPrimitiveOptions PrimitiveOptions;
				FVector LocalPosition = DynamicMeshComponent->GetComponentTransform().InverseTransformPosition(Position);
				FTransform FinalTransform;
				FinalTransform.SetLocation(LocalPosition);
				UDynamicMesh* SphereMeshBox = UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendSphereBox(SphereMesh, PrimitiveOptions, FTransform::Identity, SphereRadius, 6, 6, 6, EGeometryScriptPrimitiveOriginMode::Center);

				FGeometryScriptMeshBooleanOptions MeshBooleanOptions;
				UGeometryScriptLibrary_MeshBooleanFunctions::ApplyMeshBoolean(DynamicMesh, FTransform::Identity, SphereMeshBox, FinalTransform, EGeometryScriptBooleanOperation::Subtract, MeshBooleanOptions);

				ReleaseAllComputeMeshes();
			}
		}
	}
}

void ALiraDynamicMeshActor::GenerateBox()
{
	if (DynamicMeshComponent)
	{
		if (UDynamicMesh* DynamicMesh = DynamicMeshComponent->GetDynamicMesh())
		{
			DynamicMesh->Reset();
			FGeometryScriptSimpleCollision CollisionSettings;
			FGeometryScriptPrimitiveOptions PrimitiveOptions;
			PrimitiveOptions.PolygroupMode = EGeometryScriptPrimitivePolygroupMode::PerFace;
			PrimitiveOptions.UVMode = EGeometryScriptPrimitiveUVMode::Uniform;
			UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBoxWithCollision(DynamicMesh, CollisionSettings, PrimitiveOptions, FTransform::Identity, BoxSize.X, BoxSize.Y, BoxSize.Z, 0, 0, 0);
			//UGeometryScriptLibrary_MeshPrimitiveFunctions::AppendBox(DynamicMesh, PrimitiveOptions, FTransform::Identity, BoxSize.X, BoxSize.Y, BoxSize.Z, 0, 0, 0);
		}
	}
}
