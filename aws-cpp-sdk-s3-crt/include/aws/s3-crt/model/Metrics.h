﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/s3-crt/model/MetricsStatus.h>
#include <aws/s3-crt/model/ReplicationTimeValue.h>
#include <utility>

namespace Aws
{
namespace Utils
{
namespace Xml
{
  class XmlNode;
} // namespace Xml
} // namespace Utils
namespace S3Crt
{
namespace Model
{

  /**
   * <p> A container specifying replication metrics-related settings enabling
   * replication metrics and events.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/Metrics">AWS API
   * Reference</a></p>
   */
  class AWS_S3CRT_API Metrics
  {
  public:
    Metrics();
    Metrics(const Aws::Utils::Xml::XmlNode& xmlNode);
    Metrics& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    /**
     * <p> Specifies whether the replication metrics are enabled. </p>
     */
    inline const MetricsStatus& GetStatus() const{ return m_status; }

    /**
     * <p> Specifies whether the replication metrics are enabled. </p>
     */
    inline bool StatusHasBeenSet() const { return m_statusHasBeenSet; }

    /**
     * <p> Specifies whether the replication metrics are enabled. </p>
     */
    inline void SetStatus(const MetricsStatus& value) { m_statusHasBeenSet = true; m_status = value; }

    /**
     * <p> Specifies whether the replication metrics are enabled. </p>
     */
    inline void SetStatus(MetricsStatus&& value) { m_statusHasBeenSet = true; m_status = std::move(value); }

    /**
     * <p> Specifies whether the replication metrics are enabled. </p>
     */
    inline Metrics& WithStatus(const MetricsStatus& value) { SetStatus(value); return *this;}

    /**
     * <p> Specifies whether the replication metrics are enabled. </p>
     */
    inline Metrics& WithStatus(MetricsStatus&& value) { SetStatus(std::move(value)); return *this;}


    /**
     * <p> A container specifying the time threshold for emitting the
     * <code>s3:Replication:OperationMissedThreshold</code> event. </p>
     */
    inline const ReplicationTimeValue& GetEventThreshold() const{ return m_eventThreshold; }

    /**
     * <p> A container specifying the time threshold for emitting the
     * <code>s3:Replication:OperationMissedThreshold</code> event. </p>
     */
    inline bool EventThresholdHasBeenSet() const { return m_eventThresholdHasBeenSet; }

    /**
     * <p> A container specifying the time threshold for emitting the
     * <code>s3:Replication:OperationMissedThreshold</code> event. </p>
     */
    inline void SetEventThreshold(const ReplicationTimeValue& value) { m_eventThresholdHasBeenSet = true; m_eventThreshold = value; }

    /**
     * <p> A container specifying the time threshold for emitting the
     * <code>s3:Replication:OperationMissedThreshold</code> event. </p>
     */
    inline void SetEventThreshold(ReplicationTimeValue&& value) { m_eventThresholdHasBeenSet = true; m_eventThreshold = std::move(value); }

    /**
     * <p> A container specifying the time threshold for emitting the
     * <code>s3:Replication:OperationMissedThreshold</code> event. </p>
     */
    inline Metrics& WithEventThreshold(const ReplicationTimeValue& value) { SetEventThreshold(value); return *this;}

    /**
     * <p> A container specifying the time threshold for emitting the
     * <code>s3:Replication:OperationMissedThreshold</code> event. </p>
     */
    inline Metrics& WithEventThreshold(ReplicationTimeValue&& value) { SetEventThreshold(std::move(value)); return *this;}

  private:

    MetricsStatus m_status;
    bool m_statusHasBeenSet = false;

    ReplicationTimeValue m_eventThreshold;
    bool m_eventThresholdHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
