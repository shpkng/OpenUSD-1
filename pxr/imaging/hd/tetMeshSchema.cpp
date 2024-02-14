//
// Copyright 2023 Pixar
//
// Licensed under the Apache License, Version 2.0 (the "Apache License")
// with the following modification; you may not use this file except in
// compliance with the Apache License and the following modification to it:
// Section 6. Trademarks. is deleted and replaced with:
//
// 6. Trademarks. This License does not grant permission to use the trade
//    names, trademarks, service marks, or product names of the Licensor
//    and its affiliates, except as required to comply with Section 4(c) of
//    the License and to reproduce the content of the NOTICE file.
//
// You may obtain a copy of the Apache License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the Apache License with the above modification is
// distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
// KIND, either express or implied. See the Apache License for the specific
// language governing permissions and limitations under the Apache License.
//
////////////////////////////////////////////////////////////////////////

/* ************************************************************************** */
/* **                                                                      ** */
/* ** This file is generated by a script.                                  ** */
/* **                                                                      ** */
/* ** Do not edit it directly (unless it is within a CUSTOM CODE section)! ** */
/* ** Edit hdGen/schema.py instead to make changes.                        ** */
/* **                                                                      ** */
/* ************************************************************************** */

#include "pxr/imaging/hd/tetMeshSchema.h"

#include "pxr/imaging/hd/retainedDataSource.h"

#include "pxr/base/trace/trace.h"

// --(BEGIN CUSTOM CODE: Includes)--
// --(END CUSTOM CODE: Includes)--

PXR_NAMESPACE_OPEN_SCOPE

TF_DEFINE_PUBLIC_TOKENS(HdTetMeshSchemaTokens,
    HD_TET_MESH_SCHEMA_TOKENS);

// --(BEGIN CUSTOM CODE: Schema Methods)--
// --(END CUSTOM CODE: Schema Methods)--

HdTetMeshTopologySchema
HdTetMeshSchema::GetTopology()
{
    return HdTetMeshTopologySchema(_GetTypedDataSource<HdContainerDataSource>(
        HdTetMeshSchemaTokens->topology));
}

HdBoolDataSourceHandle
HdTetMeshSchema::GetDoubleSided()
{
    return _GetTypedDataSource<HdBoolDataSource>(
        HdTetMeshSchemaTokens->doubleSided);
}

/*static*/
HdContainerDataSourceHandle
HdTetMeshSchema::BuildRetained(
        const HdContainerDataSourceHandle &topology,
        const HdBoolDataSourceHandle &doubleSided
)
{
    TfToken _names[2];
    HdDataSourceBaseHandle _values[2];

    size_t _count = 0;

    if (topology) {
        _names[_count] = HdTetMeshSchemaTokens->topology;
        _values[_count++] = topology;
    }

    if (doubleSided) {
        _names[_count] = HdTetMeshSchemaTokens->doubleSided;
        _values[_count++] = doubleSided;
    }
    return HdRetainedContainerDataSource::New(_count, _names, _values);
}

HdTetMeshSchema::Builder &
HdTetMeshSchema::Builder::SetTopology(
    const HdContainerDataSourceHandle &topology)
{
    _topology = topology;
    return *this;
}

HdTetMeshSchema::Builder &
HdTetMeshSchema::Builder::SetDoubleSided(
    const HdBoolDataSourceHandle &doubleSided)
{
    _doubleSided = doubleSided;
    return *this;
}

HdContainerDataSourceHandle
HdTetMeshSchema::Builder::Build()
{
    return HdTetMeshSchema::BuildRetained(
        _topology,
        _doubleSided
    );
}

/*static*/
HdTetMeshSchema
HdTetMeshSchema::GetFromParent(
        const HdContainerDataSourceHandle &fromParentContainer)
{
    return HdTetMeshSchema(
        fromParentContainer
        ? HdContainerDataSource::Cast(fromParentContainer->Get(
                HdTetMeshSchemaTokens->tetMesh))
        : nullptr);
}

/*static*/
const TfToken &
HdTetMeshSchema::GetSchemaToken()
{
    return HdTetMeshSchemaTokens->tetMesh;
}

/*static*/
const HdDataSourceLocator &
HdTetMeshSchema::GetDefaultLocator()
{
    static const HdDataSourceLocator locator(GetSchemaToken());
    return locator;
}

/* static */
const HdDataSourceLocator &
HdTetMeshSchema::GetTopologyLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdTetMeshSchemaTokens->topology);
    return locator;
}

/* static */
const HdDataSourceLocator &
HdTetMeshSchema::GetDoubleSidedLocator()
{
    static const HdDataSourceLocator locator =
        GetDefaultLocator().Append(
            HdTetMeshSchemaTokens->doubleSided);
    return locator;
} 

PXR_NAMESPACE_CLOSE_SCOPE