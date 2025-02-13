﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ec2/EC2_EXPORTS.h>
#include <aws/core/utils/memory/stl/AWSStreamFwd.h>
#include <aws/core/utils/memory/stl/AWSString.h>
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
namespace EC2
{
namespace Model
{

  /**
   * <p>Describes the Amazon S3 bucket for the disk image.</p><p><h3>See Also:</h3>  
   * <a href="http://docs.aws.amazon.com/goto/WebAPI/ec2-2016-11-15/UserBucket">AWS
   * API Reference</a></p>
   */
  class AWS_EC2_API UserBucket
  {
  public:
    UserBucket();
    UserBucket(const Aws::Utils::Xml::XmlNode& xmlNode);
    UserBucket& operator=(const Aws::Utils::Xml::XmlNode& xmlNode);

    void OutputToStream(Aws::OStream& ostream, const char* location, unsigned index, const char* locationValue) const;
    void OutputToStream(Aws::OStream& oStream, const char* location) const;


    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline const Aws::String& GetS3Bucket() const{ return m_s3Bucket; }

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline bool S3BucketHasBeenSet() const { return m_s3BucketHasBeenSet; }

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline void SetS3Bucket(const Aws::String& value) { m_s3BucketHasBeenSet = true; m_s3Bucket = value; }

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline void SetS3Bucket(Aws::String&& value) { m_s3BucketHasBeenSet = true; m_s3Bucket = std::move(value); }

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline void SetS3Bucket(const char* value) { m_s3BucketHasBeenSet = true; m_s3Bucket.assign(value); }

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline UserBucket& WithS3Bucket(const Aws::String& value) { SetS3Bucket(value); return *this;}

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline UserBucket& WithS3Bucket(Aws::String&& value) { SetS3Bucket(std::move(value)); return *this;}

    /**
     * <p>The name of the Amazon S3 bucket where the disk image is located.</p>
     */
    inline UserBucket& WithS3Bucket(const char* value) { SetS3Bucket(value); return *this;}


    /**
     * <p>The file name of the disk image.</p>
     */
    inline const Aws::String& GetS3Key() const{ return m_s3Key; }

    /**
     * <p>The file name of the disk image.</p>
     */
    inline bool S3KeyHasBeenSet() const { return m_s3KeyHasBeenSet; }

    /**
     * <p>The file name of the disk image.</p>
     */
    inline void SetS3Key(const Aws::String& value) { m_s3KeyHasBeenSet = true; m_s3Key = value; }

    /**
     * <p>The file name of the disk image.</p>
     */
    inline void SetS3Key(Aws::String&& value) { m_s3KeyHasBeenSet = true; m_s3Key = std::move(value); }

    /**
     * <p>The file name of the disk image.</p>
     */
    inline void SetS3Key(const char* value) { m_s3KeyHasBeenSet = true; m_s3Key.assign(value); }

    /**
     * <p>The file name of the disk image.</p>
     */
    inline UserBucket& WithS3Key(const Aws::String& value) { SetS3Key(value); return *this;}

    /**
     * <p>The file name of the disk image.</p>
     */
    inline UserBucket& WithS3Key(Aws::String&& value) { SetS3Key(std::move(value)); return *this;}

    /**
     * <p>The file name of the disk image.</p>
     */
    inline UserBucket& WithS3Key(const char* value) { SetS3Key(value); return *this;}

  private:

    Aws::String m_s3Bucket;
    bool m_s3BucketHasBeenSet = false;

    Aws::String m_s3Key;
    bool m_s3KeyHasBeenSet = false;
  };

} // namespace Model
} // namespace EC2
} // namespace Aws
