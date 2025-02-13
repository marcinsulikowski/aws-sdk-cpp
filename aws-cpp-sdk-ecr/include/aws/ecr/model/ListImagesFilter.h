﻿/**
 * Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
 * SPDX-License-Identifier: Apache-2.0.
 */

#pragma once
#include <aws/ecr/ECR_EXPORTS.h>
#include <aws/ecr/model/TagStatus.h>
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
namespace ECR
{
namespace Model
{

  /**
   * <p>An object representing a filter on a <a>ListImages</a>
   * operation.</p><p><h3>See Also:</h3>   <a
   * href="http://docs.aws.amazon.com/goto/WebAPI/ecr-2015-09-21/ListImagesFilter">AWS
   * API Reference</a></p>
   */
  class AWS_ECR_API ListImagesFilter
  {
  public:
    ListImagesFilter();
    ListImagesFilter(Aws::Utils::Json::JsonView jsonValue);
    ListImagesFilter& operator=(Aws::Utils::Json::JsonView jsonValue);
    Aws::Utils::Json::JsonValue Jsonize() const;


    /**
     * <p>The tag status with which to filter your <a>ListImages</a> results. You can
     * filter results based on whether they are <code>TAGGED</code> or
     * <code>UNTAGGED</code>.</p>
     */
    inline const TagStatus& GetTagStatus() const{ return m_tagStatus; }

    /**
     * <p>The tag status with which to filter your <a>ListImages</a> results. You can
     * filter results based on whether they are <code>TAGGED</code> or
     * <code>UNTAGGED</code>.</p>
     */
    inline bool TagStatusHasBeenSet() const { return m_tagStatusHasBeenSet; }

    /**
     * <p>The tag status with which to filter your <a>ListImages</a> results. You can
     * filter results based on whether they are <code>TAGGED</code> or
     * <code>UNTAGGED</code>.</p>
     */
    inline void SetTagStatus(const TagStatus& value) { m_tagStatusHasBeenSet = true; m_tagStatus = value; }

    /**
     * <p>The tag status with which to filter your <a>ListImages</a> results. You can
     * filter results based on whether they are <code>TAGGED</code> or
     * <code>UNTAGGED</code>.</p>
     */
    inline void SetTagStatus(TagStatus&& value) { m_tagStatusHasBeenSet = true; m_tagStatus = std::move(value); }

    /**
     * <p>The tag status with which to filter your <a>ListImages</a> results. You can
     * filter results based on whether they are <code>TAGGED</code> or
     * <code>UNTAGGED</code>.</p>
     */
    inline ListImagesFilter& WithTagStatus(const TagStatus& value) { SetTagStatus(value); return *this;}

    /**
     * <p>The tag status with which to filter your <a>ListImages</a> results. You can
     * filter results based on whether they are <code>TAGGED</code> or
     * <code>UNTAGGED</code>.</p>
     */
    inline ListImagesFilter& WithTagStatus(TagStatus&& value) { SetTagStatus(std::move(value)); return *this;}

  private:

    TagStatus m_tagStatus;
    bool m_tagStatusHasBeenSet = false;
  };

} // namespace Model
} // namespace ECR
} // namespace Aws
