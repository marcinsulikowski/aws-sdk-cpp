﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/s3-crt/S3Crt_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSVector.h>
#include <aws/s3-crt/model/LifecycleRule.h>
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
   * <p>Specifies the lifecycle configuration for objects in an Amazon S3 bucket. For
   * more information, see <a
   * href="https://docs.aws.amazon.com/AmazonS3/latest/dev/object-lifecycle-mgmt.html">Object
   * Lifecycle Management</a> in the <i>Amazon S3 User Guide</i>.</p><p><h3>See
   * Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/s3-2006-03-01/BucketLifecycleConfiguration">AWS
   * API Reference</a></p>
   */
  class AWS_S3CRT_API BucketLifecycleConfiguration
  {
  public:
    BucketLifecycleConfiguration();
    BucketLifecycleConfiguration(const Aws::Utils::Xml::XmlNode& xmlNode);
    BucketLifecycleConfiguration& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void AddToNode(Aws::Utils::Xml::XmlNode& parentNode) const;


    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline const Aws::Vector<LifecycleRule>& GetRules() const{ return m_rules; }

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline bool RulesHasBeenSet() const { return m_rulesHasBeenSet; }

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline void SetRules(const Aws::Vector<LifecycleRule>& value) { m_rulesHasBeenSet = true; m_rules = value; }

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline void SetRules(Aws::Vector<LifecycleRule>&& value) { m_rulesHasBeenSet = true; m_rules = std::move(value); }

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline BucketLifecycleConfiguration& WithRules(const Aws::Vector<LifecycleRule>& value) { SetRules(value); return *this;}

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline BucketLifecycleConfiguration& WithRules(Aws::Vector<LifecycleRule>&& value) { SetRules(std::move(value)); return *this;}

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline BucketLifecycleConfiguration& AddRules(const LifecycleRule& value) { m_rulesHasBeenSet = true; m_rules.push_back(value); return *this; }

    /**
     * <p>A lifecycle rule for individual objects in an Amazon S3 bucket.</p>
     */
    inline BucketLifecycleConfiguration& AddRules(LifecycleRule&& value) { m_rulesHasBeenSet = true; m_rules.push_back(std::move(value)); return *this; }

  private:

    Aws::Vector<LifecycleRule> m_rules;
    bool m_rulesHasBeenSet = false;
  };

} // namespace Model
} // namespace S3Crt
} // namespace Aws
