﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/elasticmapreduce/EMR_EXPORTS.h>
#include <aws/elasticmapreduce/EMRRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace EMR
{
namespace Model
{

  /**
   */
  class AWS_EMR_API GetAutoTerminationPolicyRequest : public EMRRequest
  {
  public:
    GetAutoTerminationPolicyRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "GetAutoTerminationPolicy"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline const Aws::String& GetClusterId() const{ return m_clusterId; }

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline bool ClusterIdHasBeenSet() const { return m_clusterIdHasBeenSet; }

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline void SetClusterId(const Aws::String& value) { m_clusterIdHasBeenSet = true; m_clusterId = value; }

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline void SetClusterId(Aws::String&& value) { m_clusterIdHasBeenSet = true; m_clusterId = std::move(value); }

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline void SetClusterId(const char* value) { m_clusterIdHasBeenSet = true; m_clusterId.assign(value); }

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline GetAutoTerminationPolicyRequest& WithClusterId(const Aws::String& value) { SetClusterId(value); return *this;}

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline GetAutoTerminationPolicyRequest& WithClusterId(Aws::String&& value) { SetClusterId(std::move(value)); return *this;}

    /**
     * <p>Specifies the ID of the Amazon EMR cluster for which the auto-termination
     * policy will be fetched.</p>
     */
    inline GetAutoTerminationPolicyRequest& WithClusterId(const char* value) { SetClusterId(value); return *this;}

  private:

    Aws::String m_clusterId;
    bool m_clusterIdHasBeenSet = false;
  };

} // namespace Model
} // namespace EMR
} // namespace Aws
