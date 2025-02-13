﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/sagemaker/SageMaker_EXPORTS.h>
#include <aws/sagemaker/SageMakerRequest.h>
#include <aws/core/utils/memory/stl/AWSString.h>
#include <utility>

namespace Aws
{
namespace SageMaker
{
namespace Model
{

  /**
   */
  class AWS_SAGEMAKER_API StopMonitoringScheduleRequest : public SageMakerRequest
  {
  public:
    StopMonitoringScheduleRequest();

    // Service request name is the Operation name which will send this request out,
    // each operation should has unique request name, so that we can get operation's name from this request.
    // Note: this is not true for response, multiple operations may have the same response name,
    // so we can not get operation's name from response.
    inline virtual const char* GetServiceRequestName() const override { return "StopMonitoringSchedule"; }

    Aws::String SerializePayload() const override;

    Aws::Http::HeaderValueCollection GetRequestSpecificHeaders() const override;


    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline const Aws::String& GetMonitoringScheduleName() const{ return m_monitoringScheduleName; }

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline bool MonitoringScheduleNameHasBeenSet() const { return m_monitoringScheduleNameHasBeenSet; }

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline void SetMonitoringScheduleName(const Aws::String& value) { m_monitoringScheduleNameHasBeenSet = true; m_monitoringScheduleName = value; }

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline void SetMonitoringScheduleName(Aws::String&& value) { m_monitoringScheduleNameHasBeenSet = true; m_monitoringScheduleName = std::move(value); }

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline void SetMonitoringScheduleName(const char* value) { m_monitoringScheduleNameHasBeenSet = true; m_monitoringScheduleName.assign(value); }

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline StopMonitoringScheduleRequest& WithMonitoringScheduleName(const Aws::String& value) { SetMonitoringScheduleName(value); return *this;}

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline StopMonitoringScheduleRequest& WithMonitoringScheduleName(Aws::String&& value) { SetMonitoringScheduleName(std::move(value)); return *this;}

    /**
     * <p>The name of the schedule to stop.</p>
     */
    inline StopMonitoringScheduleRequest& WithMonitoringScheduleName(const char* value) { SetMonitoringScheduleName(value); return *this;}

  private:

    Aws::String m_monitoringScheduleName;
    bool m_monitoringScheduleNameHasBeenSet = false;
  };

} // namespace Model
} // namespace SageMaker
} // namespace Aws
