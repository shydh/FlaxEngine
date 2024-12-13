// Copyright (c) 2012-2024 Wojciech Figat. All rights reserved.

#pragma once

#include "VertexElement.h"
#include "Engine/Graphics/GPUResource.h"
#include "Engine/Core/Collections/Array.h"

/// <summary>
/// Defines input layout of vertex buffer data passed to the Vertex Shader.
/// </summary>
API_CLASS(Sealed, NoSpawn) class FLAXENGINE_API GPUVertexLayout : public GPUResource
{
    DECLARE_SCRIPTING_TYPE_NO_SPAWN(GPUVertexLayout);
    typedef Array<VertexElement, FixedAllocation<GPU_MAX_VS_ELEMENTS>> Elements;

protected:
    Elements _elements;

    GPUVertexLayout();

public:
    /// <summary>
    /// Gets the list of elements used by this layout.
    /// </summary>
    API_PROPERTY() FORCE_INLINE const Array<VertexElement, FixedAllocation<GPU_MAX_VS_ELEMENTS>>& GetElements() const
    {
        return _elements;
    }

    /// <summary>
    /// Gets the vertex layout for a given list of elements. Uses internal cache to skip creating layout if it's already exists for a given list.
    /// </summary>
    /// <param name="elements">The list of elements for the layout.</param>
    /// <returns>Vertex layout object. Doesn't need to be cleared as it's cached for an application lifetime.</returns>
    API_FUNCTION() static GPUVertexLayout* Get(const Array<VertexElement, FixedAllocation<GPU_MAX_VS_ELEMENTS>>& elements);

public:
    // [GPUResource]
    GPUResourceType GetResourceType() const override
    {
        return GPUResourceType::Descriptor;
    }
};
