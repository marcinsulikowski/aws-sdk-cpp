﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/opensearch/OpenSearchService_EXPORTS.h>
#include <aws/opensearch/model/InstanceCountLimits.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Json
{
  class JsonValue;
  class JsonView;
} // namespace Json
} // namespace Utils
namespace OpenSearchService
{
namespace Model
{

  /**
   * <p>InstanceLimits represents the list of instance-related attributes that are
   * available for a given InstanceType. </p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/opensearch-2021-01-01/InstanceLimits">AWS
   * API Reference</a></p>
   */
  class AWS_OPENSEARCHSERVICE_API InstanceLimits
  {
  public:
    InstanceLimits();
    InstanceLimits(Aws::Utils::Json::JsonView jsonValue);
    InstanceLimits& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    
    inline const InstanceCountLimits& GetInstanceCountLimits() const{ return m_instanceCountLimits; }

    
    inline bool InstanceCountLimitsHasBeenSet() const { return m_instanceCountLimitsHasBeenSet; }

    
    inline void SetInstanceCountLimits(const InstanceCountLimits& value) { m_instanceCountLimitsHasBeenSet = true; m_instanceCountLimits = value; }

    
    inline void SetInstanceCountLimits(InstanceCountLimits&& value) { m_instanceCountLimitsHasBeenSet = true; m_instanceCountLimits = std::move(value); }

    
    inline InstanceLimits& WithInstanceCountLimits(const InstanceCountLimits& value) { SetInstanceCountLimits(value); return *this;}

    
    inline InstanceLimits& WithInstanceCountLimits(InstanceCountLimits&& value) { SetInstanceCountLimits(std::move(value)); return *this;}

  private:

    InstanceCountLimits m_instanceCountLimits;
    bool m_instanceCountLimitsHasBeenSet = false;
  };

} // namespace Model
} // namespace OpenSearchService
} // namespace Aws
